#include <stdio.h>
#include <stdlib.h>

void temperaturPruefenUndMelden(int temperatur, int grenze);

int main(void)
{
    int temperatur = 0;
    int grenze = 80;

    printf("Temperatur eingeben: ");
    scanf_s("%d", &temperatur);

    temperaturPruefenUndMelden(temperatur, grenze);

    system("pause");

    return 0;
}

void temperaturPruefenUndMelden(int temperatur, int grenze)
{
    if (temperatur > grenze)
        printf("Warnung: Temperatur zu hoch!\n");
    else
        printf("Temperatur im normalen Bereich.\n");
}
