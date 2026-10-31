#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int temperatur = 21;

    if (temperatur > 20)
    {
        int meldung = 1;
        printf("Warnung ausgeloest.\n");
    }

    printf("Meldung: %d\n", meldung);

    system("pause");

    return 0;
}
