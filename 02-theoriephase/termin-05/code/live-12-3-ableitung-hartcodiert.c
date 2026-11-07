#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SCHRITTWEITE 0.0001

double ableitung(double x); // (1)!

int main(void)
{
    double x = 1.0;

    printf("Numerisch:  %f\n", ableitung(x)); // (2)!
    printf("Analytisch: %f\n", -sin(x)); // (3)!

    system("pause");

    return 0;
}

double ableitung(double x)
{
    return (cos(x + SCHRITTWEITE) - cos(x - SCHRITTWEITE)) / (2 * SCHRITTWEITE); // (4)!
}
