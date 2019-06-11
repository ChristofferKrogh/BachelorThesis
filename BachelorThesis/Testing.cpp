//
//  Testing.cpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 09/05/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//

#include "Testing.hpp"

void Testing::printTests() {
    // Plan: print at table of running times for each operation and data structure
    BaselineOne baselineEven;
    BaselineOne baselineOdd;
    BaselineOne baselineEvenSmall;
    LinkedList linkedListEven;
    LinkedList linkedListOdd;
    LinkedList linkedListEvenSmall;
    RedBlackTree redBlackTreeEven;
    RedBlackTree redBlackTreeOdd;
    RedBlackTree redBlackTreeEvenSmall;
    
    /*
    LinkedList listOne;
    LinkedList listTwo;
    std::vector<int> testValues = {1, 3, 5, 7, 9, 13, 17, 25, 37, 51, 69};
    std::vector<int> testValuesTwo = {2, 4, 6, 8, 10, 14, 18, 26, 38, 52, 70, 130, 140, 150};
    for (int value : testValues) {
        listOne.createNode(value);
    }
    for (int value : testValuesTwo) {
        listTwo.createNode(value);
    }
    listOne.merge(&listTwo);
    listOne.display();*/
    
    
    for (int i = 1; i < 100000; ++i) {
        baselineOdd.insert((i<<1) - 1);
//        baselineEven.insert(i<<1);
        linkedListOdd.createNode((i<<1) - 1);
//        linkedListEven.createNode(i<<1);
        redBlackTreeOdd.createNode((i<<1) - 1);
//        redBlackTreeEven.createNode(i<<1);
    }
    for (int i = 1; i < 1000; i = i<<1) {
        baselineEvenSmall.insert(i);
        linkedListEvenSmall.createNode(i);
        redBlackTreeEvenSmall.createNode(i);
    }
//    std::cout << "Searching in RBT for 2000\n" << redBlackTreeEvenSmall.search(2000)->data << std::endl;
//    std::cout << "Shifting with 2 and searching for 2002\n";
//    redBlackTreeEvenSmall.shift(2);
//    std::cout << redBlackTreeEvenSmall.search(2002)->data << std::endl;
    
    
    std::string results;
    results.append("     Split  |  Merge  |  Shift \n");
    std::cout << results;
//    std::cout << "Merging baselines...\n";
    std::chrono::high_resolution_clock::time_point tBefore = std::chrono::high_resolution_clock::now();
//    baselineOdd.merge(baselineEven);
    std::chrono::high_resolution_clock::time_point tAfter = std::chrono::high_resolution_clock::now();
//    std::cout << "It took " << std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count() << " nanoseconds\n";
//
//    std::cout << "\nMerging linkedlists...\n";
//    tBefore = std::chrono::high_resolution_clock::now();
//    linkedListOdd.merge(&linkedListEven);
//    tAfter = std::chrono::high_resolution_clock::now();
//    std::cout << "It took " << std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count() << " nanoseconds\n";
//
//    std::cout << "\nMerging redblacktrees...\n";
//    tBefore = std::chrono::high_resolution_clock::now();
//    redBlackTreeOdd.merge(&redBlackTreeEven);
//    tAfter = std::chrono::high_resolution_clock::now();
//    std::cout << "It took " << std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count() << " nanoseconds\n";
    
    std::cout << "\nMerging the data structures with a smaller set\n";
    std::cout << "Merging baselines...\n";
    tBefore = std::chrono::high_resolution_clock::now();
    baselineOdd.merge(baselineEvenSmall);
    tAfter = std::chrono::high_resolution_clock::now();
    std::cout << "It took " << std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count() << " nanoseconds\n";
    
    std::cout << "\nMerging linkedlists...\n";
    tBefore = std::chrono::high_resolution_clock::now();
    linkedListOdd.merge(&linkedListEvenSmall);
    tAfter = std::chrono::high_resolution_clock::now();
    std::cout << "It took " << std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count() << " nanoseconds\n";
    
    std::cout << "\nMerging redblacktrees...\n";
    tBefore = std::chrono::high_resolution_clock::now();
    redBlackTreeOdd.merge(&redBlackTreeEvenSmall);
    tAfter = std::chrono::high_resolution_clock::now();
    std::cout << "It took " << std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count() << " nanoseconds\n";
     
}
