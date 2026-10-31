#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int anzahl = 0;
    printf("Wie viele Werte? ");
    if (scanf_s("%d", &anzahl) != 1 || anzahl <= 0)
    {
        printf("Bitte eine positive Zahl eingeben.\n");
        return 1;
    }

    int *unbestimmt = malloc(anzahl * sizeof(int)); // (1)!
    if (unbestimmt == NULL) // (2)!
    {
        printf("Nicht genug Speicher.\n");
        return 1;
    }

    printf("malloc:");
    for (int i = 0; i < anzahl; i++)
        printf(" %d", unbestimmt[i]); // (3)!
    printf("\n");
    free(unbestimmt); // (4)!

    int *werte = calloc(anzahl, sizeof(int)); // (5)!
    if (werte == NULL)
    {
        printf("Nicht genug Speicher.\n");
        return 1;
    }

    printf("calloc:");
    for (int i = 0; i < anzahl; i++)
        printf(" %d", werte[i]);
    printf("\n");

    for (int i = 0; i < anzahl; i++)
        werte[i] = i * i;

    int *vergroessert = realloc(werte, 2 * anzahl * sizeof(int)); // (6)!
    if (vergroessert == NULL)
    {
        printf("Nicht genug Speicher.\n");
        free(werte); // (7)!
        return 1;
    }
    werte = vergroessert; // (8)!

    for (int i = anzahl; i < 2 * anzahl; i++)
        werte[i] = i * i;

    printf("realloc:");
    for (int i = 0; i < 2 * anzahl; i++)
        printf(" %d", werte[i]);
    printf("\n");
    free(werte);

    system("pause");

    return 0;
}
