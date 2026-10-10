#define _USE_MATH_DEFINES // (1)!

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double radius = 2.5;
    double umfang = 2 * M_PI * radius;

    printf("Umfang: %.2f\n", umfang);

    system("pause");

    return 0;
}
