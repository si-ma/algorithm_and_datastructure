#include <stdio.h>
#include "InOrderNonRecursive.h"

//自分をスタックにpushして左に、左に行けなくなったら出力して１つ戻って右に。
void InOrderNonRecursive(struct BinaryTreeNode *root) {
    TreeStack *S = CreateStack(10);
    while(1) {
        while(root) {
            Push(S, root);
            root = root->left;
        }
        if(IsEmptyStack(S)){
            break;
        }
        root = Pop(S);
        printf("%d", root->data);
        root = root->right;
    }
    DeleteStack(S);
}
