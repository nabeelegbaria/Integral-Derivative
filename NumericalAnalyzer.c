#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <memory.h>
#include "infi.h"
#include "infi.c"

/**
 * This is the first given function;
 * @param x
 * @return result of function.
 */
double func1(double x)
{
    return pow(x, 2) / 4;
}

/**
 * This is the second given function;
 * @param x
 * @return result of function.
 */
double func2(double x)
{
    if (x <= 0)
    {
        fprintf(stderr, "Invalid input\n");
        exit(EXIT_FAILURE);
    }
    double result = (-pow(x, 3) + 3 * pow(x, 2) + x - (4 * sqrt(x))) / (2 * x * sqrt(x));
    return result;
}

/**
 * This is the third given function;
 * @param x
 * @return result of function.
 */
double func3(double x)
{
    return pow(sin(x), 2) - pow(cos(x), 2);
}

/**
 * This is the four'th given function;
 * @param x
 * @return result of function.
 */
double func4(double x)
{
    return sin(x) / (1 + cos(2 * x));
}

/**
 * This is the five given function;
 * @param x
 * @return result of function.
 */
double func5(double x)
{
    return exp(x);
}

/**
 * This is the six given function;
 * @param x
 * @return result of function.
 */
double func6(double x)
{
    return sinh(2 * x) / (exp(1) * pow(x, 2));
}

/**
 * This function receives the number of the function were chosen by the user
 * @param numfunc
 * @return the appropriate function .
 */
RealFunction getfunc(int numfunc)
{
    if (numfunc == 1)
    {
        RealFunction f1 = func1;
        return f1;
    }
    if (numfunc == 2)
    {
        RealFunction f2 = func2;
        return f2;
    }
    if (numfunc == 3)
    {
        RealFunction f3 = func3;
        return f3;
    }
    if (numfunc == 4)
    {
        RealFunction f4 = func4;
        return f4;
    }
    if (numfunc == 5)
    {
        RealFunction f5 = func5;
        return f5;
    }
    if (numfunc == 6)
    {
        RealFunction f6 = func6;
        return f6;
    }
    return NULL;
}

/**
 * This function receives the input from the user and checks if it legal or not .
 * @param argv
 * @return 1 if it is illegal , 0 otherwise.
 */
int checkarguments(char *argv[])
{
    for (int i = 1; i < 7; ++i)
    {
        if (i == 1 || i == 4)
        {
            size_t len = strlen(argv[i]);
            for (int j = 0; j < (int) len; ++j)
            {
                if (isdigit(argv[i][j]) == 0)
                {
                    fprintf(stderr, "Invalid input\n");
                    return EXIT_FAILURE;
                }

            }
            if (i == 1)
            {
                int numfunc = (int) strtod(argv[1], NULL);
                if (numfunc < 0 || numfunc > 6)
                {
                    fprintf(stderr, "Invalid input\n");
                    return EXIT_FAILURE;
                }
            }
            continue;
        }
        if (i == 2 || i == 3 || i == 5)
        {
            size_t len = strlen(argv[i]);
            for (int j = 0; j < (int) len; ++j)
            {
                if (j == 0 && argv[i][j] == '-')
                {
                    continue;
                }
                if (isdigit(argv[i][j]) == 0 && (argv[i][j] != '.'))
                {
                    fprintf(stderr, "Invalid input\n");
                    return EXIT_FAILURE;
                }

            }
            continue;
        }
        size_t len = strlen(argv[i]);
        for (int j = 0; j < (int) len; ++j)
        {
            if (isdigit(argv[i][j]) == 0 && argv[i][j] != '.')
            {
                fprintf(stderr, "Invalid input\n");
                return EXIT_FAILURE;
            }

        }
    }
    return EXIT_SUCCESS;
}

/**
 * main function which runs the program .
 * @param argc
 * @param argv
 * @return 1 if the input is wrong , 0 otherwise .
 */
int main(int argc, char *argv[])
{
    if (argc != 7)
    {
        fprintf(stderr, "Usage: NumericalAnalyzer <function number> <a> <b> <N> <x0> <h>\n");
        exit(EXIT_FAILURE);
    }
    if (checkarguments(argv) == EXIT_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    int numfunc = *argv[1] - '0';
    RealFunction func = getfunc(numfunc);
    double beggining = strtod(argv[2], NULL);
    double end = strtod(argv[3], NULL);
    unsigned int n = (unsigned int) strtol(argv[4], NULL, 10);
    integration(func, beggining, end, n);
    double point = strtod(argv[5], NULL);
    double h = strtod(argv[6], NULL);
    derivative(func, point, h);
    return EXIT_SUCCESS;
}