#include <stdio.h>

int main(void)
{
    int sekunden = 0;

    printf("Anzahl Sekunden: ");
    scanf_s("%d", &sekunden);

    int stunden = sekunden / 3600;
    int rest = sekunden % 3600;
    int minuten = rest / 60;
    int restsekunden = rest % 60;

    printf("%d Sekunden sind %d:%02d:%02d (hh:mm:ss)\n", sekunden, stunden, minuten, restsekunden);

    return 0;
}
