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

int RedBlackTree::getBlackHeight() {
    if (root == NULL) {
        return 0;
    } else {
        return this->blackHeightAssumingValid(root);
    }
}

void RedBlackTree::createNode(int value){
    if (root == nullptr) {
        RBTNode * newNode = new RBTNode;
        newNode->data = value;
        root = newNode;
        root->isBlack = true;
    } else {
        createNode(root, value);
    }
}

void RedBlackTree::createNode(RBTNode * currentNode, int newValue) {
    newValue -= currentNode->shift;
    if (newValue < currentNode->data) {
        if (currentNode->hasLeftChild()) {
            createNode(currentNode->leftChild, newValue);
        } else {
            RBTNode * newNode = new RBTNode;
            newNode->data = newValue;
            newNode->isBlack = false;
            newNode->parent = currentNode;
            currentNode->leftChild = newNode;
            rotateTree(newNode);
        }
    } else if (newValue > currentNode->data) {
        if (currentNode->hasRightChild()) {
            createNode(currentNode->rightChild, newValue);
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

void RedBlackTree::createTree(int * values, int listSize){
    if (listSize >= 1) {
        createNode(values[0]);
        for (int i = 1; i < listSize; i++) {
            createNode(root, values[i]);
        }
    }
}

void RedBlackTree::rotateTree(RBTNode * newNode) {
    // There are three types of standard rotations:
    // 1. black-red-red in line formation
    // 2. b-r-r in zig-zag formation
    // 3. red uncle formation
    
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
    if (grandparent == root) {
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
    grandparent->parent = parent;
    if (grandparent->data < parent->data) {
        if (parent->hasLeftChild()) {
            parent->leftChild->parent = grandparent;
        }
        grandparent->rightChild = parent->leftChild;
        // The grandparent must not feel the effect of the shift of the parent - but the right child of the grandparent needs the shift of the parent.
        if (grandparent->hasRightChild()) {
            grandparent->rightChild->shift += parent->shift;
        }
        parent->leftChild = grandparent;
        parent->rightChild = newNode;
    } else {
        if (parent->hasRightChild()) {
            parent->rightChild->parent = grandparent;
        }
        grandparent->leftChild = parent->rightChild;
        // The grandparent must not feel the effect of the shift of the parent - but the left child of the grandparent needs the shift of the parent.
        if (grandparent->hasLeftChild()) {
            grandparent->leftChild->shift += parent->shift;
        }
        parent->rightChild = grandparent;
        parent->leftChild = newNode;
    }
    
    // Update shift values
    parent->shift += grandparent->shift;
    grandparent->shift -= parent->shift;
}

void RedBlackTree::fixZigZagFormation(RBTNode * newNode) {
    RBTNode * parent = newNode->parent;
    RBTNode * grandparent = parent->parent;
    if (newNode->data < parent->data) {
        parent->leftChild = newNode->rightChild;
        if (parent->hasLeftChild()) {
            parent->leftChild->shift += newNode->shift; // Update shift
        }
        parent->parent = newNode;
        newNode->rightChild = parent;
        newNode->parent = grandparent;
        grandparent->rightChild = newNode;
    } else {
        parent->rightChild = newNode->leftChild;
        if (parent->hasRightChild()) {
            parent->rightChild->shift += newNode->shift; // Update shift
        }
        parent->parent = newNode;
        newNode->leftChild = parent;
        newNode->parent = grandparent;
        grandparent->leftChild = newNode;
    }
    
    // Update shift values
    newNode->shift += parent->shift;
    parent->shift -= newNode->shift;
    
    fixLineFormation(parent);
}

bool RedBlackTree::isTreeValid() {
    // A red node must not have a red child.
    // All root to leaf paths must have the same amount of black nodes.
    // root must be black and cannot have a parent
    if (root == NULL) {
        return true;
    }
    if (!(root->isBlack)) { // if the root is not black then the tree is not valid
        std::cout << "Root is red\n";
        return false;
    }
    if (root->parent != NULL) {
        std::cout << "Root has a parent\n";
        return false;
    }
    if (checkBlackHeight(root) == -1) {
        return false;
    }
    return checkRedCriteria(root);
}

bool RedBlackTree::checkRedCriteria(RBTNode * currentNode) {
    if (currentNode == NULL) {
        return true;
    }
    
    if ((currentNode->hasLeftChild() && (currentNode->leftChild->data + currentNode->leftChild->shift) > currentNode->data) ||
        (currentNode->hasRightChild() &&
         (currentNode->rightChild->data + currentNode->rightChild->data) < currentNode->data)) {
            std::cout << "The node with value " << currentNode->data << " has at least one child that is misplaced\n";
            return false;
    }
    
    if (!(currentNode->isBlack)) { // If the node is red and has a red parent then the tree is not valid
        if (!(currentNode->parent->isBlack)) {
            std::cout << "\nThe red criteria is violated at: " << currentNode->data << std::endl;
            return false;
        }
    }
    
    return checkRedCriteria(currentNode->leftChild) && checkRedCriteria(currentNode->rightChild);
}

int RedBlackTree::checkBlackHeight(RBTNode * currentNode) {
    if (currentNode == NULL) {
        return 1;
    }
    int leftBlackHeight = checkBlackHeight(currentNode->leftChild);
    int rightBlackHeight = checkBlackHeight(currentNode->rightChild);
    if (leftBlackHeight == -1 || rightBlackHeight == -1) { // One of the children is an invalid subtree
        return -1;
    } else if (leftBlackHeight != rightBlackHeight) { // The black heights of the two subtrees are different -> tree is invalid
        std::cout << "The black criteria is violated at: " << currentNode->data << std::endl;
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

int RedBlackTree::blackHeightAssumingValid(RBTNode * currentNode) {
    if (currentNode == NULL) {
        return 1;
    } else if (currentNode->isBlack) {
        return blackHeightAssumingValid(currentNode->leftChild) + 1;
    } else {
        return blackHeightAssumingValid(currentNode->leftChild);
    }
}

std::tuple<RBTNode *, int> RedBlackTree::getNodeOfHeight(int blackHeight, bool leftmost) {
    // This method starts from the leftmost/rightmost node in the tree i.e. the minNode/maxNode and works its way up the tree until it reaches a node of the specified black height. This method will always return a black node except if the specified height is 1. In this case it will return the minNode/maxNode.
    // a null pointer exception will be thrown if the specified black height is too big.
    int currentBlackHeight = 1;
    RBTNode * currentNode = root;
    int totalShift = 0;
    totalShift += currentNode->shift;
    if (leftmost) {
        while (currentNode->hasLeftChild()) {
            currentNode = currentNode->leftChild;
            totalShift += currentNode->shift;
        }
    } else { // If not leftmost then rightmost will be returned
        while (currentNode->hasRightChild()) {
            currentNode = currentNode->rightChild;
            totalShift += currentNode->shift;
        }
    }
    
    if (currentNode->isBlack) {
        currentBlackHeight++;
    }
    while (currentBlackHeight < blackHeight) {
        totalShift -= currentNode->shift;
        currentNode = currentNode->parent;
        if (currentNode->isBlack) {
            currentBlackHeight++;
        }
    }
    return std::make_tuple(currentNode, totalShift);
}

void RedBlackTree::erase() {
    root = nullptr;
}

void RedBlackTree::setTree(RedBlackTree * newTree) {
    this->root = newTree->root;
}

void RedBlackTree::display(bool showDetails){
    if (showDetails) {
        std::cout << "The black height of the tree is: " << getBlackHeight() << "\n";
    }
    inOrder(root, showDetails, 0);
    std::cout << std::endl;
}

void RedBlackTree::inOrder(RBTNode * currentNode, bool showDetails, int currentShiftValue) {
    if (currentNode != NULL) {
        currentShiftValue += currentNode->shift;
        inOrder(currentNode->leftChild, showDetails, currentShiftValue);
        std::cout << currentNode->data + currentShiftValue << " ";
        if (showDetails) {
            if (currentNode->parent != NULL) {
                std::cout << "(p: " << currentNode->parent->data + currentShiftValue - currentNode->shift << (currentNode->isBlack? ", b" : ", r") << "), ";
            } else {
                std::cout << "(root, " << (currentNode->isBlack? "b), " : "r), ");
            }
        }
        inOrder(currentNode->rightChild, showDetails, currentShiftValue);
    }
}

RBTNode * RedBlackTree::search(int searchValue){
    if (root == NULL) {
        throw "Tree is empty";
    }
    return predecessorSearch(root, searchValue, 0);
}

RBTNode * RedBlackTree::predecessorSearch(RBTNode * currentNode, int searchValue, int totalShift) {
    if (currentNode == NULL) {
        throw "Somehow the currentNode is NULL";
    } else {
        totalShift += currentNode->shift;
    }
    
    if (searchValue == (currentNode->data + totalShift)) {
        //return std::make_tuple(currentNode, totalShift);
        RBTNode * resultCopy = new RBTNode(currentNode->data, currentNode->parent, currentNode->leftChild, currentNode->rightChild, totalShift, currentNode->isBlack);
        return resultCopy;
    } else if (searchValue < (currentNode->data + totalShift)) {
        if (currentNode->hasLeftChild()) {
           return predecessorSearch(currentNode->leftChild, searchValue, totalShift);
        } else {
            while (searchValue < (currentNode->data + totalShift)) {
                totalShift -= currentNode->shift;
                currentNode = currentNode->parent;
                if (currentNode == NULL) {
                    return nullptr;
                }
            }
            //return std::make_tuple(currentNode, totalShift);
            RBTNode * resultCopy = new RBTNode(currentNode->data, currentNode->parent, currentNode->leftChild, currentNode->rightChild, totalShift, currentNode->isBlack);
            return resultCopy;

        }
    } else if (searchValue > (currentNode->data + totalShift)) {
        if (currentNode->hasRightChild()) {
            return predecessorSearch(currentNode->rightChild, searchValue, totalShift);
        } else {
            //return std::make_tuple(currentNode, totalShift);
            RBTNode * resultCopy = new RBTNode(currentNode->data, currentNode->parent, currentNode->leftChild, currentNode->rightChild, totalShift, currentNode->isBlack);
            return resultCopy;

        }
    }
    throw "Reached the end of search without finding a match";
}

RBTNode * RedBlackTree::findMinNode() {
    RBTNode * currentNode = root;
    if (currentNode != NULL) {
        while (currentNode->hasLeftChild()) {
            currentNode = currentNode->leftChild;
        }
    }
    return currentNode;
}

RBTNode * RedBlackTree::findMaxNode() {
    RBTNode * currentNode = root;
    if (currentNode != NULL) {
        while (currentNode->hasRightChild()) {
            currentNode = currentNode->rightChild;
        }
    }
    return currentNode;
}

RBTNode * RedBlackTree::findMinNodeWithTotalShift() {
    RBTNode * currentNode = root;
    int totalShift = 0;
    if (currentNode != NULL) {
        totalShift += currentNode->shift;
        while (currentNode->hasLeftChild()) {
            currentNode = currentNode->leftChild;
            totalShift += currentNode->shift;
        }
        RBTNode * resultCopy = new RBTNode(currentNode->data, currentNode->parent, currentNode->leftChild, currentNode->rightChild, totalShift, currentNode->isBlack);
        return resultCopy;
    } else {
        return  NULL;
    }
}

RBTNode * RedBlackTree::findMaxNodeWithTotalShift() {
    RBTNode * currentNode = root;
    int totalShift = 0;
    if (currentNode != NULL) {
        totalShift += currentNode->shift;
        while (currentNode->hasRightChild()) {
            currentNode = currentNode->rightChild;
            totalShift += currentNode->shift;
        }
        RBTNode * resultCopy = new RBTNode(currentNode->data, currentNode->parent, currentNode->leftChild, currentNode->rightChild, totalShift, currentNode->isBlack);
        return resultCopy;
    } else {
        return NULL;
    }
}

void RedBlackTree::rotateAfterRedColoring(RBTNode *currentNode) {
    // * = black,  = red
    
    //       p*                        curr
    //  l       curr      ->      p*       r*
    //        l      r         l    l
    
    bool isLeftChild = (currentNode->parent->leftChild == currentNode);
    RBTNode * parent = currentNode->parent;
    if (currentNode->hasLeftChild() &&
        !currentNode->leftChild->isBlack &&
        currentNode->hasRightChild() &&        !currentNode->rightChild->isBlack) { // Two red children
        if (isLeftChild) {
            parent->leftChild = currentNode->rightChild;
            parent->leftChild->parent = parent;
            currentNode->rightChild = parent;
            currentNode->leftChild->isBlack = true;
        } else {
            parent->rightChild = currentNode->leftChild;
            parent->rightChild->parent = parent;
            currentNode->leftChild = parent;
            currentNode->rightChild->isBlack = true;
        }
        currentNode->parent = parent->parent;
        parent->parent = currentNode;
        if (currentNode->parent != NULL) {
            currentNode->data > currentNode->parent->data? currentNode->parent->rightChild = currentNode : currentNode->parent->leftChild = currentNode;
            currentNode->isBlack = false;
        } else {
            root = currentNode;
            currentNode->isBlack = true;
        }
        
        // Update shift values
        if (isLeftChild) {
            parent->leftChild->shift += currentNode->shift;
        } else {
            parent->rightChild->shift += currentNode->shift;
        }
        currentNode->shift += parent->shift;
        parent->shift -= currentNode->shift;
    } else if (currentNode->hasLeftChild() &&
               !currentNode->leftChild->isBlack) { // only left child is red
        if (isLeftChild) {
            fixLineFormation(currentNode->leftChild);
        } else {
            fixZigZagFormation(currentNode->leftChild);
        }
    } else if(currentNode->hasRightChild() &&
              !currentNode->rightChild->isBlack) { // only right child is red
        if (isLeftChild) {
            fixZigZagFormation(currentNode->rightChild);
        } else {
            fixLineFormation(currentNode->rightChild);
        }
    }
    while (root->parent != NULL) {
        root = root->parent;
    }
}

void RedBlackTree::resolveDoubleBlack(RBTNode *currentNode) {
    // The currentNode is double-black
    // If the currentNode is the root, then nothing needs to be done
    bool isLeftChild = false;
    RBTNode * sibling;
    if (currentNode != root) {
        isLeftChild = currentNode->parent->leftChild == currentNode;
    }
    while (currentNode != root) {
        isLeftChild? sibling = currentNode->parent->rightChild : sibling = currentNode->parent->leftChild;
        // If the currentNode is red, we can simply color is black. Otherwise, we need to consider three cases:
        // 1. The parent is red. Here we can recolor the parent black and the sibling red (perform rotation on sibling afterwards)
        // 2. The parent is black and the sibling is red. Here we can recolor and rotate to achieve a situation equivalent to case 1.
        // 3. The parent is black and the sibling is black. Here we can recolor the sibling red (and perform rotations) and set the currentNode to be the parent. The approach is very similar to case 1
        if (!currentNode->isBlack) {
            currentNode->isBlack = true;
            currentNode = root;
        } else if (!currentNode->parent->isBlack) { // Case 1: the parent is red
            // Recolor
            currentNode->parent->isBlack = true;
            sibling->isBlack = false;
            rotateAfterRedColoring(sibling);
            // The currentNode pointer is set to point at the root, so the loop breaks
            currentNode = root;
        } else if (!sibling->isBlack) { // Case 2: the parent is black and the sibling is red
            // Plan: rotate and recolor to achieve a situation that corresponds to case 1.
            sibling->isBlack = true;
            currentNode->parent->isBlack = false;
            if (isLeftChild) {
                // Connect the sibling to the grandparent
                sibling->parent = currentNode->parent->parent;
                if (sibling->parent != NULL) {
                    sibling->parent->leftChild = sibling;
                }
                // Connect the parent to the left child of the sibling
                currentNode->parent->rightChild = sibling->leftChild;
                currentNode->parent->rightChild->parent = currentNode->parent;
                // Connect the sibling to the parent
                currentNode->parent->parent = sibling;
                sibling->leftChild = currentNode->parent;
                
                // Now we have the same situation as in case 1.
                // Recolor
                currentNode->parent->isBlack = true;
                currentNode->parent->rightChild->isBlack = false;
                
                // Update shift values
                sibling->shift += currentNode->parent->shift;
                currentNode->parent->shift -= sibling->shift;
                sibling->leftChild->rightChild->shift = sibling->leftChild->rightChild->shift - sibling->leftChild->shift + sibling->shift;
                
                rotateAfterRedColoring(currentNode->parent->rightChild);
            } else {
                // Connect the sibling to the grandparent
                sibling->parent = currentNode->parent->parent;
                if (sibling->parent != NULL) {
                    sibling->parent->rightChild = sibling;
                }
                // Connect the parent to the left child of the sibling
                currentNode->parent->leftChild = sibling->rightChild;
                currentNode->parent->leftChild->parent = currentNode->parent;
                // Connect the sibling to the parent
                currentNode->parent->parent = sibling;
                sibling->rightChild = currentNode->parent;
                
                // Now we have the same situation as in case 1.
                // Recolor
                currentNode->parent->isBlack = true;
                currentNode->parent->leftChild->isBlack = false;
                
                // Update shift values
                sibling->shift += currentNode->parent->shift;
                currentNode->parent->shift -= sibling->shift;
                sibling->rightChild->leftChild->shift = sibling->rightChild->leftChild->shift - sibling->rightChild->shift + sibling->shift;
                
                rotateAfterRedColoring(currentNode->parent->leftChild);
            }
            // The currentNode pointer is set to point at the root, so the loop breaks
            currentNode = root;
        } else { // Case 3: the parent and the sibling are both black
            // Recolor
            sibling->isBlack = false;
            if (isLeftChild && sibling->hasRightChild() && !sibling->rightChild->isBlack) {
                currentNode = sibling;
            } else if (isLeftChild && sibling->hasLeftChild() && !sibling->leftChild->isBlack) {
                currentNode = sibling->leftChild;
            } else if (!isLeftChild && sibling->hasLeftChild() && !sibling->leftChild->isBlack) {
                currentNode = sibling;
            } else if (!isLeftChild && sibling->hasRightChild() && !sibling->rightChild->isBlack) {
                currentNode = sibling->rightChild;
            } else {
                currentNode = currentNode->parent;
            }
            rotateAfterRedColoring(sibling);
        }
    }
}

void RedBlackTree::deleteMinNode() {
    // The min node cannot have any left children - otherwise it wouldn't be the min node. Since it has no left children, it cannot have any black nodes in its right subtree. This means that the min node can have at most one child and this child must be red. Consequently, the min node cannot have any children if it is colored red.
    // If the min node is red then it can simply be removed.
    // If it is the case that the min node is black and has a red child, then the min node will be replaced by its child and the child will be colored black
    // If the min node is black, does not have any children and has a red parent, then the sibling must also be black. In this case, the parent will be colored black and the min node and its sibling will be colored red. If the sibling has any children (they must be red) then some rotations are required. Before the rotations are carried out, the min node is removed.
    // if the min node is black, has no children, a black parent and a red sibling, then the sibling must have two black cildren. In this case we can perform a special rotation
    // If the min node is black, has no children a black parent and a black sibling, then we will color the min node and its sibling red and mark the parent as double black. We will have to resolve this double black - but first, we need to rotate the tree if the sibling had any children.
    
    // find min node
    RBTNode * minNode = root;
    while (minNode->hasLeftChild()) {
        minNode = minNode->leftChild;
    }
    
    if (!minNode->isBlack) { // the min node is simply removed
        minNode->parent->leftChild = nullptr;
    } else if (minNode->hasRightChild()) { // the min node is replaced by its child
        if (minNode != root) {
            minNode->parent->leftChild = minNode->rightChild;
            minNode->rightChild->parent = minNode->parent;
        } else {
            minNode->rightChild->parent = nullptr;
            root = minNode->rightChild;
        }
        minNode->rightChild->isBlack = true;
    } else if (minNode == root) { // We wish to delete the root, and the root has no children. Therefore we erase the tree.
        erase();
    } else if (!minNode->parent->isBlack) { // if the parent is red then the min node and its sibling are black. I will recolor and rotate
        // Recolor
        minNode->parent->isBlack = true;
        minNode->parent->rightChild->isBlack = false;
        // Remove minNode
        minNode->parent->leftChild = nullptr;
        rotateAfterRedColoring(minNode->parent->rightChild);
    } else if (!minNode->parent->rightChild->isBlack) { // The minNode is black, has no children and a black parent. Since the minNode is black, it must have a sibling. If that sibling is red then it must have two black children.
        // Plan: Recolor and rotate to achieve the situation above
        RBTNode * parent = minNode->parent;
        RBTNode * sibling = minNode->parent->rightChild;
        // Firstly, recolor
        parent->isBlack = false;
        sibling->isBlack = true;
        // Secondly, rotate
        parent->rightChild = sibling->leftChild;
        parent->rightChild->parent = parent;
        sibling->leftChild = parent;
        sibling->parent = parent->parent;
        parent->parent = sibling;
        if (sibling->parent != NULL) {
            sibling->parent->leftChild = sibling;
        } else {
            root = sibling;
        }
        // Update shift
        parent->rightChild->shift += sibling->shift;
        sibling->shift += parent->shift;
        parent->shift -= sibling->shift;
        
        
        // Now, we have the same situation as above, so the solution is the same.
        // Recolor
        minNode->parent->isBlack = true;
        minNode->parent->rightChild->isBlack = false;
        // Remove minNode
        minNode->parent->leftChild = nullptr;
        rotateAfterRedColoring(minNode->parent->rightChild);
    } else { // minNode is black and has no children. The parent and sibling are also black.
        // Plan: delete minNode, color sibling red (and rotate if necessary) and consider the parent of minNode as a double-black node. Resolve this double-blackness
        // Remove minNode
        minNode->parent->leftChild = nullptr;
        minNode = minNode->parent;
        // Recolor and rotate
        minNode->rightChild->isBlack = false;
        // Rotate - Note: minNode is now the parent of the original minNode
        // We might have to resolve a double-black after deleting the minNode, so we have to find out which node is gonna be on top after the rotation
        RBTNode * topNode = minNode;
        if (minNode->rightChild->hasRightChild() && !minNode->rightChild->rightChild->isBlack) {
            topNode = minNode->rightChild;
        } else if (minNode->rightChild->hasLeftChild() &&
                   !minNode->rightChild->leftChild->isBlack) {
            topNode = minNode->rightChild->leftChild;
        }
        rotateAfterRedColoring(minNode->rightChild);
        // Resolve double-blackness of the new topNode
        resolveDoubleBlack(topNode);
    }
}

void RedBlackTree::deleteMaxNode() {
    // This will be symmetric/equivalent to deleteMinNode()
    
    // Find max node
    RBTNode * maxNode = root;
    while (maxNode->hasRightChild()) {
        maxNode = maxNode->rightChild;
    }
    
    if (!maxNode->isBlack) { // the max node is simply removed
        maxNode->parent->rightChild = nullptr;
    } else if (maxNode->hasLeftChild()) { // the max node is replaced by its child
        if (maxNode != root) {
            maxNode->parent->rightChild = maxNode->leftChild;
            maxNode->leftChild->parent = maxNode->parent;
        } else {
            maxNode->leftChild->parent = nullptr;
            root = maxNode->leftChild;
        }
        maxNode->leftChild->isBlack = true;
    } else if (maxNode == root) { // We wish to delete the root, and the root has no children. Therefore we erase the tree.
        erase();
    } else if (!maxNode->parent->isBlack) { // if the parent is red then the max node and its sibling are black. I will recolor and rotate
        // Recolor
        maxNode->parent->isBlack = true;
        maxNode->parent->leftChild->isBlack = false;
        // Remove maxNode
        maxNode->parent->rightChild = nullptr;
        rotateAfterRedColoring(maxNode->parent->leftChild);
    } else if (!maxNode->parent->leftChild->isBlack) { // The maxNode is black, has no children and a black parent. Since the maxNode is black, it must have a sibling. If that sibling is red then it must have two black children.
        // Plan: Recolor and rotate to achieve the situation above
        RBTNode * parent = maxNode->parent;
        RBTNode * sibling = maxNode->parent->leftChild;
        // Firstly, recolor
        parent->isBlack = false;
        sibling->isBlack = true;
        // Secondly, rotate
        parent->leftChild = sibling->rightChild;
        parent->leftChild->parent = parent;
        sibling->rightChild = parent;
        sibling->parent = parent->parent;
        parent->parent = sibling;
        if (sibling->parent != NULL) {
            sibling->parent->rightChild = sibling;
        } else {
            root = sibling;
        }
        // Update shift
        parent->leftChild->shift += sibling->shift;
        sibling->shift += parent->shift;
        parent->shift -= sibling->shift;
        
        // Now, we have the same situation as above, so the solution is the same.
        // Recolor
        maxNode->parent->isBlack = true;
        maxNode->parent->leftChild->isBlack = false;
        // Remove maxNode
        maxNode->parent->rightChild = nullptr;
        rotateAfterRedColoring(maxNode->parent->leftChild);
    } else { // maxNode is black and has no children. The parent and sibling are also black.
        // Plan: delete maxNode, color sibling red (and rotate if necessary) and consider the parent of maxNode as a double-black node. Resolve this double-blackness
        // Remove maxNode
        maxNode->parent->rightChild = nullptr;
        maxNode = maxNode->parent;
        // Recolor and rotate
        maxNode->leftChild->isBlack = false;
        // Rotate - Note: maxNode is now the parent of the original maxNode
        // We might have to resolve a double-black after deleting the maxNode, so we have to find out which node is gonna be on top after the rotation
        RBTNode * topNode = maxNode;
        if (maxNode->leftChild->hasLeftChild() && !maxNode->leftChild->leftChild->isBlack) {
            topNode = maxNode->leftChild;
        } else if (maxNode->leftChild->hasRightChild() &&
                   !maxNode->leftChild->rightChild->isBlack) {
            topNode = maxNode->leftChild->rightChild;
        }
        rotateAfterRedColoring(maxNode->leftChild);
        // Resolve double-blackness of the topNode
        resolveDoubleBlack(topNode);
    }
}

void RedBlackTree::join(RedBlackTree * newTree) {
    // This method assumes that all elements in this tree are smaller than all elements in the new tree
    if (this->root == NULL) {
        this->setTree(newTree);
        newTree->erase();
    } else if (newTree->root != NULL) {
        RBTNode * thisMax = this->findMaxNodeWithTotalShift();
        RBTNode * newTreeMin = newTree->findMinNodeWithTotalShift();
        thisMax->data += thisMax->shift;
        thisMax->shift = 0;
        newTreeMin->data += newTreeMin->shift;
        newTreeMin->shift = 0;
        
        if (thisMax->data < newTreeMin->data) { // Verify that all elements are actually smaller
            int blackHeightOriginal = this->getBlackHeight();
            int blackHeightNew = newTree->getBlackHeight();
            RBTNode * currentNode;
            int currentParentShift = 0;
            if (blackHeightOriginal < blackHeightNew) { // search down in the new tree
                RBTNode * newParent = newTreeMin;
                newTree->deleteMinNode();
                std::tie(currentNode, currentParentShift) = newTree->getNodeOfHeight(blackHeightOriginal, true);
                currentParentShift -= currentNode->shift;
                RBTNode * currentParent = currentNode->parent;
                
                // Update shift
                newParent->shift = -currentParentShift;
                currentNode->shift += currentParentShift;
                
                // Connect the two trees
                newParent->isBlack = false;
                newParent->parent = currentParent;
                if (currentParent != NULL) {
                    currentParent->leftChild = newParent;
                }
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
                    // The currentParent might be red and the newParent is certainly red, so the tree is rotated if necessary.
                    rotateTree(newParent);
                }
            } else if (blackHeightOriginal > blackHeightNew) { // search down in this tree
                RBTNode * newParent = thisMax;
                this->deleteMaxNode();
                std::tie(currentNode, currentParentShift) = getNodeOfHeight(blackHeightNew, false);
                currentParentShift -= currentNode->shift;
                RBTNode * currentParent = currentNode->parent;
                
                // Update shift
                newParent->shift = -currentParentShift;
                currentNode->shift += currentParentShift;
                
                // Connect the two trees
                newParent->isBlack = false;
                newParent->parent = currentParent;
                if (currentParent != NULL) {
                    currentParent->rightChild = newParent;
                }
                newParent->rightChild = newTree->root;
                newParent->leftChild = currentNode;
                newTree->root->parent = newParent;
                currentNode->parent = newParent;
                // Update the root of this tree
                if (currentParent == NULL) {
                    this->root = newParent;
                    newParent->isBlack = true;
                } else { // The root does not need updating. However, the newParent is red, and the currentParent might also be red. So the tree is rotated if necessary
                    rotateTree(newParent);
                }
            } else { // blackHeightOriginal = blackHeightNew
                // This is a special case, because when the minNode/maxNode is deleted the black height might decrease.
                // Plan: delete minNode of the newTree. If the black height is still the same then that minNode will become the new root. Otherwise we will search down in this tree to find a node of the same height.
                RBTNode * newParent = newTreeMin;
                newTree->deleteMinNode();
                blackHeightNew = newTree->getBlackHeight();
                if (blackHeightOriginal == blackHeightNew) { // Set newParent to be the new root
                    newParent->parent = nullptr;
                    newParent->isBlack = true;
                    newParent->leftChild = this->root;
                    newParent->rightChild = newTree->root;
                    this->root->parent = newParent;
                    newTree->root->parent = newParent;
                    this->root = newParent;
                    
                    // Update shift
                    newParent->shift = 0;
                } else if (blackHeightNew == 0) {
                    this->createNode(newParent->data);
                } else { // search down in this tree
                    std::tie(currentNode, currentParentShift) = this->getNodeOfHeight(blackHeightNew, false);
                    currentParentShift -= currentNode->shift;
                    RBTNode * currentParent = currentNode->parent;
                    
                    // Update shift
                    newParent->shift = -currentParentShift;
                    currentNode->shift += currentParentShift;
                    
                    // Connect the two trees
                    newParent->isBlack = false;
                    newParent->parent = currentParent;
                    if (currentParent != NULL) {
                        currentParent->rightChild = newParent;
                    }
                    newParent->rightChild = newTree->root;
                    newParent->leftChild = currentNode;
                    if (blackHeightNew != 0) {
                        newTree->root->parent = newParent;
                    }
                    currentNode->parent = newParent;
                    // Update the root of this tree
                    if (currentParent == NULL) {
                        this->root = newParent;
                        newParent->isBlack = true;
                    } else { // The root does not need updating. However, the newParent is red, and the currentParent might also be red. So the tree is rotated if necessary
                        rotateTree(newParent);
                    }
                }
            }
            newTree->erase();
        } else {
            std::cout << "All elements in the new tree are not greater than all elements in this tree\n";
        }
    }
}

void RedBlackTree::pushShiftDown(RBTNode * node) {
    if (node->hasLeftChild()) {
        node->leftChild->shift += node->shift;
    }
    if (node->hasRightChild()) {
        node->rightChild->shift += node->shift;
    }
    node->data += node->shift;
    node->shift = 0;
}

void RedBlackTree::reduceBlackHeight(RBTNode *& node, bool goingLeft) {
    /*
     Lets the node pointer point to the next black node - either to the left or right. Also the shift is brought along such that 'node' always contains its total offset.
     */
    pushShiftDown(node);
    
    // node should always point to a black node
    if (goingLeft) {
        node = node->leftChild;
    } else {
        node = node->rightChild;
    }
    
    // node might be red now. We don't want that. The child of a red node is always black or null. We will not reduce the black height further by moving to the child of a red node
    if (node != NULL && !node->isBlack) {
        reduceBlackHeight(node, goingLeft);
    }
}

RBTNode * RedBlackTree::bigTreeJoin(RBTNode *root, RBTNode *pb, RBTNode *lTb) {
    if (this->root == NULL && root != NULL) {
        this->root = root;
        this->root->parent = NULL;
        if (!this->root->isBlack) {
            this->root->isBlack = true;
            pushShiftDown(this->root);
            return this->root->leftChild;
        } else {
            return this->root;
        }
    } else {
        if (root == NULL) {
            if (pb != NULL) {
                this->createNode(pb->data + pb->shift);
            }
        } else {
            pb->leftChild = root;
            pb->rightChild = lTb;
            if (lTb->parent != NULL) {
                pb->parent = lTb->parent;
                pb->parent->leftChild = pb;
                pb->isBlack = false;
                if (!pb->parent->isBlack) {
                    rotateTree(pb);
                }
            } else {
                pb->parent = NULL;
                pb->isBlack = true;
                this->root = pb;
            }
            root->parent = pb;
            lTb->parent = pb;
        }
    }
    
    return root;
}

RBTNode * RedBlackTree::smallTreeJoin(RBTNode * root, RBTNode * ps, RBTNode * rTs) {
    if (this->root == NULL && root != NULL) {
        this->root = root;
        this->root->parent = NULL;
        if (!this->root->isBlack) {
            this->root->isBlack = true;
            pushShiftDown(this->root);
            return this->root->rightChild;
        } else {
            return this->root;
        }
    } else {
        if (root == NULL) {
            if (ps != NULL) {
                this->createNode(ps->data + ps->shift);
            }
        } else {
            ps->rightChild = root;
            ps->leftChild = rTs;
            if (rTs->parent != NULL) {
                ps->parent = rTs->parent;
                ps->parent->rightChild = ps;
                ps->isBlack = false;
                if (!ps->parent->isBlack) {
                    rotateTree(ps);
                }
            } else {
                ps->parent = NULL;
                ps->isBlack = true;
                this->root = ps;
            }
            root->parent = ps;
            rTs->parent = ps;
        }
    }
    
    return root;
}

RedBlackTree * RedBlackTree::split(int splitValue, bool includeSplitValue) {
    RedBlackTree * Ts = new RedBlackTree; // Small tree
    RedBlackTree * Tb = new RedBlackTree; // Big tree
    RBTNode * currentNode = root;
    RBTNode * ps = NULL; // Pivot node for small tree
    RBTNode * pb = NULL; // Pivot node for big tree
    RBTNode * rTs = NULL; // A pointer to the rightmost node of Ts that has approriate black height
    RBTNode * lTb = NULL; // A pointer to the leftmost node of Tb that has approriate black height
    bool isSmallRootRed;
    bool isBigRootRed;
    
    
    while (currentNode != NULL) {
        isSmallRootRed = isBigRootRed = false;
        pushShiftDown(currentNode);
        
        if (splitValue < currentNode->data) {
            // join subtree rooted at right child of current node with Tb using pb
            if (currentNode->isBlack && currentNode->hasRightChild() && lTb != NULL) {
                if (currentNode->rightChild->isBlack) {
                    reduceBlackHeight(lTb, true);
                } else {
                    currentNode->rightChild->isBlack = true;
                    isSmallRootRed = true;
                }
            }
            lTb = Tb->bigTreeJoin(currentNode->rightChild, pb, lTb);
            if (isSmallRootRed) {
                reduceBlackHeight(lTb, true);
            }
            pb = currentNode;
            if (currentNode->isBlack && rTs != NULL) {
                reduceBlackHeight(rTs, false);
            }
            currentNode = currentNode->leftChild;
        } else if (splitValue > currentNode->data) {
            // join subtree rooted at left child of current node with Ts using ps
            if (currentNode->isBlack && currentNode->hasLeftChild() && rTs != NULL) {
                if (currentNode->leftChild->isBlack) {
                    reduceBlackHeight(rTs, false);
                } else {
                    currentNode->leftChild->isBlack = true;
                    isBigRootRed = true;
                }
            }
            rTs = Ts->smallTreeJoin(currentNode->leftChild, ps, rTs);
            if (isBigRootRed) {
                reduceBlackHeight(rTs, false);
            }
            ps = currentNode;
            if (currentNode->isBlack && lTb != NULL) {
                reduceBlackHeight(lTb, true);
            }
            currentNode = currentNode->rightChild;
        } else {
            if (currentNode->isBlack && currentNode->hasLeftChild() && rTs != NULL) {
                if (currentNode->leftChild->isBlack) {
                    reduceBlackHeight(rTs, false);
                } else {
                    currentNode->leftChild->isBlack = true;
                }
            }
            if (currentNode->isBlack && currentNode->hasRightChild() && lTb != NULL) {
                if (currentNode->rightChild->isBlack) {
                    reduceBlackHeight(lTb, true);
                } else {
                    currentNode->rightChild->isBlack = true;
                }
            }
            // join subtree rooted at right child of current node with Tb using pb
            lTb = Tb->bigTreeJoin(currentNode->rightChild, pb, lTb);
            // join subtree rooted at left child of current node with Ts using ps
            rTs = Ts->smallTreeJoin(currentNode->leftChild, ps, rTs);
            ps = NULL;
            pb = NULL;
            if (includeSplitValue) {
                Ts->createNode(currentNode->data);
            }
            currentNode = NULL;
        }
    }
    if (ps != NULL) {
        Ts->createNode(ps->data);
    }
    if (pb != NULL) {
        Tb->createNode(pb->data);
    }
    this->setTree(Tb);
    return Ts;
}

void RedBlackTree::merge(RedBlackTree * newTree){
    // Plan:
    // Find out which tree has the smallest element.
    // Assuming that treeOne has the smallest element, we will split treeOne at the smallest element of treeTwo.
    RedBlackTree * mergedTree = new RedBlackTree;
    RedBlackTree * tmpTree = new RedBlackTree;
    RBTNode * thisMin;
    RBTNode * newTreeMin;
    int thisMinValue;
    int newTreeMinValue;
    
    while (this->root != NULL && newTree->root != NULL) {
        thisMin = this->findMinNodeWithTotalShift();
        newTreeMin = newTree->findMinNodeWithTotalShift();
        thisMinValue = thisMin->data + thisMin->shift;
        newTreeMinValue = newTreeMin->data + newTreeMin->shift;
        if (thisMinValue < newTreeMinValue) {
            tmpTree->setTree(this->split(newTreeMinValue, false));
        } else {
            tmpTree->setTree(newTree->split(thisMinValue, false));
        }
        mergedTree->join(tmpTree);
    }
    
    if (this->root != NULL) {
        mergedTree->join(this);
    } else if (newTree->root != NULL) {
        mergedTree->join(newTree);
    }
    this->setTree(mergedTree);
}

void RedBlackTree::shift(int shiftValue){
    this->root->shift += shiftValue;
}
