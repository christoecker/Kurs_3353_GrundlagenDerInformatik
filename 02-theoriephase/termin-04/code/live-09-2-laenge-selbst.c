#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int laenge(char text[]);

int main(void)
{
    char wort[] = "Sensor";

    printf("Eigene Laenge von \"%s\": %d\n", wort, laenge(wort));
    printf("Zum Vergleich strlen:    %zu\n", strlen(wort));

    system("pause");

    return 0;
}

int laenge(char text[]) // (1)!
{
    int anzahl = 0;

    while (text[anzahl] != '\0') // (2)!
        anzahl++;

    return anzahl;
}
