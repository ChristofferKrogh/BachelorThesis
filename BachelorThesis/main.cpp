//
//  main.cpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 25/02/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
//#include <tuple>
#include "BaselineOne.hpp"

void printArray(int array[], int arraySize);
/*
int search(int searchSet[], int arraySize, int searchValue);
void shift(int set[], int setSize, int shiftValue);
std::tuple<int *, int, int *, int> split(int splitSet[], int setSize, int splitValue);
int * merge(int setOne[], int setTwo[], int setSizeOne, int setSizeTwo);
 */

int main(int argc, const char * argv[]) {
    BaselineOne baselineOne;
    int setOne[] = {1, 2, 6, 8, 9, 10};
    int setSizeOne = sizeof(setOne) / sizeof(setOne[0]);
    int setTwo[] = {3, 4, 5, 7, 11, 12};
    int setSizeTwo = sizeof(setTwo) / sizeof(setTwo[0]);
    int setThree[] = {13, 16, 18, 19, 20};
    int setSizeThree = sizeof(setThree) / sizeof(setThree[0]);
    std::cout << "The sets are:\n";
    std::cout << "Set 1 = ";
    printArray(setOne, setSizeOne);
    std::cout << ", size = " << setSizeOne << "\n";
    std::cout << "Set 2 = ";
    printArray(setTwo, setSizeTwo);
    std::cout << ", size = " << setSizeTwo << "\n";
    std::cout << "Set 3 = ";
    printArray(setThree, setSizeThree);
    std::cout << ", size = " << setSizeThree << "\n";
    std::cout << "\nSearching for '3' in set 1 results in:\n";
    std::cout << "Index = " << baselineOne.search(setOne, setSizeOne, 3) << "\n";
    std::cout << "\nSearching for '7' in set 2 results in:\n";
    std::cout << "Index = " << baselineOne.search(setTwo, setSizeTwo, 7) << "\n";
    std::cout << "\nSearching for '7' in set 3 results in:\n";
    std::cout << "Index = " << baselineOne.search(setThree, setSizeThree, 7) << "\n";
    std::cout << "Merging set 1 and set 3 results in:\n";
    int * mergedSet = baselineOne.merge(setOne, setThree, setSizeOne, setSizeThree);
    printArray(mergedSet, setSizeOne + setSizeThree);
    std::cout << ", size = " << setSizeOne + setSizeThree << "\n";
    std::cout << "Shifting set 1 by 3 results in:\n";
    baselineOne.shift(setOne, setSizeOne, 3);
    printArray(setOne, setSizeOne);
    std::cout << ", size = " << setSizeOne << "\n";
    std::cout << "Splitting set 3 at 18 results in:\n";
    std::tuple <int *, int, int *, int> splitSets;
    splitSets = baselineOne.split(setThree, setSizeThree, 18);
    int * setFour = std::get<0>(splitSets);
    int setSizeFour = std::get<1>(splitSets);
    int * setFive = std::get<2>(splitSets);
    int setSizeFive = std::get<3>(splitSets);
    printArray(setFour, setSizeFour); std::cout << ", size = " << setSizeFour << "\n";
    printArray(setFive, setSizeFive); std::cout << ", size = " << setSizeFive << "\n";
    std::cout << "End of program" << std::endl;
    return 0;
}

void printArray(int array[], int arraySize) {
    if (arraySize == 0) {
        std::cout << "Array is empty\n";
    } else {
        std::cout << "[" << array[0];
        for (int i = 1; i < arraySize; i++) {
            std::cout << ", " << array[i];
        }
        std::cout << "]";
    }
}
