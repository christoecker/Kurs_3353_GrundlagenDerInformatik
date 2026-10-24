#include <stdio.h>
#include <stdlib.h>

void bubblesort(int a[], int n);
void arrayAusgeben(int a[], int n);

int main(void)
{
    int daten[] = { 5, 2, 8, 1, 9, 3, 4 };
    int anzahl = 7;

    bubblesort(daten, anzahl);
    arrayAusgeben(daten, anzahl);

    system("pause");

    return 0;
}

void bubblesort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int zwischenspeicher = a[j];
                a[j] = a[j + 1];
                a[j + 1] = zwischenspeicher;
            }
        }
    }
}

void arrayAusgeben(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
