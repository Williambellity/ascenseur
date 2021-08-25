#include "elevator.h"
#include <stdlib.h>
#include "gc.h"
#include <stdio.h>

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons) {
    Elevator *res = MALLOC(sizeof(res));

    res->capacity = capacity;
    res->currentFloor = currentFloor;
    res->persons = persons;

    return res;
}

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists) {
    Building *res = MALLOC(sizeof(res));

    res->nbFloor = nbFloor;
    res->elevator = elevator;
    res->waitingLists = waitingLists;
}


PersonList* exitElevator(Elevator *e) {
    if (e->persons != NULL) {
    PersonList *cursor = e->persons;
    for (int i = 0; i < e->capacity; i++) {
        if (cursor->person->dest == e->currentFloor)
        {
            cursor = delete_start(cursor);
        } else {
            cursor = cursor->next;
        }
    }
    }
    return e->persons;

}

PersonList* enterElevator(Elevator *e, PersonList *list) {
    printf("test1");
    int empty_places = len(e->persons);
    printf("test2");
    int len_waitingList = len(list);
    printf("test3");
    PersonList *cursor = list;
    printf("test4");

    for (int i = 0; i < len_waitingList && empty_places > 0; i++) {
        printf("test5");
        e->persons = insert_start(cursor->person, e->persons);
        empty_places--;
        cursor = delete_start(cursor);
    }

    return list;

}

void stepElevator(Building *b) {
    if (b->elevator->targetFloor != b->elevator->currentFloor) {
        b->elevator->currentFloor = b->elevator->targetFloor;
        b->elevator->persons = exitElevator(b->elevator);
        printf("test4");
        b->elevator->persons = enterElevator(b->elevator, b->waitingLists[0]);
    }
    




    
}