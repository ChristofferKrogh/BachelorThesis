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
#include <tuple>
class BaselineOne {
private:
    
public:
    int search(int searchSet[], int setSize, int searchValue);
    void shift(int shiftSet[], int setSize, int shiftValue);
    std::tuple<int *, int, int *, int> split(int splitSet[], int setSize, int splitValue);
    int * merge(int setOne[], int setTwo[], int setSizeOne, int setSizeTwo);
};
#endif /* BaselineOne_hpp */
