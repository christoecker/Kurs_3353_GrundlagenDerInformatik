#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int temperatur = 21;
    int meldung = 0;

    if (temperatur > 20)
    {
        meldung = 1;
        printf("Warnung ausgeloest.\n");
    }

    printf("Meldung: %d\n", meldung);

    system("pause");

    return 0;
}
