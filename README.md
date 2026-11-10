# Data Structures and Algorithms Labs in C

My second-semester DSA coursework at Zhengzhou University (2024), cleaned up
and corrected in November 2026. Each lab is a separate console program.

The programs here are reviewed versions of the 2024 submissions, not unchanged
copies. [REVIEW_NOTES.md](REVIEW_NOTES.md) records where each one came from and
every correction made since.

This follows my [first-semester C labs](https://github.com/devbyabir/c-programming-labs).
The focus here is on linked structures, stacks, queues, trees and graph algorithms.

## Labs

| Lab | Folder | Exercise |
| --- | --- | --- |
| 1 | [`lab01-prefix-averages`](lab01-prefix-averages/) | Prefix averages and maximum contiguous subsequence sum |
| 2 | [`lab02-linked-list`](lab02-linked-list/) | Swap adjacent list nodes by changing links |
| 3 | [`lab03-postfix-evaluation`](lab03-postfix-evaluation/) | Evaluate a postfix expression with a stack |
| 4 | [`lab04-queue-reversal`](lab04-queue-reversal/) | Reverse the last k queue elements |
| 5 | [`lab05-expression-tree`](lab05-expression-tree/) | Evaluate a fixed arithmetic expression tree |
| 6 | [`lab06-tree-traversal`](lab06-tree-traversal/) | Iterative preorder traversal using a linked stack |
| 7 | [`lab07-breadth-first-search`](lab07-breadth-first-search/) | Breadth-first traversal using a queue |
| 8 | [`lab08-dijkstra`](lab08-dijkstra/) | Single-source shortest path distances |
| 9 | [`lab09-prim`](lab09-prim/) | Minimum spanning tree |
| 10 | [`lab10-substring-search`](lab10-substring-search/) | Find a substring using naive matching |
| 11 | [`lab11-quicksort`](lab11-quicksort/) | Sort the characters of a string in descending order |

## Build and run

Use a C11 compiler. No third-party C libraries are needed. From the repository root:

```sh
mkdir build
gcc -std=c11 -Wall -Wextra -Wpedantic lab04-queue-reversal/main.c -o build/queue
./build/queue
```

On Windows, use `-o build/queue.exe` and run `.\build\queue.exe`.
Every other lab builds the same way; only the folder and output name change.

For lab 4, enter `k`, the number of elements, then the elements:

```text
2
5
1 2 3 4 5
```

The resulting queue is `[1,2,3,5,4]`.

## Exercise conventions

- Lab 1 accepts 1–100 integers, each between -1,000,000 and 1,000,000.
  The maximum-subsequence calculation allows an empty subsequence, so an
  all-negative array has a maximum sum of zero. It uses the course's O(n²) method.
- Lab 2 uses one-based positions; position 2 swaps the second and third nodes.
- Lab 3 accepts single-digit operands, optional whitespace, and `+ - * /`.
  Division uses C integer division. Invalid expressions and arithmetic overflow
  are rejected. Up to 126 characters plus a newline fit the input buffer.
- Lab 4 accepts 0–100 elements and requires `0 <= k <= n`.
- Labs 5–9 use the small fixed trees and graphs from the submissions.
  Dijkstra's graph has non-negative weights; `INF` marks an absent edge.
  Prim's graph uses zero for an absent edge, so it does not represent zero-weight edges.
- Lab 10 returns one-based substring positions; an empty substring matches at
  position 1. With newline-terminated input, each line is at most 48 characters.
- Lab 11 sorts individual ASCII characters, not a list of words or natural-language
  text. With newline-terminated input, the maximum length is 998 characters.

## Tests

Python 3 is needed only for the tests:

```sh
python tests/test_labs.py
```

The script compiles all 11 programs with warnings treated as errors, then checks
ordinary inputs, invalid inputs, input-length and queue boundaries, the fixed
tree and graph results, and randomized queue/string cases. Set `CC` to select a
compiler and `CFLAGS` for extra flags.

GitHub Actions checks formatting and runs normal and sanitizer builds with GCC
and Clang. Sanitizer errors are fatal, and the runner checks exact exit status
and expected error diagnostics. It also exercises linked-list and graph functions
on additional inputs, numeric reader failures, and adversarial quicksort inputs.
Seven runner self-tests ensure crashes and unexpected diagnostics cannot pass.

## Build tooling

With GNU Make, Python 3.9+, GCC/Clang and clang-format 18 installed:

```sh
make CC=gcc
make test CC=gcc
make sanitize CC=clang
make format-check
make format
make clean
```

`make` writes standalone executables to `build/`. Tests compile their own temporary
executables and remove them afterward. Make targets use a POSIX shell; on Windows
use WSL/MSYS2, or invoke the Python test script directly with a compiler on PATH.
The shared numeric reader must remain alongside labs 1 and 4. Supported arithmetic
assumes 32-bit `int` and at least 64-bit `long long`.

Each lab folder contains a short algorithm explanation, complexity analysis,
example and limitations. See [tests/README.md](tests/README.md) for testing details.

## Provenance and reuse

This is a public coursework archive with **no repository-wide open-source license**.
The original sources of every inherited fragment have not been established.
[LICENSE.md](LICENSE.md) states the licensing status; [ATTRIBUTION.md](ATTRIBUTION.md)
records known provenance and gaps. Do not interpret publication as a blanket grant
to reuse third-party material.
