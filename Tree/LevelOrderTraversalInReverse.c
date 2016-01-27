#include <stdio.h>
#include <stdlib.h>

#include "./TreeDynArrayQueue.h"
#include "./TreeStack.h"

void LevelOrderTraversalInReverse(struct BinaryTreeNode *root);

int main () {
    struct BinaryTreeNode *root = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *second = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *third = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *fourth = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *fifth = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *sixth = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *seventh = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    root->data = 1;
    root->left = second;
    root->right = third;
    second->data = 2;
    second->left = fourth;
    second->right = fifth;
    third->data = 3;
    third->left = sixth;
    third->right = seventh;
    fourth->data = 4;
    fourth->left = fourth->right = NULL;
    fifth->data = 5;
    fifth->left = fifth->right = NULL;
    sixth->data = 6;
    sixth->left = sixth->right = NULL;
    seventh->data = 7;
    seventh->left = seventh->right = NULL;
    
    LevelOrderTraversalInReverse(root);
    return 1;
}

void LevelOrderTraversalInReverse(struct BinaryTreeNode *root) {
    struct DynArrayQueue *Q = CreateQueue();
    struct TreeStack *S = CreateStack(10); 
    struct BinaryTreeNode *temp;
    if (!root) return;
    EnQueue(Q, root);
    while (!IsEmptyQueue(Q)) {
        temp = DeQueue(Q);
        Push(S, temp);
        if (temp->right) {
            EnQueue(Q,temp->right);
        }
        if (temp->left) {
           EnQueue(Q,temp->left); 
        }
    }
    while(!IsEmptyStack(S)) {
        temp = Pop(S);
        printf("%d", temp->data);
    }
    DeleteStack(S);
    DeleteQueue(Q);
}
