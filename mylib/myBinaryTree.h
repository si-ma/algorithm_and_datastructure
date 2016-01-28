//
// Created by Hidekazu Shimane on 2015/06/21.
//

#ifndef MYLIB_MYBINARYTREE_H
#define MYLIB_MYBINARYTREE_H

#include "myBinaryTreeNode.h"
#include "myBinaryTreeNodeQueue.h"
#include "myBinaryTreeNodeStack.h"

BinaryTreeNode *makeBinaryTree(int nodeAmount);

void insertInBinaryTree(BinaryTreeNode *root, int insertData);

int FindNode(BinaryTreeNode *root, int data);

int FindMax(BinaryTreeNode *root);
#endif //MYLIB_MYBINARYTREE_H
