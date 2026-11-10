# Breadth-first search

## Goal and algorithm

Start at vertex 0, mark vertices when enqueued, then visit each dequeued vertex’s neighbors in increasing index order.

## Complexity

O(V²) time for an adjacency matrix; O(V) traversal space plus O(V²) graph storage.

## Example

Input (or fixed setup):

```text
No input; a fixed seven-vertex undirected graph.
```

Key result (prompts and surrounding labels omitted):

```text
0 1 2 3 4 5 6
```

## Limits and conventions

Visits the component reachable from vertex 0. Matrix entry 1 means an edge. The fixed queue capacity exceeds this example’s vertex count; this is not a configurable graph API.

See the [root build instructions](../README.md#build-and-run) and [source](main.c).
