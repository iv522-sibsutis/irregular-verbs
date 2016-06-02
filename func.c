#define filename "Verbs.txt"

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/time.h>
#include <time.h>
#include "func.h"

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

typedef struct
{
    char first[200];
    char second[200];
    char third[200];
}   VerbForms;

void ReadWords(char *IFILE, VerbForms *verbs)
{
    int i;
    FILE *f;
    if ((f = fopen(IFILE, "r")) == NULL)
    {
        perror("fopen");
        exit(1);
    }
    for (i = 0; i < 117; i++)
    {
        fscanf(f, "%s %s %s", verbs[i].first, verbs[i].second, verbs[i].third);
    }
}

int check()
{
    time_t t;
    srand((unsigned)time(&t));

    int i, j, q, k;
    printf("Выберите уровень сложности: easy-1\t medium-2\t hard-3\t, введите цифру\n");
    scanf("%d", &q);

    char mass2[100];
    char mass3[100];
    VerbForms Verbs[117];

    ReadWords(filename, Verbs);

    if (q == 1)
    {
        for (j = 0; j < 10; j++)
        {
            i = getrand(1, 35);
            printf("\n%d I: %s\t\n", j + 1, Verbs[i - 1].first);
            printf("Введите вторую и третью формы\n");
            scanf("%s %s", mass2, mass3);
            if (strcmp(mass2, Verbs[i - 1].second) == 0)
            {
                k = k + 5;
                printf("True\t");
            }
            else
            {
                printf("Falls\t");
            }
            if (strcmp(mass3, Verbs[i - 1].third) == 0)
            {
                k = k + 5;
                printf("true\n");
            }
            else
            {
                printf("Falls\n");
            }
        }
    }
    if (q == 2)
    {
        for (j = 0; j < 10; j++)
        {
            i = getrand(1, 85);
            printf("\n%d I: %s\t\n", j + 1, Verbs[i - 1].first);
            printf("Введите вторую и третью формы\n");
            scanf("%s %s", mass2, mass3);
            if (strcmp(mass2, Verbs[i - 1].second) == 0)
            {
                k = k + 5;
                printf("True\t");
            }
            else
            {
                printf("Falls\t");
            }
            if (strcmp(mass3, Verbs[i - 1].third) == 0)
            {
                k = k + 5;
                printf("true\n");
            }
            else
            {
                printf("Falls\n");
            }
        }
    }
    if (q == 3)
    {
        for (j = 0; j < 10; j++)
        {
            i = getrand(1, 117);
            printf("\n%d I: %s\t\n", j + 1, Verbs[i - 1].first);
            printf("Введите вторую и третью формы\n");
            scanf("%s %s", mass2, mass3);
            if (strcmp(mass2, Verbs[i - 1].second) == 0)
            {
                k = k + 5;
                printf("True\t");
            }
            else
            {
                printf("Falls\t");
            }
            if (strcmp(mass3, Verbs[i - 1].third) == 0)
            {
                k = k + 5;
                printf("true\n");
            }
            else
            {
                printf("Falls\n");
            }
        }
    }
    return k;
}
