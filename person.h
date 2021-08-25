#ifndef PERSON_H
#define PERSON_H

typedef struct _Person {
    int src;
    int dest;
} Person;

typedef struct _PersonList {
    Person *person;
    struct _PersonList *next;
} PersonList;

Person* createPerson(int src, int dest);
void printPerson(Person* p);

PersonList* createPersonList(Person *p);
void printPersonList(PersonList* list);
PersonList* insert_start(Person *p, PersonList *list);
PersonList* insert_end(Person *p, PersonList *list);
PersonList* delete_start(PersonList* list);
PersonList* delete_end(PersonList* list);
int len(PersonList *list);

#endif