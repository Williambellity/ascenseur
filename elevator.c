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

    return res;
}


PersonList* exitElevator(Elevator *e) {
    if (e->persons != NULL) {
        PersonList* cursor = e->persons;
        // First node
        if ( cursor->person->dest == e->currentFloor)
        {
            e->persons = delete_start(e->persons); // Changed head    
        } 
        // Others nodes
        while(cursor->next != NULL)
          {
              if(cursor->next->person->dest == e->currentFloor)
              {
                  cursor->next = cursor->next->next;
                  
              }
              else
                  cursor = cursor->next;
          }

    } else {
        return NULL;
    }

}

PersonList* enterElevator(Elevator *e, PersonList *list) {
    int empty_places = e->capacity - len(e->persons);
    int len_waitingList = len(list);
   
    PersonList *newWaitingList = list;

    for (int i = 0; i < len_waitingList && empty_places > 0; i++) {
        
        if (e->persons == NULL) {
            e->persons = createPersonList(newWaitingList->person);
        } else {
            e->persons = insert_start(newWaitingList->person, e->persons);
        }
        newWaitingList = delete_start(newWaitingList);
        empty_places--;

    }
    return newWaitingList;

}

void stepElevator(Building *b) {
    if (b->elevator->targetFloor != b->elevator->currentFloor) {
        b->elevator->currentFloor = b->elevator->targetFloor;
        PersonList* personsOut = NULL;
        
        for (int i = 0; i <= b->elevator->capacity; i++) {
            personsOut = exitElevator(b->elevator);
            b->waitingLists[b->elevator->targetFloor] = enterElevator(b->elevator, b->waitingLists[b->elevator->targetFloor]);
        }
    } 
    
}