#include <stdio.h>
#include <stdlib.h>

void meinKopieren(void *ziel, const void *quelle, size_t anzahlBytes); // (1)!

int main(void)
{
    int quellwert = 12345;
    int zielwert = 0;

    meinKopieren(&zielwert, &quellwert, sizeof(int)); // (2)!
    printf("zielwert nach dem Kopieren:  %d\n", zielwert);

    double quellkomma = 3.75;
    double zielkomma = 0.0;

    meinKopieren(&zielkomma, &quellkomma, sizeof(double)); // (3)!
    printf("zielkomma nach dem Kopieren: %f\n", zielkomma);

    system("pause");

    return 0;
}

void meinKopieren(void *ziel, const void *quelle, size_t anzahlBytes)
{
    unsigned char *zielBytes = (unsigned char *)ziel; // (4)!
    const unsigned char *quellBytes = (const unsigned char *)quelle;

    for (size_t i = 0; i < anzahlBytes; i++)
        zielBytes[i] = quellBytes[i]; // (5)!
}
