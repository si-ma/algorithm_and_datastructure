#ifndef ARRAY_STACK
#define ARRAY_STACK
#include "BinaryTreeNode.h"

struct TreeStack {
    int top;
    int capacity;
    struct BinaryTreeNode **array;
};

typedef struct TreeStack TreeStack;

TreeStack *CreateStack(int capacity);

int IsEmptyStack(TreeStack *S);

int IsFullStack(TreeStack *S);

void Push(TreeStack *S, struct BinaryTreeNode *node);

struct BinaryTreeNode *Pop(TreeStack *S);

struct BinaryTreeNode *Top(TreeStack *S);

void DeleteStack(TreeStack *S);
#endif

