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
    a->partner = b; // (1)!
    b->partner = a;
}

void partnerAusgeben(const Student *s)
{
    if (s->partner == NULL) // (2)!
        printf("%s hat noch keinen Partner.\n", s->name);
    else
        printf("%s lernt mit %s.\n", s->name, s->partner->name); // (3)!
}
