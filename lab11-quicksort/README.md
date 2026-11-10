# Descending character quicksort

## Goal and algorithm

Partition around the final character, moving larger characters to the left, then recursively sort the two partitions.

## Complexity

Average O(n log n) time; worst-case O(n²). Recursion uses O(log n) average and O(n) worst-case space.

## Example

Input (or fixed setup):

```text
cab
```

Key result (prompts and surrounding labels omitted):

```text
Characters in descending order: cba
```

## Limits and conventions

Sorts ASCII characters, including spaces, not words. Newline-terminated input is limited to 998 characters. Sorted and equal-character inputs exercise the worst case; this course implementation retains its simple pivot rule.

See the [root build instructions](../README.md#build-and-run) and [source](main.c).
