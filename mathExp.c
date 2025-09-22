#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES

int myFactorial(int fact)
{
    int result = 1;
    for (int i = 1; i <= fact; i++)
    {
        result *= i;
    }
    return result;
}

double mypow(double base, int exp)
{
    double result = 1.0;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}

double kob(double base)
{
    double result = 1.0;
    for (int i = 0; i < 3; i++)
    {
        result *= base;
    }
    return result;
}
//! My own sin calculator function, it calculates by the taylor series formula
double mySin(double rad)
{
    int counter = 0;
    double result = rad;
    for (int i = 3; i < 13; i += 2)
    {
        counter++;
        double term = (mypow(rad, i) / myFactorial(i));
        if (counter % 2 != 0)
        {
            result -= term;
        }
        else if (counter % 2 == 0)
        {
            result += term;
        }
    }
    return result;
}

double myAbs(double base)
{
    double result = base;
    if (base < 0)
    {
        result *= -1;
    }
    return result;
}

int main()
{
    // Exercise 2.
    double index = -1;
    while (index <= 1)
    {
        printf("\na: %.4lf, a^3: %.4lf, |a|: %.4lf, sin(a): %.4lf\n", index, kob(index), myAbs(index), mySin(index));
        index += 0.1;
    }
    return 0;
}