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
    // TODO: add black height here.
    int data;
    RBTNode * parent = nullptr;
    RBTNode * leftChild = nullptr;
    RBTNode * rightChild = nullptr;
    bool isBlack = false;
};

class RedBlackTree {
private:
    
    
private:
    void createNode(RBTNode * currentNode, int newValue);
    RBTNode * predecessorSearch(RBTNode * currentNode, int searchValue);
    void rotateTree(RBTNode * newNode);
    void inOrder(RBTNode * currentNode, bool showDetails);
    bool checkRedCriteria(RBTNode * currentNode);
    void fixLineFormation(RBTNode * newNode);
    void fixZigZagFormation(RBTNode * newNode);
//    void restoreRBTProperties(RBTNode * currentNode);
    int blackHeight(RBTNode * currentNode);

public:
    RBTNode * root;
    RBTNode * minNode;
    RBTNode * maxNode;
    
public:
    RedBlackTree();
    void createNode(int value);
    void createTree(int * values, int listSize);
    void display(bool showDetails);
    RBTNode * search(int searchValue);
    bool isTreeValid();
    int getBlackHeight();
//    void shift(int shiftValue);
//    void merge(RedBlackTree * newTree);
//    RedBlackTree split(int splitValue);
    void join(RedBlackTree * newTree);
    void erase();
    void deleteMinNode();
    void deleteMaxNode();
    int blackHeightAssumingValid(RBTNode * currentNode);
    RBTNode * getLeftmostNodeOfHeight(int blackHeight);
    RBTNode * getRightmostNodeOfHeight(int blackHeight);
};

#endif /* RedBlackTree_hpp */
