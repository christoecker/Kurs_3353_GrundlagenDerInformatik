#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SCHRITTWEITE 0.0001

double ableitung(double (*f)(double), double x); // (1)!
double polynom(double x); // (2)!

int main(void)
{
    double x = 1.0;

    printf("Ableitung cos an x=1:     %f (analytisch: %f)\n", ableitung(cos, x), -sin(x)); // (3)!
    printf("Ableitung sin an x=1:     %f (analytisch: %f)\n", ableitung(sin, x), cos(x));
    printf("Ableitung polynom an x=1: %f (analytisch: %f)\n", ableitung(polynom, x), 3 * x * x - 2); // (4)!

    system("pause");

    return 0;
}

double ableitung(double (*f)(double), double x)
{
    return (f(x + SCHRITTWEITE) - f(x - SCHRITTWEITE)) / (2 * SCHRITTWEITE); // (5)!
}

double polynom(double x)
{
    return x * x * x - 2 * x + 1; // (6)!
}
