#include "../include/read_int.h"
/* DSA Lab 1: prefix averages. Reviewed in 2026. */
#include <stdio.h>
#include <stdlib.h>
void prefixAverages2(int X[], int n, double A[])
{
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        s += X[i];
        A[i] = s / (i + 1);
    }
}
int maxSubSum2(int X[], int total)
{
    int maxSum = 0;
    for (int i = 0; i < total; i++)
    {
        int thisSum = 0;
        for (int j = i; j < total; j++)
        {
            thisSum += X[j];
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}
int main(void)
{
    int n, i;
    int X[100];
    printf("Enter The Number of Elements: ");
    if (!read_int(&n) || n < 1 || n > 100) {
        fputs("Invalid input.\n", stderr);
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter The Element : ");
        if (!read_int(&X[i]) || X[i] < -1000000 || X[i] > 1000000) {
            fputs("Invalid input.\n", stderr);
            return 1;
        }
    }
    double A[100];
     prefixAverages2(X, n, A);

    printf("Prefix Averages: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", A[i]);
    }

    int total_elements = n;
    int maxSum = maxSubSum2(X, total_elements);
    printf("\nMaximum Subsequence Sum: %d\n", maxSum);

    return 0;
}
