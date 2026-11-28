#include <stdio.h>
#include <stdlib.h>

typedef struct Student Student;

struct Student
{
    char name[20];
    Student *partner; // Lernpartner, NULL = noch keiner
};

void lerngruppeBilden(Student *a, Student *b);
void partnerAusgeben(const Student *s);

int main(void)
{
    Student anna = { "Anna", NULL };
    Student ben = { "Ben", NULL };
    Student chris = { "Chris", NULL };

    partnerAusgeben(&anna);

    lerngruppeBilden(&anna, &ben);

    partnerAusgeben(&anna);
    partnerAusgeben(&ben);
    partnerAusgeben(&chris);

    system("pause");

    return 0;
}

void lerngruppeBilden(Student *a, Student *b)
{
    // TODO: Beide Studierende sollen sich gegenseitig als Partner eintragen.
}

void partnerAusgeben(const Student *s)
{
    // TODO: "<Name> lernt mit <Name des Partners>." ausgeben, oder
    //       "<Name> hat noch keinen Partner.", falls partner gleich NULL ist.
}
