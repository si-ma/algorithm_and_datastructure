#include<stdio.h>
#include<stdlib.h>

#include "ArrayQueue.h"

void DebugQueue(struct ArrayQueue *Q);

struct ArrayQueue *CreateQueue(int size){
    struct ArrayQueue *Q = malloc(sizeof(struct ArrayQueue));
    if(!Q) return NULL;
    Q->capacity = size;
    Q->front = Q->rear = -1;
    Q->array = malloc(sizeof(Q->capacity * sizeof(int)));
    if(!Q) return NULL;
    return Q;
}

int IsEmptyQueue(struct ArrayQueue *Q){
    return (Q->front == -1);
}

int IsFullQueue(struct ArrayQueue *Q){
    return ((Q->rear + 1) % Q->capacity == Q->front);
}

int QueueSize(struct ArrayQueue *Q){
    return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}

void EnQueue(struct ArrayQueue *Q, int data){
    if(IsFullQueue(Q))
        printf("Queue Overflow");
    else{
        Q->rear = (Q->rear + 1) % Q->capacity;
        Q->array[Q->rear] = data;
        if(Q->front == -1)
            Q->front = Q->rear;
        printf("<EnQueue>\n");
        DebugQueue(Q);
    }
}

int DeQueue(struct ArrayQueue *Q){
    int data = 0;
    if(IsEmptyQueue(Q)){
        printf("Queue Underflow");
        return 0;
    }
    else{
        data = Q->array[Q->front];
        if(Q->front == Q->rear){
            Q->front = Q->rear = -1;
        }
        else{
        Q->front = (Q->front + 1) % Q->capacity;
        } 
        printf("<DeQueue>\n");
        DebugQueue(Q);
    }
    return data;
}

void DeleteQueue(struct ArrayQueue *Q){
    if(Q){
        if(Q->array){
            free(Q->array);
        }
        free(Q);
    }
}

void DebugQueue(struct ArrayQueue *Q){
    printf("front : %d\n", Q->front);
    printf("rear : %d\n", Q->rear);
    
    int i;
    for(i=0; i<Q->capacity; i++){
        printf("array[%d] : %d\n",i ,Q->array[i]);
    }
}
