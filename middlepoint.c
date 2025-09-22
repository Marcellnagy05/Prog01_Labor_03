#include <stdio.h>

int main()
{
    // Exercise 4.
    typedef struct Point
    {
        double x, y;
    } Point;

    double x2, y2;
    printf("Give me an x and y coordinate: ");
    scanf("%lf %lf", &x2, &y2);
    Point points[2] = {
        {2.2, 1.6},
        {x2, y2}};
    Point point = {
        (points[0].x + points[1].x) / 2,
        (points[0].y + points[1].y) / 2};

    printf("Middle of the two coordinates: (x = %lf; y = %lf)\n", point.x, point.y);

    return 0;
}