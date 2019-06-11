//
//  BaselineOne.hpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 09/03/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//

#ifndef BaselineOne_hpp
#define BaselineOne_hpp

#include <stdio.h>
#include <iostream>
#include <tuple>
#include <vector>

class BaselineOne {
private:
    
public:
    std::vector<int> OLDvalues;
    int * values = new int[0];
    int indexOfLastElement;
    int arraySize;
    
public:
    BaselineOne();
    void insert(int value);
    void setValues(std::vector<int> newValues);
    int search(int searchValue);
    void shift(int shiftValue);
    BaselineOne split(int splitValue);
    void merge(BaselineOne newSet);
    void display();
};
#endif /* BaselineOne_hpp */
