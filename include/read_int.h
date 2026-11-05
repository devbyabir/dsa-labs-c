#ifndef READ_INT_H
#define READ_INT_H
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* Consume a complete whitespace-delimited token before checking its range. */
static int read_int(int *value)
{
    char token[64];
    size_t length = 0;
    int c, too_long = 0;
    do { c = getchar(); } while (c != EOF && isspace((unsigned char)c));
    if (c == EOF) return 0;
    do {
        if (length + 1 < sizeof token) token[length++] = (char)c;
        else too_long = 1;
        c = getchar();
    } while (c != EOF && !isspace((unsigned char)c));
    token[length] = '\0';
    if (too_long) return 0;
    char *end;
    errno = 0;
    long number = strtol(token, &end, 10);
    if (errno || end == token || *end || number < INT_MIN || number > INT_MAX) return 0;
    *value = (int)number;
    return 1;
}
#endif
