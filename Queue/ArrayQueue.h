struct ArrayQueue{
    int front;
    int rear;
    int capacity;
    int *array;
};

struct ArrayQueue *CreateQueue(int size);

int IsEmptyQueue(struct ArrayQueue *Q);

int IsFullQueue(struct ArrayQueue *Q);

int QueueSize();

void EnQueue(struct ArrayQueue *Q, int data);

int DeQueue(struct ArrayQueue *Q);

void DeleteQueue(struct ArrayQueue *Q);
