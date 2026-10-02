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

void teilEinfuegen(Teil lager[], int *anzahlTeile, Teil neuesTeil);
void teilAusgeben(const Teil *teil);                          // Clean Code: PoLP - nur lesender Zugriff
void alleTeileAnzeigen(const Teil lager[], int anzahlTeile);  // Clean Code: PoLP - nur lesender Zugriff

#endif
