#include <stdio.h>
#include <stdlib.h>

// Hier die Makros bitSet und bitReset definieren

int main(void)
{
    int zahl = 12;
    printf("%d\n", zahl); // Ausgabe: 12

    bitSet(zahl, 1);
    printf("%d\n", zahl); // Ausgabe: 14

    bitReset(zahl, 3);
    printf("%d\n", zahl); // Ausgabe: 6

    system("pause");

    return 0;
}
