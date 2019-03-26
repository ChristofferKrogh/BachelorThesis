//
//  RedBlackTree.cpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 17/03/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//

#include "RedBlackTree.hpp"

RedBlackTree::RedBlackTree(){
    root = nullptr;
}

void RedBlackTree::createNode(int value){
    if (root == nullptr) {
        RBTNode * newNode = new RBTNode;
        newNode->data = value;
        root = newNode;
        root->isBlack = true;
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
            newNode->isBlack = false;
            newNode->parent = currentNode;
            currentNode->leftChild = newNode;
            rotateTree(newNode);
        }
    } else if (newValue > currentNode->data) {
        if (currentNode->rightChild != NULL) {
            newNode(currentNode->rightChild, newValue);
        } else {
            RBTNode * newNode = new RBTNode;
            newNode->data = newValue;
            newNode->isBlack = false;
            newNode->parent = currentNode;
            currentNode->rightChild = newNode;
            rotateTree(newNode);
        }
    }
}

void RedBlackTree::rotateTree(RBTNode * newNode) {
    // There are two types of rotations:
    // 1. b-r-r in line formation
    // 2. b-r-r in zig-zag formation
    // I might only have to check if I should rotate at the new node
    
    // How do I check if I have one of these formations?
    // I can use the parent pointer here. I will get the parent and grandparent of the new node. I can use their values and colors to see if I have special formation. NOTE: check that grandparent isn't NULL. Another way to put this: if the parent is the root then there is no special formation
    if (newNode->parent == root) {
    } else if (!(newNode->parent->isBlack)) { // if parent is red then there is a formation
        // if (grandparent < parent) == (parent < newNode) then line else zig zag
        if ((newNode->parent->parent->data < newNode->parent->data) ==
            (newNode->parent->data < newNode->data)) { // line formation
            fixLineFormation(newNode);
        } else { // zig-zag formation
            fixZigZagFormation(newNode);
        }
    }
}

void RedBlackTree::fixLineFormation(RBTNode * newNode) {
    RBTNode * parent = newNode->parent;
    RBTNode * grandparent = parent->parent;
    if (grandparent->parent == NULL) { // grandparent is the root
        parent->parent = NULL;
        root = parent;
    } else if (grandparent->parent->leftChild == grandparent) { // the grandparent is the left child
        grandparent->parent->leftChild = parent;
        parent->parent = grandparent->parent;
    } else { // the grandparent is the right child
        grandparent->parent->rightChild = parent;
        parent->parent = grandparent->parent;
    }
    parent->isBlack = true;
    grandparent->isBlack = false;
    newNode->isBlack = false;
    if (grandparent->data < parent->data) {
        grandparent->rightChild = parent->leftChild;
        parent->leftChild = grandparent;
        parent->rightChild = newNode;
    } else {
        grandparent->leftChild = parent->rightChild;
        parent->rightChild = grandparent;
        parent->leftChild = newNode;
    }
}

void RedBlackTree::fixZigZagFormation(RBTNode * newNode) {
    RBTNode * parent = newNode->parent;
    RBTNode * grandparent = parent->parent;
    if (newNode->data < parent->data) {
        parent->leftChild = newNode->rightChild;
        newNode->rightChild = parent;
        newNode->parent = grandparent;
        grandparent->rightChild = newNode;
    } else {
        parent->rightChild = newNode->leftChild;
        newNode->leftChild = parent;
        newNode->parent = grandparent;
        grandparent->leftChild = newNode;
    }
    fixLineFormation(parent);
}

void RedBlackTree::createTree(int * values, int listSize){
    createNode(values[0]);
    for (int i = 1; i < listSize; i++) {
        newNode(root, values[i]);
    }
}

bool RedBlackTree::checkTreeValidity() {
    // A red node must not have a red child.
    // All root to leaf paths must have the same amount of black nodes.
    //  -
    if (root == NULL) {
        return true;
    }
    if (!(root->isBlack)) { // if the root is not black then the tree is not valid
        return false;
    }
    return checkRedCriteria(root);
}

bool RedBlackTree::checkRedCriteria(RBTNode * currentNode) {
    if (currentNode == NULL) {
        return true;
    }
    
    if (!(checkRedCriteria(currentNode->leftChild))) { // If the left child does not satisfy the red criteria
        return false;
    }
    
    if (!(checkRedCriteria(currentNode->rightChild))) { // If the right child does not satisfy the red criteria
        return false;
    }
    
    if (!(currentNode->isBlack)) { // If the node is red and has a red parent then the tree is not valid
        if (!(currentNode->parent->isBlack)) {
            std::cout << "\nDet går galt ved " << currentNode->data << std::endl;
            return false;
        }
    }
    return true;
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
    return NULL;
    return searchRecursive(root, searchValue);
}

RBTNode * RedBlackTree::searchRecursive(RBTNode * currentNode, int searchValue) {
    return NULL;
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

//void RedBlackTree::createTestTree() {
//    RBTNode * newNode = new RBTNode;
//    newNode->
//}

void RedBlackTree::testDisplay() {
//    std::cout << "        " << root->data << " ("<< root->isBlack << ")" << std::endl;
//    std::cout << "  " << root->leftChild->data << " ("<< root->leftChild->isBlack << ")" << "    " << root->rightChild->data << " ("<< root->rightChild->isBlack << ")" << std::endl;
//    std::cout << "              " << root->rightChild->rightChild->data << " ("<< root->rightChild->rightChild->isBlack << ")" << std::endl;
    std::cout << root->data << " " << root->isBlack << std::endl;
    std::cout << root->leftChild->data << " " << root->isBlack << std::endl;
    std::cout << root->leftChild->leftChild->data << " " << root->isBlack << std::endl;
}
