"""Compile every lab, then exercise normal, boundary and invalid inputs."""
import os
from pathlib import Path
import random
import shlex
import subprocess
import tempfile
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]

class Labs(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temp = tempfile.TemporaryDirectory()
        cls.addClassCleanup(cls.temp.cleanup)
        cls.executables = {}
        for source in sorted(ROOT.glob("lab*/main.c")) + sorted((ROOT / "tests" / "harnesses").glob("*.c")):
            number = int(source.parent.name[3:5]) if source.name == "main.c" else source.stem
            target = Path(cls.temp.name) / (str(number) + (".exe" if os.name == "nt" else ""))
            subprocess.run([os.environ.get("CC", "gcc"), "-std=c11", "-Wall", "-Wextra",
                            "-Wpedantic", "-Werror", *shlex.split(os.environ.get("CFLAGS", "")),
                            str(source), "-o", str(target)], check=True, timeout=60)
            cls.executables[number] = target

    def run_lab(self, number, data="", success=True, expected_error=None):
        result = subprocess.run([str(self.executables[number])], input=data,
                                text=True, capture_output=True, timeout=5)
        self.assertEqual(result.returncode, 0 if success else 1, result.stdout + result.stderr)
        if success:
            self.assertEqual(result.stderr, "", result.stderr)
        elif expected_error is not None:
            self.assertEqual(result.stderr, "", result.stderr)
            self.assertTrue(result.stdout.endswith(expected_error + "\n"), result.stdout)
        else:
            self.assertEqual(result.stderr, "Invalid input.\n", result.stdout + result.stderr)
        return result.stdout

    def test_prefix_averages(self):
        self.assertIn("1.00 1.50 2.00 2.50 3.00", self.run_lab(1, "5 1 2 3 4 5"))
        self.assertIn("Sum: 15", self.run_lab(1, "5 1 2 3 4 5"))
        self.assertIn("Sum: 0", self.run_lab(1, "3 -5 -2 -9"))
        for data in ("0", "101", "abc", "1 abc", "1 1000001", "99999999999999999999"):
            self.run_lab(1, data, False)

    def test_list(self):
        self.assertIn("1 3 2 4 5", self.run_lab(2))

    def test_postfix(self):
        for expression, expected in (("23+4*", 20), ("82/3-", 1), ("0", 0), ("2 3 +", 5)):
            self.assertIn(f"Result: {expected}", self.run_lab(3, expression + "\n"))
        for expression, message in (("", "Invalid expression."), ("23", "Invalid expression."),
                                    ("+", "Invalid expression."), ("20/", "Division by zero."),
                                    ("23?", "Invalid operator."),
                                    ("99999999999999999999*******************", "Result out of range.")):
            self.run_lab(3, expression + "\n", False, message)
        self.run_lab(3, "1" * 130 + "\n", False)

    def test_postfix_boundaries(self):
        # 126 characters plus a newline fit the buffer; 127 do not.
        self.assertIn("Result: 1", self.run_lab(3, "1" + " " * 125 + "\n"))
        self.run_lab(3, "1" + " " * 126 + "\n", False)
        self.assertIn("Invalid expression.", self.run_lab(3, "23++\n", False, "Invalid expression."))
        # 9 to the 10th power overflows int in either direction before the last step.
        for expression in ("9" + "9*" * 10, "09-" + "9*" * 10):
            self.assertIn("Result out of range.", self.run_lab(3, expression + "\n", False, "Result out of range."))

    def test_embedded_nul_line_input(self):
        for data in ("23+\0ignored", "23+\0ignored\n"):
            self.run_lab(3, data, False)
        for data in ("hello world\nworld\0ignored", "hello world\nworld\0ignored\n"):
            self.run_lab(10, data, False)
        for data in ("ab\0ignored", "ab\0ignored\n"):
            self.run_lab(11, data, False)
        self.assertIn("Result: 1", self.run_lab(3, "1" + " " * 125))
        self.run_lab(3, "1" + " " * 126, False)
        self.assertIn("position : 1", self.run_lab(10, "a\n" + "a" * 48))
        self.run_lab(10, "a\n" + "a" * 49, False)
        self.assertIn("Characters in descending order: " + "x" * 998,
                      self.run_lab(11, "x" * 998))
        self.run_lab(11, "x" * 999, False)

    def test_queue_randomized(self):
        rng = random.Random(2026)
        for size in (0, 1, 2, 5, 50, 100):
            values = [rng.randint(-100, 100) for _ in range(size)]
            for k in sorted({0, size, size // 2}):
                expected = values[:size-k] + list(reversed(values[size-k:])) if k else values
                output = self.run_lab(4, f"{k} {size} " + " ".join(map(str, values)))
                self.assertTrue(output.rstrip().endswith("[" + ",".join(map(str, expected)) + "]"), output)
        for data in ("3 2", "-1 2", "0 101", "x", "1 1 x", "1 0", "101 100"):
            self.run_lab(4, data, False)

    def test_tree_and_graphs(self):
        self.assertIn("Result of the expression tree: 13\n", self.run_lab(5))
        self.assertEqual(self.run_lab(6), "8 5 7 6 4 9 8 \n")
        self.assertEqual(self.run_lab(7).strip(), "0 1 2 3 4 5 6")
        result = self.run_lab(8)
        for vertex, distance in enumerate((0, 8, 5, 9, 7)):
            self.assertIn(f"V0 and V{vertex} is {distance}", result)
        edges = self.run_lab(9).splitlines()[1:]
        self.assertEqual(sum(int(line.split()[-1]) for line in edges), 10)
        self.assertEqual([line.split() for line in edges],
                         [["3", "-", "1", "4"], ["0", "-", "2", "3"],
                          ["2", "-", "3", "2"], ["3", "-", "4", "1"]])

    def test_substring(self):
        for sentence, word, expected in (("hello world", "world", "position : 7"),
                                          ("aaaaab", "aab", "position : 4"),
                                          ("hello", "xyz", "not found"),
                                          ("hello", "", "position : 1")):
            self.assertIn(expected, self.run_lab(10, sentence + "\n" + word + "\n"))
        self.run_lab(10, "x" * 80 + "\na\n", False)
        # Each line may hold 48 characters plus a newline; 49 are rejected.
        self.assertIn("position : 1", self.run_lab(10, "a" * 48 + "\n" + "a" * 48 + "\n"))
        self.run_lab(10, "a" * 49 + "\na\n", False)
        self.run_lab(10, "a" * 48 + "\n" + "a" * 49 + "\n", False)
        self.run_lab(10, "", False)

    def test_quicksort_randomized(self):
        rng = random.Random(11)
        for length in (0, 1, 2, 20, 100, 998):
            text = "".join(rng.choice("abcXYZ 123") for _ in range(length))
            expected = "".join(sorted(text, reverse=True))
            self.assertIn("Characters in descending order: " + expected + "\n",
                          self.run_lab(11, text + "\n"))
        self.run_lab(11, "x" * 999 + "\n", False)
        self.run_lab(11, "x" * 1000 + "\n", False)
        self.run_lab(11, "", False)

    def test_numeric_tokens(self):
        for token in ("12\0abc", "12abc", "2147483648", "-2147483649", "9" * 100):
            with self.subTest(token=repr(token)):
                self.run_lab(1, "1 " + token, False)
                self.run_lab(4, "1 1 " + token, False)
        self.run_lab(1, "", False)
        self.run_lab(4, "", False)
        self.assertIn("[-2147483648,2147483647]", self.run_lab(4, "0 2 -2147483648 2147483647"))

    def test_algorithm_harnesses(self):
        for name in ("linked_list", "dijkstra", "read_int"):
            with self.subTest(harness=name):
                self.assertEqual(self.run_lab(name), "")
        self.assertEqual(self.run_lab("prim"), "Edge \tWeight\nGraph is disconnected.\n"
                         "Edge \tWeight\n2 - 1 \t2 \n0 - 2 \t1 \n")

    def test_quicksort_adversarial(self):
        for text in ("a" * 998, "a" * 499 + "z" * 499, "z" * 499 + "a" * 499):
            with self.subTest(prefix=text[:10]):
                self.assertEqual(self.run_lab(11, text + "\n"),
                                 "Enter a string : Characters in descending order: " +
                                 "".join(sorted(text, reverse=True)) + "\n")


class RunnerTests(unittest.TestCase):
    def check_mock(self, status, stdout="", stderr="", success=True, expected_error=None):
        lab = Labs()
        lab.executables = {1: "not-executed"}
        result = subprocess.CompletedProcess([], status, stdout, stderr)
        with patch.object(subprocess, "run", return_value=result):
            return lab.run_lab(1, success=success, expected_error=expected_error)

    def test_success(self):
        self.check_mock(0)

    def test_expected_rejection(self):
        self.check_mock(1, stderr="Invalid input.\n", success=False)

    def test_crash_is_not_rejection(self):
        for status in (-11, 139, 2):
            with self.subTest(status=status), self.assertRaises(AssertionError):
                self.check_mock(status, stderr="Invalid input.\n", success=False)

    def test_success_stderr_rejected(self):
        with self.assertRaises(AssertionError):
            self.check_mock(0, stderr="runtime error: overflow")

    def test_failure_stderr_rejected(self):
        with self.assertRaises(AssertionError):
            self.check_mock(1, stderr="AddressSanitizer: error", success=False)

    def test_wrong_message_rejected(self):
        with self.assertRaises(AssertionError):
            self.check_mock(1, stdout="wrong\n", success=False, expected_error="Invalid expression.")

    def test_timeout_propagates(self):
        lab = Labs()
        lab.executables = {1: "not-executed"}
        with patch.object(subprocess, "run", side_effect=subprocess.TimeoutExpired("lab", 5)):
            with self.assertRaises(subprocess.TimeoutExpired):
                lab.run_lab(1)

if __name__ == "__main__":
    unittest.main(verbosity=2)
