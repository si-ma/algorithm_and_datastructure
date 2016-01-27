struct DynArrayQueue {
    int front, rear;
    int capacity;
    int *array;
};

struct DynArrayQueue *CreateQueue();

int IsEmptyQueue(struct DynArrayQueue *Q);

int IsFullQueue(struct DynArrayQueue *Q);

int QueueSize(struct DynArrayQueue *Q);

void EnQueue(struct DynArrayQueue *Q, int data);

void ResizeQueue(struct DynArrayQueue *Q);

int DeQueue(struct DynArrayQueue *Q);

void DeleteQueue(struct DynArrayQueue *Q);
