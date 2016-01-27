#include <stdio.h>
#include <stdlib.h>

#include "./BinaryTreeNode.h"

void DeleteBinaryTree(struct BinaryTreeNode *root);

int main() {
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
    
    DeleteBinaryTree(root);
    return 1;
}

void DeleteBinaryTree(struct BinaryTreeNode *root) {
    if(root == NULL) return;

    DeleteBinaryTree(root->left);
    DeleteBinaryTree(root->right);
    printf("delete:%d\n", root->data);
    free(root);
}
