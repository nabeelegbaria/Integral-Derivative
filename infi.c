#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "infi.h"

/**
 * This function receives the function and its upper and lower bound , in addition a number n
 * which represents the size of the distribution .
 * @param func
 * @param beginning
 * @param end
 * @param n
 * @return the value of the integral .
 */
double integration(RealFunction func, double beginning, double end, unsigned int n)
{
    assert(end > beginning);
    assert(n > 0);
    double distribution[n + 1];
    distribution[0] = beginning;
    distribution[n] = end;
    double delta = ((end - beginning) / n);
    for (unsigned int i = 1; i < n; ++i)
    {
        distribution[i] = beginning + (i * delta);
    }
    double midpoint[n];
    for (unsigned int j = 0; j < n; ++j)
    {
        double difference = (distribution[j + 1] - distribution[j]) / 2;
        midpoint[j] = distribution[j] + difference;
    }
    double sum = 0;
    for (unsigned int k = 0; k < n; ++k)
    {
        sum += func(midpoint[k]);
    }
    printf("Integral: %0.5f\n", sum * delta);
    return sum * delta;
}

/**
 * This function receives a function , point , and h value .
 * @param func
 * @param point
 * @param h
 * @return the derivative value.
 */
double derivative(RealFunction func, double point, double h)
{
    assert(h > 0);
    double variable1 = func(point + h);
    double variable2 = func(point - h);
    double finalresult = (variable1 - variable2) / (2 * h);
    printf("Derivative: %0.5f", finalresult);
    return finalresult;
}

