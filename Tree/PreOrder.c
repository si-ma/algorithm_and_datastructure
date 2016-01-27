#include<stdio.h>

#include "PreOrder.h"

void PreOrder(struct BinaryTreeNode *root){
    if (root) {
        printf("%d", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}   
