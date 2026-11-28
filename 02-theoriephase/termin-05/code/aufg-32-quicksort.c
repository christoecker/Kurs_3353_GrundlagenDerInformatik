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
    if (links < rechts)
    {
        int teiler = teile(daten, links, rechts);
        quicksort(daten, links, teiler - 1);
        quicksort(daten, teiler + 1, rechts);
    }
}

int teile(int daten[], int links, int rechts)
{
    int i = links;
    int j = rechts - 1;
    int pivot = daten[rechts];

    while (i < j)
    {
        while (i < j && daten[i] <= pivot)
            i++;

        while (j > i && daten[j] > pivot)
            j--;

        if (daten[i] > daten[j])
        {
            int zwischenspeicher = daten[i];
            daten[i] = daten[j];
            daten[j] = zwischenspeicher;
        }
    }

    if (daten[i] > pivot)
    {
        int zwischenspeicher = daten[i];
        daten[i] = daten[rechts];
        daten[rechts] = zwischenspeicher;
    }
    else
    {
        i = rechts;
    }

    return i;
}

void arrayAusgeben(int daten[], int anzahl)
{
    for (int i = 0; i < anzahl; i++)
        printf("%d ", daten[i]);
    printf("\n");
}
