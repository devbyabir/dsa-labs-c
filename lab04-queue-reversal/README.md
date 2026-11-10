# Reverse the last k queue elements

## Goal and algorithm

Push the last k occupied array slots onto a stack, then pop them back into those slots. The preceding elements stay in place.

## Complexity

Reversal: O(k) time and O(k) conceptual stack space (fixed capacity 100 here). Reading/printing: O(n).

## Example

Input (or fixed setup):

```text
2 5 1 2 3 4 5
```

Key result (prompts and surrounding labels omitted):

```text
After reversing last 2 elements: [1,2,3,5,4]
```

## Limits and conventions

Enter k, n, then n integers. Requires 0 <= k <= n <= 100. Empty and full queues are supported. The queue is a bounded linear array, not a general circular queue.

See the [root build instructions](../README.md#build-and-run) and [source](main.c).
