//
//  LinkedList.hpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 10/03/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>

struct Node {
    int data;
    int * shiftPointer;
    Node *next;
    Node *prev;
};

class LinkedList {
public:
    int shiftValue = 0;
    
private:
    Node *head, *tail;
    
public:
    LinkedList();
    void createNode(int value);
    void display();
    Node * search(int searchValue);
    void shift(int shiftValue);
    void setHead(Node * newHead);
    Node * getHead();
    void setTail(Node * newTail);
    Node * getTail();
};
#endif /* LinkedList_hpp */
