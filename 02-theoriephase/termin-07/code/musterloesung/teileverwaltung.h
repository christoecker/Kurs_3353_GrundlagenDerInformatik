#ifndef TEILEVERWALTUNG_H
#define TEILEVERWALTUNG_H

/*
 * Deklarationen fuer die Teileverwaltung: Datenmodell (Teil) und alle
 * Funktionen, die auf dem Lager arbeiten. main.c kennt nur diese
 * Schnittstelle, nicht die Umsetzung in teileverwaltung.c.
 *
 * Aufteilung bewusst nur in Header + Implementierung (teileverwaltung.h/.c)
 * plus main.c fuer Menue und Programmstart - eine feinere Aufteilung
 * (z. B. eine eigene Datei je Menuepunkt) waere fuer ein Projekt dieser
 * Groesse YAGNI: mehr Dateien wuerden hier nur mehr Includes bedeuten,
 * nicht mehr Uebersicht.
 */

#define MAX_TEILE 200             // Clean Code: Magic Number vermeiden
#define MAX_BEZEICHNUNG_LAENGE 30 // Clean Code: Magic Number vermeiden

// Clean Code: Konvention vor Konfiguration - Typname in PascalCase (Teil)
typedef struct
{
    int teilenummer;
    char bezeichnung[MAX_BEZEICHNUNG_LAENGE];
    int bestand;
} Teil;

void teileMitTestdatenBefuellen(Teil lager[], int *anzahlTeile);
void teilEinfuegen(Teil lager[], int *anzahlTeile, Teil neuesTeil);

// Nicht const, weil die Funktion sowohl fuer reine Anzeige (Menuepunkt
// "Teil suchen") als auch fuer die anschliessende Bestandsaenderung
// gebraucht wird. Eine zweite, rein lesende Variante nur fuer die Anzeige
// waere hier eine DRY-Verletzung fuer wenig Nutzen gewesen (YAGNI).
Teil *teilSuchen(Teil lager[], int anzahlTeile, int teilenummer);

void teilAusgeben(const Teil *teil);                          // Clean Code: PoLP - nur lesender Zugriff
void alleTeileAnzeigen(const Teil lager[], int anzahlTeile);  // Clean Code: PoLP - nur lesender Zugriff
void bestandAendern(Teil *teil, int aenderung);

#endif
