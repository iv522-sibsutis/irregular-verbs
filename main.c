#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/time.h>
#include <time.h>

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
} VerbForms;

void ReadWords(char *IFILE, VerbForms *verbs)
{ 
    int i;
    FILE *f;
    if((f = fopen(IFILE, "r")) == NULL)
    {
        perror("fopen");
        exit(1);
    }
    for (i = 0; i < 117; i++)
    {
        fscanf(f, "%s %s %s", verbs[i].first, verbs[i].second, verbs[i].third);
    }
}
