//
//  LinkedList.cpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 10/03/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//

#include "LinkedList.hpp"

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
}

void LinkedList::createNode(int value) {
    LLNode *newNode = new LLNode;
    newNode->data = value - this->shiftValue;
    newNode->next = NULL;
    
    // We could replace most of this method by using the search method. 
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else if (newNode->data < head->data) {
        newNode->next = head;
        head = newNode;
    } else {
        LLNode * smallTmp = head;
        LLNode * bigTmp = smallTmp->next;
        while (bigTmp != NULL) {
            if ((smallTmp->data < newNode->data) && (newNode->data < bigTmp->data)) {
                smallTmp->next = newNode;
                newNode->next = bigTmp;
                smallTmp = NULL;
                bigTmp = NULL;
            } else if (smallTmp->data == newNode->data ||
                       bigTmp->data == newNode->data) {
                smallTmp = NULL;
                bigTmp = NULL;
            } else {
                smallTmp = bigTmp;
                bigTmp = bigTmp->next;
            }
        }
        if (smallTmp != NULL) {
            smallTmp->next = newNode;
            tail = newNode;
        }
    }
}

void LinkedList::createSet(int * values, int listSize) {
    for (int i = 0; i < listSize; i++) {
        createNode(values[i]);
    }
}

void LinkedList::display() {
    LLNode * currentNode;
    currentNode = head;
    if (head == NULL)
        std::cout << "The list is empty";
    while (currentNode != NULL) {
        std::cout << currentNode -> data + shiftValue << " ";
        currentNode = currentNode -> next;
    }
    std::cout << std::endl;
}

LLNode * LinkedList::search(int searchValue) {
    searchValue -= shiftValue;
    LLNode * currentNode;
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

void LinkedList::shift(int shiftValue) {
    this->shiftValue += shiftValue;
}

void LinkedList::updateShiftValue(int shiftValueDiff) {
    this->shiftValue -= shiftValueDiff;
    LLNode * currentNode = head;
    while (currentNode != NULL) {
        currentNode -> data += shiftValueDiff;
        currentNode = currentNode -> next;
    }
}

void LinkedList::merge(LinkedList * newList) {
    // The two lists need to have the same shift value
    int shiftValueDiff = newList->shiftValue - this->shiftValue;
    shiftValueDiff < 0? updateShiftValue(-shiftValueDiff) : newList->updateShiftValue(shiftValueDiff);
    
    // Now we are ready for the actual merging.
    LLNode * i = head;  // Initial index of first list
    LLNode * j = newList->head;  // Initial index of second list
    LLNode * k;                         // Initial index of merged list
    if (i->data == j->data) {
        k = i;
        i = i->next;
        j = j->next;
    } else if ((i -> data) < (j -> data)) {
        k = i;
        i = i -> next;
    } else {
        k = j;
        j = j -> next;
    }
    head = k;
    
    while (i != NULL && j != NULL) {
        if (i->data == j->data) { // This is added to avoid duplicates in resulting list
            k->next = i;
            k = k->next;
            i = i->next;
            j = j->next;
        } else if ((i -> data) < (j -> data)) {
            k -> next = i;
            k = k -> next;
            i = i -> next;
        } else {
            k -> next = j;
            k = k -> next;
            j = j -> next;
        }
    }
    
    if (i != NULL) {
        k -> next = i;
    } else if (j != NULL) {
        k -> next = j;
        tail = newList->tail;
    }
}

LinkedList LinkedList::split(int splitValue) {
    LinkedList newList;
    newList.shiftValue = this->shiftValue;
    LLNode * newTail = search(splitValue);
    if (newTail == NULL) {
        newList.head = head;
        newList.tail = tail;
        head = tail = NULL;
    } else{
        newList.tail = tail;
        newList.head = newTail -> next;
        newTail -> next = NULL;
        tail = newTail;
    }
    return newList;
}
