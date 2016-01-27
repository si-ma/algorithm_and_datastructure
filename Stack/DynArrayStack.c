#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#include "DynArrayStack.h"

struct DynArrayStack *CreateStack(){
    struct DynArrayStack *S = malloc(sizeof(struct DynArrayStack));
    if(!S) return NULL;
    S->capacity = 1;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int));
    if(!S->array) return NULL;
    return S;
}

int IsFullStack(struct DynArrayStack *S){
    return (S->top == S->capacity - 1);
}

void DoubleStack(struct DynArrayStack *S){
    S->capacity *= 2;
    S->array = realloc(S->array, S->capacity);
}

void Push(struct DynArrayStack *S, int x){
    if(IsFullStack(S))
        DoubleStack(S);
    S->array[++S->top] = x;
}

int IsEmptyStack(struct DynArrayStack *S){
    return S->top == -1;
}

int Top(struct DynArrayStack *S){
    if(IsEmptyStack(S))
        return INT_MIN;
    return S->array[S->top];
}

int Pop(struct DynArrayStack *S){
    if(IsEmptyStack(S))
        return INT_MIN;
    return S->array[S->top--];
}

void DeleteStack(struct DynArrayStack *S){
    if(S){
        if(S->array) free(S->array);
        free(S);
    }
}
