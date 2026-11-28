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
    Student dora = { "Dora", NULL };

    lerngruppeBilden(&anna, &ben);
    printf("Anna und Ben bilden eine Lerngruppe:\n");
    partnerAusgeben(&anna);
    partnerAusgeben(&ben);

    lerngruppeBilden(&anna, &chris);
    printf("\nAnna wechselt zu Chris:\n");
    partnerAusgeben(&anna);
    partnerAusgeben(&ben);
    partnerAusgeben(&chris);

    lerngruppeBilden(&ben, &dora);
    lerngruppeBilden(&chris, &dora);
    printf("\nBen geht zu Dora, dann wechselt Dora zu Chris:\n");
    partnerAusgeben(&anna);
    partnerAusgeben(&ben);
    partnerAusgeben(&chris);
    partnerAusgeben(&dora);

    system("pause");

    return 0;
}

void lerngruppeBilden(Student *a, Student *b)
{
    if (a->partner != NULL)
        a->partner->partner = NULL; // (1)!
    if (b->partner != NULL)
        b->partner->partner = NULL; // (2)!

    a->partner = b;
    b->partner = a;
}

void partnerAusgeben(const Student *s)
{
    if (s->partner == NULL)
        printf("%s hat noch keinen Partner.\n", s->name);
    else
        printf("%s lernt mit %s.\n", s->name, s->partner->name);
}
