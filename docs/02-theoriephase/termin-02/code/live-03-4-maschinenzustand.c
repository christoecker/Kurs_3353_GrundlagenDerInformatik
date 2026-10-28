#include <stdio.h>

int main(void)
{
    int zustand = 0;

    printf("Betriebszustand eingeben (0 = Aus, 1 = Standby, 2 = Laeuft, 3 = Fehler): ");
    scanf_s("%d", &zustand);

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
            // Ohne diesen Fall wuerde eine ungueltige Eingabe (z. B. 9)
            // einfach stillschweigend nichts ausgeben - der Default-Fall
            // macht stattdessen sichtbar, dass die Eingabe nicht zu einem
            // der vorgesehenen Zustaende passt.
            printf("Unbekannter Zustand\n");
            break;
    }

    return 0;
}
