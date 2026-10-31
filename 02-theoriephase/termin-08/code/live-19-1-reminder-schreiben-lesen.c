#define _CRT_SECURE_NO_WARNINGS // (1)!

#include <stdio.h>
#include <stdlib.h>

#define ZEILENLAENGE 100

int main(void)
{
    FILE *datei = fopen("notizen.txt", "w"); // (2)!
    if (datei == NULL)
    {
        printf("Datei konnte nicht angelegt werden.\n");
        return 1;
    }

    fprintf(datei, "Erste Zeile\n");
    fprintf(datei, "Zweite Zeile\n");
    fclose(datei);

    datei = fopen("notizen.txt", "r"); // (3)!
    if (datei == NULL) // (4)!
    {
        printf("Datei konnte nicht geoeffnet werden.\n");
        return 1;
    }

    char zeile[ZEILENLAENGE];
    while (fgets(zeile, sizeof(zeile), datei) != NULL) // (5)!
        printf("%s", zeile);

    fclose(datei);

    system("pause");

    return 0;
}
