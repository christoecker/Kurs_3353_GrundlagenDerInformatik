#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("chcp 1252"); // Codepage fuer korrekte Umlaute in der Ausgabe

    char anfangsbuchstabe = '\0';
    int alter = 0;

    // Reihenfolge ist wichtig: erst das Zeichen, dann die Zahl einlesen
    printf("Anfangsbuchstabe deines Vornamens: ");
    scanf_s("%c", &anfangsbuchstabe, 1);

    printf("Dein Alter: ");
    scanf_s("%d", &alter);

    printf("\nHallo, %c! Mit %d Jahren startest du dein Studium in ", anfangsbuchstabe, alter);
    printf("Mechatronik/Automatisierung - wir wünschen dir viel Erfolg und Freude beim ");
    printf("Programmieren-Lernen, auch wenn's am Anfang größere Mühe kostet!\n");

    system("pause"); // Fenster offen halten, bis eine Taste gedrueckt wird

    return 0;
}
