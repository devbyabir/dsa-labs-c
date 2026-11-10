# Prefix averages and maximum subsequence

## Goal and algorithm

Maintain a running sum for each prefix average. Try every start/end pair for the maximum contiguous sum.

## Complexity

Prefix averages: O(n) time and O(n) output space. Maximum sum: O(n²) time and O(1) auxiliary space.

## Example

Input (or fixed setup):

```text
5 1 2 3 4 5
```

Key result (prompts and surrounding labels omitted):

```text
Prefix averages: 1.00 1.50 2.00 2.50 3.00; maximum sum: 15.
```

## Limits and conventions

Accepts 1–100 integers in [-1000000, 1000000]. The empty subsequence is allowed, giving zero for all-negative input. The quadratic method is retained for the course exercise.

See the [root build instructions](../README.md#build-and-run) and [source](main.c).
