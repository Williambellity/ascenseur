#include "person.h"
#include <stdlib.h>
#include <stdio.h>
#include "gc.h"

Person* createPerson(int src, int dest) {
    Person* res = MALLOC(sizeof(Person));

    res->src = src;
    res->dest = dest;

    return res;
}

void printPerson(Person *p){
    printf("%i%i", p->src, p->dest);
}

PersonList* createPersonList(Person* p) {
    PersonList* res = MALLOC(sizeof(PersonList));

    res->person = p;
    res->next = NULL;

    return res;
}


void printPersonList(PersonList* list) {
    printf("[");
    while (list->next != NULL) {
        printPerson(list->person);
        printf(", ");
        list = list->next;
    }
    printPerson(list->person);
    printf("]");
}

PersonList* insert(Person *p, PersonList *list) {

    PersonList *new_list = MALLOC(sizeof(PersonList));
    new_list->person = p;
    new_list->next = list;

    return new_list;
}

int len(PersonList *list) {
    PersonList *cursor = list;
    int res = 0;
    while (cursor->next != NULL) {
        res++;
        cursor = cursor->next;
    }
    res++;
    return res;
}

PersonList *delete(Person *p, PersonList* list) {
    if (list->person == p) {
        return 
    }
    return insert(list->person, delete(p, list->next))

}
