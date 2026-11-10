# Dijkstra shortest paths

## Goal and algorithm

Repeatedly select the unvisited vertex with smallest tentative distance, then relax its outgoing edges. Stop when remaining vertices are unreachable.

## Complexity

O(V²) time and O(V) auxiliary space, plus O(V²) matrix storage.

## Example

Input (or fixed setup):

```text
No input; fixed five-vertex directed graph, source 0.
```

Key result (prompts and surrounding labels omitted):

```text
Distances for vertices 0–4: 0, 8, 5, 9, 7.
```

## Limits and conventions

Requires non-negative weights and a valid source index. INF (9999999) denotes no edge; zero-weight edges are supported. INT_MAX denotes unreachable/unrepresentable distance. Addition is checked to avoid overflow.

See the [root build instructions](../README.md#build-and-run) and [source](main.c).
