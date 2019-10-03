#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../src/priority_queue.h"

#define NPRIOS 2

#define PRIO   0
#define PRIO2  1

#define VALUE1 1
#define VALUE2 2
#define VALUE3 3
#define VALUE4 4
#define VALUE5 5
#define VALUE6 6

/* This test suite is the inverse of the npriosTwo suite */


int main(int argc, char *argv[]){
    PriorityQueue *pqueue = pqueue_init(NPRIOS);
    struct PQNode **tails = pqueue -> tails;

    pqueue_insert(pqueue, VALUE1, PRIO2); /* Inserts the first node */
    struct PQNode *nodeOne = tails[PRIO2];

    /* Verify that head is the original node */
    if (pqueue -> head != nodeOne){
        puts("failed 1");
        return 1;
    }
    
    /* Verify that head and tails[0] are equal */
    if (pqueue -> head != pqueue->tails[PRIO2]) {
        puts("failed 2");
        return 1;
    }

    pqueue_insert(pqueue, VALUE2, PRIO2); /* Inserts the second node */
    struct PQNode *nodeTwo = tails[PRIO2];

    /* Verify that the head is still the original node */
    if (pqueue -> head != nodeOne){
        puts("failed 3");
        return 1;
    }

    /* Verify that the next of node one is node two */
    if (nodeOne -> next != nodeTwo){
        puts("failed 4");
        return 1;
    }

    /* Verify that the prev of node two is node one */
    if (nodeTwo -> prev != nodeOne){
        puts("failed 5");
        return 1;
    }

    /* Verify that the prev of node one is still NULL */
    if (nodeOne -> prev != NULL){
        puts("failed 6");
        return 1;
    }

    pqueue_insert(pqueue, VALUE3, PRIO2); /* Inserts the third node */
    struct PQNode *nodeThree = tails[PRIO2];

    /* Verify that the head is still the original node */
    if (pqueue -> head != nodeOne){
        puts("failed 7");
        return 1;
    }

    /* Verify node one */
    if ((nodeOne -> prev != NULL) && (nodeOne -> next != nodeTwo)){
        puts("failed 8");
        return 1;
    }

    /* Verify node two */
    if ((nodeTwo -> prev != nodeOne) && (nodeTwo -> next != nodeThree)){
        puts("failed 9");
        return 1;
    }

    /* Verify node three */
    if ((nodeThree -> prev != nodeTwo) && (nodeThree -> next != NULL)){
        puts("failed 10");
        return 1;
    }

    pqueue_insert(pqueue, VALUE4, PRIO); /* Inserts the fourth node */
    struct PQNode *nodeFour = tails[PRIO];
    
    /* Verify node four */
    if ((pqueue -> head != nodeFour) && (nodeFour -> prev != NULL) && (nodeFour -> next != nodeOne)){
        puts("failed 11");
        return 1;
    }

    /* Verify node one */
    if ((nodeOne -> prev != nodeFour) && (nodeOne -> next != nodeTwo)){
        puts("failed 12");
        return 1;
    }

    /* Verify node two */
    if ((nodeTwo -> prev != nodeOne) && (nodeTwo -> next != nodeThree)){
        puts("failed 13");
        return 1;
    }

    /* Verify node three */
    if ((nodeThree -> prev != nodeTwo) && (nodeThree -> next != NULL)){
        puts("failed 14");
        return 1;
    }

    pqueue_insert(pqueue, VALUE5, PRIO); /* Inserts the fifth node */
    struct PQNode *nodeFive = tails[PRIO];

    /* Verify node four */
    if ((pqueue -> head != nodeFour) && (nodeFour -> prev != NULL) && (nodeFour -> next != nodeOne)){
        puts("failed 15");
        return 1;
    }

    /* Verify node five */
    if ((nodeFive -> prev != nodeFour) && (nodeFive -> next != nodeOne)){
        puts("failed 16");
        return 1;
    }

    /* Verify node one */
    if ((nodeOne -> prev != nodeFive) && (nodeOne -> next != nodeTwo)){
        puts("failed 17");
        return 1;
    }

    /* Verify node two */
    if ((nodeTwo -> prev != nodeOne) && (nodeTwo -> next != nodeThree)){
        puts("failed 18");
        return 1;
    }
    
    /* Verify node three */
    if ((nodeThree -> prev != nodeTwo) && (nodeThree -> next != NULL)){
        puts("failed 19");
        return 1;
    }
    
    puts("passed");
    return 0;
}
