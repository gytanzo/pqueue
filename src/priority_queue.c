#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "priority_queue.h"
#include "validate.h"

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

int neighbor(PQNode **tails, PQNode *node, PriorityQueue *pqueue, int status){
    int nprios = pqueue -> nprios;
    int length = nprios - 1;
    int priority = node -> priority;
    if (status == -1){
        for (int entry = priority - 1; entry >= 0; entry--){
            if (tails[entry] != NULL){
                return entry;
            }
            else {
                ;
            }
        }
    }
    if (status == 1){
        for (int entry = priority + 1; entry <= length; entry++){
            if (tails[entry] != NULL){
                return entry;
            }
            else {
                ;
            }
        }
    }
    return -1;
}

void pqueue_insert(PriorityQueue *pqueue, int value, int priority) {
    struct PQNode *node = (PQNode*) calloc(1, sizeof(PQNode));
    struct PQNode **tails = pqueue -> tails;
    struct PQNode *head = pqueue -> head;
    
    node -> value = value;
    node -> priority = priority;

    int prevArr = neighbor(tails, node, pqueue, -1);
    int nextArr = neighbor(tails, node, pqueue, 1);
    if (prevArr == -1 && nextArr == -1){
        node -> next = NULL;
        if (tails[priority] == NULL){
            node -> prev = NULL;
            pqueue -> head = node;
        }
        else {
            node -> prev = tails[priority];
            tails[priority] -> next = node;
        }
    }
    else if (prevArr != -1 && nextArr == -1){
        node -> next = NULL;
        if (tails[priority] == NULL){
            node -> prev = tails[prevArr];
            tails[prevArr] -> next = node;
        }
        else {
            node -> prev = tails[priority];
            tails[priority] -> next = node;
        }
    }
    else if (prevArr == -1 && nextArr != -1){
        if (tails[priority] == NULL){
            node -> prev = NULL;
            pqueue -> head = node;
        }
        else {
            node -> prev = tails[priority];
            tails[priority] -> next = node;
        }
        
        if (tails[nextArr] -> prev != NULL && tails[nextArr] -> prev -> priority == nextArr){
            node -> next = tails[nextArr] -> prev;
            tails[nextArr] -> prev -> prev = node;
        }
        else {
            node -> next = tails[nextArr];
            tails[nextArr] -> prev = node;
        }
    }
    else {
        if (tails[priority] == NULL){
            node -> prev = tails[prevArr];
            tails[prevArr] -> next = node;
        }
        else {
            node -> prev = tails[priority];
            tails[priority] -> next = node;
        }
        node -> next = tails[nextArr];
        tails[nextArr] -> prev = node;
    }
    tails[priority] = node;

    if (head == NULL){
        pqueue -> head = node;
    }
}

/*
 * Return the head queue node without removing it.
 */
PQNode *pqueue_peek(PriorityQueue *pqueue) {
    struct PQNode *head = pqueue -> head;
    return head;
}

/*
 * Remove and return the head queue node.
 */
PQNode *pqueue_get(PriorityQueue *pqueue) {
    struct PQNode *head = pqueue -> head;
    struct PQNode *newHead = pqueue -> head -> next;
    if (isEmpty(pqueue)){
        return NULL;
    }

    pqueue -> head = newHead;
    pqueue -> head -> prev = NULL;
    return head;
}
