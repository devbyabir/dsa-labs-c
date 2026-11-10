/* Inject a read failure portably, without depending on OS-specific FILE tricks. */
#include <assert.h>
#include <stdio.h>
#include <string.h>
static const unsigned char *bytes;
static size_t position, length;
static int broken;
static int test_getchar(void)
{
    return position < length ? bytes[position++] : EOF;
}
static int test_ferror(FILE *stream)
{
    (void)stream;
    return broken;
}
#define getchar test_getchar
#define ferror test_ferror
#include "../../include/read_int.h"
#undef getchar
#undef ferror

static void input(const char *text, size_t size, int error)
{
    bytes = (const unsigned char *)text;
    position = 0;
    length = size;
    broken = error;
}
int main(void)
{
    int value = 77;
    input("12\0abc 34", 9, 0);
    assert(!read_int(&value) && value == 77);
    assert(read_int(&value) && value == 34);
    input("12", 2, 1);
    assert(!read_int(&value) && value == 34);
    input("", 0, 1);
    assert(!read_int(&value));
    input("-2147483648", 11, 0);
    assert(read_int(&value) && value == INT_MIN);
    input("2147483647", 10, 0);
    assert(read_int(&value) && value == INT_MAX);
    input("2147483648", 10, 0);
    assert(!read_int(&value));
    input("12x", 3, 0);
    assert(!read_int(&value));
    return 0;
}
