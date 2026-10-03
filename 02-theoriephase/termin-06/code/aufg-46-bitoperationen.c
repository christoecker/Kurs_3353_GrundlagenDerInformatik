#include <stdio.h>
#include <stdlib.h>

// Bit mit der Nummer pos (von rechts, ab 0) setzen: ODER mit der Bitmaske
#define bitSet(var, pos) ((var) |= (1 << (pos)))
// Bit mit der Nummer pos zuruecksetzen: UND mit der invertierten Bitmaske
#define bitReset(var, pos) ((var) &= ~(1 << (pos)))

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
