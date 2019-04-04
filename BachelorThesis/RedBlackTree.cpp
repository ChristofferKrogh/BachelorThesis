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
    minNode = nullptr;
    maxNode = nullptr;
}

int RedBlackTree::getBlackHeight() {
    return this->blackHeight(root);
}

void RedBlackTree::createNode(int value){
    if (root == nullptr) {
        RBTNode * newNode = new RBTNode;
        newNode->data = value;
        root = minNode = maxNode = newNode;
        root->isBlack = true;
    } else {
        createNode(root, value);
    }
}

void RedBlackTree::createNode(RBTNode * currentNode, int newValue) {
    if (newValue < currentNode->data) {
        if (currentNode->leftChild != NULL) {
            createNode(currentNode->leftChild, newValue);
        } else {
            RBTNode * newNode = new RBTNode;
            newNode->data = newValue;
            newNode->isBlack = false;
            newNode->parent = currentNode;
            currentNode->leftChild = newNode;
            if (newValue < minNode->data) {
                minNode = newNode;
            }
            rotateTree(newNode);
        }
    } else if (newValue > currentNode->data) {
        if (currentNode->rightChild != NULL) {
            createNode(currentNode->rightChild, newValue);
        } else {
            RBTNode * newNode = new RBTNode;
            newNode->data = newValue;
            newNode->isBlack = false;
            newNode->parent = currentNode;
            currentNode->rightChild = newNode;
            if (newValue > maxNode->data) {
                maxNode = newNode;
            }
            rotateTree(newNode);
        }
    }
}

void RedBlackTree::createTree(int * values, int listSize){
    if (listSize < 1) {
        // do nothing
    } else {
        createNode(values[0]);
        for (int i = 1; i < listSize; i++) {
            createNode(root, values[i]);
        }
    }
}

void RedBlackTree::rotateTree(RBTNode * newNode) {
    // There are three types of rotations:
    // 1. b-r-r in line formation
    // 2. b-r-r in zig-zag formation
    // 3. red uncle formation
    // I might only have to check if I should rotate at the new node
    
    // How do I check if I have one of these formations?
    // I can use the parent pointer here. I will get the parent and grandparent of the new node. I can use their values and colors to see if I have special formation. NOTE: check that grandparent isn't NULL. Another way to put this: if the parent is the root then there is no special formation
    if ((newNode == root) || (newNode->parent == root)) { // do nothing
    } else if (!(newNode->parent->isBlack)) { // if parent is red then there is a formation
        RBTNode * parent = newNode->parent;
        RBTNode * grandparent = parent->parent;
        RBTNode * uncle;
        if (grandparent->leftChild == parent) {
            uncle = grandparent->rightChild;
        } else {
            uncle = grandparent->leftChild;
        }
        if (uncle != NULL && !uncle->isBlack) { // if parent and uncle are red then we simply need to recolor
            parent->isBlack = true;
            uncle->isBlack = true;
            if (grandparent != root) {
                grandparent->isBlack = false;
                rotateTree(grandparent);
            }
        } else {
            // if (grandparent < parent) == (parent < newNode) then line else zig zag
            if ((grandparent->data < parent->data) ==
                (parent->data < newNode->data)) { // line formation
                fixLineFormation(newNode);
            } else { // zig-zag formation
                fixZigZagFormation(newNode);
            }
        }
    }
}

void RedBlackTree::fixLineFormation(RBTNode * newNode) {
    RBTNode * parent = newNode->parent;
    RBTNode * grandparent = parent->parent;
    if (grandparent->parent == NULL) { // grandparent is the root
        parent->parent = NULL;
        parent->isBlack = true;
        root->parent = parent;
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
        if (parent->leftChild != NULL) {
            parent->leftChild->parent = grandparent;
        }
        grandparent->rightChild = parent->leftChild;
        grandparent->parent = parent;
        parent->leftChild = grandparent;
        parent->rightChild = newNode;
    } else {
        if (parent->rightChild != NULL) {
            parent->rightChild->parent = grandparent;
        }
        grandparent->leftChild = parent->rightChild;
        grandparent->parent = parent;
        parent->rightChild = grandparent;
        parent->leftChild = newNode;
    }
}

void RedBlackTree::fixZigZagFormation(RBTNode * newNode) {
    RBTNode * parent = newNode->parent;
    RBTNode * grandparent = parent->parent;
    if (newNode->data < parent->data) {
        parent->leftChild = newNode->rightChild;
        parent->parent = newNode;
        newNode->rightChild = parent;
        newNode->parent = grandparent;
        grandparent->rightChild = newNode;
    } else {
        parent->rightChild = newNode->leftChild;
        parent->parent = newNode;
        newNode->leftChild = parent;
        newNode->parent = grandparent;
        grandparent->leftChild = newNode;
    }
    fixLineFormation(parent);
}

