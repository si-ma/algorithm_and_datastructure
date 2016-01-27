struct DynArrayStack {
    int top;
    int capacity;
    int *array;
};

struct DynArrayStack *CreateStack();

int IsFullSatck(struct DynArrayStack *S);

void DoubleStack(struct DynArrayStack *S);

void Push(struct DynArrayStack *S, int x);

int IsEmptyStack(struct DynArrayStack *S);

int Top(struct DynArrayStack *S);

int Pop(struct DynArrayStack *S);

void DeleteStack(struct DynArrayStack *S);
