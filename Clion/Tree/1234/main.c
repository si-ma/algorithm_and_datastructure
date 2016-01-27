#include <stdio.h>
#define NARABI_LENGTH 4

void printElement(int *array, int length, int *printArray);

int main() {
    int array[] = {1, 2, 3, 4};
    int length = sizeof(array) /sizeof(array[0]);
    int printArray[NARABI_LENGTH];
    printElement(array, length,printArray);
    return 0;
}

void printElement(int *array, int length, int *printArray) {
    if(length == 0) {
        int num;
        for(num = 0; num < NARABI_LENGTH; num++) {
            printf("%d", printArray[num]);
        }
        printf("\n");
        return;
    }
    int i;
    for (i = 0; i < length; i++) {
        printArray[NARABI_LENGTH - length] = array[i];
        int array2[length-1];
        int count=0;
        int j;
        for(j = 0; count < length-1;j++) {
            if(j != i) {
                array2[count]=array[j];
                count++;
            }
        }
        printElement(array2, length - 1, printArray);
    }
}