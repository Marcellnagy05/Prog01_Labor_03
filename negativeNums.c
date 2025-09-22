#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

    return 0;
}