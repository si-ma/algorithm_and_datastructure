cmake_minimum_required(VERSION 3.2)
project(Tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    BinaryTreeNode.h
    DeleteBinaryTree.c
    FindInBinaryTree.c
    FindInBinaryTreeNonRecrusive.c
    FindMax.c
    FindMaxNonRecrusive.c
    HeightOfBinaryTree.c
    InOrder.c
    InOrder.h
    InOrderNonRecursive.c
    InOrderNonRecursive.h
    InsertInBinaryTree.c
    LevelOrder.c
    LevelOrder.h
    LevelOrderTraversalInReverse.c
    MainLevelOrder.c
    MainTreeQueue.c
    PostOrder.c
    PostOrder.h
    PostOrderNonRecursive.c
    PostOrderNonRecursive.h
    PreOrder.c
    PreOrder.h
    PreOrderNonRecursive.c
    PreOrderNonRecursive.h
    SizeOfBinaryTree.c
    test.c
    testStack.c
    TreeDynArrayQueue.c
    TreeDynArrayQueue.h
    TreeStack.c
    TreeStack.h)

add_executable(Tree ${SOURCE_FILES})