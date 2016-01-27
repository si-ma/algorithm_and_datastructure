//
// Created by Hidekazu Shimane on 2015/06/27.
//
#include <limits.h>
#include <stddef.h>
#include <mylib/myBinaryTreeNodeQueue.h>
#include <mylib/myBinaryTreeNodeStack.h>
#include <stdio.h>
#include <stdlib.h>

#include "testlib.h"

/* Find max value in binary tree.This used recursion.
 * @arg
 * BinaryTreeNode *root : root binary tree node address.
 * @return
 * int max : max value in binary tree.
 */
int FindMax(BinaryTreeNode *root) {
    int root_val, left, right, max = INT_MIN;
    if(root != NULL) {

        root_val = root->data;
        left = FindMax(root->left);
        right = FindMax(root->right);

        //max in 3 value.
        if(left > right) {
            max = left;
        } else {
            max = right;
        }
        if (root_val > max){
            max = root_val;
        }
    }
    return max;
}

/* Find max value in binary tree.This used recursion.
 * @arg
 * BinaryTreeNode *root : root binary tree node address.
 * @return
 * int max : max value in binary tree.
 */
int FindMaxUsingLevelOrder(BinaryTreeNode *root){
    BinaryTreeNode *temp;
    int max = INT_MIN;
    BinaryTreeNodeQueue *Q = CreateQueue();
    EnQueue(Q, root);
    while (!IsEmptyQueue(Q)) {
        temp = DeQueue(Q);
        if(temp->data > max) {
            max = temp->data;
        }
        if(temp->left) {
            EnQueue(Q, temp->left);
        }
        if(temp->right) {
            EnQueue(Q, temp->right);
        }
    }
    DeleteQueue(Q);
    return max;
}

/* Whether exist certain value.
 *@args
 * BinaryTreeNode *root : root binary tree node address.
 * int data : search data
 * @return int : if exist return 1, not exist return 0.
 */
int FindInBinaryTreeUsingRecursion(BinaryTreeNode *root, int data) {
    int temp;
    // base case.
    if (root == NULL){
        return 0;
    } else {
        if(data == root->data) {
            return 1;
        } else {
            temp = FindInBinaryTreeUsingRecursion(root->left, data);
            if(temp !=0) {
                return temp;
            } else {
                return FindInBinaryTreeUsingRecursion(root->right, data);
            }
        }
    }
}

/* calculate binary tree size.
 * @arg
 * BinaryTreeNode *root : root binary tree node address.
 * return
 * int size : binary tree size.
 */
int SizeOfBinaryTree(BinaryTreeNode *root) {
    if(root == NULL){
        return 0;
    } else {
        return SizeOfBinaryTree(root->left) + 1 + SizeOfBinaryTree(root->right);
    }

}

/* calculate binary tree size by using level order (not used recursion).
 * @arg
 * BinaryTreeNode *root : root binary tree node address.
 * @return
 * int size : binary tree size.
 */
int SizeofBTUsingLevelOrder(BinaryTreeNode *root) {
    BinaryTreeNode *temp;
    BinaryTreeNodeQueue *Q = CreateQueue();
    int count = 0;
    if(!root) return 0;
    EnQueue(Q, root);
    while (!IsEmptyQueue(Q)) {
        temp = DeQueue(Q);
        count = count + 1;
        if(temp->left)
            EnQueue(Q, temp->left);
        if(temp->right)
            EnQueue(Q, temp->right);
    }
    DeleteQueue(Q);
    return count;
}

/* print binary tree order by bottom.
 * @arg
 * BinaryTreeNode *root : root binary tree node address.
 * @return
 * void
 */
void PrintBinaryTreeReverse(BinaryTreeNode *root) {
    BinaryTreeNode *temp;
    BinaryTreeNodeQueue *Q;
    BinaryTreeNodeStack *S;
    if(!root) return;
    Q = CreateQueue();
    S = CreateStack();
    EnQueue(Q, root);
    while(!IsEmptyQueue(Q)) {
        temp = DeQueue(Q);
        Push(S,temp);
        if(temp->right)
            EnQueue(Q, temp->right);
        if(temp->left)
            EnQueue(Q, temp->left);
    }
    while (!IsEmptyStack(S)){
        temp = Pop(S);
        printf("%d",temp->data);
    }
    printf("\n");
    DeleteQueue(Q);
    DeleteStack(S);
}

/* delete binary tree.
 * @arg
 * BinaryTreeNode *root : root binary tree node address.
 */
void DeleteBinaryTree(BinaryTreeNode *root) {
    if(root == NULL)
        return;
    DeleteBinaryTree(root->left);
    DeleteBinaryTree(root->right);
    DeleteBinaryTree(root);
}
/* get height of binary tree.
 * @arg
 * BinaryTreeNode *root : root binary tree node address.
 * @return
 * int size : height of binary tree node.
 */
int HeightOfBinaryTree(BinaryTreeNode *root){
    int leftheight, rightheight;
    if(root == NULL) {
        return 0;
    } else{
        leftheight = HeightOfBinaryTree(root->left);
        rightheight = HeightOfBinaryTree(root->right);
        if(leftheight > rightheight) {
            return leftheight + 1;
        } else {
            return rightheight + 1;
        }
    }

}

/* get height of binary tree not using recursion.
 * using level order .
 */
int HeightOfBinaryTreeNonRecursive(BinaryTreeNode *root) {
    int level = 1;
    BinaryTreeNode *temp;
    BinaryTreeNodeQueue *Q;
    if(!root) return 0;
    Q = CreateQueue();
    EnQueue(Q, root);
    //最初のレベル終わり
    EnQueue(Q, NULL);
    while (!IsEmptyQueue(Q)) {
        temp = DeQueue(Q);
        //現在のレベル完了
        if(temp == NULL) {
            //次のレベルへ印をつける
            if(!IsEmptyQueue(Q)){
                EnQueue(Q,NULL);
            }
            level++;
        } else {
            if(temp->left){
                EnQueue(Q, temp->left);
            }
            if(temp->right){
                EnQueue(Q, temp->right);
            }
        }
    }
    DeleteQueue(Q);
    return level;
}

/* find the deepest node in binary tree.
 * @arg
 * BinaryTreeNode *root : root binary tree node address.
 * @return
 * BinaryTreeNode : the deepest binary tree node.
 */
BinaryTreeNode *DeepestNodeInBinaryTree(BinaryTreeNode *root) {
    BinaryTreeNode *temp;
    BinaryTreeNodeQueue *Q;
    if(!root) return NULL;
    Q = CreateQueue();
    EnQueue(Q, root);
    while (!IsEmptyQueue(Q)) {
        temp = DeQueue(Q);
        if(temp->left) {
            EnQueue(Q, temp->left);
        }
        if(temp->right){
            EnQueue(Q, temp->right);
        }
    }
    DeleteQueue(Q);
    return temp;
}

int NumberOfLeavesInBTusingLevelOrder(BinaryTreeNode *root) {
    BinaryTreeNode *temp;
    BinaryTreeNodeQueue *Q;
    int count = 0;
    if(!root) return 0;
    Q = CreateQueue();
    EnQueue(Q, root);
    while(!IsEmptyQueue(Q)) {
        temp = DeQueue(Q);
        if(!temp->right && !temp->left) {
            count++;
        } else {
            if(temp->right){
                EnQueue(Q, temp->right);
            }
            if(temp->left) {
                EnQueue(Q, temp->left);
            }
        }
    }
    DeleteQueue(Q);
    return count;
}