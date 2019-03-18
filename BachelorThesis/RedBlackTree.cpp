//
//  RedBlackTree.cpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 17/03/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//

#include "RedBlackTree.hpp"

RedBlackTree::RedBlackTree(){
    root = NULL;
}

void RedBlackTree::createNode(int value){
    RBTNode * newNode = new RBTNode;
    newNode->data = value;
    newNode->black = false;
    
    if (root == NULL) {
        newNode->parent = NULL;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->black = true;
        root = newNode;
    } else {
        
    }
}

void RedBlackTree::createTree(int * values, int listSize){
    
}

void RedBlackTree::display(){
    RBTNode * currentNode;
}

RBTNode * RedBlackTree::search(int searchValue){
    RBTNode * currentNode;
    return NULL;
}

void RedBlackTree::shift(int shiftValue){
    
}

void RedBlackTree::merge(RedBlackTree * newTree){
    
}

RedBlackTree RedBlackTree::split(int splitValue){
    
    return *new RedBlackTree();
}
