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
    if (s == neu || s->anzahlPartner >= MAX_PARTNER) // (1)!
        return 0;

    for (int i = 0; i < s->anzahlPartner; i++)
        if (s->partner[i] == neu) // (2)!
            return 0;

    s->partner[s->anzahlPartner] = neu; // (3)!
    s->anzahlPartner++;

    return 1;
}

int lerngruppeBilden(Student *a, Student *b)
{
    if (a->anzahlPartner >= MAX_PARTNER || b->anzahlPartner >= MAX_PARTNER) // (4)!
        return 0;

    if (partnerHinzufuegen(a, b) == 0)
        return 0;

    partnerHinzufuegen(b, a);

    return 1;
}

void partnerAusgeben(const Student *s)
{
    if (s->anzahlPartner == 0)
    {
        printf("%s hat noch keine Partner.\n", s->name);
        return;
    }

    printf("%s lernt mit:", s->name);
    for (int i = 0; i < s->anzahlPartner; i++)
        printf(" %s", s->partner[i]->name); // (5)!
    printf("\n");
}
