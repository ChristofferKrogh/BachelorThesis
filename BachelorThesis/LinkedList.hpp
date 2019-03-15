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
    Node *next;
};

class LinkedList {
public:
    int shiftValue = 0;
    Node *head, *tail;
    
private:
    
public:
    LinkedList();
    void createNode(int value);
    void createSet(int * values, int listSize);
    void display();
    Node * search(int searchValue);
    void shift(int shiftValue);
    void updateShiftValue(int differenceInShiftValues);
    void merge(LinkedList * newList);
    LinkedList split(int splitValue);
};
#endif /* LinkedList_hpp */
