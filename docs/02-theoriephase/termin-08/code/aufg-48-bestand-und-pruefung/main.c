/*
 * Ersatzteilverwaltung MechaTech GmbH (Bestand persistieren, Datei pruefen)
 * Kurs:    Grundlagen der Informatik (Kurs 3353)
 * Termin:  8, Block 19 (Dateien lesen und schreiben)
 *
 * Aufgabe 48 (Musterloesung): Baut auf der CSV-Persistenz aus der Uebung
 * auf. Neu: Bestandsaenderungen eines vorhandenen Teils werden ebenfalls
 * dauerhaft gespeichert, und beschaedigte Zeilen beim Einlesen werden
 * erkannt statt das Programm abstuerzen zu lassen oder falsche Daten zu
 * uebernehmen.
 *
 * Das ist eine von mehreren moeglichen Loesungen - eure Umsetzung darf
 * anders aussehen und trotzdem gut sein.
 */

#include <stdio.h>
#include <stdlib.h>
#include "teileverwaltung.h"

void menueAnzeigen(void);
void menueAusfuehren(Teil lager[], int *anzahlTeile);
void teilEintragenUeberMenue(Teil lager[], int *anzahlTeile);
void bestandAendernUeberMenue(Teil lager[], int anzahlTeile);

int main(void)
{
    Teil lager[MAX_TEILE];
    int anzahlTeile = 0;

    teileAusDateiLaden(lager, &anzahlTeile);

    menueAusfuehren(lager, &anzahlTeile);

    return 0;
}

void menueAnzeigen(void)
{
    printf("\n=== Ersatzteilverwaltung MechaTech GmbH ===\n");
    printf("1 - Teil eintragen\n");
    printf("2 - Alle Teile anzeigen\n");
    printf("3 - Bestand aendern\n");
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
            case 3:
                bestandAendernUeberMenue(lager, *anzahlTeile);
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
        teilAnDateiAnhaengen(&neuesTeil);
        printf("Teil %d wurde aufgenommen.\n", neuesTeil.teilenummer);
    }
}

void bestandAendernUeberMenue(Teil lager[], int anzahlTeile)
{
    int teilenummer = 0;
    int aenderung = 0;

    printf("Teilenummer: ");
    scanf_s("%d", &teilenummer);

    Teil *gefunden = teilSuchen(lager, anzahlTeile, teilenummer);
    if (gefunden == NULL)
    {
        printf("Teil mit Nummer %d nicht gefunden.\n", teilenummer);
        return;
    }

    printf("Aenderung (positiv = Zugang, negativ = Abgang): ");
    scanf_s("%d", &aenderung);

    bestandAendern(gefunden, aenderung);
    lagerInDateiSpeichern(lager, anzahlTeile);
    printf("Neuer Bestand von Teil %d: %d\n", teilenummer, gefunden->bestand);
}
