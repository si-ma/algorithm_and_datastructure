#include <stdio.h>
#include <mylib/myBinaryTree.h>
#include "testlib.h"

int main() {
    BinaryTreeNode *root = makeBinaryTree(7);
//    int max = FindMax(root);
//    int maxLevelOrder = FindMaxUsingLevelOrder(root);
//    int findres = FindInBinaryTreeUsingRecursion(root, 8);
//    int size = SizeOfBinaryTree(root);
//    int size2 = SizeofBTUsingLevelOrder(root);
//    int height = HeightOfBinaryTree(root);
    int height2 = HeightOfBinaryTreeNonRecursive(root);
    int leavesCount = NumberOfLeavesInBTusingLevelOrder(root);
//    PrintBinaryTreeReverse(root);
//    DeleteBinaryTree(root);
//    printf("max : %d\n", max);
//    printf("maxLevelorder : %d\n", maxLevelOrder);
//    printf("findres : %d\n", findres);
//    printf("size : %d\n", size);
//    printf("size2 : %d\n", size2);
//    printf("height : %d\n", height);
    printf("height2 : %d\n", height2);
    printf("leaves count : %d\n", leavesCount);
    return 0;
}