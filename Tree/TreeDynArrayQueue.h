#include "BinaryTreeNode.h"

struct DynArrayQueue {
    int front, rear;
    int capacity;
    struct BinaryTreeNode **array;
};

struct DynArrayQueue *CreateQueue();

int IsEmptyQueue(struct DynArrayQueue *Q);

int IsFullQueue(struct DynArrayQueue *Q);

int QueueSize(struct DynArrayQueue *Q);

void EnQueue(struct DynArrayQueue *Q, struct BinaryTreeNode *data);

void ResizeQueue(struct DynArrayQueue *Q);

struct BinaryTreeNode *DeQueue(struct DynArrayQueue *Q);

void DeleteQueue(struct DynArrayQueue *Q);
