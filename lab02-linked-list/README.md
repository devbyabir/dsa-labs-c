# Swap adjacent linked-list nodes

## Goal and algorithm

Walk to the link pointing at the requested node, then reconnect the two adjacent nodes without swapping their stored values.

## Complexity

O(p) time to reach position p; O(1) extra space for the swap. The demonstration list occupies O(n) space.

## Example

Input (or fixed setup):

```text
No input; the demo swaps position 2 in 1 2 3 4 5.
```

Key result (prompts and surrounding labels omitted):

```text
List after swapping at position 2: 1 3 2 4 5
```

## Limits and conventions

Positions are one-based. Empty lists, non-positive positions and positions without a following node return failure. The caller supplies a valid head pointer. Allocated nodes are freed.

See the [root build instructions](../README.md#build-and-run) and [source](main.c).
