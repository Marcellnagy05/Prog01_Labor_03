#include <stdio.h>

int isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
        return 1;
    }
    else
    {

        return 0;
    }
}

int main()
{
    // Exercise 3.
    printf("Input a word: ");
    char c;
    while (scanf("%c", &c) != EOF)
    {
        if (isVowel(c))
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            {
                printf("%cv%c", c, c + 32);
            }
            else
            {
                printf("%cv%c", c, c);
            }
        else
            printf("%c", c);
    }
    return 0;
}