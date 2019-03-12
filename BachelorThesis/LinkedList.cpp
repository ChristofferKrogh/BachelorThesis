//
//  LinkedList.cpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 10/03/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//

#include "LinkedList.hpp"

// Man bør muligvis bruge følgende i stedet:
// LinkedList::LinkedList():head(NULL), tail(NULL){}
LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
}

void LinkedList::createNode(int value) {
    Node *newNode = new Node;
    newNode -> data = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    newNode -> shiftPointer = &shiftValue;
    
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode = NULL; // why is this necessary? maybe a way to free up memory.
    } else {
        newNode -> prev = tail;
        tail -> next = newNode;
        tail = newNode;
    }
}

void LinkedList::display() {
    Node * currentNode;
    currentNode = head;
    if (head == NULL)
        std::cout << "The list is empty";
    while (currentNode != NULL) {
        std::cout << currentNode -> data + shiftValue << " ";
        currentNode = currentNode -> next;
    }
    std::cout << std::endl;
}

Node * LinkedList::search(int searchValue) {
    searchValue -= shiftValue;
    Node * currentNode;
    currentNode = head;
    if (head == NULL) {
        std::cout << "The list is empty" << std::endl;
        return NULL;
    } else if ((head -> data) > searchValue) {
        std::cout << "The list contains no values smaller than or equal to the search value" << std::endl;
        return NULL;
    }
    while (currentNode != NULL) {
        if ((currentNode -> data) == searchValue) {
            return currentNode;
        } else if ((currentNode -> data) < searchValue
                   && ((currentNode -> next) == NULL
                    || (currentNode -> next -> data) > searchValue)) {
            return currentNode;
        }
        currentNode = currentNode -> next;
    }
    return NULL;
}
test for LEX

void LinkedList::shift(int shiftValue) {
    this->shiftValue += shiftValue;
}

void LinkedList::setHead(Node * newHead) {
    this -> head = newHead;
}

Node * LinkedList::getHead() {
    return head;
}

void LinkedList::setTail(Node * newTail) {
    this -> tail = newTail;
}
Node * LinkedList::getTail() {
    return tail;
}
