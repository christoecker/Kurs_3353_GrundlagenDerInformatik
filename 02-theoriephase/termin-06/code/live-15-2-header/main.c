#include <stdio.h>
#include <stdlib.h>
#include "myUtil.h"

#define ANZAHL 5

int main(void)
{
    int messwerte[ANZAHL] = { 12, 15, 9, 20, 17 };

    arrayAusgeben(messwerte, ANZAHL);

    system("pause");

    return 0;
}
