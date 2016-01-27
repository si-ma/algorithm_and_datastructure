#include <stdio.h>
#include <stdlib.h>

#include "./TreeDynArrayQueue.h"

int SizeOfBinaryTree(struct BinaryTreeNode *root);
int SizeOfBinaryTreeNonRecrusive(struct BinaryTreeNode *root);

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
    
    int result = SizeOfBinaryTreeNonRecrusive(root);
    printf("size : %d\n", result);
    return 1;
}

int SizeOfBinaryTree(struct BinaryTreeNode *root) {
   if (root == NULL) {
        return 0;
    } else {
        return(SizeOfBinaryTree(root->left) + 1 + SizeOfBinaryTree(root->right));
    }
}

int SizeOfBinaryTreeNonRecrusive(struct BinaryTreeNode *root) {
    int size = 0;
    struct BinaryTreeNode *temp;
    struct DynArrayQueue *Q = CreateQueue();
    if(!root) {
        return size;
    }
    EnQueue(Q, root);
    while(!IsEmptyQueue(Q)) {
        temp = DeQueue(Q);
        size++;
        if (temp->left) {
            EnQueue(Q, temp->left);
        }
        if (temp->right) {
            EnQueue(Q, temp->right);
        }
    }
    DeleteQueue(Q);
    return size;
}
