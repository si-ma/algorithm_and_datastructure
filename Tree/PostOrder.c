#include<stdio.h>

#include "PostOrder.h"

void PostOrder(struct BinaryTreeNode *root){
    if(root){
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d", root->data);
    }
}
