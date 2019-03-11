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

struct node {
    int data;
    int * shiftPointer;
    node *next;
    node *prev;
};

class LinkedList {
private:
    node *head, *tail;
    int shiftValue = 0;
    
public:
    LinkedList();
    void createNode(int value);
    void display();
    node * search(int searchValue);
    void shift(int shiftValue);
};
#endif /* LinkedList_hpp */
