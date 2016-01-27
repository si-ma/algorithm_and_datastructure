#include<stdio.h>
#include "DynArrayStack.h"

int main(){
    printf("Hello\n");
    struct DynArrayStack *S = CreateStack();
    for(int i = 0; i < 10; i++){
        Push(S, 1);
    }
    Pop(S);
    return 1;
}
