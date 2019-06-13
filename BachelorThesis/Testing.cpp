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
    /*BaselineOne baselineEven;
    BaselineOne baselineOdd;
    BaselineOne baselineEvenSmall;
    LinkedList linkedListEven;
    LinkedList linkedListOdd;
    LinkedList linkedListEvenSmall;
    RedBlackTree redBlackTreeEven;
    RedBlackTree redBlackTreeOdd;
    RedBlackTree redBlackTreeEvenSmall;
    
    
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
    listOne.display();
    
    
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
    */
//    BaselineOne * base = new BaselineOne;
//    for (int i = 0; i < 1000; ++i) {
//        base->insert(rand() % 1000);
//        std::cout << "i: " << i << " - lastIndex: " << base->indexOfLastElement << std::endl;
//    }
    
    std::cout << "\n--Testing running time of merge--\n";
    std::chrono::high_resolution_clock::time_point tBefore;
    std::chrono::high_resolution_clock::time_point tAfter;
    BaselineOne * base = new BaselineOne;
    LinkedList * list = new LinkedList;
    RedBlackTree * tree = new RedBlackTree;
    BaselineOne * base2 = new BaselineOne;
    LinkedList * list2 = new LinkedList;
    RedBlackTree * tree2 = new RedBlackTree;
    int newElement;
    int numberOfTests = 3;
    int setSize = 5000;
    long long results[3][numberOfTests];
    std::cout << "Number of elements: " << setSize << "\nNumber of merges: " << numberOfTests << std::endl;
    for (int j = 0; j < setSize; j++) {
        newElement = rand();
        base->insert(newElement);
        list->createNode(newElement);
        tree->createNode(newElement);
    }
    for (int i = 0; i < numberOfTests; i++) {
        /*base = new BaselineOne;
        list = new LinkedList;
        tree = new RedBlackTree;
        base2 = new BaselineOne;
        list2 = new LinkedList;
        tree2 = new RedBlackTree;*/
        
        /*for (int j = setSize; j < 2*setSize; j++) {
            base2->insert(j);
            list2->createNode(j);
            tree2->createNode(j);
        }
        for (int j = 2*setSize; j < 3*setSize; j++) {
            base->insert(j);
            list->createNode(j);
            tree->createNode(j);
        }
        for (int j = 3*setSize; j < 4*setSize; j++) {
            base2->insert(j);
            list2->createNode(j);
            tree2->createNode(j);
        }*/
        newElement = rand();
        // Test baseline
        tBefore = std::chrono::high_resolution_clock::now();
        base->insert(newElement);
        tAfter = std::chrono::high_resolution_clock::now();
        results[0][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test linked list
        tBefore = std::chrono::high_resolution_clock::now();
        list->createNode(newElement);
        tAfter = std::chrono::high_resolution_clock::now();
        results[1][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test red-black tree
        tBefore = std::chrono::high_resolution_clock::now();
        tree->createNode(newElement);
        tAfter = std::chrono::high_resolution_clock::now();
        results[2][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
//        delete base;
//        delete list;
//        delete tree;
    }
    
    std::cout << "\nBase, List, Tree\n";
    for (int i = 0; i < numberOfTests; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << results[j][i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "nanoseconds\n";
}
