#include <stdio.h>
#include "DynArrayQueue.h"

int main(){
    struct DynArrayQueue *Q = CreateQueue();
    int i;
    for(i=0; i<5; i++){
        EnQueue(Q, i+5);
    }
    for(i=0; i<5; i++){
        DeQueue(Q);
    }
    return 0;
}
