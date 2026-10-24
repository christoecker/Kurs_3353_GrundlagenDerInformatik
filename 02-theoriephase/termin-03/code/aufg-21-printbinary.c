#include <stdio.h>
#include <stdlib.h>

void printBinary(int zahl);

int main(void)
{
    int zahl = 0;

    printf("Dezimalzahl eingeben (> 0): ");
    scanf_s("%d", &zahl);

    printBinary(zahl);
    printf("\n");

    system("pause");

    return 0;
}

void printBinary(int zahl)
{
    if (zahl == 0)
        return;

    printBinary(zahl / 2);
    printf("%d", zahl % 2);
}
