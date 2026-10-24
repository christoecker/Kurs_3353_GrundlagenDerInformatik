#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    double wert;
} Messpunkt;

void verdoppelnKopie(Messpunkt p); // (1)!
void verdoppelnPointer(Messpunkt *p); // (2)!

int main(void)
{
    Messpunkt messpunkt = { 1, 20.0 };

    verdoppelnKopie(messpunkt);
    printf("Nach der Kopie:   %.1f\n", messpunkt.wert); // (3)!

    verdoppelnPointer(&messpunkt); // (4)!
    printf("Nach dem Pointer: %.1f\n", messpunkt.wert);

    system("pause");

    return 0;
}

void verdoppelnKopie(Messpunkt p)
{
    p.wert = p.wert * 2;
}

void verdoppelnPointer(Messpunkt *p)
{
    p->wert = p->wert * 2; // (5)!
}
