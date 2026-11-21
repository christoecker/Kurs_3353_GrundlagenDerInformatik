#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 5

void bubbleSort(int a[], int n);
void arrayAusgeben(int a[], int n);

int main(void)
{
    int daten[ANZAHL] = { 29, 8, 41, 15, 3 };

    printf("Start:   ");
    arrayAusgeben(daten, ANZAHL);

    bubbleSort(daten, ANZAHL);

    system("pause");

    return 0;
}

void bubbleSort(int a[], int n)
{
    for (int durchlauf = 1; durchlauf < n; durchlauf++)
    {
        for (int i = 0; i < n - durchlauf; i++)
            if (a[i] > a[i + 1])
            {
                int zwischenspeicher = a[i];
                a[i] = a[i + 1];
                a[i + 1] = zwischenspeicher;
            }

        printf("Nach %d:  ", durchlauf); // (1)!
        arrayAusgeben(a, n);
    }
}

void arrayAusgeben(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
