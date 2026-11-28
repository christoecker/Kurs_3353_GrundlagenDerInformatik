#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int gewicht = 0;
    int region = 0;
    int express = 0;
    int kosten = 0;

    // Eingabe: alle drei Werte einlesen
    printf("Paketgewicht in Gramm (1 bis 30000): ");
    scanf_s("%d", &gewicht);
    printf("Zielregion (1 = Inland, 2 = EU-Ausland): ");
    scanf_s("%d", &region);
    printf("Expressversand (1 = ja, 0 = nein): ");
    scanf_s("%d", &express);

    // Ungueltige Eingaben zuerst abfangen, damit nie mit falschen Werten gerechnet wird
    if (gewicht < 1 || gewicht > 30000) // (1)!
    {
        printf("Fehler: Das Gewicht muss zwischen 1 und 30000 g liegen.\n");
    }
    else if (region != 1 && region != 2) // (2)!
    {
        printf("Fehler: Die Region muss 1 (Inland) oder 2 (EU-Ausland) sein.\n");
    }
    else
    {
        // Grundpreis: aeussere Verzweigung nach Region, innen je eine Kette nach Gewicht
        if (region == 1) // (3)!
        {
            if (gewicht <= 1000)
            {
                kosten = 4;
            }
            else if (gewicht <= 5000) // (4)!
            {
                kosten = 7;
            }
            else if (gewicht <= 10000)
            {
                kosten = 10;
            }
            else
            {
                kosten = 15;
            }
        }
        else
        {
            if (gewicht <= 1000)
            {
                kosten = 9;
            }
            else if (gewicht <= 5000)
            {
                kosten = 14;
            }
            else if (gewicht <= 10000)
            {
                kosten = 20;
            }
            else
            {
                kosten = 30;
            }
        }

        // Expressaufschlag: nur bei Wunsch und nur fuer Pakete, die der Shop als Express anbietet
        if (express == 1)
        {
            if (gewicht <= 10000) // (5)!
            {
                if (region == 1)
                {
                    kosten = kosten + 5;
                }
                else
                {
                    kosten = kosten + 8;
                }
            }
            else
            {
                printf("Hinweis: Express ist nur bis 10000 g verfuegbar, es gilt der normale Preis.\n");
            }
        }

        printf("Versandkosten: %d Euro\n", kosten);
    }

    system("pause");

    return 0;
}
