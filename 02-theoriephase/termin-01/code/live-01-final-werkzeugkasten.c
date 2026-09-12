// Werkzeugkasten fuer Ein- und Ausgabe in C
// Fasst die Bausteine dieser Einheit in einem Programm zusammen.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("chcp 1252"); // Codepage fuer korrekte Umlaute in der Ausgabe

    printf("Willkommen im GdI-Werkzeugkasten!\n\n");

    int zahl = 0;
    printf("Gib eine ganze Zahl ein: ");
    scanf_s("%d", &zahl);
    printf("Dezimal: %d | Oktal: %o | Hexadezimal: %x\n\n", zahl, zahl, zahl);

    char zeichen = '\0';
    printf("Gib ein einzelnes Zeichen ein: ");
    scanf_s("%c", &zeichen, 1);
    printf("Zeichen: %c | ASCII-Code: %d\n\n", zeichen, zeichen);

    printf("\x1b[32mFertig! Druecke eine Taste zum Beenden.\x1b[0m\n");
    system("pause");

    return 0;
}
