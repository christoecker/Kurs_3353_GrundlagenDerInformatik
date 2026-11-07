#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define DATEINAME "messwerte.dat"
#define ANZAHL 4

typedef struct
{
    int nummer;
    float temperatur;
} Messwert;

int main(void)
{
    Messwert messwerte[ANZAHL] =
    {
        { 1, 21.5f },
        { 2, 22.0f },
        { 3, 23.25f },
        { 4, 22.75f }
    };

    FILE *datei = fopen(DATEINAME, "wb");
    fwrite(messwerte, sizeof(Messwert), ANZAHL, datei);
    fclose(datei);

    Messwert korrigiert = { 3, 23.5f };
    datei = fopen(DATEINAME, "r+b"); // (1)!
    fseek(datei, 2 * sizeof(Messwert), SEEK_SET); // (2)!
    fwrite(&korrigiert, sizeof(Messwert), 1, datei); // (3)!
    fclose(datei);

    Messwert gelesen[ANZAHL];
    datei = fopen(DATEINAME, "rb");
    int anzahlGelesen = fread(gelesen, sizeof(Messwert), ANZAHL, datei);
    fclose(datei);

    for (int i = 0; i < anzahlGelesen; i++)
        printf("Nr. %d: %.2f Grad\n", gelesen[i].nummer, gelesen[i].temperatur);

    system("pause");

    return 0;
}
