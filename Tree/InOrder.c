#include<stdio.h>
#include "InOrder.h"

void InOrder(struct BinaryTreeNode *root){
    if(root) {
        InOrder(root->left);
        printf("%d", root->data);
        InOrder(root->right);
    }
}
