#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int zahl = 0;
    int ziffer = 0;
    int quersumme = 0;
    int stellen = 0; // (1)!

    printf("Zahl eingeben: ");
    scanf_s("%d", &zahl);

    do
    {
        ziffer = zahl % 10;
        quersumme = quersumme + ziffer;
        stellen++; // (2)!
        zahl = zahl / 10;
    } while (zahl != 0);

    printf("Quersumme: %d\n", quersumme);
    printf("Stellenanzahl: %d\n", stellen); // (3)!

    system("pause");

    return 0;
}
