#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 8

void quicksort(int daten[], int links, int rechts);
int teile(int daten[], int links, int rechts);
void arrayAusgeben(int daten[], int anzahl);

int main(void)
{
    int daten[ANZAHL] = { 33, 6, 48, 19, 2, 55, 27, 41 };

    printf("Vorher:  ");
    arrayAusgeben(daten, ANZAHL);

    quicksort(daten, 0, ANZAHL - 1);

    printf("Nachher: ");
    arrayAusgeben(daten, ANZAHL);

    system("pause");

    return 0;
}

void quicksort(int daten[], int links, int rechts)
{
    // TODO
}

int teile(int daten[], int links, int rechts)
{
    // TODO
    return 0;
}

void arrayAusgeben(int daten[], int anzahl)
{
    for (int i = 0; i < anzahl; i++)
        printf("%d ", daten[i]);
    printf("\n");
}
