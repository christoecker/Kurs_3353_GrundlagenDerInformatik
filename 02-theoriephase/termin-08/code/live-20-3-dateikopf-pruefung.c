#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATEINAME "messwerte.dat"
#define KENNUNG "MWL"
#define VERSION 1
#define ANZAHL 4
#define MAX_MESSWERTE 100

typedef struct
{
    int nummer;
    float temperatur;
} Messwert;

typedef struct
{
    char kennung[4]; // (1)!
    int version;
    int anzahl;
} Dateikopf;

void messwerteSpeichern(const Messwert messwerte[], int anzahl);
int messwerteLaden(Messwert messwerte[], int maxAnzahl);
int kopfIstGueltig(const Dateikopf *kopf, int maxAnzahl);

int main(void)
{
    Messwert messwerte[ANZAHL] =
    {
        { 1, 21.5f },
        { 2, 22.0f },
        { 3, 23.25f },
        { 4, 22.75f }
    };

    messwerteSpeichern(messwerte, ANZAHL);
    printf("Messwerte gespeichert. Jetzt koennt ihr die Datei im Hex-Editor veraendern.\n");
    system("pause"); // (2)!

    Messwert gelesen[MAX_MESSWERTE];
    int anzahlGelesen = messwerteLaden(gelesen, MAX_MESSWERTE);

    printf("%d Messwerte geladen.\n", anzahlGelesen);
    for (int i = 0; i < anzahlGelesen; i++)
        printf("Nr. %d: %.2f Grad\n", gelesen[i].nummer, gelesen[i].temperatur);

    system("pause");

    return 0;
}

void messwerteSpeichern(const Messwert messwerte[], int anzahl)
{
    FILE *datei = fopen(DATEINAME, "wb");
    if (datei == NULL)
        return;

    Dateikopf kopf = { KENNUNG, VERSION, anzahl }; // (3)!
    fwrite(&kopf, sizeof(Dateikopf), 1, datei);
    fwrite(messwerte, sizeof(Messwert), anzahl, datei);
    fclose(datei);
}

int messwerteLaden(Messwert messwerte[], int maxAnzahl)
{
    FILE *datei = fopen(DATEINAME, "rb");
    if (datei == NULL)
        return 0;

    int anzahl = 0;
    Dateikopf kopf;
    if (fread(&kopf, sizeof(Dateikopf), 1, datei) == 1)
    {
        kopf.kennung[sizeof(kopf.kennung) - 1] = '\0'; // (4)!
        if (kopfIstGueltig(&kopf, maxAnzahl))
        {
            int gelesen = fread(messwerte, sizeof(Messwert), kopf.anzahl, datei);
            if (gelesen == kopf.anzahl) // (5)!
                anzahl = gelesen;
        }
    }

    fclose(datei);
    return anzahl; // (6)!
}

int kopfIstGueltig(const Dateikopf *kopf, int maxAnzahl)
{
    return strcmp(kopf->kennung, KENNUNG) == 0
        && kopf->version == VERSION
        && kopf->anzahl >= 0
        && kopf->anzahl <= maxAnzahl;
}
