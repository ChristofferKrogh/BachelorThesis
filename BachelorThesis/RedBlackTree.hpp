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
#include <tuple>
//#include <stdexcept>

struct RBTNode { // Red Black Tree Node
    int data;
    RBTNode * parent;
    RBTNode * leftChild;
    RBTNode * rightChild;
    int shift;
    bool isBlack;
    RBTNode() {
        this->parent = nullptr;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
        this->shift = 0;
        this->isBlack = false;
    }
    RBTNode(int data, RBTNode * parent, RBTNode * leftChild, RBTNode * rightChild, int shift, bool isBlack){
        this->data = data;
        this->parent = parent;
        this->leftChild = leftChild;
        this->rightChild = rightChild;
        this->shift = shift;
        this->isBlack = isBlack;
    }
    bool hasLeftChild() {
        return leftChild != NULL;
    }
    bool hasRightChild() {
        return rightChild != NULL;
    }
//    RBTNode * copy() {
//        RBTNode * copy = new RBTNode;
//        copy->data = this->data;
//        copy->parent = this->parent;
//        copy->leftChild = this->leftChild;
//        copy->rightChild = this->rightChild;
//        copy->shift = this->shift;
//        copy->isBlack = this->isBlack;
//        return copy;
//    }
};

class RedBlackTree {
private:
    void createNode(RBTNode * currentNode, int newValue);
    RBTNode * predecessorSearch(RBTNode * currentNode, int searchValue, int totalShift);
    void rotateTree(RBTNode * newNode);
    void inOrder(RBTNode * currentNode, bool showDetails, int currentShiftValue);
    bool checkRedCriteria(RBTNode * currentNode);
    void fixLineFormation(RBTNode * newNode);
    void fixZigZagFormation(RBTNode * newNode);
    int checkBlackHeight(RBTNode * currentNode);
    void reduceBlackHeight(RBTNode *& node, bool goingLeft);
    void pushShiftDown(RBTNode * node);

public:
    RBTNode * root;
    
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
    void join(RedBlackTree * newTree);
    void erase();
    void deleteMinNode();
    void deleteMaxNode();
    int blackHeightAssumingValid(RBTNode * currentNode);
    std::tuple<RBTNode *, int> getNodeOfHeight(int blackHeight, bool leftmost);
    void setTree(RedBlackTree * newTree);
    RBTNode * findMinNode();
    RBTNode * findMaxNode();
    RBTNode * findMinNodeWithTotalShift();
    RBTNode * findMaxNodeWithTotalShift();
    void rotateAfterRedColoring(RBTNode * currentNode);
    void resolveDoubleBlack(RBTNode * currentNode);
    RBTNode * bigTreeJoin(RBTNode * root, RBTNode * pb, RBTNode * lTb);
    RBTNode * smallTreeJoin(RBTNode * root, RBTNode * ps, RBTNode * rTs);
    RedBlackTree * split(int splitValue, bool includeSplitValue);
};

#endif /* RedBlackTree_hpp */
