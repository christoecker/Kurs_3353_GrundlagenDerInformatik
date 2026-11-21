#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int zahl1 = 0;
    int zahl2 = 0;

    // Eingabe: beide Zahlen einlesen
    printf("Erste Zahl: ");
    scanf_s("%d", &zahl1);
    printf("Zweite Zahl: ");
    scanf_s("%d", &zahl2);

    // Vergleich: die groessere der beiden Zahlen merken
    int maximum = 0;

    if (zahl1 > zahl2)
    {   // (1)!
        maximum = zahl1;
    }
    else
    {   // (2)!
        maximum = zahl2;
    }

    // Ausgabe: Ergebnis
    printf("Maximum: %d\n", maximum);

    system("pause");

    return 0;
}
