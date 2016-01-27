//
// Created by Hidekazu Shimane on 2015/06/27.
//

#ifndef BINARYTREEEX1_TESTLIB_H
#define BINARYTREEEX1_TESTLIB_H

#include <mylib/myBinaryTreeNode.h>

int FindMax(BinaryTreeNode *root);
int FindMaxUsingLevelOrder(BinaryTreeNode *root);
int FindInBinaryTreeUsingRecursion(BinaryTreeNode *root, int data);
int SizeOfBinaryTree(BinaryTreeNode *root);
int SizeofBTUsingLevelOrder(BinaryTreeNode *root);
void PrintBinaryTreeReverse(BinaryTreeNode *root);
void DeleteBinaryTree(BinaryTreeNode *root);
int HeightOfBinaryTree(BinaryTreeNode *root);
int HeightOfBinaryTreeNonRecursive(BinaryTreeNode *root);
int NumberOfLeavesInBTusingLevelOrder(BinaryTreeNode *root);
#endif //BINARYTREEEX1_TESTLIB_H
