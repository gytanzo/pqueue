#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "priority_queue.h"

/*
 * Create a new PriorityQueue structure and return it.
 *
 * The newly-created structure should have a NULL head, and every tail
 * pointer in its tails table should be NULL.
 *
 * nprios: The maximum number of priorities to support
 */

PriorityQueue *pqueue_init(int nprios) {
    struct PQNode **tails = (PQNode**) calloc(nprios, sizeof(PQNode*));
    struct PQNode *head = (PQNode*) calloc(1, sizeof(PQNode*));
    struct PriorityQueue *pqueue = (PriorityQueue*) calloc(1, sizeof(PriorityQueue*));
    int npriosArg;

    head = NULL;
  
    if (nprios <= 0) {
        free(tails);
        free(head);
        free(pqueue);
        return NULL;
    }
    else {
        npriosArg = nprios;
    }
  
    pqueue -> head = head;
    pqueue -> tails = tails;
    pqueue -> nprios = npriosArg;
  
    return pqueue;
}

/*
 * Free all structures associated with this priority queue, including their
 * queue structure itself.  Any access to pqueue after this function returns
 * should be considered invalid.
 *
 * pqueue: the queue to free
 */
void pqueue_free(PriorityQueue *pqueue) {
}

/*
 * Insert a new node into a queue by priority and value.
 *
 * pqueue: the queue into which the new node should be inserted
 * value: the opaque value being inserted into the queue
 * priority: the priority at which this value is to be inserted
 */

void pqueue_insert(PriorityQueue *pqueue, int value, int priority) {
    struct PQNode *node = (PQNode*) calloc(1, sizeof(PQNode));
    struct PQNode **tails = pqueue -> tails;
    struct PQNode *head = pqueue -> head;
    int nprios = pqueue -> nprios;
    
    node -> value = value;
    node -> priority = priority;

    if (nprios == 1){
        if (tails[0] == NULL){
            node -> prev = NULL;
            node -> next = NULL;
        }
        else {
            node -> prev = tails[0];
            tails[0] -> next = node;
        }
        
        tails[0] = node;
    }

    else if (nprios == 2){
        if (priority == 0 && tails[0] == NULL && tails[1] == NULL){
            node -> prev = NULL;
            node -> next = NULL;
        }
        else if (priority == 0 && tails[0] == NULL && tails[1] != NULL){
            node -> prev = NULL;
            node -> next = tails[1];
            pqueue -> head = node;
        }
        else if (priority == 0 && tails[0] != NULL && tails[1] == NULL){
            node -> prev = tails[0];
            tails[0] -> next = node;
            node -> next = NULL;
        }
        else if (priority == 0 && tails[0] != NULL && tails[1] != NULL){
            node -> prev = tails[0];
            tails[0] -> next = node;
            node -> next = tails[1];
            tails[1] -> prev = node;
        }
        else if (priority == 1 && tails[1] == NULL && tails[0] == NULL){
            node -> next = NULL;
            node -> prev = NULL;
        }
        else if (priority == 1 && tails[1] == NULL && tails[0] != NULL){
            node -> prev = tails[0];
            node -> next = NULL;
            tails[0] -> next = node;
        }
        else if (priority == 1 && tails[1] != NULL && tails[0] == NULL){
            node -> prev = tails[1];
            tails[1] -> next = node;
            node -> next = NULL;
        }
        else if (priority == 1 && tails[1] != NULL && tails[0] != NULL){
            node -> prev = tails[1];
            node -> next = NULL;
        }
        tails[priority] = node;
    }

    if (head == NULL){
        pqueue -> head = node;
    }
}

/*
 * Return the head queue node without removing it.
 */
PQNode *pqueue_peek(PriorityQueue *pqueue) {
    return NULL;
}

/*
 * Remove and return the head queue node.
 */
PQNode *pqueue_get(PriorityQueue *pqueue) {
    return NULL;
}
