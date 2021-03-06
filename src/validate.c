#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "priority_queue.h"


/*
 * Validate the given PriorityQueue for structural correctness.
 *
 * In order for this function to return true, the queue passed in must
 * meet the specification in the project handout precisely.  Every node
 * in the linked list and every pointer in the tails table must be
 * correct.
 *
 * pqueue: queue to validate
 *
 * Returns true if the queue is valid, false otherwise.
 */

bool isEmpty(PriorityQueue *pqueue){
    struct PQNode *head = pqueue -> head;
    struct PQNode **tails = pqueue -> tails;
  
    if (head != NULL){
        return false;
    }
  
    for (int entry = 0; entry <= pqueue -> nprios - 1; entry++){
        if (tails[entry] != NULL){
            return false;
        }
    }

    return true;
}

bool sortCheck(PriorityQueue *pqueue){
    struct PQNode *start = pqueue -> head;
    struct PQNode *node = start -> next;

    while(node != NULL){
        int priority = start -> priority;
        int nextPriority = node -> priority;
        if (priority <= nextPriority){
            start = node;
            node = start -> next;
        }
        else {
            return false;
        }
    }
    
    return true;
}

bool priorityCheck(PriorityQueue *pqueue){
    int min = 0;
    int nprios = pqueue -> nprios;
    int max = nprios - 1;

    struct PQNode *currentNode = pqueue -> head;
    struct PQNode *nextNode = currentNode -> next;

    while (nextNode != NULL){
        int priority = currentNode -> priority;
        if (min == max){
            if (priority == min){
                currentNode = nextNode;
                nextNode = currentNode -> next;
            }
            else {
                return false;
            }
        }
        else {
            if (min <= priority && priority <= max){
                currentNode = nextNode;
                nextNode = currentNode -> next;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

bool testHead(PriorityQueue *pqueue){
    struct PQNode *head = pqueue -> head;
    struct PQNode *prev = head -> prev;

    if (prev != NULL){
        return false;
    }

    return true;
}

bool testTail(PriorityQueue *pqueue){
    struct PQNode **tails = pqueue -> tails;
    int nprios = pqueue -> nprios;
    int maxIndex = nprios - 1;

    struct PQNode *finalNode = tails[maxIndex];
    struct PQNode *next = finalNode -> next;

    if (next != NULL){
        return false;
    }

    return true;
}

bool testContinuity(PriorityQueue *pqueue){
    struct PQNode *currentNode = pqueue -> head;
    struct PQNode *nextNode = currentNode -> next;

    while (nextNode != NULL){
        struct PQNode *prev = currentNode -> prev;
        if (prev != NULL){
            struct PQNode *prevToNext = prev -> next;

            if (prevToNext == currentNode){
                currentNode = nextNode;
                nextNode = currentNode -> next;
            }
        }
        else if (prev == NULL){
            nextNode = NULL;
        }
        else {
            return false;
        }
    }

    currentNode = pqueue -> head;
    nextNode = currentNode -> next;
  
    while (nextNode != NULL){
        struct PQNode *nextToPrev = nextNode -> prev;

        if (nextToPrev == currentNode){
            currentNode = nextNode;
            nextNode = currentNode -> next;
        }
        else {
            return false;
        }
    }

    return true;
}

bool lastNode(PQNode **tails, int index){
    PQNode *pointed = tails[index]; /* pointed refers to the node tails[index] points to. */
    int value = pointed -> value;
  
    PQNode *next = pointed -> next;
    int nextValue = 0;

    if (next != NULL){
        nextValue = next -> value;
    }

    if (next != NULL && nextValue == value){
        return false;
    }

    return true;
}

bool entryCheck(PriorityQueue *pqueue){
    struct PQNode **tails = pqueue -> tails;
    int length = pqueue -> nprios;

    for (int entry = 0; entry <= length - 1; entry++){
        if (!lastNode(tails, entry)){
            return false;
        }
    }

    return true;
}

bool pqueue_validate(PriorityQueue *pqueue) {
    if (!sortCheck(pqueue)){
        puts("failed sortCheck");
        return false;
    }
  
    if (!priorityCheck(pqueue)){
        puts("failed priorityCheck");
        return false;
    }

    if (!testHead(pqueue)){
        puts("failed testHead");
        return false;
    }

    if (!testTail(pqueue)){
        puts("failed testTail");
        return false;
    }
  
    if (!testContinuity(pqueue)){
        puts("failed testContinuity");
        return false;
    }

    if (!entryCheck(pqueue)){
        puts("failed entryCheck");
        return false;
    }
  
    return true;
}

/* You have an isEmpty function defined for testing if an empty queue is valid if you need it. */

/* You still need to do the following:
 * Write tests for all of the helper functions*/
