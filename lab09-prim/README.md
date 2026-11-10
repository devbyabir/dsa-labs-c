# Prim minimum spanning tree

## Goal and algorithm

Grow a tree from vertex 0 by choosing the unvisited vertex with the cheapest connecting edge; update each neighbor’s best parent.

## Complexity

O(V²) time and O(V) auxiliary space, plus matrix storage (fixed 100×100 allocation).

## Example

Input (or fixed setup):

```text
No input; fixed five-vertex undirected graph.
```

Key result (prompts and surrounding labels omitted):

```text
Edges: 3–1 (4), 0–2 (3), 2–3 (2), 3–4 (1). Total weight: 10.
```

## Limits and conventions

Requires a symmetric graph. Zero denotes no edge, so zero-weight edges are unsupported. Disconnected graphs print a message. Vertex count is limited to 1–100; weights must be below INT_MAX.

See the [root build instructions](../README.md#build-and-run) and [source](main.c).
