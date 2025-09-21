#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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

typedef struct Datum {
    int ev, ho, nap;
} Datum;
 
typedef struct Versenyzo {
    char nev[31];
    Datum szuletes;
    int helyezes;
} Versenyzo;
 
void datum_kiir(Datum d){
    if(d.ho < 10 && d.nap < 10){
        printf("%d.0%d.0%d\n",d.ev,d.ho,d.nap);
    }
    else if(d.nap < 10){
        printf("%d.%d.0%d\n",d.ev,d.ho,d.nap);
    }
    else if(d.ho < 10){
        printf("%d.0%d.%d\n",d.ev,d.ho,d.nap);
    }
};
 
void versenyzo_kiir(Versenyzo v){
    printf("Nev: %s, szuletesi datum: %d.%d.%d, helyezes: %d\n", v.nev, v.szuletes.ev,v.szuletes.ho,v.szuletes.nap, v.helyezes);
};

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
        printf("\na: %.4lf, a^3: %.4lf, |a|: %.4lf, sin(a): %.4lf\n", index, kob(index), myAbs(index), mySin(index));
        index += 0.1;
    }

    // Exercise 3.
    // printf("Irj be egy szot: ");
    // char c;
    // while (scanf("%c", &c) != EOF)
    // {
    //     if (isVowel(c))
    //         if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
    //             printf("%cv%c", c,c+32);
    //         }
    //         else{
    //             printf("%cv%c", c,c);
    //         }
    //     else
    //         printf("%c", c);
    // }

    //Exercise 4.
    typedef struct Point{
        double x,y;
    }Point;

    double x2,y2;
    printf("Give me an x and y coordinate: ");
    scanf("%lf %lf",&x2,&y2);
    Point points[2] = {
        {2.2, 1.6},
        {x2,y2}
    };
    Point point = {
        (points[0].x + points[1].x)/2, 
        (points[0].y + points[1].y)/2
    };

    printf("Middle of the two coordinates: (x = %lf; y = %lf)\n", point.x,point.y);

    //Exercise 5.
    Versenyzo versenyzok[5] = {
        { "Am Erika", {1984, 5, 6}, 1 },
        { "Break Elek", {1982, 9, 30}, 3 },
        { "Dil Emma", {1988, 8, 25}, 2 },
        { "Kasza Blanka", {1979, 6, 10}, 5 },
        { "Reset Elek", {1992, 4, 5}, 4 },
    };
 
    /* 0-s versenyző neve - printf %s */
    printf("%s\n",versenyzok[0].nev);
    /* 2-es versenyző helyezése */
    printf("%d\n",versenyzok[2].helyezes);
    /* 4-es versenyző születési dátumát (írd meg a datum_kiir függvényt!) */
    datum_kiir(versenyzok[4].szuletes);
    /* 1-es versenyző nevének kezdőbetűjét (ne feledd, a sztring karaktertömb) */
    printf("%c\n", versenyzok[1].nev[0]);
    /* az 1-es versenyző dobogós-e? igen/nem, akár ?: operátorral, de egy printf-fel */
    char helyezes[] = "asd";
    versenyzok[1].helyezes <= 3 ? printf("Igen\n") : printf("Nem\n");
    /* az 4-es versenyző gyorsabb-e, mint a 3-as versenyző? */
    versenyzok[4].helyezes < versenyzok[3].helyezes ? printf("Igen\n") : printf("Nem\n");
    /* az 1-es versenyző ugyanabban az évben született-e, mint a 2-es? */
    versenyzok[1].szuletes.ev == versenyzok[2].szuletes.ev ? printf("Igen\n") : printf("Nem\n");
    /* egészítsd ki a versenyzo_kiir() függvényt,
     /* aztán írd ki az 1-es versenyző összes adatát */
     versenyzo_kiir(versenyzok[1]);
    /* végül listázd ki az összes versenyzőt sorszámozva, összes adatukkal. */
    for (int i = 0; i < 5; i++)
    {
        versenyzo_kiir(versenyzok[i]);
    }
    

    return 0;
}