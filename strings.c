#include <stdio.h>
#include <string.h>
#include "strings.h"

#define TOTAL_CHARS 256

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
    int M, N, i, j, p, t, h; // d is number of alphabets

    M = strlen(pat);
    N = strlen(txt);
    p = 0; // hash for pattern
    t = 0; // hash for text
    h = 1;

    for (i = 0; i < M - 1; i++)
        h = (h * TOTAL_CHARS) % q;

    // h is now pow(d, M-1) % q

    // Calculate hashes for pattern and first txt slide
    for (i = 0; i < M; i++)
    {
        p = (TOTAL_CHARS * p + pat[i]) % q;
        t = (TOTAL_CHARS * t + txt[i]) % q;
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
            t = (TOTAL_CHARS * (t - txt[i] * h) + txt[i + M]) % q; // remove leading digit and add trailing digit to hash func
            if (t < 0)
            {
                t = t + q;
            }
        }
    }
}

void bayerMoore(char *pat, char *txt)
{
    int M, N, s, j, badchar[TOTAL_CHARS];

    M = strlen(pat);
    N = strlen(txt);

    badCharHeuristic(pat, M, badchar);

    s = 0; // shift of pattern relative to text

    while (s <= (N - M))
    {
        j = M - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            printf("Pattern occurs at index %d\n", s);

            // Increase shift index such that the next character in the text aligns with it's last occurence in the pattern
            s += (s + M < N) ? M - badchar[txt[s + M]] : 1;
        }
        else
        {
            s += max(1, j - badchar[txt[s + j]]);
        }
    }
}

void badCharHeuristic(char *str, int size, int badchar[TOTAL_CHARS])
{
    int i;

    for (i = 0; i < TOTAL_CHARS; i++)
    {
        badchar[i] = -1;
    }

    for (i = 0; i < size; i++)
    {
        badchar[(int)str[i]] = i;
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}