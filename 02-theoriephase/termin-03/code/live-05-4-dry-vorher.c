#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float laenge1 = 4.0f;
    float breite1 = 3.0f;
    float flaeche1 = laenge1 * breite1;
    float umfang1 = 2 * (laenge1 + breite1);
    printf("Rechteck 1: Flaeche %.2f, Umfang %.2f\n", flaeche1, umfang1);

    float laenge2 = 7.0f;
    float breite2 = 2.5f;
    float flaeche2 = laenge2 * breite2;
    float umfang2 = 2 * (laenge2 + breite2);
    printf("Rechteck 2: Flaeche %.2f, Umfang %.2f\n", flaeche2, umfang2);

    system("pause");

    return 0;
}
