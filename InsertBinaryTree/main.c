
#include <stdlib.h>
#include <stdio.h>

#include "dynArrayQueue.h"

void InsertInBinaryTree(struct BinaryTreeNode *root, int insertData);
int FindNode(struct BinaryTreeNode *root, int data );

int main() {

    struct BinaryTreeNode *root = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    root->data = 0;
    root->right = NULL;
    root->left = NULL;
    int i;
    for(i = 1; i < 8; i++){
        InsertInBinaryTree(root, i);
    }
    int result = FindNode(root, 5);
    printf("result : %d\n", result);
    return 0;
}

void InsertInBinaryTree(struct BinaryTreeNode *root, int insertData) {
    struct BinaryTreeNode *temp;
    struct BinaryTreeNode *insertNode;
    struct DynArrayQueue *Q = CreateQueue();
    insertNode = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    if(!insertData) {
        printf("Memory Error!\n");
        return;
    }
    insertNode->data = insertData;
    insertNode->left = NULL;
    insertNode->right = NULL;
    if (!root) {
        printf("!root!\n");
        root = insertNode;
        return;
    }
    EnQueue(Q, root);
    while (!IsEmptyQueue(Q)) {
        temp = DeQueue(Q);
        if (temp->left) {
            EnQueue(Q, temp->left);
        } else {
            temp->left = insertNode;
            printf("%d insert into left of %d\n", insertNode->data, temp->data);
            DeleteQueue(Q);
            return;
        }
        if (temp->right) {
            EnQueue(Q, temp->right);
        } else {
            temp->right = insertNode;
            printf("%d insert into right of %d\n", insertNode->data, temp->data);
            DeleteQueue(Q);
            return;
        }
    }
    DeleteQueue(Q);
}

int FindNode(struct BinaryTreeNode *root, int data) {
    int temp;
    if(root == NULL) {
        return 0;
    } else {
        if (data  == root->data) {
            return 1;
        } else {
            temp = FindNode(root->left, data);
            if (temp != 0) {
                return temp;
            } else {
                temp = FindNode(root->right, data);
                return temp;
            }
        }
    }
    return 0;
}