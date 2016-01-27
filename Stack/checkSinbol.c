#include<stdio.h>
#include "ArrayStack.h"

int isMatchSimbol(char inputChar, char stackChar);

int main(){
    ArrayStack *S = CreateStack(20);
    char inputChar, inputString[21];
    int i = 0;
    
    while(i < 20 && (inputChar = getchar()) != '\n' && inputChar != EOF) {
        if(inputChar == '[' || inputChar == '(' || inputChar == '{'){
            Push(S, inputChar);
        }else if(inputChar == ']' || inputChar == ')' || inputChar == '}'){
            if(IsEmptyStack(S)){
                printf("Not Matching Simbol\n");
                return 0;
            }
            if(!isMatchSimbol(inputChar, Pop(S))){
                printf("Not Matching Simbol!!\n");
                return 0;
            }
        }
        i++;
    }
    if(!IsEmptyStack(S)){
        printf("Not Maching Simbol!!!\n");
    }else{
        printf("OK!\n");
    }
    return 0;
}

int isMatchSimbol(char inputChar, char stackChar){
    if(inputChar == ']'){
        return stackChar == '[';
    }else if(inputChar == ')'){
        return stackChar == '(';
    }else if(inputChar == '}'){
        return stackChar == '{';
    }else{
        return 0;
    }
}
