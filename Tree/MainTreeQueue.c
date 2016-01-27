#include <stdio.h>
#include <stdlib.h>

#include "TreeDynArrayQueue.h"

int main(){
    struct DynArrayQueue *Q = CreateQueue();
    struct BinaryTreeNode *node = malloc(sizeof(struct BinaryTreeNode));
    node->data=5;
    EnQueue(Q, node); 
    
    struct BinaryTreeNode *a = DeQueue(Q);
    printf("%d",a->data);
    return 1;
}
