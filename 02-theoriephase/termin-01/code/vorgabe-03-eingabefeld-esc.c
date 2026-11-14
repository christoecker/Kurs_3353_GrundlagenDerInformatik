#include <stdio.h>

int main(void)
{
    printf("\x1b[2J");                     // Bildschirm loeschen
    printf("\x1b[5;10H+----------------+"); // Rahmen: obere Kante
    printf("\x1b[6;10H|                |"); // Rahmen: Innenraum
    printf("\x1b[7;10H+----------------+"); // Rahmen: untere Kante

    printf("\x1b[6;12H");                   // Cursor in das Feld setzen
    int messwert = 0;
    scanf_s("%d", &messwert);

    printf("\x1b[9;10HGemessener Wert: %d\n", messwert);

    return 0;
}
