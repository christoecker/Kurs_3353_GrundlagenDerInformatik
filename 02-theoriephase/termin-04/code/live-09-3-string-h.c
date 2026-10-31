#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char vorname[20] = "Anna";
    char nachname[] = "Meier";
    char name[40];

    printf("Laenge von vorname: %zu\n", strlen(vorname)); // (1)!

    printf("vorname gleich \"Anna\":  %d\n", strcmp(vorname, "Anna") == 0); // (2)!
    printf("vorname gleich nachname: %d\n", strcmp(vorname, nachname) == 0);

    strcpy_s(name, sizeof(name), vorname); // (3)!
    strcat_s(name, sizeof(name), " ");
    strcat_s(name, sizeof(name), nachname); // (4)!

    printf("Zusammengesetzt: %s\n", name);
    printf("Laenge: %zu, Platz: %zu Byte\n", strlen(name), sizeof(name));

    system("pause");

    return 0;
}
