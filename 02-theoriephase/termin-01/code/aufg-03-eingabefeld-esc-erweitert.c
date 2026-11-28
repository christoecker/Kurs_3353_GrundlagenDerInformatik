#include <stdio.h>

int main(void)
{
    printf("\x1b[2J");

    printf("\x1b[5;10H+----------------+");
    printf("\x1b[6;10H|                |");
    printf("\x1b[7;10H+----------------+");
    printf("\x1b[9;10H+----------------+");
    printf("\x1b[10;10H|                |");
    printf("\x1b[11;10H+----------------+");

    printf("\x1b[6;12H");
    int drehzahl = 0;
    scanf_s("%d", &drehzahl);

    printf("\x1b[10;12H");
    int temperatur = 0;
    scanf_s("%d", &temperatur);

    printf("\x1b[13;10HDrehzahl: %d U/min, Temperatur: %d Grad\n", drehzahl, temperatur);

    return 0;
}
