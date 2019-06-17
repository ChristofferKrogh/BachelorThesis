//
//  Testing.hpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 09/05/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//

#ifndef Testing_hpp
#define Testing_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "BaselineOne.hpp"
#include "LinkedList.hpp"
#include "RedBlackTree.hpp"

class Testing {
private:
    
public:
    void printTests(int numberOfTests);
    void printInsertionTests(int setSize, int numberOfTests);
    void printMergeTwoSegmentsTests(int setSize, int numberOfTests);
    void printMergeFourSegmentsTests(int setSize, int numberOfTests);
    void printMergeWorstCaseTests(int setSize, int numberOfTests);
    void printMergeRandomSetsTests(int setSize, int numberOfTests);
    void printMergeRandomSetsOfDifferentSize(int setSizeOne, int setSizeTwo, int numberOfTests);
    void printSearchTests(int setSize, int numberOfTests, bool showSearchResults);
    void printShiftTests(int setSize, int numberOfTests);
    void printSplitTests(int setSize, int numberOfTests);
    void printJoinTests(int setSize, int numberOfTests);
};

#endif /* Testing_hpp */
