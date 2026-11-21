#define _CRT_SECURE_NO_WARNINGS // (1)!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char zeile[] = "23.5;24.1;22.9;21.8"; // (2)!
    char *messwert = strtok(zeile, ";"); // (3)!

    while (messwert != NULL) // (4)!
    {
        printf("Messwert: %s\n", messwert);
        messwert = strtok(NULL, ";"); // (5)!
    }

    system("pause");

    return 0;
}
