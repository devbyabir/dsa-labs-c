# Review notes

## Source selection

These programs were recovered from my second-semester lab submissions. Labs
1–3 and 5 were recovered from the text in their Word reports; labs 4 and 6–11
came from the submitted source archives. The archive labelled Lab 5 actually
contains Lab 10, so the expression-tree code was recovered from the Lab 5 report.

Teacher answer files, lecture examples, assignment PDFs, reports, screenshots,
binaries and student IDs are excluded. This repository does not establish the
original authorship of every standard algorithm fragment or grant a new licence
to third-party material.

## Corrections made in November 2026

The first correction pass (commits 136d6d5 and 748cb25) changed the 2024
submissions as follows:

- Lab 1: removed the array sized using an uninitialized variable, corrected the
  prefix-average return type, bounded input and used double for averages.
- Lab 2: clarified one-based positions, allowed swapping at the head and freed the list.
- Lab 3: retained the stack evaluation approach but rewrote input/evaluation checks
  to reject malformed expressions, overlong input, division by zero and int overflow.
- Lab 4: replaced the rotation logic with a stack applied to the queue's last k
  slots. This preserves the prefix and handles full-capacity and empty queues.
- Lab 5: added an allocation-failure check. The fixed expression remains unchanged.
- Lab 6: corrected the traversal return type, added allocation checks and tree cleanup.
- Lab 7: added an allocation check, removed an unused variable and separated printed vertices.
- Lab 8: excluded absent edges during relaxation and guarded distance addition.
- Lab 9: handled disconnected graphs and visited all vertices before printing a result.
- Lab 10: checked line input and starting positions; clarified substring terminology.
- Lab 11: checked line input, separated pivot advancement from recursion and clarified
  that characters, rather than multiple strings, are sorted.

These are reviewed versions, not unchanged copies of the original submissions.
The algorithms remain small standalone exercises; they are not general-purpose libraries.

## Final review (2026-11)

A second review after commit 748cb25 rechecked all 11 programs, with extra
attention to queue reversal at k = 0, k = n and full capacity, malformed postfix
input and overflow, the documented input-length limits of labs 3, 10 and 11, and
the fixed tree and graph outputs, which were traced by hand.

- Lab 6: the traversal did not end its output with a newline, so the shell
  prompt appeared on the same line as the result. It now prints one.
- Tests: added regression cases for the exact input-length limits (126 characters
  for lab 3, 48 per line for lab 10, 998 for lab 11, each with the first rejected
  length), postfix operator underflow and intermediate overflow in both
  directions, invalid `k` for empty and full queues, the exact lab 5 and lab 6
  output, and the exact lab 9 edge list rather than only its total weight.
- The documentation files were re-saved as UTF-8; they were previously
  Windows-1252.

No other reproducible bugs were found. The O(n²) maximum-subsequence method, the
fixed trees and graphs, and the descending character order are course choices
and were left unchanged.

## Verification status

**Earlier local check.** All 11 programs were compiled with C11 and
`-Wall -Wextra -Wpedantic -Werror` using GCC 16.2.0 (portable w64devkit 2.11.0),
including `-fanalyzer`, with zero warnings or errors. Windows Application Control
blocked execution of the locally built executables, so no local runtime,
sanitizer or regression-test pass is claimed.

**Baseline CI, commit 748cb25.** The
[GitHub Actions run](https://github.com/devbyabir/dsa-labs-c/actions/runs/42000471719)
triggered by the push of 748cb25 on 5 November 2026 succeeded. Both matrix
jobs, `test (gcc)` and `test (clang)`, compiled all 11 programs and passed the
regression suite with `-fsanitize=address,undefined`. This result covers the
code as of 748cb25 only.

**Final-review changes, commit 9b491cf.** No C compiler was available on the
review machine, so the lab 6 fix and the new test cases were first compiled and
run by GitHub Actions. The
[run](https://github.com/devbyabir/dsa-labs-c/actions/runs/42379732751)
triggered by the push of 9b491cf on 7 November 2026 succeeded: `test (gcc)` and
`test (clang)` both passed the full suite, including the new cases, with
`-fsanitize=address,undefined`.
