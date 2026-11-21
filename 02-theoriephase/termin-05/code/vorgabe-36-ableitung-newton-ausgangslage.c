#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SCHRITTWEITE 0.0001

double ableitung(double (*f)(double), double x);
double polynom(double x);

int main(void)
{
    double x = 1.0;

    printf("Ableitung cos an x=1:     %f\n", ableitung(cos, x));
    printf("Ableitung sin an x=1:     %f\n", ableitung(sin, x));
    printf("Ableitung polynom an x=1: %f\n", ableitung(polynom, x));

    system("pause");

    return 0;
}

double ableitung(double (*f)(double), double x)
{
    return (f(x + SCHRITTWEITE) - f(x - SCHRITTWEITE)) / (2 * SCHRITTWEITE);
}

double polynom(double x)
{
    return x * x * x - 2 * x + 1;
}
