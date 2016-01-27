#include <stdio.h>
#include <stdlib.h>

#include "./TreeDynArrayQueue.h"

int FindMax(struct BinaryTreeNode *root);

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
   
    int max = FindMax(root);
    printf("max:%d\n", max);
    return 1;
}

int FindMax(struct BinaryTreeNode *root) {
    int max, root_val, left, right = 0;
    
    if (root != NULL) {
        root_val = root->data;
        left = FindMax(root->left);
        right = FindMax(root->right);
        
        if(left > right) {
            max = left;
        } else {
            max = right;
        }

        if(root_val > max){
            max = root_val;
        }
    }
    return max;
}
