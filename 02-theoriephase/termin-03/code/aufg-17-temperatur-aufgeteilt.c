#include <stdio.h>
#include <stdlib.h>

int istUeberGrenze(int temperatur, int grenze);

int main(void)
{
    int temperatur = 0;
    int grenze = 80;

    printf("Temperatur eingeben: ");
    scanf_s("%d", &temperatur);

    if (istUeberGrenze(temperatur, grenze))
        printf("Warnung: Temperatur zu hoch!\n");
    else
        printf("Temperatur im normalen Bereich.\n");

    system("pause");

    return 0;
}

int istUeberGrenze(int temperatur, int grenze)
{
    return temperatur > grenze;
}
