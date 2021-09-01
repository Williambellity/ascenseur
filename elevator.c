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
        PersonList* cursor = e->persons;
       
        if ( cursor->person->dest == e->currentFloor)
        {
            e->persons = delete_start(e->persons); // Changed head    
        } 
        while(cursor->next != NULL)
          {
              //if yes, we need to delete the cursor->next node
              if(cursor->next->person->dest == e->currentFloor)
              {
                  //node will be disconnected from the linked list.
                  cursor->next = cursor->next->next;
                  
              }
              //Otherwise, move the cursor node and proceed
              else
                  cursor = cursor->next;
          }

        
        // if ( cursor->person->dest == e->currentFloor)
        // {
        //     e->persons = delete_end(e->persons); // Changed head    
        // }
        // PersonList* prev = NULL;
    
        
        
        // while (cursor != NULL && cursor->person->dest != e->currentFloor)
        // {
        //     prev = cursor;
        //     cursor = cursor->next;
        // }
 
        // // If key was not present in linked list
        // if (cursor == NULL)
        //     return;
 
        // // Unlink the node from linked list
        // prev->next = cursor->next;
 
    
    
        

        // e->persons = delete_start(e->persons);
        
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