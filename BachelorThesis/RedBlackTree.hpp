//
//  RedBlackTree.hpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 17/03/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//

#ifndef RedBlackTree_hpp
#define RedBlackTree_hpp

#include <stdio.h>
#include <iostream>
//#include <stdexcept>

struct RBTNode { // Red Black Tree Node
    int data;
    RBTNode * parent = nullptr;
    RBTNode * leftChild = nullptr;
    RBTNode * rightChild = nullptr;
    bool isBlack = false;
};

class RedBlackTree {
private:
    RBTNode * root;
    
private:
    void newNode(RBTNode * currentNode, int newValue);
    RBTNode * searchRecursive(RBTNode * currentNode, int searchValue);
    void rotateTree(RBTNode * newNode);
    void inOrder(RBTNode * currentNode);
    bool checkRedCriteria(RBTNode * currentNode);
    void fixLineFormation(RBTNode * newNode);
    void fixZigZagFormation(RBTNode * newNode);
    void restoreRBTProperties(RBTNode * currentNode);
    int blackHeight(RBTNode * currentNode);

    
public:
    RedBlackTree();
    void createNode(int value);
    void createTree(int * values, int listSize);
    void display();
    RBTNode * search(int searchValue);
    bool isTreeValid();
//    void testDisplay();
//    void createTestTree();
//    void shift(int shiftValue);
//    void merge(RedBlackTree * newTree);
//    RedBlackTree split(int splitValue);
};

#endif /* RedBlackTree_hpp */
