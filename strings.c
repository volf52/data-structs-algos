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

void robinKarp(char *pat, char *txt, int q)
{
    int M, N, i, j, p, t, h, d = 256; // d is number of alphabets

    M = strlen(pat);
    N = strlen(txt);
    p = 0; // hash for pattern
    t = 0; // hash for text
    h = 1;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // h is now pow(d, M-1) % q

    // Calculate hashes for pattern and first txt slide
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++)
    {
        // Check only if hashes of pattern and current txt slide match
        if (p == t)
        {
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q; // remove leading digit and add trailing digit to hash func
            if (t < 0)
            {
                t = t + q;
            }
        }
    }
}