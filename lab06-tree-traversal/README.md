# Iterative preorder traversal

## Goal and algorithm

Print a node before descending left; save ancestors on a linked stack and pop them to visit their right subtrees.

## Complexity

O(n) time and O(h) auxiliary stack space.

## Example

Input (or fixed setup):

```text
No input; the program builds the course example tree.
```

Key result (prompts and surrounding labels omitted):

```text
8 5 7 6 4 9 8
```

## Limits and conventions

Traversal is preorder, not sorted order. Nodes may have equal values. Stack entries and tree nodes are freed; allocation failure exits the program.

See the [root build instructions](../README.md#build-and-run) and [source](main.c).
