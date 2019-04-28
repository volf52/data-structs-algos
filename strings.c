#include <stdio.h>
#include <string.h>
#include "string.h"

void patSearch(char *pat, char *txt)
{
    int M, N, i, j;

    M = strlen(pat);
    N = strlen(txt);

    for (i = 0; i <= N - M; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (txt[i + j] != pat[j])
                break;
        }
        if (j == M)
        {
            printf("Pattern found at index %d\n", i);
        }
    }
}

void optimPatSearch(char *pat, char *txt)
{
    int M, N, i, j;

    M = strlen(pat);
    N = strlen(txt);

    i = 0;
    while (i <= N - M)
    {
        for (j = 0; j < M; j++)
        {
            if (txt[i + j] != pat[j])
                break;
        }
        if (j == M)
        {
            printf("Pattern found at index %d\n", i);
            i += M;
        }
        else if (j == 0)
        {
            i++;
        }
        else
        {
            i += j;
        }
    }
}