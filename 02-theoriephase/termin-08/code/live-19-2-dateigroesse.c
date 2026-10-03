#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *datei = fopen("notizen.txt", "r");
    if (datei == NULL)
    {
        printf("Datei konnte nicht geoeffnet werden.\n");
        return 1;
    }

    fseek(datei, 0, SEEK_END); // (1)!

    fpos_t groesse;
    fgetpos(datei, &groesse); // (2)!

    printf("Dateigroesse: %lld Byte\n", groesse); // (3)!

    fclose(datei);

    system("pause");

    return 0;
}
