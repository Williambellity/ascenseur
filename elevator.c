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
    // int empty_places = len(e->persons);
    // int len_waitingList = len(list);
   
    PersonList *newWaitingList = list;

    // for (int i = 0; i < len_waitingList && empty_places > 0; i++) {
    //     e->persons = insert_start(cursor->person, e->persons);
    //     cursor = cursor->next;
    //     empty_places--;
    //     cursor = delete_start(cursor);
    // }
    e->persons->person = newWaitingList->person;

    newWaitingList = delete_start(newWaitingList);
    
   

    return newWaitingList;

}

void stepElevator(Building *b) {
    if (b->elevator->targetFloor != b->elevator->currentFloor) {
        b->elevator->currentFloor = b->elevator->targetFloor;
        // b->elevator->persons = exitElevator(b->elevator);
        b->waitingLists[b->elevator->targetFloor] = enterElevator(b->elevator, b->waitingLists[b->elevator->targetFloor]);
    } 
    




    
}