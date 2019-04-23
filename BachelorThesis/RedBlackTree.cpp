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
    return this->blackHeightAssumingValid(root);
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
        std::cout << "Root is red";
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
            std::cout << "\nThe red criteria is violated at: " << currentNode->data << std::endl;
            return false;
        }
    }
    
    return true;
}

int RedBlackTree::blackHeight(RBTNode * currentNode) {
    if (currentNode == NULL) {
        return 1;
    }
    int leftBlackHeight = blackHeight(currentNode->leftChild);
    int rightBlackHeight = blackHeight(currentNode->rightChild);
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

RBTNode * RedBlackTree::getLeftmostNodeOfHeight(int blackHeight) {
    // This method starts from the leftmost node in the tree i.e. the minNode and works its way up the tree until it reaches a node of the specified black height. This method will always return a black node except if the specified height is 1. In this case it will return the minNode.
    // a null pointer exception will be thrown if the specified black height is too big.
    int currentBlackHeight = 1;
//    RBTNode * currentNode = root;
//    while (currentNode->leftChild != NULL) {
//        currentNode = currentNode->leftChild;
//    }
    RBTNode * currentNode = minNode;
    if (currentNode->isBlack) {
        currentBlackHeight++;
    }
    while (currentBlackHeight != blackHeight) {
        currentNode = currentNode->parent;
        if (currentNode->isBlack) {
            currentBlackHeight++;
        }
    }
    return currentNode;
}

RBTNode * RedBlackTree::getRightmostNodeOfHeight(int blackHeight) {
    // This method is equivalent to getLeftmostNodeOfHeight
    int currentBlackHeight = 1;
    RBTNode * currentNode = maxNode;
    if (currentNode->isBlack) {
        currentBlackHeight++;
    }
    while (currentBlackHeight != blackHeight) {
        currentNode = currentNode->parent;
        if (currentNode->isBlack) {
            currentBlackHeight++;
        }
    }
    return currentNode;
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
        std::cout << "The black height of the tree is: " << getBlackHeight() << "\n";
    }
    inOrder(root, showDetails);
    std::cout << std::endl;
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

void RedBlackTree::deleteMinNode() {
    // The min node cannot have any left children - otherwise it wouldn't be the min node. Since it has no left children, it cannot have any black nodes in its right subtree. This means that the min node can have at most one child and this child must be red. Consequently, the min node cannot have any children if it is colored red.
    // If the min node is red then it can simply be removed.
    // If it is the case that the min node is black and has a red child, then the min node will be replaced by its child and the child will be colored black
    // If the min node is black, does not have any children and has a red parent, then the sibling must also be black. In this case, the parent will be colored black and the min node and its sibling will be colored red. If the sibling has any children (they must be red) then some rotations are required. Before the rotations are carried out, the min node is removed.
    
    // TODO: figure out what to do with the last case (see below)
    // If the min node is black, has no children and its parent is black
    // If the sibling has any children then these can be used to rotate the tree to resolve the double-black problem
    if (!minNode->isBlack) { // the min node is simply removed
        minNode->parent->leftChild = nullptr;
        minNode = minNode->parent;
    } else if (minNode->rightChild != NULL) { // the min node is replaced by its child
        if (minNode != root) {
            minNode->parent->leftChild = minNode->rightChild;
            minNode->rightChild->parent = minNode->parent;
        } else {
            minNode->rightChild->parent = nullptr;
            root = minNode->rightChild;
        }
        minNode->rightChild->isBlack = true;
        minNode = minNode->rightChild;
    } else if (minNode == root) { // We wish to delete the root, and the root has no children. Therefore we erase the tree.
        erase();
    } else if (!minNode->parent->isBlack) { // if the parent is red then the min node and its sibling are black. I will recolor and rotate
        // Recolor
        minNode->parent->isBlack = true;
        minNode->parent->rightChild->isBlack = false;
        // Remove minNode
        minNode->parent->leftChild = nullptr;
        minNode = minNode->parent;
        // Rotate - Note: minNode is now the parent of the original minNode
        if (minNode->rightChild->leftChild != NULL &&
            minNode->rightChild->rightChild != NULL) {
            minNode->parent->leftChild = minNode->rightChild;
            minNode->parent = minNode->rightChild;
            minNode->rightChild = minNode->parent->leftChild;
            minNode->parent->leftChild = minNode;
            minNode->parent->rightChild->isBlack = true;
        } else if (minNode->rightChild->leftChild != NULL) {
            fixZigZagFormation(minNode->rightChild->leftChild);
        } else if (minNode->rightChild->rightChild != NULL) {
            fixLineFormation(minNode->rightChild->rightChild);
        }
    } else { // The minNode is black, has no children and a black parent
        minNode->parent->leftChild = nullptr;
        minNode = minNode->parent;
        std::cout << "NOT: ";
    }
    std::cout << "deleted the min node\n";
}

void RedBlackTree::deleteMaxNode() {
    // This will be symmetric/equivalent to deleteMinNode()
    if (!maxNode->isBlack) {
        maxNode->parent->rightChild = nullptr;
        maxNode = maxNode->parent;
    } else if (maxNode->leftChild != NULL) {
        if (maxNode != root) {
            maxNode->parent->rightChild = maxNode->leftChild;
            maxNode->leftChild->parent = maxNode->parent;
        } else {
            maxNode->leftChild->parent = nullptr;
            root = maxNode->leftChild;
        }
        maxNode->leftChild->isBlack = true;
        maxNode = maxNode->leftChild;
    } else if (maxNode == root) {
        erase();
    } else if (!maxNode->parent->isBlack) {
        // Recolor
        maxNode->parent->isBlack = true;
        maxNode->parent->leftChild->isBlack = false;
        // Remove maxNode
        maxNode->parent->rightChild = nullptr;
        maxNode = maxNode->parent;
        // Rotate - Note: maxNode is now the parent of the original
        if (maxNode->leftChild->leftChild != NULL &&
            maxNode->leftChild->rightChild != NULL) {
            maxNode->parent->rightChild = maxNode->leftChild;
            maxNode->parent = maxNode->leftChild;
            maxNode->leftChild = maxNode->parent->rightChild;
            maxNode->parent->rightChild = maxNode;
            maxNode->parent->leftChild->isBlack = true;
        } else if (maxNode->leftChild->leftChild != NULL) {
            fixLineFormation(maxNode->leftChild->leftChild);
        } else if (maxNode->leftChild->rightChild != NULL) {
            fixZigZagFormation(maxNode->leftChild->rightChild);
        }
    } else { // The maxNode is black, has no children and a black parent
        std::cout << "NOT: ";
    }
    std::cout << "deleted the max node\n";
}

void RedBlackTree::join(RedBlackTree * newTree) {
    // This method assumes that all elements in this tree are smaller than all elements in the new tree
    // Verify that all elements are actually smaller
    if (this->maxNode->data < newTree->minNode->data) {
        int blackHeightOriginal = this->getBlackHeight();
        int blackHeightNew = newTree->getBlackHeight();
        RBTNode * currentNode;
        if (blackHeightOriginal <= blackHeightNew) { // search down in the new tree
            std::cout << "(During join): Searching down in the new tree\n";
            currentNode = newTree->getLeftmostNodeOfHeight(blackHeightOriginal);
            RBTNode * currentParent = currentNode->parent;
            RBTNode * newParent = newTree->minNode;
            newTree->deleteMinNode();
            
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
        } else { // search down in this tree
            currentNode = getRightmostNodeOfHeight(blackHeightNew);
            RBTNode * currentParent = currentNode->parent;
            RBTNode * newParent = this->maxNode;
            this->deleteMaxNode();
            
            // Connect the two trees
            newParent->isBlack = false;
            newParent->parent = currentParent;
            currentNode->rightChild = newParent;
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
        }
        // Update the maxNode pointer
        this->maxNode = newTree->maxNode;
        newTree->erase();
    } else {
        std::cout << "All elements in the new tree are not greater than all elements in this tree\n";
    }
    
    std::cout << "Joined the two trees\n";
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


