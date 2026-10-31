#include <stdio.h>

int main(void)
{
    int drehzahl = 0;
    double temperatur = 0.0;

    printf("Motordrehzahl (U/min): ");
    scanf_s("%d", &drehzahl);

    printf("Temperatur (Grad Celsius): ");
    scanf_s("%lf", &temperatur); // (1)!

    printf("Drehzahl: %d U/min\n", drehzahl);
    printf("Temperatur: %.1f Grad Celsius\n", temperatur); // (2)!

    return 0;
}
