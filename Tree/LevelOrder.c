#include "stdio.h"
#include "stdlib.h"

#include "./LevelOrder.h"

void LevelOrder(struct BinaryTreeNode *root){
    struct BinaryTreeNode *temp;
    struct DynArrayQueue *Q = CreateQueue();

    if(!root)
        return;
    EnQueue(Q, root);
    while (!IsEmptyQueue(Q)) {
        temp = DeQueue(Q);
        printf("%d", temp->data);
        if(temp->left)
            EnQueue(Q, temp->left);
        if(temp->right)
            EnQueue(Q, temp->right);
    }
    DeleteQueue(Q);
}
