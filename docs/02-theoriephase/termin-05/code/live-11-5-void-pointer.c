#include <stdio.h>
#include <stdlib.h>

void adresseAusgeben(void *adresse); // (1)!

int main(void)
{
    int ganzzahl = 7;
    double kommazahl = 3.5;

    void *irgendeineAdresse; // (2)!

    irgendeineAdresse = &ganzzahl; // (3)!
    adresseAusgeben(irgendeineAdresse);

    int *alsIntPointer = (int *)irgendeineAdresse; // (4)!
    printf("Als int gedeutet (in zwei Schritten): %d\n", *alsIntPointer);
    printf("Als int gedeutet (kompakt):           %d\n", *(int *)irgendeineAdresse); // (5)!

    irgendeineAdresse = &kommazahl;
    adresseAusgeben(irgendeineAdresse);
    printf("Als double gedeutet: %f\n", *(double *)irgendeineAdresse); // (6)!

    system("pause");

    return 0;
}

void adresseAusgeben(void *adresse)
{
    printf("Adresse: %p\n", adresse);
}
