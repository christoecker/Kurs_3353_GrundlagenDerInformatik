#include <stdio.h>

int main(void)
{
    float x1 = 0.0f;
    float y1 = 0.0f;
    float x2 = 0.0f;
    float y2 = 0.0f;

    // Eingabe: beide Punkte einlesen
    printf("Erster Punkt, x1 und y1 (durch Komma getrennt): ");
    scanf_s("%f, %f", &x1, &y1);

    printf("Zweiter Punkt, x2 und y2 (durch Komma getrennt): ");
    scanf_s("%f, %f", &x2, &y2);

    // Berechnung: Steigung aus den vier Koordinaten
    float steigung = (y2 - y1) / (x2 - x1);

    // Ausgabe: Ergebnis
    printf("Steigung: %.2f\n", steigung);

    return 0;
}
