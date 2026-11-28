#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int groesse = 0;

    printf("Groesse der Raute (Zeilen bis zur breitesten Stelle): ");
    scanf_s("%d", &groesse);

    // Obere Haelfte: von der schmalsten bis zur breitesten Zeile
    for (int zeile = 1; zeile <= groesse; zeile++)
    {
        for (int leerzeichen = 1; leerzeichen <= groesse - zeile; leerzeichen++)
            printf(" ");
        for (int stern = 1; stern <= 2 * zeile - 1; stern++)
            printf("*");
        printf("\n");
    }

    // Untere Haelfte: von der breitesten Zeile rueckwaerts zur schmalsten
    for (int zeile = groesse - 1; zeile >= 1; zeile--)
    {
        for (int leerzeichen = 1; leerzeichen <= groesse - zeile; leerzeichen++)
            printf(" ");
        for (int stern = 1; stern <= 2 * zeile - 1; stern++)
            printf("*");
        printf("\n");
    }

    system("pause");

    return 0;
}
