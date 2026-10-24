#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define DATEINAME "messwerte.dat"
#define ANZAHL 4

typedef struct
{
    int nummer;
    float temperatur;
} Messwert; // (1)!

int main(void)
{
    Messwert messwerte[ANZAHL] =
    {
        { 1, 21.5f },
        { 2, 22.0f },
        { 3, 23.25f },
        { 4, 22.75f }
    };

    FILE *datei = fopen(DATEINAME, "wb"); // (2)!
    fwrite(messwerte, sizeof(Messwert), ANZAHL, datei); // (3)!
    fclose(datei);

    Messwert gelesen[ANZAHL];
    datei = fopen(DATEINAME, "rb");
    int anzahlGelesen = fread(gelesen, sizeof(Messwert), ANZAHL, datei); // (4)!

    fseek(datei, 0, SEEK_END);
    long groesse = ftell(datei);
    fclose(datei);

    printf("Ein Messwert belegt %zu Byte, die Datei %ld Byte.\n", sizeof(Messwert), groesse);
    for (int i = 0; i < anzahlGelesen; i++)
        printf("Nr. %d: %.2f Grad\n", gelesen[i].nummer, gelesen[i].temperatur);

    system("pause");

    return 0;
}
