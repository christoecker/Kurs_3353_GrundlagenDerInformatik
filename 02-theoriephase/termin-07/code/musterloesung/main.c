/*
 * Projekt:  Ersatzteilverwaltung MechaTech GmbH
 * Kurs:     Grundlagen der Informatik (Kurs 3353)
 * Termin:   Zwischenprojekt (Termin 7, 02.12.2026)
 *
 * Musterloesung zum Auftrag "Kleines Verwaltungsprogramm fuer unser
 * Ersatzteillager" inklusive beider Auftraggeber-Nachtraege: Das Lager
 * wird durchgehend sortiert gehalten, damit die Suche auch bei vielen
 * Teilen schnell bleibt, und das Programm laesst sich ueber
 * Kommandozeilenparameter (demo / suche <Teilenummer>) unterschiedlich
 * starten.
 *
 * WICHTIG: Das hier ist EINE moegliche Loesung von vielen. Ein anderes
 * Datenmodell, eine andere Menuefuehrung oder eine andere Dateiaufteilung
 * koennen genauso gut oder sogar besser sein - diese Musterloesung dient
 * zum Vergleichen und Nachschlagen, nicht als einzig richtiger Weg.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teileverwaltung.h"

void menueAnzeigen(void);
void menueAusfuehren(Teil lager[], int *anzahlTeile);
void teilEintragenUeberMenue(Teil lager[], int *anzahlTeile);
void teilSuchenUeberMenue(Teil lager[], int anzahlTeile);
void bestandAendernUeberMenue(Teil lager[], int anzahlTeile);

int main(int argc, char *argv[])
{
    Teil lager[MAX_TEILE];
    int anzahlTeile = 0;

    if (argc >= 3 && strcmp(argv[1], "suche") == 0)
    {
        // Direkteinstieg ohne Menue: einmal suchen, Ergebnis ausgeben,
        // fertig (zweiter Nachtrag).
        teileMitTestdatenBefuellen(lager, &anzahlTeile);

        int gesuchteNummer = atoi(argv[2]);
        Teil *gefunden = teilSuchen(lager, anzahlTeile, gesuchteNummer);

        if (gefunden != NULL)
            teilAusgeben(gefunden);
        else
            printf("Teil mit Nummer %d nicht gefunden.\n", gesuchteNummer);

        return 0;
    }

    if (argc >= 2 && strcmp(argv[1], "demo") == 0)
        teileMitTestdatenBefuellen(lager, &anzahlTeile); // Menue startet vorbefuellt

    menueAusfuehren(lager, &anzahlTeile); // ohne Parameter: leer, mit Menue

    return 0;
}

void menueAnzeigen(void)
{
    printf("\n=== Ersatzteilverwaltung MechaTech GmbH ===\n");
    printf("1 - Teil eintragen\n");
    printf("2 - Alle Teile anzeigen\n");
    printf("3 - Teil suchen\n");
    printf("4 - Bestand aendern\n");
    printf("0 - Beenden\n");
    printf("Auswahl: ");
}

void menueAusfuehren(Teil lager[], int *anzahlTeile)
{
    int auswahl = 0;

    // Clean Code: DRY - der Menuetext steht nur einmal in menueAnzeigen(),
    // statt vor und in der Schleife doppelt ausgeschrieben zu werden.
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
                teilSuchenUeberMenue(lager, *anzahlTeile);
                break;
            case 4:
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

    // Nur ein Wort ohne Leerzeichen: fgets zum zeilenweisen Einlesen ist
    // im Kurs noch nicht eingefuehrt, scanf_s mit %s liest nur bis zum
    // ersten Leerzeichen.
    printf("Bezeichnung (ein Wort, ohne Leerzeichen): ");
    scanf_s("%s", neuesTeil.bezeichnung, (unsigned)sizeof(neuesTeil.bezeichnung));

    printf("Bestand: ");
    scanf_s("%d", &neuesTeil.bestand);

    teilEinfuegen(lager, anzahlTeile, neuesTeil);
    printf("Teil %d wurde aufgenommen.\n", neuesTeil.teilenummer);
}

void teilSuchenUeberMenue(Teil lager[], int anzahlTeile)
{
    int gesuchteNummer = 0;

    printf("Gesuchte Teilenummer: ");
    scanf_s("%d", &gesuchteNummer);

    Teil *gefunden = teilSuchen(lager, anzahlTeile, gesuchteNummer);

    if (gefunden != NULL)
        teilAusgeben(gefunden);
    else
        printf("Teil mit Nummer %d nicht gefunden.\n", gesuchteNummer);
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
    printf("Neuer Bestand von Teil %d: %d\n", teilenummer, gefunden->bestand);
}
