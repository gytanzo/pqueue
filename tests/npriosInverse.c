#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../src/priority_queue.h"

#define NPRIOS 4

#define PRIO   0
#define PRIO2  1
#define PRIO3  2
#define PRIO4  3

#define VALUE1 1
#define VALUE2 2
#define VALUE3 3
#define VALUE4 4
#define VALUE5 5
#define VALUE6 6
#define VALUE7 7
#define VALUE8 8

bool test(PriorityQueue *pqueue, PQNode *left, PQNode *center, PQNode *right, int priority, int value){
    if (center -> next != right){
        return false;
    }

    if (center -> prev != left){
        return false;
    }

    if (center -> priority != priority){
        return false;
    }

    if (center -> value != value){
        return false;
    }
    return true;
}

int main(int argc, char *argv[]){
    PriorityQueue *pqueue = pqueue_init(NPRIOS);

    pqueue_insert(pqueue, VALUE8, PRIO4); /* nodeTwo */

    pqueue_insert(pqueue, VALUE7, PRIO4); /* nodeThree */

    pqueue_insert(pqueue, VALUE6, PRIO3); /* nodeOne */

    struct PQNode *nodeOne = pqueue -> head;
    struct PQNode *nodeTwo = nodeOne -> next;
    struct PQNode *nodeThree = nodeTwo -> next;
    
    if (!test(pqueue, NULL, nodeOne, nodeTwo, PRIO3, VALUE6)){
        puts("failed 1");
        return 1;
    }

    if (!test(pqueue, nodeOne, nodeTwo, nodeThree, PRIO4, VALUE8)){
        puts("failed 2");
        return 1;
    }


    if (!test(pqueue, nodeTwo, nodeThree, NULL, PRIO4, VALUE7)){
        puts("failed 3");
        return 1;
    }

    /* Validate */
    if (!pqueue_validate(pqueue)){
        puts("failed 4");
        return 1;
    }
    
    puts("passed");
    return 0;
}
