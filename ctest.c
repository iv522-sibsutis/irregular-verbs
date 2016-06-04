#define CTEST_MAIN

#include <stdio.h>
#include <ctype.h>
#include "ctest.h"
#include "func.c"

CTEST(solution_suite, easy) 
{

    char mass2;
    char mass3;
    int i = 0;
    
    VerbForms Verbs[117];
    ReadWords(filename, Verbs);

    float solution = check(mass2, mass3, i, Verbs);

    const float expected_solution = 50;

    ASSERT_DBL_NEAR(expected_solution, solution);
}

int main (int argc, const char** argv)
{
	return ctest_main(argc, argv);
}
