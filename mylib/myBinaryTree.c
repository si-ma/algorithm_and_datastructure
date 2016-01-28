#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "myBinaryTree.h"


/*
 * make binary tree.
 * @arg
 * int nodeAmount : the number of binary tree nodes
 * @return: root node of BinaryTreeNode
 */
BinaryTreeNode *makeBinaryTree(int nodeAmount) {
    BinaryTreeNode *root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    root->data = 0;
    root->right = NULL;
    root->left = NULL;
    int i;
    for(i = 1; i < nodeAmount; i++) {
        insertInBinaryTree(root, i);
    }
    return root;
}

/*
 * insert node into binary tree.
 * @args
 * BinaryTreeNode *root : root node pointer
 * int insertData : data you intend to insert into binary tree
 * @return void.
 */
void insertInBinaryTree(BinaryTreeNode *root, int insertData) {
    BinaryTreeNode *temp;
    BinaryTreeNode *insertNode;
    BinaryTreeNodeQueue *Q = CreateQueue();
    insertNode = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    if(!insertNode) {
        printf("Memory Error!\n");
        return;
    }
    insertNode->data = insertData;
    insertNode->left = NULL;
    insertNode->right = NULL;
    if (!root) {
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
            DeleteQueue(Q);
            return;
        }
        if (temp->right) {
            EnQueue(Q, temp->right);
        } else {
            temp->right = insertNode;
            DeleteQueue(Q);
            return;
        }
    }
    DeleteQueue(Q);
}

int FindMax(BinaryTreeNode *root) {
    int root_val, left, right, max = INT_MIN;
    if(root != NULL) {
        root_val = root->data;
        left = FindMax(root->left);
        right = FindMax(root->right);

        //max in 3 value.
        if(left > right) {
            max = left;
        } else {
            max = right;
        }
        if (root_val > max){
            max = root_val;
        }
    }
    return max;
}
