#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define BYTES_PRO_ZEILE 16

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Aufruf: hexdump <Dateiname>\n");
        system("pause");
        return 1;
    }

    FILE *datei = fopen(argv[1], "rb");
    if (datei == NULL)
    {
        printf("Datei %s konnte nicht geoeffnet werden.\n", argv[1]);
        system("pause");
        return 1;
    }

    unsigned char puffer[BYTES_PRO_ZEILE];
    unsigned int offset = 0;
    int gelesen = fread(puffer, 1, BYTES_PRO_ZEILE, datei); // (1)!

    while (gelesen > 0)
    {
        printf("%08X  ", offset); // (2)!

        for (int i = 0; i < BYTES_PRO_ZEILE; i++)
            if (i < gelesen)
                printf("%02X ", puffer[i]);
            else
                printf("   "); // (3)!

        printf(" ");
        for (int i = 0; i < gelesen; i++)
            printf("%c", (puffer[i] >= 32 && puffer[i] < 127) ? puffer[i] : '.'); // (4)!
        printf("\n");

        offset = offset + gelesen;
        gelesen = fread(puffer, 1, BYTES_PRO_ZEILE, datei);
    }

    fclose(datei);

    system("pause");

    return 0;
}
