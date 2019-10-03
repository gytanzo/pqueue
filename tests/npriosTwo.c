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

int main(int argc, char *argv[]){
    PriorityQueue *pqueue = pqueue_init(NPRIOS);
    struct PQNode **tails = pqueue -> tails;

    pqueue_insert(pqueue, VALUE1, PRIO); /* Inserts the first node */
    struct PQNode *nodeOne = tails[PRIO];

    /* Verify that head is the original node */
    if (pqueue -> head != nodeOne){
        puts("failed 1");
        return 1;
    }
    
    /* Verify that head and tails[0] are equal */
    if (pqueue -> head != pqueue->tails[0]) {
        puts("failed 2");
        return 1;
    }

    pqueue_insert(pqueue, VALUE2, PRIO); /* Inserts the second node */
    struct PQNode *nodeTwo = tails[PRIO];

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

    pqueue_insert(pqueue, VALUE3, PRIO); /* Inserts the third node */
    struct PQNode *nodeThree = tails[PRIO];

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

    pqueue_insert(pqueue, VALUE4, PRIO2); /* Inserts the fourth node */
    struct PQNode *nodeFour = tails[PRIO2];

    /* Verify node one */
    if ((nodeOne != pqueue -> head) && (nodeOne -> prev != NULL) && (nodeOne -> next != nodeTwo)){
        puts("failed 11");
        return 1;
    }

    /* Verify node two */
    if ((nodeTwo -> prev != nodeOne) && (nodeTwo -> next != nodeThree)){
        puts("failed 12");
        return 1;
    }

    /* Verify node three */
    if ((nodeThree -> prev != nodeTwo) && (nodeThree -> next != nodeFour)){
        puts("failed 13");
        return 1;
    }

    /* Verify node four */
    if ((nodeFour -> prev != nodeThree) && (nodeFour -> next != NULL)){
        puts("failed 14");
        return 1;
    }

    pqueue_insert(pqueue, VALUE5, PRIO2); /* Inserts the fifth node */
    struct PQNode *nodeFive = tails[PRIO2];

    /* Verify node one */
    if ((nodeOne != pqueue -> head) && (nodeOne -> prev != NULL) && (nodeOne -> next != nodeTwo)){
        puts("failed 15");
        return 1;
    }

    /* Verify node two */
    if ((nodeTwo -> prev != nodeOne) && (nodeTwo -> next != nodeThree)){
        puts("failed 16");
        return 1;
    }

    /* Verify node three */
    if ((nodeThree -> prev != nodeTwo) && (nodeThree -> next != nodeFour)){
        puts("failed 17");
        return 1;
    }

    /* Verify node four */
    if ((nodeFour -> prev != nodeThree) && (nodeFour -> next != nodeFive)){
        puts("failed 18");
        return 1;
    }

    /* Veirfy node five */
    if ((nodeFive -> prev != nodeFour) && (nodeFive -> next != NULL)){
        puts("failed 19");
        return 1;
    }

    puts("passed");
    return 0;
}
