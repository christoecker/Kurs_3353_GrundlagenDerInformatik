#include <stdio.h>
#include <stdlib.h> // (1)!

int main(void)
{
    char anzahlText[] = "42";
    char messwertText[] = "23.5";
    char unsinn[] = "abc";

    int anzahl = atoi(anzahlText); // (2)!
    double messwert = atof(messwertText);

    printf("anzahl + 1 = %d\n", anzahl + 1);
    printf("messwert * 2 = %.1f\n", messwert * 2);
    printf("atoi(\"abc\") = %d\n", atoi(unsinn)); // (3)!

    system("pause");

    return 0;
}
