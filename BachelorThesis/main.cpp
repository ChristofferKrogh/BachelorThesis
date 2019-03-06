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
#include <tuple>

void printArray(int array[], int arraySize);
int search(int searchSet[], int arraySize, int searchValue);
void shift(int set[], int setSize, int shiftValue);
std::tuple<int *, int, int *, int> split(int splitSet[], int setSize, int splitValue);
int * merge(int setOne[], int setTwo[], int setSizeOne, int setSizeTwo);

int main(int argc, const char * argv[]) {
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
    std::cout << "Index = " << search(setOne, setSizeOne, 3) << "\n";
    std::cout << "\nSearching for '7' in set 2 results in:\n";
    std::cout << "Index = " << search(setTwo, setSizeTwo, 7) << "\n";
    std::cout << "\nSearching for '7' in set 3 results in:\n";
    std::cout << "Index = " << search(setThree, setSizeThree, 7) << "\n";
    std::cout << "Merging set 1 and set 3 results in:\n";
    int * mergedSet = merge(setOne, setThree, setSizeOne, setSizeThree);
    printArray(mergedSet, setSizeOne + setSizeThree);
    std::cout << ", size = " << setSizeOne + setSizeThree << "\n";
    std::cout << "Shifting set 1 by 3 results in:\n";
    shift(setOne, setSizeOne, 3);
    printArray(setOne, setSizeOne);
    std::cout << ", size = " << setSizeOne << "\n";
    std::cout << "Splitting set 3 at 18 results in:\n";
    std::tuple <int *, int, int *, int> splitSets;
    splitSets = split(setThree, setSizeThree, 18);
    int * setFour = std::get<0>(splitSets);
    int setSizeFour = std::get<1>(splitSets);
    int * setFive = std::get<2>(splitSets);
    int setSizeFive = std::get<3>(splitSets);
    printArray(setFour, setSizeFour); std::cout << ", size = " << setSizeFour << "\n";
    printArray(setFive, setSizeFive); std::cout << ", size = " << setSizeFive << "\n";
    std::cout << "End of program" << std::endl;
    return 0;
}

int search(int searchSet[], int setSize, int searchValue) {
    /* Primarily a binary search - with the addition that it returns the index of the largest
     element smaller than or equal to the search value.*/
    int leftmostOfSearchArray = 0;
    int rightmostOfSearchArray = setSize - 1;
    int middleOfSearchArray = 0;
    if (leftmostOfSearchArray > rightmostOfSearchArray) { // The set is empty
        return -1;
    } else if (searchSet[0] > searchValue) { // no elements are smaller than or equal to the search value
        return -2;
    }
    while (leftmostOfSearchArray <= rightmostOfSearchArray) {
        middleOfSearchArray = (leftmostOfSearchArray + rightmostOfSearchArray) / 2;
        if (searchSet[middleOfSearchArray] < searchValue) {
            leftmostOfSearchArray = middleOfSearchArray + 1;
        } else if (searchSet[middleOfSearchArray] > searchValue) {
            rightmostOfSearchArray = middleOfSearchArray - 1;
        } else {
            return middleOfSearchArray;
        }
        if (searchSet[middleOfSearchArray + 1] > searchValue &&
            searchSet[middleOfSearchArray] < searchValue) {
            return middleOfSearchArray;
        }
    }
    return NULL;
}

void shift(int shiftSet[], int setSize, int shiftValue) {
    for (int i = 0; i < setSize; i++) {
        shiftSet[i] += shiftValue;
    }
}

std::tuple<int *, int, int *, int> split(int splitSet[], int setSize, int splitValue) {
    int splitIndex = search(splitSet, setSize, splitValue);
    if (splitIndex < 0) {
//        throw error
    }
    
    std::tuple <int *, int, int *, int> splitSets;
    int setOneSize = splitIndex + 1;
    int * setOne = new int[setOneSize];
    int setTwoSize = setSize - (splitIndex + 1);
    int * setTwo = new int[setTwoSize];
    
    for (int i = 0; i < setOneSize; i++) {
        setOne[i] = splitSet[i];
    }
    
    for (int i = 0; i < setTwoSize; i++) {
        setTwo[i] = splitSet[i + setOneSize];
    }
    
    splitSets = std::make_tuple(setOne, setOneSize, setTwo, setTwoSize);
    
    return splitSets;
}

int * merge(int setOne[], int setTwo[], int setSizeOne, int setSizeTwo) {
    /* Merges the two input sets using methods from merge sort*/
    int * mergedSet = new int[setSizeOne + setSizeTwo];
    int i, j, k;
    /* Merge the arrays into mergedSet*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = 0; // Initial index of merged subarray
    while (i < setSizeOne && j < setSizeTwo) {
        if (setOne[i] <= setTwo[j]) {
            mergedSet[k] = setOne[i];
            i++;
        }
        else {
            mergedSet[k] = setTwo[j];
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of setOne, if there
     are any */
    while (i < setSizeOne) {
        mergedSet[k] = setOne[i];
        i++;
        k++;
    }
    
    /* Copy the remaining elements of setTwo, if there
     are any */
    while (j < setSizeTwo) {
        mergedSet[k] = setTwo[j];
        j++;
        k++;
    }
    return mergedSet;
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
