#ifndef READ_LINE_H
#define READ_LINE_H

#include <stdio.h>

/* Read one bounded line, rejecting embedded NUL bytes and truncated input. */
static int read_line(char *buffer, size_t capacity)
{
    size_t length = 0;
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\0' || length + 1 >= capacity)
            return 0;
        buffer[length++] = (char)c;
        if (c == '\n')
            break;
    }
    if (ferror(stdin) || length == 0 || (c == EOF && length + 1 == capacity))
        return 0;
    buffer[length] = '\0';
    return 1;
}

#endif
