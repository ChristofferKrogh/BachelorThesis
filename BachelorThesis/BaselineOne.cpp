//
//  BaselineOne.cpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 09/03/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//

#include "BaselineOne.hpp"

int BaselineOne::search(int searchSet[], int setSize, int searchValue) {
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

void BaselineOne::shift(int shiftSet[], int setSize, int shiftValue) {
    for (int i = 0; i < setSize; i++) {
        shiftSet[i] += shiftValue;
    }
}

std::tuple<int *, int, int *, int> BaselineOne::split(int splitSet[], int setSize, int splitValue) {
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

int * BaselineOne::merge(int setOne[], int setTwo[], int setSizeOne, int setSizeTwo) {
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
