#include <stdio.h>

int retBase(int starter)
{
    int result = starter;
    result = 1;
    return result;
}

int plusOne(int starter)
{
    int result = starter;
    result = starter + 1;
    return result;
}

int swSign(int starter)
{
    int result = starter;
    result = starter * -1;
    return result;
}

int multByTwo(int starter)
{
    int result = starter;
    result = starter * 2;
    return result;
}

int main()
{
    int starter = 1;
    int choice = 0;
    do
    {
        printf("0. Alapertek visszaallitasa (a = 1)\n"
               "1. Hozzaad 1-et\n"
               "2. Megforditja az elojelet\n"
               "3. Szorozza 2-vel\n"
               "9. Kilepes\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            starter = retBase(starter);
            printf("New value: %d\n", starter);
            break;
        case 1:
            starter = plusOne(starter);
            printf("New value: %d\n", starter);
            break;

        case 2:
            starter = swSign(starter);
            printf("New value: %d\n", starter);
            break;
        case 3:
            starter = multByTwo(starter);
            printf("New value: %d\n", starter);
            break;
        }
    } while (choice != 9);

    return 0;
}