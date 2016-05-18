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

#define filename "Verbs.txt"

int main()
{
    char mass2[100];
    char mass3[100];
    int k=0;
    VerbForms Verbs[117];
    ReadWords(filename, Verbs);
    int i, j;
//    printf("Проверка всех:\n");
//    for (i = 0; i < 117; i++)
//    {
//        printf("I: %s\tII: %s\tIII: %s\n", Verbs[i].first, Verbs[i].second, Verbs[i].third);
//    }
    time_t t;
    srand((unsigned) time(&t));
    i = 0;
    for (j = 0; j < 10; j++)
    {
        i = getrand(1, 117);
	    printf("\n%d I: %s\t\n", i, Verbs[i-1].first);
        printf("Введите вторую и третью формы\n");
        scanf("%s %s", mass2, mass3);
        if (strcmp(mass2, Verbs[i-1].second) == 0)
	{
            k=k+5;
	    printf("True\t");}
	    else
            {
	        printf("Falls\t");
	    }
	    if (strcmp(mass3, Verbs[i-1].third) == 0)
	    {
	        k=k+5;
          	printf("true\n");
            }
		else {printf("Falls\n");
        }

    }
    printf("Result\t");
    printf("%d %", k);
    return 0;
}

