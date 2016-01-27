#include<stdio.h>
#include<stdlib.h>

#include "ListQueue.h"

void DebugListQueue(struct Queue *Q);

struct Queue *CreateQueue() {
    struct Queue *Q;
    struct ListNode *temp;
    Q = malloc(sizeof(struct Queue));
    if(!Q) return NULL;
    Q->front = Q->rear = NULL;

    return Q;
}

int IsEmptyQueue(struct Queue *Q) {
    return (Q->front == NULL);
}

void EnQueue(struct Queue *Q, int data) {
    struct ListNode *newNode;
    newNode = malloc(sizeof(struct ListNode));
    if(!newNode)
        return;
    newNode->data = data;
    newNode->next = NULL;
    Q->rear->next = newNode;
    Q->rear = newNode;
    if(Q->front == NULL)
        Q->front = Q->rear;
    printf("<EnQueue>\n");
    DebugListQueue(Q);
}

int DeQueue(struct Queue *Q) {
    int data;
    struct ListNode *temp;
    if(IsEmptyQueue(Q)) {
        printf("Queue is Empty\n");
        return 0;
    }
    else {
        temp = Q->front;
        data = Q->front->data;
        Q->front = Q->front->next;
        free(temp);
    }
    printf("<DeQueue>\n");
    DebugListQueue(Q);
    return data;
}

void DeleteQueue(struct Queue *Q) {
    struct ListNode *temp, *delnode;
    temp = Q->front;
    while(temp) {
        delnode = temp;
        temp = temp->next;
        free(delnode);
    }
    free(Q);
}

void DebugListQueue(struct Queue *Q){
    printf("front data : %d\n", Q->front->data);
    printf("rear data : %d\n", Q->rear->data);
    struct ListNode *temp;
    int i;
    temp = Q->front;
    while(temp){
        printf("[%d] : %d\n", i, temp->data);
        temp = temp->next;
        i++;
    }
}
