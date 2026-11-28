#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int zustand = 0;

    printf("Betriebszustand eingeben (0-3, -1 zum Beenden): ");
    scanf_s("%d", &zustand);

    while (zustand != -1)
    {
        switch (zustand)
        {
            case 0:
                printf("Aus\n");
                break;
            case 1:
                printf("Standby\n");
                break;
            case 2:
                printf("Laeuft\n");
                break;
            case 3:
                printf("Fehler\n");
                break;
            default:
                printf("Unbekannter Zustand\n");
                break;
        }

        printf("Naechster Betriebszustand eingeben (0-3, -1 zum Beenden): ");
        scanf_s("%d", &zustand);
    }

    printf("Programm beendet.\n");

    system("pause");

    return 0;
}
