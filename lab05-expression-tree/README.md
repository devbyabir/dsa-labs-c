# Evaluate an expression tree

## Goal and algorithm

Recursively evaluate the two child subtrees and apply the parent operator. Leaves contain single-digit operands.

## Complexity

O(n) time and O(h) recursion space for n nodes and tree height h.

## Example

Input (or fixed setup):

```text
No input; fixed expression: (6 + 7) * (2 - 1).
```

Key result (prompts and surrounding labels omitted):

```text
Result of the expression tree: 13
```

## Limits and conventions

This is a fixed, valid tree demonstration, not a parser. General expression overflow and malformed-tree validation are outside its scope. Cleanup matches the fixed tree shape.

See the [root build instructions](../README.md#build-and-run) and [source](main.c).
