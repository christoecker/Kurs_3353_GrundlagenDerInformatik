#include <stdio.h>
#include <stdlib.h>

#define MAX_PARTNER 3

typedef struct Student Student;

struct Student
{
    char name[20];
    Student *partner[MAX_PARTNER]; // bis zu drei Lernpartner
    int anzahlPartner;
};

int partnerHinzufuegen(Student *s, Student *neu);
int lerngruppeBilden(Student *a, Student *b);
void partnerAusgeben(const Student *s);

int main(void)
{
    Student anna = { "Anna", { NULL }, 0 };
    Student ben = { "Ben", { NULL }, 0 };
    Student chris = { "Chris", { NULL }, 0 };
    Student dora = { "Dora", { NULL }, 0 };
    Student emil = { "Emil", { NULL }, 0 };

    lerngruppeBilden(&anna, &ben);
    lerngruppeBilden(&anna, &chris);
    lerngruppeBilden(&anna, &dora);
    lerngruppeBilden(&ben, &chris);

    printf("Anna und Emil: %s\n", lerngruppeBilden(&anna, &emil) ? "gebildet" : "nicht moeglich");
    printf("Anna und Ben erneut: %s\n", lerngruppeBilden(&anna, &ben) ? "gebildet" : "nicht moeglich");

    partnerAusgeben(&anna);
    partnerAusgeben(&ben);
    partnerAusgeben(&chris);
    partnerAusgeben(&dora);
    partnerAusgeben(&emil);

    system("pause");

    return 0;
}

int partnerHinzufuegen(Student *s, Student *neu)
{
    // TODO: neu bei s eintragen und 1 zurueckgeben. Ist s schon voll, neu schon
    //       eingetragen oder s gleich neu, nichts eintragen und 0 zurueckgeben.
    return 0;
}

int lerngruppeBilden(Student *a, Student *b)
{
    // TODO: a und b gegenseitig eintragen und 1 zurueckgeben. Ist das nicht
    //       moeglich (einer ist voll oder sie sind schon verbunden), darf
    //       keiner von beiden veraendert werden. Dann 0 zurueckgeben.
    return 0;
}

void partnerAusgeben(const Student *s)
{
    // TODO: "<Name> lernt mit: <Partner 1> <Partner 2> ..." ausgeben, oder
    //       "<Name> hat noch keine Partner.", falls es keinen gibt.
}
