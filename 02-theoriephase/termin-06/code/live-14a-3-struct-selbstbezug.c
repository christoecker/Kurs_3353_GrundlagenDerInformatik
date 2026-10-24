#include <stdio.h>
#include <stdlib.h>

typedef struct Knoten // (1)!
{
    int wert;
    struct Knoten *nachfolger; // (2)!
} Knoten;

int main(void)
{
    Knoten erster = { 1, NULL }; // (3)!
    Knoten zweiter = { 2, &erster }; // (4)!

    printf("zweiter.wert = %d\n", zweiter.wert);
    printf("Wert des Nachfolgers: %d\n", zweiter.nachfolger->wert); // (5)!

    system("pause");

    return 0;
}
