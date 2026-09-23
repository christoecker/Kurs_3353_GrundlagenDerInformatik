#include <stdio.h>
#include <stdlib.h>

void neuerMesswert(int wert);

int main(void)
{
    neuerMesswert(42);
    neuerMesswert(17);
    neuerMesswert(87);
    neuerMesswert(53);
    neuerMesswert(-5);

    system("pause");

    return 0;
}

void neuerMesswert(int wert)
{
    static int maximum = 0;
    static int ersterAufruf = 1;

    if (ersterAufruf || wert > maximum)
    {
        maximum = wert;
        printf("Neuer Hoechstwert: %d\n", maximum);
    }
    else
    {
        printf("Kein neuer Hoechstwert (bisheriges Maximum: %d)\n", maximum);
    }

    ersterAufruf = 0;
}
