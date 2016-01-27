#include<stdio.h>
#include<stdlib.h>
#include "ArrayStack.h"

void DebugS(ArrayStack *S);

ArrayStack *CreateStack(int capacity) {
    ArrayStack *S = malloc(sizeof(ArrayStack));
    if(!S) return NULL;
    S -> capacity = capacity;
    S -> top = -1;
    S -> array = malloc(S -> capacity * sizeof(char));
    if(!S -> array){
        return NULL;
    }
    return S;
}

int IsEmptyStack(ArrayStack *S) {
    return (S -> top == -1);
}

int IsFullStack(ArrayStack *S) {
    return (S -> top == S->capacity - 1);
}

void Push(ArrayStack *S, char data) {
    if(IsFullStack(S)) {
        printf("Stack Overflow\n");
    }else{
        S -> array[++S -> top] = data;
            //printf("<PUSH>\n");
            //DebugS(S);
    }
}

int Pop(ArrayStack *S) {
    if(IsEmptyStack(S)) {
        printf("Stack is Empty\n");
        return 0;
    }else{
        int rtndata = S -> array[S -> top--];
            //printf("<POP>\n");
            //DebugS(S);
        return rtndata;
    }
}

void DeleteStack(ArrayStack *S) {
    if(S) {
        if(S -> array) {
            free(S -> array);
        }
        free(S);
    }
}

void DebugS(ArrayStack *S){
    printf("capacity:%d\n", S->capacity);
    printf("top:%d\n", S->top);
    printf("size of array:%lu\n" , sizeof(S->array));
    for(int i; i < 10; i++){
        printf("array data[%d]:%d\n", i, S->array[i]);
    }
}
