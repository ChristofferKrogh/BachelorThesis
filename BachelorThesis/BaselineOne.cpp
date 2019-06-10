//
//  BaselineOne.cpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 09/03/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//

#include "BaselineOne.hpp"



void BaselineOne::insert(int value) {
    values.push_back(value);
}

void BaselineOne::setValues(std::vector<int> newValues) {
    values = newValues;
}

int BaselineOne::search(int searchValue) {
    // Primarily a binary search - with the addition that it returns the index of the largest element smaller than or equal to the search value.
    int leftmostOfSearchArray = 0;
    int rightmostOfSearchArray = static_cast<int>(values.size())  - 1;
    int middleOfSearchArray = 0;
    if (leftmostOfSearchArray > rightmostOfSearchArray) { // The set is empty
        return -1;
    } else if (values[0] > searchValue) { // no elements are smaller than or equal to the search value
        return -2;
    }
    while (leftmostOfSearchArray <= rightmostOfSearchArray) {
        middleOfSearchArray = (leftmostOfSearchArray + rightmostOfSearchArray) / 2;
        if (values[middleOfSearchArray] < searchValue) {
            leftmostOfSearchArray = middleOfSearchArray + 1;
        } else if (values[middleOfSearchArray] > searchValue) {
            rightmostOfSearchArray = middleOfSearchArray - 1;
        } else {
            return middleOfSearchArray;
        }
        if (values[middleOfSearchArray + 1] > searchValue &&
            values[middleOfSearchArray] < searchValue) {
            return middleOfSearchArray;
        }
    }
    return NULL;
}

void BaselineOne::shift(int shiftValue) {
    for (int &value : values) {
        value += shiftValue;
    }
}

std::vector<int> BaselineOne::split(int splitValue) {
    int splitIndex = search(splitValue);
    if (splitIndex < 0) {
        //        throw error
    }
    
    std::vector<int> setOne;
    std::vector<int> setTwo;
    
    for (int i = 0; i <= splitIndex; i++) {
        setOne.push_back(values[i]);
    }
    for (int i = 0; i < static_cast<int>(values.size()) - splitIndex - 1; i++) {
        setTwo.push_back(values[i + splitIndex + 1]);
    }
    values = setTwo;
    
    return setOne;
}

void BaselineOne::merge(BaselineOne newSet) {
    /* Merges the two input sets using methods from merge sort*/
    std::vector<int> mergedSet;
    int i, j, k;
    /* Merge the arrays into mergedSet*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = 0; // Initial index of merged subarray
    while (i < static_cast<int>(values.size()) && j < static_cast<int>(newSet.values.size())) {
        if (values[i] == newSet.values[j]){ // This is added to avoid duplicates in resulting set
            mergedSet.push_back(values[i]);
            i++;
            j++;
        } else if (values[i] < newSet.values[j]) {
            mergedSet.push_back(values[i]);
            i++;
        }
        else {
            mergedSet.push_back(newSet.values[j]);
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of setOne, if there
     are any */
    while (i < static_cast<int>(values.size())) {
        mergedSet[k] = values[i];
        i++;
        k++;
    }
    
    /* Copy the remaining elements of setTwo, if there
     are any */
    while (j < static_cast<int>(newSet.values.size())) {
        mergedSet[k] = newSet.values[j];
        j++;
        k++;
    }
    values = mergedSet;
    newSet.values.clear();
}

void BaselineOne::display() {
    for (int value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
