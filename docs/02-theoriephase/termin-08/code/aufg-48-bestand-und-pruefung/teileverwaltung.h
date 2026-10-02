#ifndef TEILEVERWALTUNG_H
#define TEILEVERWALTUNG_H

#define MAX_TEILE 200             // Clean Code: Magic Number vermeiden
#define MAX_BEZEICHNUNG_LAENGE 30 // Clean Code: Magic Number vermeiden

// Clean Code: Konvention vor Konfiguration - Typname in PascalCase (Teil)
typedef struct
{
    int teilenummer;
    char bezeichnung[MAX_BEZEICHNUNG_LAENGE];
    int bestand;
} Teil;

void teileAusDateiLaden(Teil lager[], int *anzahlTeile);
void teilAnDateiAnhaengen(const Teil *teil);                 // Clean Code: PoLP - nur lesender Zugriff
void lagerInDateiSpeichern(const Teil lager[], int anzahlTeile); // Clean Code: PoLP - nur lesender Zugriff
void teilEinfuegen(Teil lager[], int *anzahlTeile, Teil neuesTeil);

// Nicht const, siehe Begruendung im Zwischenprojekt: wird sowohl zum
// Anzeigen als auch zum anschliessenden Aendern des Bestands gebraucht.
Teil *teilSuchen(Teil lager[], int anzahlTeile, int teilenummer);

void bestandAendern(Teil *teil, int aenderung);
void teilAusgeben(const Teil *teil);                          // Clean Code: PoLP - nur lesender Zugriff
void alleTeileAnzeigen(const Teil lager[], int anzahlTeile);  // Clean Code: PoLP - nur lesender Zugriff

#endif
