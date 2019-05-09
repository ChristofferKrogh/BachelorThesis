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
    std::vector<int> values;
    
public:
    void insert(int value);
    void setValues(std::vector<int> newValues);
//    int search(int searchSet[], int setSize, int searchValue);
    int search(int searchValue);
//    void shift(int shiftSet[], int setSize, int shiftValue);
    void shift(int shiftValue);
//    std::tuple<int *, int, int *, int> split(int splitSet[], int setSize, int splitValue);
    std::vector<int> split(int splitValue);
//    int * merge(int setOne[], int setTwo[], int setSizeOne, int setSizeTwo);
    void merge(BaselineOne newSet);
//    void display(int array[], int arraySize);
    void display();
};
#endif /* BaselineOne_hpp */
