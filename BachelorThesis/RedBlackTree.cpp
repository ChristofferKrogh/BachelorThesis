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
        this->newNode(root, value);
    }
}

void RedBlackTree::newNode(RBTNode * currentNode, int newValue) {
    if (newValue <= currentNode->data) {
        if (currentNode->leftChild != NULL) {
            newNode(currentNode->leftChild, newValue);
        } else {
            RBTNode * newNode = new RBTNode;
            newNode->data = newValue;
            newNode->black = false;
            currentNode->leftChild = newNode;
        }
    } else if (newValue > currentNode->data) {
        if (currentNode->rightChild != NULL) {
            newNode(currentNode->rightChild, newValue);
        } else {
            RBTNode * newNode = new RBTNode;
            newNode->data = newValue;
            newNode->black = false;
            currentNode->rightChild = newNode;
        }
    }
}

void RedBlackTree::createTree(int * values, int listSize){
    createNode(values[0]);
    for (int i = 1; i < listSize; i++) {
        newNode(root, values[i]);
    }
}

void RedBlackTree::display(){
    inOrder(root);
}

void RedBlackTree::inOrder(RBTNode * currentNode) {
    if (currentNode != NULL) {
        inOrder(currentNode->leftChild);
        std::cout << currentNode->data << " ";
        inOrder(currentNode->rightChild);
    }
}

RBTNode * RedBlackTree::search(int searchValue){
    if (root == NULL) {
        std::cout << "Tree is empty\n";
        return NULL;
    }
    return searchRecursive(root, searchValue);
}

RBTNode * RedBlackTree::searchRecursive(RBTNode * currentNode, int searchValue) {
    
}

//void RedBlackTree::shift(int shiftValue){
//
//}

//void RedBlackTree::merge(RedBlackTree * newTree){
//
//}

//RedBlackTree RedBlackTree::split(int splitValue){
//
//    return *new RedBlackTree();
//}
