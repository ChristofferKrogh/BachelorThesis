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
    node *newNode = new node;
    newNode -> data = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    
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
    node * currentNode;
    currentNode = head;
    if (head == NULL)
        std::cout << "The list is empty";
    while (currentNode != NULL) {
        std::cout << currentNode -> data << " ";
        currentNode = currentNode -> next;
    }
    std::cout << std::endl;
}

node * LinkedList::search(int searchValue) {
    node * currentNode;
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
