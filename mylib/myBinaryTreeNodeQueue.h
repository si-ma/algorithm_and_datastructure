#include "myBinaryTreeNode.h"

typedef struct {
    int front, rear;
    int capacity;
    struct BinaryTreeNode **array;
} BinaryTreeNodeQueue;

BinaryTreeNodeQueue *CreateQueue();

int IsEmptyQueue(BinaryTreeNodeQueue *Q);

int IsFullQueue(BinaryTreeNodeQueue *Q);

int QueueSize(BinaryTreeNodeQueue *Q);

void EnQueue(BinaryTreeNodeQueue *Q, BinaryTreeNode *data);

void DoubleBinaryTreeNodeQueue(BinaryTreeNodeQueue *Q);

BinaryTreeNode *DeQueue(BinaryTreeNodeQueue *Q);

void DeleteQueue(BinaryTreeNodeQueue *Q);
