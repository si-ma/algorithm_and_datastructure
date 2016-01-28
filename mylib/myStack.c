#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#include "myStack.h"

arrayStack *CreateStack(){
    arrayStack *S = malloc(sizeof(arrayStack));
    if(!S) return NULL;
    S->capacity = 1;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int));
    if(!S->array) return NULL;
    return S;
}

int IsFullStack(arrayStack *S){
    return (S->top == S->capacity - 1);
}

void Push(arrayStack *S, int x){
    if(IsFullStack(S))
        DoubleStack(S);
    S->array[++S->top] = x;
}

void DoubleStack(arrayStack *S){
    S->capacity *= 2;
    S->array = realloc(S->array, S->capacity);
}

int IsEmptyStack(arrayStack *S){
    return S->top == -1;
}

int Top(arrayStack *S){
    if(IsEmptyStack(S))
        return INT_MIN;
    return S->array[S->top];
}

int Pop(arrayStack *S){
    if(IsEmptyStack(S))
        return INT_MIN;
    return S->array[S->top--];
}

void DeleteStack(arrayStack *S){
    if(S){
        if(S->array) free(S->array);
        free(S);
    }
}
