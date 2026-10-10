#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float laenge = 0.0f;
    float breite = 0.0f;

    // Eingabe: Laenge und Breite, durch Komma getrennt einlesen
    printf("Laenge und Breite (durch Komma getrennt): ");
    scanf_s("%f, %f", &laenge, &breite);

    // Berechnung: Flaeche und Umfang aus den eingelesenen Werten
    float flaeche = laenge * breite;
    float umfang = 2 * (laenge + breite);

    // Ausgabe: beide Ergebnisse formatiert ausgeben
    printf("Flaeche: %.2f\n", flaeche);
    printf("Umfang:  %.2f\n", umfang);

    system("pause");

    return 0;
}
