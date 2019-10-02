#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../src/priority_queue.h"

#define NPRIOS 1
#define PRIO   0
#define VALUE  1
#define VALUE2 3
#define VALUE3 5

int main(int argc, char *argv[]){
    PriorityQueue *pqueue = pqueue_init(NPRIOS);
    struct PQNode **tails = pqueue -> tails;

    pqueue_insert(pqueue, VALUE, PRIO); /* Inserts the first node */

    /* Verify that head is the original node */
    if (pqueue -> head -> priority != PRIO || pqueue -> head -> value != VALUE){
        puts("failed 1");
        return 1;
    }

    /* Verify that head and tails[0] are equal */
    if (pqueue->head != pqueue->tails[0]) {
        puts("failed 2");
        return 1;
    }

    pqueue_insert(pqueue, VALUE2, PRIO); /* Inserts the second node */

    /* Verify the second node got added */
    if (tails[0] -> priority != PRIO || tails[0] -> value != VALUE2){
        puts("failed 3");
        return 1;
    }

    /* Verify that the next of head is the new node */
    if (pqueue -> head -> next != tails[0]){
        puts("failed 4");
        return 1;
    }

    /* Verify that the prev of the new node is the head */
    if (tails[0] -> prev != pqueue -> head){
        puts("failed 5");
        return 1;
    }

    struct PQNode *secondNode = tails[0]; /* Creates a value I can use to reference the second node */
    pqueue_insert(pqueue, VALUE3, PRIO); /* Inserts the third node */
    
    /* Verify the third node got added */
    if (tails[0] -> priority != PRIO || tails[0] -> value != VALUE3){
        puts("failed 6");
        return 1;
    }

    /* Verify that the prev of the second node is the head */
    if (secondNode -> prev != pqueue -> head){
        puts("failed 7");
        return 1;
    }

    /* Verify that the next of the second node is the new node */
    if (secondNode -> next != tails[0]){
        puts("failed 8");
        return 1;
    }

    puts("passed");
    return 0;
}
