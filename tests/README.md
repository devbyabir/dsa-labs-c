# Tests

Run `python3 tests/test_labs.py` or `make test`. Set `CC` to the compiler executable
and `CFLAGS` to extra options. Each program has a five-second execution timeout;
compilation has a sixty-second timeout. Tests compile into a temporary directory.

The suite checks normal and invalid input, numeric bounds and embedded NUL tokens,
line-length limits, fixed graph/tree outputs, randomized queue/string inputs, and
sorted/equal-character quicksort inputs. The four C harnesses include the actual
lab implementations with their demonstration `main` renamed, so functions can be
checked on empty lists, boundary positions, alternative/disconnected graphs,
unreachable vertices and overflowing path sums without changing the lab interface.
The input harness injects a stream failure portably.

Successful execution must return 0 with empty stderr. Invalid input must return
exactly 1 and the expected diagnostic. Crashes, sanitizer diagnostics and timeouts
fail the suite. Seven runner self-tests verify these rejection rules.

`make sanitize` enables AddressSanitizer and UndefinedBehaviorSanitizer with
`-fno-sanitize-recover=all`. Keep assertions enabled in harness builds (do not set
`NDEBUG`). The suite is regression coverage, not exhaustive branch coverage or
proof of correctness for every possible graph.
