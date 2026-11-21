#include <stdio.h>
#include <stdlib.h>

void rechteckAuswerten(float laenge, float breite);

int main(void)
{
    rechteckAuswerten(4.0f, 3.0f);
    rechteckAuswerten(7.0f, 2.5f);

    system("pause");

    return 0;
}

void rechteckAuswerten(float laenge, float breite)
{
    float flaeche = laenge * breite;
    float umfang = 2 * (laenge + breite);
    printf("Rechteck: Flaeche %.2f, Umfang %.2f\n", flaeche, umfang);
}
