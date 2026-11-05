/* Evaluate postfix expressions with single-digit operands and + - * /. */
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>

int main(void)
{
    char expression[128];
    int stack[128], count = 0;
    printf("Enter a postfix expression: ");
    if (!fgets(expression, sizeof expression, stdin)) return 1;
    if (!strchr(expression, '\n') && !feof(stdin)) return 1;
    for (int i = 0; expression[i]; i++) {
        unsigned char c = (unsigned char)expression[i];
        if (isspace(c)) continue;
        if (isdigit(c)) { stack[count++] = c - '0'; continue; }
        if (count < 2) { puts("Invalid expression."); return 1; }
        int b = stack[--count], a = stack[--count];
        long long value;
        switch (c) {
        case '+': value = (long long)a + b; break;
        case '-': value = (long long)a - b; break;
        case '*': value = (long long)a * b; break;
        case '/':
            if (b == 0) { puts("Division by zero."); return 1; }
            value = (long long)a / b; break;
        default: puts("Invalid operator."); return 1;
        }
        if (value < INT_MIN || value > INT_MAX) { puts("Result out of range."); return 1; }
        stack[count++] = (int)value;
    }
    if (count != 1) { puts("Invalid expression."); return 1; }
    printf("Result: %d\n", stack[0]);
    return 0;
}
