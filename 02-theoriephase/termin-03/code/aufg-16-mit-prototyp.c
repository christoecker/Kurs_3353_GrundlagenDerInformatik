#include <stdio.h>
#include <stdlib.h>

int quadrat(int zahl);

int main(void)
{
    int zahl = 0;

    printf("Zahl eingeben: ");
    scanf_s("%d", &zahl);

    int ergebnis = quadrat(zahl);
    printf("Quadrat: %d\n", ergebnis);

    system("pause");

    return 0;
}

int quadrat(int zahl)
{
    return zahl * zahl;
}
