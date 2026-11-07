#include <stdio.h>
#include <stdlib.h>

#define MAX_N 12800

static long quicksortVergleiche; // (1)!

long vergleicheBubblesort(int a[], int n);
int teileMitZaehler(int a[], int links, int rechts);
void quicksortMitZaehler(int a[], int links, int rechts);

int main(void)
{
    static int original[MAX_N];
    static int arbeitskopie[MAX_N];
    int groessen[] = { 100, 200, 400, 800, 1600, 3200, 6400, 12800 };
    int anzahlGroessen = sizeof(groessen) / sizeof(groessen[0]);

    srand(42); // (2)!
    for (int i = 0; i < MAX_N; i++)
        original[i] = rand() % 100000;

    printf("n,VergleicheBubblesort,VergleicheQuicksort\n");

    for (int g = 0; g < anzahlGroessen; g++)
    {
        int n = groessen[g];

        for (int i = 0; i < n; i++)
            arbeitskopie[i] = original[i];
        long vergleicheB = vergleicheBubblesort(arbeitskopie, n);

        for (int i = 0; i < n; i++)
            arbeitskopie[i] = original[i];
        quicksortVergleiche = 0;
        quicksortMitZaehler(arbeitskopie, 0, n - 1); // (3)!

        printf("%d,%ld,%ld\n", n, vergleicheB, quicksortVergleiche);
    }

    system("pause");

    return 0;
}

long vergleicheBubblesort(int a[], int n)
{
    long vergleiche = 0;

    for (int durchlauf = 1; durchlauf < n; durchlauf++)
        for (int i = 0; i < n - durchlauf; i++)
        {
            vergleiche++; // (4)!
            if (a[i] > a[i + 1])
            {
                int zwischenspeicher = a[i];
                a[i] = a[i + 1];
                a[i + 1] = zwischenspeicher;
            }
        }

    return vergleiche;
}

int teileMitZaehler(int a[], int links, int rechts)
{
    int i = links;
    int j = rechts - 1;
    int pivot = a[rechts];

    while (i < j)
    {
        while (i < j && a[i] <= pivot)
        {
            quicksortVergleiche++; // (5)!
            i++;
        }

        while (j > i && a[j] > pivot)
        {
            quicksortVergleiche++;
            j--;
        }

        quicksortVergleiche++;
        if (a[i] > a[j])
        {
            int zwischenspeicher = a[i];
            a[i] = a[j];
            a[j] = zwischenspeicher;
        }
    }

    quicksortVergleiche++;
    if (a[i] > pivot)
    {
        int zwischenspeicher = a[i];
        a[i] = a[rechts];
        a[rechts] = zwischenspeicher;
    }
    else
    {
        i = rechts;
    }

    return i;
}

void quicksortMitZaehler(int a[], int links, int rechts)
{
    if (links < rechts)
    {
        int teiler = teileMitZaehler(a, links, rechts);
        quicksortMitZaehler(a, links, teiler - 1);
        quicksortMitZaehler(a, teiler + 1, rechts);
    }
}
