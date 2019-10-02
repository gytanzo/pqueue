#ifndef VALIDATE_H_
#define VALIDATE_H_

#include <stdbool.h>

bool isEmpty(PriorityQueue *pqueue);
bool sortCheck(PriorityQueue *pqueue);
bool priorityCheck(PriorityQueue *pqueue);
bool testHead(PriorityQueue *pqueue);
bool testTail(PriorityQueue *pqueue);
bool testContinuity(PriorityQueue *pqueue);
bool lastNode(PriorityQueue *pqueue);
bool entryCheck(PriorityQueue *pqueue);
bool pqueue_validate(PriorityQueue *pqueue);

#endif /* VALIDATE_H */
