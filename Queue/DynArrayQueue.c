#include<stdio.h>
#include<stdlib.h>

#include "DynArrayQueue.h"

void DebugQueue(struct DynArrayQueue *Q);

struct DynArrayQueue *CreateQueue() {
    struct DynArrayQueue *Q = malloc(sizeof(struct DynArrayQueue));
    if(!Q) return NULL;
    Q->capacity = 1;
    Q->front = Q->rear = -1;
    Q->array = malloc(Q->capacity * sizeof(int));
    if(!Q)
        return NULL;
    return Q;
}

int IsEmptyQueue(struct DynArrayQueue *Q) {
    return (Q->front == -1);
}

int IsFullQueue(struct DynArrayQueue *Q) {
    return ((Q->rear + 1) % Q->capacity == Q->front);
}

int QueueSize(struct DynArrayQueue *Q) {
    return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}

void EnQueue(struct DynArrayQueue *Q, int data){
    if(IsFullQueue(Q))
        ResizeQueue(Q);
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->array[Q->rear] = data;
    if(Q->front == -1)
        Q->front = Q->rear;
    printf("<EnQueue>\n");
    printf("capacity : %d\n", Q->capacity);
    DebugQueue(Q);
}

void ResizeQueue(struct DynArrayQueue *Q) {
    printf("<Resize>\n");
    int size = Q->capacity;
    Q->capacity = size * 2;
    Q->array = realloc(Q->array, Q->capacity);
    if(!Q->array){
        printf("Memory Error\n");
        return;
    }
    if(Q->front > Q->rear){
        int i;
        for(i=0; i < Q->front; i++){
            Q->array[i+size] = Q->array[i];
        }
        Q->rear = Q->rear + size;
    }
}

int DeQueue(struct DynArrayQueue *Q) {
    int data = 0;
    if(IsEmptyQueue(Q)) {
        printf("Queue is Empty\n");
        return 0;
    }
    else {
        data = Q->array[Q->front];
        if(Q->front == Q->rear)
            Q->front = Q->rear = -1;
        else
            Q->front = (Q->front + 1) % Q->capacity;
    }
    printf("<DeQueue>\n");
    DebugQueue(Q);
    return data;
}

void DeleteQueue(struct DynArrayQueue *Q){
    if(Q)
        if(Q->array)
            free(Q->array);
        free(Q);
}

void DebugQueue(struct DynArrayQueue *Q){
    printf("front : %d\n", Q->front);
    printf("rear : %d\n", Q->rear);
    
    int i;
    for(i=0; i<Q->capacity; i++){
        printf("array[%d] : %d\n",i ,Q->array[i]);
    }
}
