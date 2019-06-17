//
//  Testing.cpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 09/05/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//

#include "Testing.hpp"

void Testing::printMergeTwoSegmentsTests(int setSize, int numberOfTests) {
    std::cout << "\n--Testing running time of Merge--\n";
    std::chrono::high_resolution_clock::time_point tBefore;
    std::chrono::high_resolution_clock::time_point tAfter;
    BaselineOne * base;
    LinkedList * list;
    RedBlackTree * tree;
    BaselineOne * base2;
    LinkedList * list2;
    RedBlackTree * tree2;
    long long results[3][numberOfTests];
    std::cout << "Number of elements: " << setSize << "\nNumber of merges: " << numberOfTests << std::endl;
    for (int i = 0; i < numberOfTests; i++) {
        base = new BaselineOne;
        list = new LinkedList;
        tree = new RedBlackTree;
        base2 = new BaselineOne;
        list2 = new LinkedList;
        tree2 = new RedBlackTree;
        for (int j = 0; j < setSize; j++) {
            base->insert(j);
            list->createNode(j);
            tree->createNode(j);
        }
        for (int j = setSize; j < 2*setSize; j++) {
            base2->insert(j);
            list2->createNode(j);
            tree2->createNode(j);
        }
        // Test baseline
        tBefore = std::chrono::high_resolution_clock::now();
        base->merge(base2);
        tAfter = std::chrono::high_resolution_clock::now();
        results[0][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test linked list
        tBefore = std::chrono::high_resolution_clock::now();
        list->merge(list2);
        tAfter = std::chrono::high_resolution_clock::now();
        results[1][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test red-black tree
        tBefore = std::chrono::high_resolution_clock::now();
        tree->merge(tree2);
        tAfter = std::chrono::high_resolution_clock::now();
        results[2][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        delete base;
        delete list;
        delete tree;
        delete base2;
        delete list2;
        delete tree2;
    }
    std::cout << "\nBase:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[0][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nList:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[1][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nTree:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[2][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
}

void Testing::printMergeFourSegmentsTests(int setSize, int numberOfTests) {
    std::cout << "\n--Testing running time of Merge--\n";
    std::chrono::high_resolution_clock::time_point tBefore;
    std::chrono::high_resolution_clock::time_point tAfter;
    BaselineOne * base;
    LinkedList * list;
    RedBlackTree * tree;
    BaselineOne * base2;
    LinkedList * list2;
    RedBlackTree * tree2;
    long long results[3][numberOfTests];
    std::cout << "Number of elements: " << setSize << "\nNumber of merges: " << numberOfTests << std::endl;
    for (int i = 0; i < numberOfTests; i++) {
        base = new BaselineOne;
        list = new LinkedList;
        tree = new RedBlackTree;
        base2 = new BaselineOne;
        list2 = new LinkedList;
        tree2 = new RedBlackTree;
        for (int j = 0; j < setSize; j++) {
            base->insert(j);
            list->createNode(j);
            tree->createNode(j);
        }
        for (int j = setSize; j < 2*setSize; j++) {
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
        }
        // Test baseline
        tBefore = std::chrono::high_resolution_clock::now();
        base->merge(base2);
        tAfter = std::chrono::high_resolution_clock::now();
        results[0][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test linked list
        tBefore = std::chrono::high_resolution_clock::now();
        list->merge(list2);
        tAfter = std::chrono::high_resolution_clock::now();
        results[1][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test red-black tree
        tBefore = std::chrono::high_resolution_clock::now();
        tree->merge(tree2);
        tAfter = std::chrono::high_resolution_clock::now();
        results[2][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        delete base;
        delete list;
        delete tree;
        delete base2;
        delete list2;
        delete tree2;
    }
    std::cout << "\nBase:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[0][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nList:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[1][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nTree:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[2][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
}

void Testing::printMergeWorstCaseTests(int setSize, int numberOfTests) {
    std::cout << "\n--Testing worst case running time of Merge--\n";
    std::chrono::high_resolution_clock::time_point tBefore;
    std::chrono::high_resolution_clock::time_point tAfter;
    BaselineOne * base;
    LinkedList * list;
    RedBlackTree * tree;
    BaselineOne * base2;
    LinkedList * list2;
    RedBlackTree * tree2;
    long long results[3][numberOfTests];
    std::cout << "Number of elements: " << setSize << "\nNumber of merges: " << numberOfTests << std::endl;
    for (int i = 0; i < numberOfTests; i++) {
        base = new BaselineOne;
        list = new LinkedList;
        tree = new RedBlackTree;
        base2 = new BaselineOne;
        list2 = new LinkedList;
        tree2 = new RedBlackTree;
        for (int j = 1; j < setSize; j += 2) {
            base->insert(j);
            list->createNode(j);
            tree->createNode(j);
        }
        for (int j = 0; j < setSize; j += 2) {
            base2->insert(j);
            list2->createNode(j);
            tree2->createNode(j);
        }
        // Test baseline
        tBefore = std::chrono::high_resolution_clock::now();
        base->merge(base2);
        tAfter = std::chrono::high_resolution_clock::now();
        results[0][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test linked list
        tBefore = std::chrono::high_resolution_clock::now();
        list->merge(list2);
        tAfter = std::chrono::high_resolution_clock::now();
        results[1][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test red-black tree
        tBefore = std::chrono::high_resolution_clock::now();
        tree->merge(tree2);
        tAfter = std::chrono::high_resolution_clock::now();
        results[2][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        delete base;
        delete list;
        delete tree;
        delete base2;
        delete list2;
        delete tree2;
    }
    std::cout << "\nBase:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[0][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nList:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[1][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nTree:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[2][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
}

void Testing::printMergeRandomSetsTests(int setSize, int numberOfTests) {
    std::cout << "\n--Testing running time of Merge with random sets--\n";
    std::chrono::high_resolution_clock::time_point tBefore;
    std::chrono::high_resolution_clock::time_point tAfter;
    BaselineOne * base;
    LinkedList * list;
    RedBlackTree * tree;
    BaselineOne * base2;
    LinkedList * list2;
    RedBlackTree * tree2;
    int newElement;
    long long results[3][numberOfTests];
    std::cout << "Number of elements: " << setSize << "\nNumber of merges: " << numberOfTests << std::endl;
    for (int i = 0; i < numberOfTests; i++) {
        base = new BaselineOne;
        list = new LinkedList;
        tree = new RedBlackTree;
        base2 = new BaselineOne;
        list2 = new LinkedList;
        tree2 = new RedBlackTree;
        for (int j = 0; j < setSize; ++j) {
            newElement = rand();
            base->insert(newElement);
            list->createNode(newElement);
            tree->createNode(newElement);
        }
        for (int j = 0; j < setSize; ++j) {
            newElement = rand();
            base2->insert(newElement);
            list2->createNode(newElement);
            tree2->createNode(newElement);
        }
        // Test baseline
        tBefore = std::chrono::high_resolution_clock::now();
        base->merge(base2);
        tAfter = std::chrono::high_resolution_clock::now();
        results[0][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test linked list
        tBefore = std::chrono::high_resolution_clock::now();
        list->merge(list2);
        tAfter = std::chrono::high_resolution_clock::now();
        results[1][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test red-black tree
        tBefore = std::chrono::high_resolution_clock::now();
        tree->merge(tree2);
        tAfter = std::chrono::high_resolution_clock::now();
        results[2][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        delete base;
        delete list;
        delete tree;
        delete base2;
        delete list2;
        delete tree2;
    }
    std::cout << "\nBase:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[0][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nList:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[1][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nTree:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[2][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
}

void Testing::printMergeRandomSetsOfDifferentSize(int setSizeOne, int setSizeTwo, int numberOfTests) {
    std::cout << "\n--Testing running time of Merge with random sets of different sizes--\n";
    std::chrono::high_resolution_clock::time_point tBefore;
    std::chrono::high_resolution_clock::time_point tAfter;
    BaselineOne * base;
    LinkedList * list;
    RedBlackTree * tree;
    BaselineOne * base2;
    LinkedList * list2;
    RedBlackTree * tree2;
    int newElement;
    long long results[3][numberOfTests];
    std::cout << "Number of elements in set 1: " << setSizeOne << "\nNumber of elements in set 2: " << setSizeTwo << "\nNumber of merges: " << numberOfTests << std::endl;
    for (int i = 0; i < numberOfTests; i++) {
        base = new BaselineOne;
        list = new LinkedList;
        tree = new RedBlackTree;
        base2 = new BaselineOne;
        list2 = new LinkedList;
        tree2 = new RedBlackTree;
        for (int j = 0; j < setSizeOne; ++j) {
            newElement = rand();
            base->insert(newElement);
            list->createNode(newElement);
            tree->createNode(newElement);
        }
        for (int j = 0; j < setSizeTwo; ++j) {
            newElement = rand();
            base2->insert(newElement);
            list2->createNode(newElement);
            tree2->createNode(newElement);
        }
        // Test baseline
        tBefore = std::chrono::high_resolution_clock::now();
        base->merge(base2);
        tAfter = std::chrono::high_resolution_clock::now();
        results[0][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test linked list
        tBefore = std::chrono::high_resolution_clock::now();
        list->merge(list2);
        tAfter = std::chrono::high_resolution_clock::now();
        results[1][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test red-black tree
        tBefore = std::chrono::high_resolution_clock::now();
        tree->merge(tree2);
        tAfter = std::chrono::high_resolution_clock::now();
        results[2][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        delete base;
        delete list;
        delete tree;
        delete base2;
        delete list2;
        delete tree2;
    }
    std::cout << "\nBase:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[0][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nList:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[1][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nTree:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[2][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
}

void Testing::printSearchTests(int setSize, int numberOfTests, bool showSearchResults) {
    std::cout << "\n--Testing running time of search--\n";
    std::chrono::high_resolution_clock::time_point tBefore;
    std::chrono::high_resolution_clock::time_point tAfter;
    BaselineOne * base = new BaselineOne;
    LinkedList * list = new LinkedList;
    RedBlackTree * tree = new RedBlackTree;
    int newElement;
    int min = 2147483647; // max integer value
    long long results[3][numberOfTests];
    int baseIndex;
    LLNode * listSearch;
    RBTNode * treeSearch;
    std::cout << "Number of elements: " << setSize << "\nNumber of searches: " << numberOfTests << std::endl;
    for (int j = 0; j < setSize; j++) {
        newElement = rand();
        if (newElement < min) {
            min = newElement;
        }
        base->insert(newElement);
        list->createNode(newElement);
        tree->createNode(newElement);
    }
    std::cout << "Actual number of elements: " << base->indexOfLastElement + 1 << std::endl;
    for (int i = 0; i < numberOfTests; i++) {
        newElement = min + (rand() % (2147483647-min)); // We can only search for something that is larger than min of sets.
        // Test baseline
        tBefore = std::chrono::high_resolution_clock::now();
        baseIndex = base->search(newElement);
        tAfter = std::chrono::high_resolution_clock::now();
        results[0][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test linked list
        tBefore = std::chrono::high_resolution_clock::now();
        listSearch = list->search(newElement);
        tAfter = std::chrono::high_resolution_clock::now();
        results[1][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test red-black tree
        tBefore = std::chrono::high_resolution_clock::now();
        treeSearch = tree->search(newElement);
        tAfter = std::chrono::high_resolution_clock::now();
        results[2][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        if (showSearchResults) {
            // Print search results
            std::cout << "\nThe baseline found:       " << base->values[baseIndex] << std::endl;
            std::cout << "The linked list found:    " << listSearch->data + list->shiftValue << std::endl;
            std::cout << "The red-black tree found: " << treeSearch->data + treeSearch->shift << std::endl;
        }
    }
    
    std::cout << "\nBase:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[0][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nList:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[1][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nTree:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[2][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    delete base;
    delete list;
    delete tree;
}

void Testing::printInsertionTests(int setSize, int numberOfTests) {
    std::cout << "\n--Testing running time of insertion--\n";
    std::chrono::high_resolution_clock::time_point tBefore;
    std::chrono::high_resolution_clock::time_point tAfter;
    BaselineOne * base = new BaselineOne;
    LinkedList * list = new LinkedList;
    RedBlackTree * tree = new RedBlackTree;
    int newElement;
    long long results[3][numberOfTests];
    std::cout << "Number of elements: " << setSize << "\nNumber of insertions: " << numberOfTests << std::endl;
    for (int j = 0; j < setSize; j++) {
        newElement = rand();
        base->insert(newElement);
        list->createNode(newElement);
        tree->createNode(newElement);
    }
    std::cout << "Actual number of elements: " << base->indexOfLastElement + 1 << std::endl;
    for (int i = 0; i < numberOfTests; i++) {
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
    }
    
    std::cout << "\nBase:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[0][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nList:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[1][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nTree:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[2][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    delete base;
    delete list;
    delete tree;
}

void Testing::printShiftTests(int setSize, int numberOfTests) {
    std::cout << "\n--Testing running time of Shift--\n";
    std::chrono::high_resolution_clock::time_point tBefore;
    std::chrono::high_resolution_clock::time_point tAfter;
    BaselineOne * base = new BaselineOne;
    LinkedList * list = new LinkedList;
    RedBlackTree * tree = new RedBlackTree;
    int newElement;
    long long results[3][numberOfTests];
    std::cout << "Number of elements: " << setSize << "\nNumber of shifts: " << numberOfTests << std::endl;
    for (int j = 0; j < setSize; j++) {
        newElement = rand();
        base->insert(newElement);
        list->createNode(newElement);
        tree->createNode(newElement);
    }
    std::cout << "Actual number of elements: " << base->indexOfLastElement + 1 << std::endl;
    for (int i = 0; i < numberOfTests; i++) {
        newElement = rand();
        // Test baseline
        tBefore = std::chrono::high_resolution_clock::now();
        base->shift(newElement);
        tAfter = std::chrono::high_resolution_clock::now();
        results[0][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test linked list
        tBefore = std::chrono::high_resolution_clock::now();
        list->shift(newElement);
        tAfter = std::chrono::high_resolution_clock::now();
        results[1][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test red-black tree
        tBefore = std::chrono::high_resolution_clock::now();
        tree->shift(newElement);
        tAfter = std::chrono::high_resolution_clock::now();
        results[2][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
    }
    
    std::cout << "\nBase:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[0][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nList:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[1][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nTree:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[2][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    delete base;
    delete list;
    delete tree;
}

void Testing::printSplitTests(int setSize, int numberOfTests) {
    std::cout << "\n--Testing running time of Split--\n";
    std::chrono::high_resolution_clock::time_point tBefore;
    std::chrono::high_resolution_clock::time_point tAfter;
    BaselineOne * base;
    LinkedList * list;
    RedBlackTree * tree;
    int newElement;
    long long results[3][numberOfTests];
    std::cout << "Number of elements: " << setSize << "\nNumber of splits: " << numberOfTests << std::endl;
    for (int i = 0; i < numberOfTests; i++) {
        base = new BaselineOne;
        list = new LinkedList;
        tree = new RedBlackTree;
        for (int j = 0; j < setSize; j++) {
            newElement = rand();
            base->insert(newElement);
            list->createNode(newElement);
            tree->createNode(newElement);
        }
        std::cout << "Actual number of elements: " << base->indexOfLastElement + 1 << std::endl;
        newElement = rand();
        // Test baseline
        tBefore = std::chrono::high_resolution_clock::now();
        base->split(newElement);
        tAfter = std::chrono::high_resolution_clock::now();
        results[0][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test linked list
        tBefore = std::chrono::high_resolution_clock::now();
        list->split(newElement);
        tAfter = std::chrono::high_resolution_clock::now();
        results[1][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        
        // Test red-black tree
        tBefore = std::chrono::high_resolution_clock::now();
        tree->split(newElement, true);
        tAfter = std::chrono::high_resolution_clock::now();
        results[2][i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        delete base;
        delete list;
        delete tree;
    }
    std::cout << "\nBase:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[0][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nList:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[1][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
    
    std::cout << "\nTree:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[2][i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
}

void Testing::printJoinTests(int setSize, int numberOfTests) {
    std::cout << "\n--Testing running time of Join--\n";
    std::chrono::high_resolution_clock::time_point tBefore;
    std::chrono::high_resolution_clock::time_point tAfter;
    RedBlackTree * tree;
    RedBlackTree * tree2;
    long long results[numberOfTests];
    std::cout << "Number of elements: " << setSize << "\nNumber of insertions: " << numberOfTests << std::endl;
    for (int i = 0; i < numberOfTests; i++) {
        tree = new RedBlackTree;
        tree2 = new RedBlackTree;
        for (int j = 0; j < setSize; j++) {
            tree->createNode(j);
        }
        for (int j = setSize; j < 2*setSize; j++) {
            tree2->createNode(j);
        }
        
        // Test red-black tree
        tBefore = std::chrono::high_resolution_clock::now();
        tree->join(tree2);
        tAfter = std::chrono::high_resolution_clock::now();
        results[i] = std::chrono::duration_cast<std::chrono::nanoseconds>(tAfter - tBefore).count();
        delete tree;
        delete tree2;
    }
    std::cout << "\nTree:\n";
    for (int i = 0; i < numberOfTests; ++i) {
        std::cout << results[i] << ", ";
    }
    std::cout << "[nanoseconds]\n";
}

void Testing::printTests(int numberOfTests) {
    int setSizes[] = {100, 1000, 5000, 10000, 50000, 100000, 500000};
    for (int i = 0; i < 6; i++) {
        this->printInsertionTests(setSizes[i], numberOfTests);
        //this->printSearchTests(setSizes[i], numberOfTests, false);
        //this->printShiftTests(setSizes[i], numberOfTests);
        //this->printSplitTests(setSizes[i], numberOfTests); // max 50000 setSize
        //this->printJoinTests(setSizes[i], numberOfTests);
        //this->printMergeFourSegmentsTests(setSizes[i], 30);
        //this->printMergeWorstCaseTests(setSizes[i], 30);
        //this->printMergeRandomSetsTests(setSizes[i], 30);
        //printMergeRandomSetsOfDifferentSize(setSizes[i], 100, 30);
    }
    //printMergeRandomSetsTests(100000, 1);
}
