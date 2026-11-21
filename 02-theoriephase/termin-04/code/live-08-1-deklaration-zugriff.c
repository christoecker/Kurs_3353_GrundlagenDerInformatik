#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int messwerte[5] = { 12, 15, 9, 20, 17 };
    int teilweise[5] = { 1, 2 }; // (1)!
    int ohneGroesse[] = { 4, 8, 15, 16, 23, 42 }; // (2)!

    printf("Erster Messwert: %d\n", messwerte[0]); // (3)!
    printf("Letzter Messwert: %d\n", messwerte[4]);

    messwerte[2] = 11; // (4)!
    printf("Dritter Messwert nach der Korrektur: %d\n", messwerte[2]);

    printf("teilweise[3]: %d\n", teilweise[3]);
    printf("ohneGroesse[5]: %d\n", ohneGroesse[5]);

    system("pause");

    return 0;
}
