#include <stdio.h>

int main(void)
{
    int fehlercode = 0;

    printf("Fehlercode eingeben (0 = Kein Fehler, 1 = Ueberhitzung, 2 = Kabelbruch, 3 = Kurzschluss): ");
    scanf_s("%d", &fehlercode);

    switch (fehlercode)
    {
        case 0:
            printf("Kein Fehler\n");
            break;
        case 1:
            printf("Ueberhitzung\n");
            break;
        case 2:
            printf("Kabelbruch\n");
            break;
        case 3:
            printf("Kurzschluss\n");
            break;
        default:
            // Unbekannte Fehlercodes sollen auffallen statt stumm ignoriert
            // zu werden - deshalb ein eigener Fall dafuer.
            printf("Unbekannter Fehlercode\n");
            break;
    }

    return 0;
}
