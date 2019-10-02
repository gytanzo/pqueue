#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../src/priority_queue.h"
#include "../src/validate.h"

int main(int argc, char *argv[]){
    struct PriorityQueue *pqueue = pqueue_init(1);
    if (!isEmpty(pqueue)){
        puts("failed");
        return 1;
    }
    puts("passed");
    return 0;
}
