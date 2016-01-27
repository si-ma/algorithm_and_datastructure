#include<stdio.h>
#include<stdlib.h>
#include "TreeStack.h"

void DebugS(TreeStack *S);

TreeStack *CreateStack(int capacity) {
    TreeStack *S = malloc(sizeof(TreeStack));
    if(!S) return NULL;
    S -> capacity = capacity;
    S -> top = -1;
    S -> array = malloc(S -> capacity * sizeof(struct BinaryTreeNode *));
    if(!S -> array){
        return NULL;
    }
    return S;
}

int IsEmptyStack(TreeStack *S) {
    return (S -> top == -1);
}

int IsFullStack(TreeStack *S) {
    return (S -> top == S->capacity - 1);
}

void Push(TreeStack *S, struct BinaryTreeNode *node) {
    if(IsFullStack(S)) {
        printf("Stack Overflow\n");
    }else{
        S -> array[++S -> top] = node;
            //printf("<PUSH>\n");
            //DebugS(S);
    }
}

struct BinaryTreeNode *Pop(TreeStack *S) {
    if(IsEmptyStack(S)) {
        printf("Stack is Empty\n");
        return 0;
    }else{
        struct BinaryTreeNode *rtndata = S -> array[S -> top--];
            //printf("<POP>\n");
            //DebugS(S);
        return rtndata;
    }
}

struct BinaryTreeNode *Top(TreeStack *S){
    if(IsEmptyStack(S)){
        printf("Stack is Empty\n");
        return NULL;
    } else {
        struct BinaryTreeNode *rtndata = S -> array[S->top];
        return rtndata;
    }
}

void DeleteStack(TreeStack *S) {
    if(S) {
        if(S -> array) {
            free(S -> array);
        }
        free(S);
    }
}

void DebugS(TreeStack *S){
    printf("capacity:%d\n", S->capacity);
    printf("top:%d\n", S->top);
    printf("size of array:%lu\n" , sizeof(S->array));
    /*
    for(int i; i < 10; i++){
        printf("array data[%d]:%d\n", i, S->array[i]);
    }
    */
}
