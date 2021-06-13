#include "elevator.h"
#include <stdlib.h>
#include "gc.h"

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
    
}

PersonList* enterElevator(Elevator *e, PersonList *list) {

}

void stepElevator(Building *b) {
    
}