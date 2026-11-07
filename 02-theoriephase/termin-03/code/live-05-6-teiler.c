#include <stdio.h>
#include <stdlib.h>

void teilerAusgeben(int zahl);

int main(void)
{
    int zahl = 0;

    printf("Zahl eingeben: ");
    scanf_s("%d", &zahl);

    teilerAusgeben(zahl);

    system("pause");

    return 0;
}

void teilerAusgeben(int zahl)
{
    printf("Echte Teiler von %d:\n", zahl);
    for (int teiler = 1; teiler <= zahl/2; teiler++) // (1)!
        if (zahl % teiler == 0)
            printf("%d\n", teiler);
}
