#include <stdio.h>

int main(void)
{
    double r1 = 0.0;
    double r2 = 0.0;

    printf("Widerstand R1 (Ohm): ");
    scanf_s("%lf", &r1);

    printf("Widerstand R2 (Ohm): ");
    scanf_s("%lf", &r2);

    double rGesamt = r1 + r2;
    printf("Gesamtwiderstand bei Reihenschaltung: %.2f Ohm\n", rGesamt);

    return 0;
}
