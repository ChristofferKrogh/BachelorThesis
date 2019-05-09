//
//  Testing.cpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 09/05/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//

#include "Testing.hpp"
// Plan: print at table of running times for each operation and data structure

void Testing::printTests() {
    BaselineOne baseline;
    LinkedList linkedList;
    RedBlackTree redBlackTree;
    std::vector<int> testValues = {1, 3, 5, 7, 9, 13, 17, 25, 37, 51, 69};
    baseline.setValues(testValues);
    for (int value : testValues) {
        linkedList.createNode(value);
        redBlackTree.createNode(value);
    }
    std::string results;
    results.append("     Split  |  Merge  |  Shift");
    std::cout << results;
}
