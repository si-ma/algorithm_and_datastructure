#include <stdio.h>
#include "PostOrderNonRecursive.h"

void PostOrderNonRecursive(struct BinaryTreeNode *root){
    TreeStack *S = CreateStack(10);
    while(1) {
        //自分をスタックにpushして左に行けるところまで行く。
        if(root) {
            Push(S, root);
            root = root->left;
        }
        else {
            if(IsEmptyStack(S)) {
                printf("Stack is Empty\n");
                return;
            }
            //右にも行けなくなったらpopして１つ前のノードを取り出す（１つ戻る）
            else if(Top(S)->right == NULL) {
                root = Pop(S);
                printf("%d", root->data);
                //
            }
            while(root == Top(S)->right) {
                    printf("%d", Top(S)->data);
                    root = Pop(S);
            }
            
            if(!IsEmptyStack(S)){
                    root = Top(S)->right;
            }else{
                root = NULL;
            }
        }
    }
    DeleteStack(S);
}
