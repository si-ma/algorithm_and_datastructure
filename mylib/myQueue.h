//
// Created by Hidekazu Shimane on 2015/06/16.
//

#ifndef MYLIB_MYQUEUE_H
#define MYLIB_MYQUEUE_H

typedef struct {
    int front, rear;
    int capacity;
    int *array;
} arrayQueue;

arrayQueue *CreateQueue();

int IsEmptyQueue(arrayQueue *Q);

int IsFullQueue(arrayQueue *Q);

int QueueSize(arrayQueue *Q);

void EnQueue(arrayQueue *Q, int data);

void ResizeQueue(arrayQueue *Q);

int DeQueue(arrayQueue *Q);

void DeleteQueue(arrayQueue *Q);

#endif //MYLIB_MYQUEUE_H
