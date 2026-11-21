#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATEINAME "messwerte.dat"
#define TEMP_DATEINAME "messwerte.tmp"
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
    char kennung[4];
    int version;
    int anzahl;
} Dateikopf;

typedef enum
{
    FEHLER_KEIN,
    FEHLER_OEFFNEN,
    FEHLER_SCHREIBEN,
    FEHLER_LESEN,
    FEHLER_KENNUNG,
    FEHLER_ANZAHL_UNGUELTIG
} Fehlercode;

Fehlercode messwerteSpeichern(const Messwert messwerte[], int anzahl);
Fehlercode messwerteLaden(Messwert messwerte[], int maxAnzahl, int *anzahl);
Fehlercode kopfPruefen(const Dateikopf *kopf, int maxAnzahl);
void fehlerAusgeben(Fehlercode fehler);

int main(void)
{
    Messwert messwerte[ANZAHL] =
    {
        { 1, 21.5f },
        { 2, 22.0f },
        { 3, 23.25f },
        { 4, 22.75f }
    };

    Fehlercode fehler = messwerteSpeichern(messwerte, ANZAHL);
    if (fehler != FEHLER_KEIN)
    {
        fehlerAusgeben(fehler);
        system("pause");
        return 1;
    }
    printf("Messwerte gespeichert. Jetzt koennt ihr die Datei im Hex-Editor veraendern.\n");
    system("pause");

    Messwert gelesen[MAX_MESSWERTE];
    int anzahlGelesen = 0;
    fehler = messwerteLaden(gelesen, MAX_MESSWERTE, &anzahlGelesen);
    if (fehler != FEHLER_KEIN)
    {
        fehlerAusgeben(fehler);
        system("pause");
        return 1;
    }

    printf("%d Messwerte geladen.\n", anzahlGelesen);
    for (int i = 0; i < anzahlGelesen; i++)
        printf("Nr. %d: %.2f Grad\n", gelesen[i].nummer, gelesen[i].temperatur);

    system("pause");

    return 0;
}

Fehlercode messwerteSpeichern(const Messwert messwerte[], int anzahl)
{
    FILE *datei = fopen(TEMP_DATEINAME, "wb"); // (1)!
    if (datei == NULL)
        return FEHLER_OEFFNEN;

    Dateikopf kopf = { KENNUNG, VERSION, anzahl };
    int kopfGeschrieben = fwrite(&kopf, sizeof(Dateikopf), 1, datei);
    int werteGeschrieben = fwrite(messwerte, sizeof(Messwert), anzahl, datei);
    int geschlossen = fclose(datei);

    if (kopfGeschrieben != 1 || werteGeschrieben != anzahl || geschlossen != 0)
    {
        remove(TEMP_DATEINAME); // (2)!
        return FEHLER_SCHREIBEN;
    }

    remove(DATEINAME); // (3)!
    if (rename(TEMP_DATEINAME, DATEINAME) != 0) // (4)!
        return FEHLER_SCHREIBEN;

    return FEHLER_KEIN;
}

Fehlercode messwerteLaden(Messwert messwerte[], int maxAnzahl, int *anzahl)
{
    FILE *datei = fopen(DATEINAME, "rb");
    if (datei == NULL)
        return FEHLER_OEFFNEN;

    Fehlercode fehler = FEHLER_KEIN;
    Dateikopf kopf;
    if (fread(&kopf, sizeof(Dateikopf), 1, datei) != 1)
        fehler = FEHLER_LESEN;
    else
    {
        kopf.kennung[sizeof(kopf.kennung) - 1] = '\0';
        fehler = kopfPruefen(&kopf, maxAnzahl);
    }

    if (fehler == FEHLER_KEIN)
    {
        *anzahl = fread(messwerte, sizeof(Messwert), kopf.anzahl, datei);
        if (*anzahl != kopf.anzahl)
            fehler = FEHLER_LESEN;
    }

    fclose(datei);
    return fehler;
}

Fehlercode kopfPruefen(const Dateikopf *kopf, int maxAnzahl)
{
    if (strcmp(kopf->kennung, KENNUNG) != 0 || kopf->version != VERSION)
        return FEHLER_KENNUNG;

    if (kopf->anzahl < 0 || kopf->anzahl > maxAnzahl)
        return FEHLER_ANZAHL_UNGUELTIG;

    return FEHLER_KEIN;
}

void fehlerAusgeben(Fehlercode fehler)
{
    switch (fehler)
    {
        case FEHLER_OEFFNEN:
            printf("Fehler: Datei %s konnte nicht geoeffnet werden.\n", DATEINAME);
            break;
        case FEHLER_SCHREIBEN:
            printf("Fehler: Beim Schreiben in die Datei ist etwas schiefgegangen.\n");
            break;
        case FEHLER_LESEN:
            printf("Fehler: Die Datei ist zu kurz (beschaedigt?).\n");
            break;
        case FEHLER_KENNUNG:
            printf("Fehler: Das ist keine Messwert-Datei (Kennung oder Version falsch).\n");
            break;
        case FEHLER_ANZAHL_UNGUELTIG:
            printf("Fehler: Die Anzahl der Messwerte im Dateikopf ist unplausibel.\n");
            break;
        default:
            printf("Unbekannter Fehler.\n");
            break;
    }
}
