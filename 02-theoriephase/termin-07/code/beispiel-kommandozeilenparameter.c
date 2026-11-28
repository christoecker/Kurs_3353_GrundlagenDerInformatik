#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) // (1)!
{
    printf("Anzahl Parameter (inkl. Programmname): %d\n", argc); // (2)!

    for (int i = 0; i < argc; i++) // (3)!
        printf("argv[%d] = %s\n", i, argv[i]);

    if (argc >= 2 && strcmp(argv[1], "hallo") == 0) // (4)!
        printf("Hallo zurueck!\n");

    if (argc >= 3 && strcmp(argv[1], "verdopple") == 0) // (5)!
    {
        int zahl = atoi(argv[2]); // (6)!
        printf("Verdoppelt: %d\n", zahl * 2);
    }

    system("pause");

    return 0;
}
