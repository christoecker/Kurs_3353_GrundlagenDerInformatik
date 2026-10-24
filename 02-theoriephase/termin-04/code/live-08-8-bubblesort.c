#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 5

void bubbleSort(int a[], int n);
void arrayAusgeben(int a[], int n);

int main(void)
{
    int daten[ANZAHL] = { 29, 8, 41, 15, 3 };

    printf("Vorher:  ");
    arrayAusgeben(daten, ANZAHL);

    bubbleSort(daten, ANZAHL);

    printf("Nachher: ");
    arrayAusgeben(daten, ANZAHL);

    system("pause");

    return 0;
}

void bubbleSort(int a[], int n)
{
    for (int durchlauf = 1; durchlauf < n; durchlauf++)
        for (int i = 0; i < n - durchlauf; i++) // (1)!
            if (a[i] > a[i + 1])
            {
                int zwischenspeicher = a[i]; // (2)!
                a[i] = a[i + 1];
                a[i + 1] = zwischenspeicher;
            }
}

void arrayAusgeben(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
