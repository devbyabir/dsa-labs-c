# Data Structures and Algorithms Labs in C

My second-semester DSA coursework at Zhengzhou University (2024), cleaned up
and corrected in November 2026. Each lab is a separate console program.

This follows my [first-semester C labs](https://github.com/devbyabir/c-programming-labs).
The focus here is on linked structures, stacks, queues, trees and graph algorithms.

## Labs

| Lab | Folder | Exercise |
| --- | --- | --- |
| 1 | `lab01-prefix-averages` | Prefix averages and maximum contiguous subsequence sum |
| 2 | `lab02-linked-list` | Swap adjacent list nodes by changing links |
| 3 | `lab03-postfix-evaluation` | Evaluate a postfix expression with a stack |
| 4 | `lab04-queue-reversal` | Reverse the last k queue elements |
| 5 | `lab05-expression-tree` | Evaluate a fixed arithmetic expression tree |
| 6 | `lab06-tree-traversal` | Iterative preorder traversal using a linked stack |
| 7 | `lab07-breadth-first-search` | Breadth-first traversal using a queue |
| 8 | `lab08-dijkstra` | Single-source shortest path distances |
| 9 | `lab09-prim` | Minimum spanning tree |
| 10 | `lab10-substring-search` | Find a substring using naive matching |
| 11 | `lab11-quicksort` | Sort the characters of a string in descending order |

## Build and run

Use a C11 compiler. From the repository root:

```sh
mkdir build
gcc -std=c11 -Wall -Wextra -Wpedantic lab04-queue-reversal/main.c -o build/queue
./build/queue
```

On Windows, use `-o build/queue.exe` and run `.\build\queue.exe`.
No third-party C libraries are needed. Python 3 is only needed for the tests.

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

```sh
python tests/test_labs.py
```

The script compiles all 11 programs with warnings treated as errors, then checks
ordinary inputs, invalid inputs, queue boundaries, graph results, and randomized
queue/string cases. Set `CC` to select a compiler and `CFLAGS` for extra flags.
GitHub Actions runs the suite with GCC and Clang and memory/undefined-behavior sanitizers.

See [REVIEW_NOTES.md](REVIEW_NOTES.md) for source selection, corrections and the
current verification status. The automated suite has not yet been run successfully;
this is a prepared local repository awaiting runtime verification.
