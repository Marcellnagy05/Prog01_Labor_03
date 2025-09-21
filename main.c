#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int myFactorial(int fact){
    int result = 1;
    for(int i = 1; i <= fact; i++){
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

double kob(double base){
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
    for(int i = 3; i < 13; i += 2){
        counter++;
        double term = (mypow(rad,i)/myFactorial(i));
        if(counter % 2 != 0){
            result -= term;
        }   
        else if(counter % 2 == 0){
            result += term;
        }
    }
    return result;
}

double myAbs(double base){
    double result = base;
    if(base < 0){
        result *= -1;
    }
    return result;
}

// (180) / (M_PI * deg) =  rad

int main()
{
    // Exercise 1.
    double nums[10] = {2.5, -69, 5.4, -8, -7.7, 6, 2.9, -10, -3, 9.8};
    int *indexes = NULL;
    int indexCount = 0;
    int lengthOfNums = sizeof(nums) / sizeof(nums[0]);
    int *tmpIndexes;
    for (int i = 0; i < lengthOfNums; i++)
    {
        tmpIndexes = realloc(indexes, (indexCount + 1) * sizeof(int));
        if (!tmpIndexes)
        {
            printf("Memory allocation failed");
            free(indexes);
            return 1;
        }
        if (nums[i] < 0)
        {
            indexes = tmpIndexes;
            indexes[indexCount] = i;
            indexCount++;
        }
    }
    printf("There are %d pieces of negative numbers:\n", indexCount);
    printf("The indexes are: ");
    for (int i = 0; i < indexCount; i++)
    {
        printf("%d ", indexes[i]);
    }

    printf("\nThere are %d pieces of numbers:\n", lengthOfNums);
    for (int i = 0; i < lengthOfNums; i++)
    {
        printf(" [%d]=%.1lf ", i, nums[i]);
    }

    printf("\nAnd [%d] of these numbers are negative:\n", indexCount);
    for (int i = 0; i < indexCount; i++)
    {
        printf(" [%d]=%.1lf ", i, nums[indexes[i]]);
    }

    free(indexes);

    // Exercise 2.
    double index = -1;
    while (index <= 1)
    {
        printf("\na: %.4lf, a^3: %.4lf, |a|: %.4lf, sin(a): %.4lf\n", index,kob(index),myAbs(index),mySin(index));
        index += 0.1;
    }
    
    return 0;
}