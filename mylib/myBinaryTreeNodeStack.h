#ifndef MYLIB_BINARYTREENODESTACK
#define MYLIB_BINARYTREENODESTACK
#include "myBinaryTreeNode.h"

typedef struct {
    int top;
    int capacity;
    BinaryTreeNode **array;
} BinaryTreeNodeStack;

BinaryTreeNodeStack *CreateStack();

int IsEmptyStack(BinaryTreeNodeStack *S);

int IsFullStack(BinaryTreeNodeStack *S);

void Push(BinaryTreeNodeStack *S, BinaryTreeNode *node);

BinaryTreeNode *Pop(BinaryTreeNodeStack *S);

BinaryTreeNode *Top(BinaryTreeNodeStack *S);

void DeleteStack(BinaryTreeNodeStack *S);

void DoubleBinaryTreeNodeStack(BinaryTreeNodeStack *S);

#endif
