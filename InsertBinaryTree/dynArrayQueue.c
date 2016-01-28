//
// Created by Hidekazu Shimane on 2015/06/16.
//

#include<stdio.h>
#include<stdlib.h>

#include "dynArrayQueue.h"

struct DynArrayQueue *CreateQueue() {
    struct DynArrayQueue *Q = malloc(sizeof(struct DynArrayQueue));
    if(!Q) return NULL;
    Q->capacity = 1;
    Q->front = Q->rear = -1;
    Q->array = malloc(Q->capacity * sizeof(struct BinaryTreeNode));
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

void EnQueue(struct DynArrayQueue *Q, struct BinaryTreeNode *data){
    if(IsFullQueue(Q))
        ResizeQueue(Q);
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->array[Q->rear] = data;
    if(Q->front == -1)
        Q->front = Q->rear;
}

void ResizeQueue(struct DynArrayQueue *Q) {
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

struct BinaryTreeNode *DeQueue(struct DynArrayQueue *Q) {
    if(IsEmptyQueue(Q)) {
        printf("Queue is Empty\n");
        return NULL;
    }
    else {
        struct BinaryTreeNode *data = Q->array[Q->front];
        if(Q->front == Q->rear)
            Q->front = Q->rear = -1;
        else
            Q->front = (Q->front + 1) % Q->capacity;
        return data;
    }
}

void DeleteQueue(struct DynArrayQueue *Q){
    if(Q)
    if(Q->array)
        free(Q->array);
    free(Q);
}