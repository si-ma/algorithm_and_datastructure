#include<stdio.h>
#include "PreOrderNonRecursive.h"

//自分をpushして左に行けなくなったら１個戻って右に行く
void PreOrderNonRecursive(struct BinaryTreeNode *root){
    TreeStack *S = CreateStack(10);
    while(1) {
        while(root) {
            printf("%d", root->data);
            Push(S, root);
            root = root->left;
        }
        if(IsEmptyStack(S)){
            break;
        }
        root = Pop(S);
        root = root->right;
    }
    DeleteStack(S);
}
