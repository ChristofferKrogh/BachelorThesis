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

struct RBTNode { // Red Black Tree Node
    int data;
    RBTNode * parent;
    RBTNode * leftChild;
    RBTNode * rightChild;
    bool black;
};

class RedBlackTree {
private:
    RBTNode * root;
    
public:
    RedBlackTree();
    void createNode(int value);
    void createTree(int * values, int listSize);
    void display();
    RBTNode * search(int searchValue);
    void shift(int shiftValue);
    void merge(RedBlackTree * newTree);
    RedBlackTree split(int splitValue);
};

#endif /* RedBlackTree_hpp */
