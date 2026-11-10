# Naive substring matching

## Goal and algorithm

Compare characters until a mismatch, then restart at the next sentence position. Return the first complete match.

## Complexity

O(nm) worst-case time for sentence length n and pattern length m; O(1) auxiliary space.

## Example

Input (or fixed setup):

```text
hello world
world
```

Key result (prompts and surrounding labels omitted):

```text
The substring starts at position : 7
```

## Limits and conventions

Positions are one-based and an empty pattern matches at position 1. Each newline-terminated input line is at most 48 characters. Matching is case-sensitive byte matching, not Unicode-aware search.

See the [root build instructions](../README.md#build-and-run) and [source](main.c).
