struct ListNode {
    int data;
    struct ListNode *next;
};

struct Queue {
    struct ListNode *front;
    struct ListNode *rear;
};

struct Queue *CreateQueue();

int IsEmptyQueue(struct Queue *Q);

void EnQueue(struct Queue *Q, int data);

int DeQueue(struct Queue *Q);

void DeleteQueue(struct Queue *Q);
