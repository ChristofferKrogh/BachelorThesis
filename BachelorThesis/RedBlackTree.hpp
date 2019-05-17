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
    int shift = 0;
    bool isBlack = false;
    bool hasLeftChild() {
        return leftChild != NULL;
    }
    bool hasRightChild() {
        return rightChild != NULL;
    }
};

class RedBlackTree {
private:
    void createNode(RBTNode * currentNode, int newValue);
    RBTNode * predecessorSearch(RBTNode * currentNode, int searchValue);
    void rotateTree(RBTNode * newNode);
    void inOrder(RBTNode * currentNode, bool showDetails, int currentShiftValue);
    bool checkRedCriteria(RBTNode * currentNode);
    void fixLineFormation(RBTNode * newNode);
    void fixZigZagFormation(RBTNode * newNode);
    int checkBlackHeight(RBTNode * currentNode);

public:
    RBTNode * root;
//    RBTNode * minNode;
//    RBTNode * maxNode;
    
public:
    RedBlackTree();
    void createNode(int value);
    void createTree(int * values, int listSize);
    void display(bool showDetails);
    RBTNode * search(int searchValue);
    bool isTreeValid();
    int getBlackHeight();
    void shift(int shiftValue);
    void merge(RedBlackTree * newTree);
    RedBlackTree * split(int splitValue);
    void join(RedBlackTree * newTree);
    void erase();
    void deleteMinNode();
    void deleteMaxNode();
    int blackHeightAssumingValid(RBTNode * currentNode);
    RBTNode * getNodeOfHeight(int blackHeight, bool leftmost);
    void setTree(RedBlackTree * newTree);
    RBTNode * findMinNode();
    RBTNode * findMaxNode();
    void rotateAfterRedColoring(RBTNode * currentNode);
    void resolveDoubleBlack(RBTNode * currentNode);
    bool hasLeftChild(RBTNode * currentNode);
    bool hasRightChild(RBTNode * currentNode);
};

#endif /* RedBlackTree_hpp */
