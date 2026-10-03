#include <stdio.h>
#include <stdlib.h>

void bubblesort(int a[], int n, int (*kriterium)(int, int)); // (1)!
int aufsteigend(int a, int b); // (2)!
int absteigend(int a, int b);
int geradeVorUngerade(int a, int b);
void arrayAusgeben(int a[], int n);

int main(void)
{
    int daten1[] = { 5, 2, 8, 1, 9, 3, 4 };
    int daten2[] = { 5, 2, 8, 1, 9, 3, 4 };
    int daten3[] = { 5, 2, 8, 1, 9, 3, 4 };
    int anzahl = 7;

    bubblesort(daten1, anzahl, aufsteigend); // (3)!
    printf("Aufsteigend:         ");
    arrayAusgeben(daten1, anzahl);

    bubblesort(daten2, anzahl, absteigend);
    printf("Absteigend:          ");
    arrayAusgeben(daten2, anzahl);

    bubblesort(daten3, anzahl, geradeVorUngerade);
    printf("Gerade vor ungerade: ");
    arrayAusgeben(daten3, anzahl);

    system("pause");

    return 0;
}

void bubblesort(int a[], int n, int (*kriterium)(int, int))
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (kriterium(a[j], a[j + 1])) // (4)!
            {
                int zwischenspeicher = a[j];
                a[j] = a[j + 1];
                a[j + 1] = zwischenspeicher;
            }
        }
    }
}

int aufsteigend(int a, int b)
{
    return a > b; // (5)!
}

int absteigend(int a, int b)
{
    return a < b;
}

int geradeVorUngerade(int a, int b) // (6)!
{
    int aIstGerade = (a % 2 == 0);
    int bIstGerade = (b % 2 == 0);

    if (aIstGerade == bIstGerade)
        return 0;

    return bIstGerade;
}

void arrayAusgeben(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