bool RedBlackTree::isTreeValid() {
    // A red node must not have a red child.
    // All root to leaf paths must have the same amount of black nodes.
    //  -
    if (root == NULL) {
        return true;
    }
    if (!(root->isBlack)) { // if the root is not black then the tree is not valid
        return false;
    }
    if (blackHeight(root) == -1) {
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

int RedBlackTree::blackHeight(RBTNode * currentNode) {
    if (currentNode == NULL) { // should maybe return 1 instead
        return 0;
    }
    int leftBlackHeight = blackHeight(currentNode->leftChild);
    int rightBlackHeight = blackHeight(currentNode->rightChild);
    if (leftBlackHeight == -1 || rightBlackHeight == -1) { // One of the children is an invalid subtree
        return -1;
    } else if (leftBlackHeight != rightBlackHeight) { // The black heights of the two subtrees are different -> tree is invalid
        return -1;
    } else {
        if (currentNode->isBlack) {
            return leftBlackHeight + 1;
        } else {
            return leftBlackHeight;
        }
    }
    return 0;
}

//void RedBlackTree::restoreRBTProperties(RBTNode * currentNode) {
//    if (currentNode == NULL) {
//    } else {
//        if (!currentNode->isBlack && !currentNode->parent->isBlack) {
//            rotateTree(currentNode);
//        }
//        restoreRBTProperties(currentNode->leftChild);
//        restoreRBTProperties(currentNode->rightChild);
//    }
//}

void RedBlackTree::erase() {
    root = nullptr;
    minNode = nullptr;
    maxNode = nullptr;
}

void RedBlackTree::display(bool showDetails){
    if (showDetails) {
        std::cout << "The black height of the tree is: " << blackHeight(root) << "\n";
    }
    inOrder(root, showDetails);
}

void RedBlackTree::inOrder(RBTNode * currentNode, bool showDetails) {
    if (currentNode != NULL) {
        inOrder(currentNode->leftChild, showDetails);
        std::cout << currentNode->data << " ";
        if (showDetails) {
            if (currentNode->parent != NULL) {
                std::cout << "(p: " << currentNode->parent->data << (currentNode->isBlack? ", b" : ", r") << "), ";
            } else {
                std::cout << "(root, " << (currentNode->isBlack? "b), " : "r), ");
            }
        }
        inOrder(currentNode->rightChild, showDetails);
    }
}

RBTNode * RedBlackTree::search(int searchValue){
    if (root == NULL) {
        std::cout << "Tree is empty\n";
        return NULL;
    }
    return predecessorSearch(root, searchValue);
}

RBTNode * RedBlackTree::predecessorSearch(RBTNode * currentNode, int searchValue) {
    if (currentNode == NULL) {
        return NULL;
    } else if (searchValue == currentNode->data) {
        return currentNode;
    } else if (searchValue < currentNode->data) {
        if (currentNode->leftChild == NULL) {
            while (currentNode->data > searchValue) {
                currentNode = currentNode->parent;
                if (currentNode == NULL) {
                    std::cout << "No node smaller than or equal to search value exists\n";
                    return NULL;
                }
            }
            return currentNode;
        } else {
            return predecessorSearch(currentNode->leftChild, searchValue);
        }
    } else if (searchValue > currentNode->data) {
        if (currentNode->rightChild == NULL) {
            return currentNode;
        } else {
            return predecessorSearch(currentNode->rightChild, searchValue);
        }
    }
    return NULL;
}

void RedBlackTree::join(RedBlackTree * newTree) {
    int blackHeightOriginal = this->getBlackHeight();
    int blackHeightNew = newTree->getBlackHeight();
    RBTNode * currentNode;
    if (this->maxNode->data < newTree->minNode->data) { // All nodes in this tree are smaller than all nodes in the new tree
        if (blackHeightOriginal <= blackHeightNew) { // search down in the new tree
            currentNode = newTree->root;
            while (blackHeightOriginal != blackHeightNew) {
                currentNode = currentNode->leftChild;
                blackHeightNew = blackHeight(currentNode);
            }
            if (!currentNode->isBlack) {
                currentNode = currentNode->leftChild;
            }
            RBTNode * currentParent = currentNode->parent;
            RBTNode * newParent = newTree->minNode;
            newTree->minNode->parent->leftChild = nullptr;
            
            newParent->isBlack = false;
            newParent->parent = currentParent;
            currentParent->leftChild = newParent;
            newParent->leftChild = this->root;
            newParent->rightChild = currentNode;
            this->root->parent = newParent;
            currentNode->parent = newParent;
            // Update the root of this tree
            if (currentParent == NULL) {
                this->root = newParent;
                newParent->isBlack = true;
            } else {
                this->root = newTree->root;
                rotateTree(newParent);
            }
            
            newTree->erase();
            
            
        } else { // search down in this tree
            currentNode = this->root;
            while (blackHeightOriginal != blackHeightNew) {
                currentNode = currentNode -> rightChild;
                blackHeightOriginal = blackHeight(currentNode);
            }
            if (!currentNode->isBlack) {
                currentNode = currentNode->rightChild;
            }
        }
    } else if (this->minNode->data > newTree->maxNode->data) { // All nodes in this tree are bigger than all nodes in the new tree
        
    } else { // Join error
        std::cout << "The join prerequistes are not met\n";
    }
}

//RedBlackTree RedBlackTree::split(int splitValue){
//
//    return *new RedBlackTree();
//}

//void RedBlackTree::shift(int shiftValue){
//
//}

//void RedBlackTree::merge(RedBlackTree * newTree){
//
//}


