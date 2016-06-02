#define CTEST_MAIN

#include <stdio.h>
#include <ctype.h>
#include "ctest.h"
#include "func.c"

CTEST(solution_suite, easy) 
{
    const int solution = check();

    const int expected_solution = 20;

    ASSERT_DBL_NEAR(expected_solution, solution);
}

int main (int argc, const char** argv)
{
	return ctest_main(argc, argv);
}
