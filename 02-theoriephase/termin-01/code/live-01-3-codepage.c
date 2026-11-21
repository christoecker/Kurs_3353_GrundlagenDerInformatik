#include <stdio.h>
#include <windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8); // Ausgabe
    SetConsoleCP(CP_UTF8);       // Eingabe (falls scanf genutzt wird)

    printf("Willkommen im GdI-Kurs - wir wuenschen euch viel Erfolg beim Programmieren!\n");
    printf("Ihr koennt jetzt auch Umlaute wie ae, oe, ue korrekt darstellen - probiert es aus: Bäume, Übung, Größe.\n");

    return 0;
}
