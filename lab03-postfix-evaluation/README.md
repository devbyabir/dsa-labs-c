# Postfix expression evaluation

## Goal and algorithm

Push each digit. For an operator, pop the right operand then the left, calculate with a wider intermediate and push the checked result.

## Complexity

O(L) time and O(L) stack space for expression length L.

## Example

Input (or fixed setup):

```text
23+4*
```

Key result (prompts and surrounding labels omitted):

```text
Result: 20
```

## Limits and conventions

Single-digit operands and + - * / only; whitespace is allowed. Division truncates toward zero. Rejects invalid expressions, zero divisors and int overflow. Newline-terminated input is limited to 126 characters.

See the [root build instructions](../README.md#build-and-run) and [source](main.c).
