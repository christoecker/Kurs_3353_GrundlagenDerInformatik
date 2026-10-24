#include <stdio.h>

int main(void)
{
    float grenze = 80.0f;
    float wert = 0.0f;
    float summe = 0.0f;
    int anzahl = 0;
    float ergebnis = 0.0f;

    printf("Wert eingeben (negative Zahl beendet die Eingabe): ");
    scanf_s("%f", &wert);

    while (wert >= 0) // (1)!
    {
        summe = summe + wert; // (2)!
        anzahl = anzahl + 1;
        ergebnis = summe / anzahl;

        if (ergebnis > grenze) // (3)!
        {
            printf("Abbruch: Ergebnis liegt ueber der Grenze!\n");
            break; // (4)!
        }

        printf("Wert eingeben (negative Zahl beendet die Eingabe): ");
        scanf_s("%f", &wert);
    }

    printf("Ergebnis: %.2f\n", ergebnis);

    return 0;
}
