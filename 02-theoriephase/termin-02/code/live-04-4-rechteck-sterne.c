#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int zeilen = 0;
    int spalten = 0;

    printf("Anzahl Zeilen: ");
    scanf_s("%d", &zeilen);
    printf("Anzahl Spalten: ");
    scanf_s("%d", &spalten);

    for (int zeile = 1; zeile <= zeilen; zeile++)
    {
        for (int spalte = 1; spalte <= spalten; spalte++)
            printf("*");
        printf("\n");
    }

    system("pause");

    return 0;
}
