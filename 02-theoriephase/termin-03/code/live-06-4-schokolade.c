#include <stdio.h>
#include <stdlib.h>

int bonusSchokolade(int punkte, int sammelpunkte);

int main(void)
{
    int preis = 0;
    int sammelpunkte = 0;
    int geld = 0;

    printf("Preis pro Packung (ganze Euro): ");
    scanf_s("%d", &preis);
    printf("Sammelpunkte fuer eine Bonus-Packung: ");
    scanf_s("%d", &sammelpunkte);
    printf("Verfuegbares Geld (ganze Euro): ");
    scanf_s("%d", &geld);

    int gekauft = geld / preis;
    int bonus = bonusSchokolade(gekauft, sammelpunkte);

    printf("Gekaufte Packungen: %d\n", gekauft);
    printf("Bonus-Packungen: %d\n", bonus);
    printf("Packungen insgesamt: %d\n", gekauft + bonus);

    system("pause");

    return 0;
}

int bonusSchokolade(int punkte, int sammelpunkte)
{
    if (punkte < sammelpunkte)
        return 0;

    int neueBonusPackungen = punkte / sammelpunkte;
    int restPunkte = punkte % sammelpunkte;

    return neueBonusPackungen + bonusSchokolade(neueBonusPackungen + restPunkte, sammelpunkte);
}
