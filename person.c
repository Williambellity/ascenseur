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
    if (list != NULL ) {
        while (list->next != NULL) {
            printPerson(list->person);
            printf(", ");
            list = list->next;
        }
        printPerson(list->person);
    } 
    printf("]");
}

PersonList* insert_start(Person *p, PersonList *list) {

    PersonList *new_list = MALLOC(sizeof(PersonList));
    new_list->person = p;
    new_list->next = list;
    
    return new_list;
}

PersonList* insert_end(Person *p, PersonList *list) {

   
    PersonList *cursor = list;
    PersonList *new_node = MALLOC(sizeof(Person));
    new_node->person = p;
    new_node->next = NULL;
    if (list == NULL) {
        list = new_node;
    } else {
        while (cursor->next != NULL) {
            cursor = cursor->next;
        }
        cursor->next = new_node;
    }
    return list;
}

int len(PersonList *list) {
    if (list == NULL) {
        PersonList *cursor = list;
        int res = 0;
        while (cursor->next != NULL) {
            res++;
            cursor = cursor->next;
        }
        res++;
        return res;
    } 
    return 0;
}

PersonList *delete_start(PersonList* list) {
    return list->next;
}

PersonList *delete_end(PersonList* list) {
    PersonList *cursor = list;
    if (cursor->next != NULL) {
    
        while (cursor->next->next != NULL) {
            cursor = cursor->next;
        }
        cursor->next = NULL;
        return list;
    }
    else {
        free(list);
        return NULL;
    }
}
