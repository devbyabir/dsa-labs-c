/* DSA Lab 11: quicksort. Reviewed in 2026. */
#include "../include/read_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void char_swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(char arr[], unsigned int length)
{
    unsigned int i, piv = 0;
    if (length <= 1)
        return;

    for (i = 0; i < length; i++)
    {
        if (arr[i] > arr[length - 1])
            char_swap(&arr[i], &arr[piv++]);
    }
    char_swap(&arr[piv], &arr[length - 1]);
    quicksort(arr, piv);
    piv++;
    quicksort(arr + piv, length - piv);
}

int main(void)
{
    char input[1000];
    printf("Enter a string : ");
    if (!read_line(input, sizeof input))
    {
        fputs("Invalid input.\n", stderr);
        return 1;
    }
    input[strcspn(input, "\n")] = 0;
    unsigned int length = strlen(input);
    quicksort(input, length);
    printf("Characters in descending order: %s\n", input);
    return 0;
}
