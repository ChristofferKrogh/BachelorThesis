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

struct RBTNode { // Red Black Tree Node
    int data;
    RBTNode * parent;
    RBTNode * leftChild = NULL;
    RBTNode * rightChild = NULL;
    bool black;
};

class RedBlackTree {
private:
    RBTNode * root;
    
private:
    void newNode(RBTNode * currentNode, int newValue);
    RBTNode * searchRecursive(RBTNode * currentNode, int searchValue);

    
public:
    RedBlackTree();
    void createNode(int value);
    void createTree(int * values, int listSize);
    void display();
    void inOrder(RBTNode * currentNode);
    RBTNode * search(int searchValue);
//    void shift(int shiftValue);
//    void merge(RedBlackTree * newTree);
//    RedBlackTree split(int splitValue);
};

#endif /* RedBlackTree_hpp */
