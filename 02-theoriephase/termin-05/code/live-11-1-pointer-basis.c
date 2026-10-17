#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int zahl = 42;
    int *zeigerAufZahl = &zahl; // (1)!

    printf("Wert von zahl:                %d\n", zahl);
    printf("Adresse von zahl (&zahl):      %p\n", (void *)&zahl); // (2)!
    printf("Wert von zeigerAufZahl:        %p\n", (void *)zeigerAufZahl); // (3)!
    printf("Wert, auf den er zeigt (*):    %d\n", *zeigerAufZahl); // (4)!

    *zeigerAufZahl = 100; // (5)!
    printf("zahl nach *zeigerAufZahl=100:  %d\n", zahl);

    system("pause");

    return 0;
}
