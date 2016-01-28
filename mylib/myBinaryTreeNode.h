#ifndef MYLIB_BINARY_TREE_NODE
#define MYLIB_BINARY_TREE_NODE

typedef struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

#endif
