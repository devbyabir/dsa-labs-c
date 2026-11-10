/* DSA Lab 10: substring search. Reviewed in 2026. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Index(char *S, char *T, int pos)
{
    if (pos < 1 || (size_t)(pos - 1) > strlen(S))
        return 0;
    int i = pos - 1;
    int j = 0;

    while (S[i] != '\0' && T[j] != '\0')
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }

    if (T[j] == '\0')
    {
        return i - j + 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    char sntnc[50], word[50];
    int pos;

    puts("\nEnter a sentence: ");
    if (!fgets(sntnc, sizeof(sntnc), stdin))
    {
        fputs("Invalid input.\n", stderr);
        return 1;
    }
    if ((!strchr(sntnc, '\n') && !feof(stdin)) || ferror(stdin))
    {
        fputs("Invalid input.\n", stderr);
        return 1;
    }
    sntnc[strcspn(sntnc, "\n")] = '\0';

    puts("\nEnter a word: ");
    if (!fgets(word, sizeof(word), stdin))
    {
        fputs("Invalid input.\n", stderr);
        return 1;
    }
    if ((!strchr(word, '\n') && !feof(stdin)) || ferror(stdin))
    {
        fputs("Invalid input.\n", stderr);
        return 1;
    }
    word[strcspn(word, "\n")] = '\0';

    pos = Index(sntnc, word, 1);

    if (pos == 0)
    {
        printf("The substring was not found in the sentence.\n");
    }
    else
    {
        printf("The substring starts at position : %d\n", pos);
    }

    return 0;
}
