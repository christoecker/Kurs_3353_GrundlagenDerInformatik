#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char wort[] = "Hallo"; // (1)!
    char zeichenweise[6] = { 'H', 'a', 'l', 'l', 'o', '\0' }; // (2)!

    printf("wort: %s\n", wort); // (3)!
    printf("zeichenweise: %s\n", zeichenweise);

    printf("sizeof(wort): %zu Byte\n", sizeof(wort)); // (4)!
    printf("strlen(wort): %zu Zeichen\n", strlen(wort));

    wort[0] = 'J'; // (5)!
    printf("Nach der Aenderung: %s\n", wort);

    wort[2] = '\0'; // (6)!
    printf("Nach dem Setzen von wort[2]: %s\n", wort);
    printf("strlen(wort): %zu Zeichen\n", strlen(wort));

    system("pause");

    return 0;
}
