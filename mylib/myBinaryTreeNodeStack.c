#include<stdio.h>
#include<stdlib.h>
#include "myBinaryTreeNodeStack.h"

BinaryTreeNodeStack *CreateStack() {
    BinaryTreeNodeStack *S = malloc(sizeof(BinaryTreeNodeStack));
    if(!S) return NULL;
    S -> capacity = 1;
    S -> top = -1;
    S -> array = malloc(S -> capacity * sizeof(BinaryTreeNode *));
    if(!S -> array){
        return NULL;
    }
    return S;
}

int IsEmptyStack(BinaryTreeNodeStack *S) {
    return (S -> top == -1);
}

int IsFullStack(BinaryTreeNodeStack *S) {
    return (S -> top == S->capacity - 1);
}

void Push(BinaryTreeNodeStack *S, BinaryTreeNode *node) {
    if(IsFullStack(S))
        DoubleBinaryTreeNodeStack(S);
    S -> array[++S -> top] = node;
}

BinaryTreeNode *Pop(BinaryTreeNodeStack *S) {
    if(IsEmptyStack(S)) {
        printf("Stack is Empty\n");
        return 0;
    }else{
        BinaryTreeNode *rtndata = S -> array[S -> top--];
        return rtndata;
    }
}

BinaryTreeNode *Top(BinaryTreeNodeStack *S){
    if(IsEmptyStack(S)){
        printf("Stack is Empty\n");
        return NULL;
    } else {
        struct BinaryTreeNode *rtndata = S -> array[S->top];
        return rtndata;
    }
}

void DeleteStack(BinaryTreeNodeStack *S) {
    if(S) {
        if(S -> array) {
            free(S -> array);
        }
        free(S);
    }
}

void DoubleBinaryTreeNodeStack(BinaryTreeNodeStack *S){
    S->capacity *= 2;
    S->array = realloc(S->array, S->capacity);
}
