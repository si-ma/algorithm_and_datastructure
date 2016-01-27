#ifndef ARRAY_STACK
#define ARRAY_STACK

struct arrayStack {
    int top;
    int capacity;
    char *array;
};

typedef struct arrayStack ArrayStack;

ArrayStack *CreateStack(int capacity);

int IsEmptyStack(ArrayStack *S);

int IsFullStack(ArrayStack *S);

void Push(ArrayStack *S, char data);

int Pop(ArrayStack *S);

void DeleteStack(ArrayStack *S);
#endif

