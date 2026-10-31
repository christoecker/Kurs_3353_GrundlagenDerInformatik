/*
 * Ersatzteilverwaltung MechaTech GmbH (mit CSV-Persistenz)
 * Kurs:    Grundlagen der Informatik (Kurs 3353)
 * Termin:  8, Block 19 (Dateien lesen und schreiben)
 *
 * Aufgabe 47: Erweitert die Vorgabe aus Termin 7 so, dass Teile in einer
 * CSV-Datei (ersatzteile.csv) dauerhaft gespeichert werden und einen
 * Programmneustart ueberleben.
 */

#include <stdio.h>
#include <stdlib.h>
#include "teileverwaltung.h"

void menueAnzeigen(void);
void menueAusfuehren(Teil lager[], int *anzahlTeile);
void teilEintragenUeberMenue(Teil lager[], int *anzahlTeile);

int main(void)
{
    Teil lager[MAX_TEILE];
    int anzahlTeile = 0;

    teileAusDateiLaden(lager, &anzahlTeile); // (1)!

    menueAusfuehren(lager, &anzahlTeile);

    return 0;
}

void menueAnzeigen(void)
{
    printf("\n=== Ersatzteilverwaltung MechaTech GmbH ===\n");
    printf("1 - Teil eintragen\n");
    printf("2 - Alle Teile anzeigen\n");
    printf("0 - Beenden\n");
    printf("Auswahl: ");
}

void menueAusfuehren(Teil lager[], int *anzahlTeile)
{
    int auswahl = 0;

    menueAnzeigen();
    scanf_s("%d", &auswahl);

    while (auswahl != 0)
    {
        switch (auswahl)
        {
            case 1:
                teilEintragenUeberMenue(lager, anzahlTeile);
                break;
            case 2:
                alleTeileAnzeigen(lager, *anzahlTeile);
                break;
            default:
                printf("Unbekannte Auswahl.\n");
                break;
        }

        menueAnzeigen();
        scanf_s("%d", &auswahl);
    }

    printf("Programm beendet.\n");
    system("pause");
}

void teilEintragenUeberMenue(Teil lager[], int *anzahlTeile)
{
    Teil neuesTeil;

    printf("Teilenummer: ");
    scanf_s("%d", &neuesTeil.teilenummer);

    printf("Bezeichnung (ein Wort, ohne Leerzeichen): ");
    scanf_s("%s", neuesTeil.bezeichnung, (unsigned)sizeof(neuesTeil.bezeichnung));

    printf("Bestand: ");
    scanf_s("%d", &neuesTeil.bestand);

    if (teilEinfuegen(lager, anzahlTeile, neuesTeil))
    {
        teilAnDateiAnhaengen(&neuesTeil); // (2)!
        printf("Teil %d wurde aufgenommen.\n", neuesTeil.teilenummer);
    }
}
