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

int teilEinfuegen(Teil lager[], int *anzahlTeile, Teil neuesTeil); // liefert 1 bei Erfolg, 0 wenn das Lager voll ist
void teilAusgeben(const Teil *teil);                          // Clean Code: PoLP - nur lesender Zugriff
void alleTeileAnzeigen(const Teil lager[], int anzahlTeile);  // Clean Code: PoLP - nur lesender Zugriff

#endif
