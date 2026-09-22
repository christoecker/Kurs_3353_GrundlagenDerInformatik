#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int zahl = 0;
    int rest = 0;

    printf("Dezimalzahl eingeben: ");
    scanf_s("%d", &zahl);

    printf("Dualziffern (von hinten nach vorne gelesen): ");
    do
    {
        rest = zahl % 2;
        printf("%d", rest);
        zahl = zahl / 2;
    } while (zahl != 0);
    printf("\n");

    system("pause");

    return 0;
}
