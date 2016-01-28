#include<stdio.h>
#include<stdlib.h>

#include "myBinaryTreeNodeQueue.h"

BinaryTreeNodeQueue *CreateQueue() {
    BinaryTreeNodeQueue *Q = malloc(sizeof(BinaryTreeNodeQueue));
    if(!Q) return NULL;
    Q->capacity = 1;
    Q->front = Q->rear = -1;
    Q->array = malloc(Q->capacity * sizeof(BinaryTreeNode));
    if(!Q)
        return NULL;
    return Q;
}

int IsEmptyQueue(BinaryTreeNodeQueue *Q) {
    return (Q->front == -1);
}

int IsFullQueue(BinaryTreeNodeQueue *Q) {
    return ((Q->rear + 1) % Q->capacity == Q->front);
}

int QueueSize(BinaryTreeNodeQueue *Q) {
    return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}

void EnQueue(BinaryTreeNodeQueue *Q, BinaryTreeNode *data){
    if(IsFullQueue(Q))
        DoubleBinaryTreeNodeQueue(Q);
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->array[Q->rear] = data;
    if(Q->front == -1)
        Q->front = Q->rear;
}

void DoubleBinaryTreeNodeQueue(BinaryTreeNodeQueue *Q) {
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

BinaryTreeNode *DeQueue(BinaryTreeNodeQueue *Q) {
    if(IsEmptyQueue(Q)) {
        printf("Queue is Empty\n");
        return NULL;
    }
    else {
        BinaryTreeNode *data = Q->array[Q->front];
        if(Q->front == Q->rear)
            Q->front = Q->rear = -1;
        else
            Q->front = (Q->front + 1) % Q->capacity;
        return data;
    }
}

void DeleteQueue(BinaryTreeNodeQueue *Q){
    if(Q)
        if(Q->array)
            free(Q->array);
        free(Q);
}
