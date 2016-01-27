#include <stdlib.h>
#include <stdio.h>

#include "TreeStack.h"

int main(){
    TreeStack *S = CreateStack(10);
    struct BinaryTreeNode *node = malloc(sizeof(struct BinaryTreeNode));
    node->data=5;
    Push(S, node);
    
    //struct BinaryTreeNode *a = Pop(S);
    struct BinaryTreeNode *a = Top(S);
    printf("%d",a->data);
    return 1;
}
