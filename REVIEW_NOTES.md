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

## Verification status

All 11 programs are checked with C11, `-Wall -Wextra -Wpedantic -Werror`.
GCC 16.2.0 (portable w64devkit 2.11.0), including `-fanalyzer`: all 11
compiled with zero warnings or errors.

Windows Application Control blocked execution of the locally built executables.
Therefore no local runtime, sanitizer or regression-test pass is claimed.
The Python regression suite and GitHub Actions configuration are included, but
must pass on a machine that permits execution before the repository is described
as runtime-verified. GitHub Actions has not been run because this repository has
not been uploaded.
