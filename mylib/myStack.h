//
// Created by Hidekazu Shimane on 2015/06/17.
//

#ifndef MYLIB_MYSTACK_H
#define MYLIB_MYSTACK_H
typedef struct {
    int top;
    int capacity;
    int *array;
} arrayStack;

arrayStack *CreateStack();

int IsFullSatck(arrayStack *S);

void DoubleStack(arrayStack *S);

void Push(arrayStack *S, int x);

int IsEmptyStack(arrayStack *S);

int Top(arrayStack *S);

int Pop(arrayStack *S);

void DeleteStack(arrayStack *S);

#endif //MYLIB_MYSTACK_H
