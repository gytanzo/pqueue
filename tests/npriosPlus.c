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

    pqueue_insert(pqueue, VALUE1, PRIO);

    pqueue_insert(pqueue, VALUE2, PRIO);

    pqueue_insert(pqueue, VALUE3, PRIO2);

    pqueue_insert(pqueue, VALUE4, PRIO2);

    pqueue_insert(pqueue, VALUE5, PRIO3);
    
    pqueue_insert(pqueue, VALUE6, PRIO3);
    
    pqueue_insert(pqueue, VALUE7, PRIO4);

    pqueue_insert(pqueue, VALUE8, PRIO4);

    struct PQNode *nodeOne = pqueue -> head;
    struct PQNode *nodeTwo = nodeOne -> next;
    struct PQNode *nodeThree = nodeTwo -> next;
    struct PQNode *nodeFour = nodeThree -> next;
    struct PQNode *nodeFive = nodeFour -> next;
    struct PQNode *nodeSix = nodeFive -> next;
    struct PQNode *nodeSeven = nodeSix -> next;
    struct PQNode *nodeEight = nodeSeven -> next;

    if (!test(pqueue, NULL, nodeOne, nodeTwo, PRIO, VALUE1)){
        puts("failed 1");
        return 1;
    }

    if (!test(pqueue, nodeOne, nodeTwo, nodeThree, PRIO, VALUE2)){
        puts("failed 2");
        return 1;
    }

    if (!test(pqueue, nodeTwo, nodeThree, nodeFour, PRIO2, VALUE3)){
        puts("failed 3");
        return 1;
    }

    if (!test(pqueue, nodeThree, nodeFour, nodeFive, PRIO2, VALUE4)){
        puts("failed 4");
        return 1;
    }

    if (!test(pqueue, nodeFour, nodeFive, nodeSix, PRIO3, VALUE5)){
        puts("failed 5");
        return 1;
    }

    if (!test(pqueue, nodeFive, nodeSix, nodeSeven, PRIO3, VALUE6)){
        puts("failed 6");
        return 1;
    }

    if (!test(pqueue, nodeSix, nodeSeven, nodeEight, PRIO4, VALUE7)){
        puts("failed 7");
        return 1;
    }

    if (!test(pqueue, nodeSeven, nodeEight, NULL, PRIO4, VALUE8)){
        puts("failed 8");
        return 1;
    }


    puts("passed");
    return 0;
}
