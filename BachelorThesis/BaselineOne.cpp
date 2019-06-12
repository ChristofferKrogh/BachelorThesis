//
//  BaselineOne.cpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 09/03/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//

#include "BaselineOne.hpp"

BaselineOne::BaselineOne() {
    indexOfLastElement = -1;
    arraySize = 0;
}

void BaselineOne::insert(int value) {
    // We would like a dynamic set, that we can insert whatever element in without making it unsorted.
    if (indexOfLastElement == -1) {
        int * tmpValues = new int[20];
        tmpValues[0] = value;
        indexOfLastElement = 0;
        arraySize = 20;
        this->values = tmpValues;
    } else if (indexOfLastElement < (arraySize - 1)) { // No need to allocate more space
        int index = search(value);
        if (index == -2) { // New value should be first in list.
            for (int i = indexOfLastElement; i >= 0; --i) {
                values[i+1] = values[i];
            }
            values[0] = value;
            ++indexOfLastElement;
        } else if (values[index] != value) { // No duplicates
            // 'value' should be at index + 1.
            for (int i = indexOfLastElement; i >= index + 1; --i) {
                values[i+1] = values[i];
            }
            values[index + 1] = value;
            ++indexOfLastElement;
        }
    } else { // We need to allocatope more space
        arraySize = arraySize << 1; // double size
        int * tmpValues = new int[arraySize];
        int index = search(value);
        if (index == -2) { // New value should be first in list.
            for (int i = indexOfLastElement; i >= 0; --i) {
                tmpValues[i+1] = this->values[i];
            }
            tmpValues[0] = value;
            ++indexOfLastElement;
            this->values = tmpValues;
        } else if (values[index] != value) { // No duplicates
            // 'value' should be at index + 1.
            for (int i = indexOfLastElement; i >= index + 1; --i) {
                tmpValues[i+1] = this->values[i];
            }
            tmpValues[index + 1] = value;
            for (int i = 0; i <= index; ++i) {
                tmpValues[i] = this->values[i];
            }
            ++indexOfLastElement;
            this->values = tmpValues;
        }
    }
}

void BaselineOne::setValues(std::vector<int> newValues) {
    for (int value : newValues) {
        this->insert(value);
    }
}

int BaselineOne::search(int searchValue) {
    // Primarily a binary search - with the addition that it returns the index of the largest element smaller than or equal to the search value.
    int leftmostOfSearchArray = 0;
    int rightmostOfSearchArray = indexOfLastElement;
    int middleOfSearchArray = 0;
    if (leftmostOfSearchArray > rightmostOfSearchArray) { // The set is empty
        return -1;
    } else if (values[0] > searchValue) { // no elements are smaller than or equal to the search value
        return -2;
    }
    while (leftmostOfSearchArray <= rightmostOfSearchArray) {
        middleOfSearchArray = (leftmostOfSearchArray + rightmostOfSearchArray) / 2;
        if (middleOfSearchArray == rightmostOfSearchArray) {
            return middleOfSearchArray;
        } else if (values[middleOfSearchArray + 1] > searchValue &&
            values[middleOfSearchArray] < searchValue) {
            return middleOfSearchArray;
        }
        
        if (values[middleOfSearchArray] < searchValue) {
            leftmostOfSearchArray = middleOfSearchArray + 1;
        } else if (values[middleOfSearchArray] > searchValue) {
            rightmostOfSearchArray = middleOfSearchArray - 1;
        } else {
            return middleOfSearchArray;
        }
    }
    return NULL;
}

void BaselineOne::shift(int shiftValue) {
    for (int i = 0; i <= indexOfLastElement; ++i) {
        values[i] += shiftValue;
    }
}

BaselineOne BaselineOne::split(int splitValue) {
    int splitIndex = search(splitValue);
    if (splitIndex < 0) {
        //        throw error
    }
    int * listOne = new int[splitIndex + 1];
    int * listTwo = new int[indexOfLastElement - splitIndex - 1];
    
    for (int i = 0; i <= splitIndex; ++i) {
        listOne[i] = values[i];
    }
    for (int i = 0; i <= indexOfLastElement - splitIndex - 1; ++i) {
        listTwo[i] = values[i + splitIndex + 1];
    }
    values = listTwo;
    indexOfLastElement = indexOfLastElement - splitIndex - 1;
    arraySize = indexOfLastElement - splitIndex;
    
    BaselineOne returnList;
    returnList.values = listOne;
    returnList.indexOfLastElement = splitIndex;
    returnList.arraySize = splitIndex + 1;
    return returnList;
}

void BaselineOne::merge(BaselineOne newList) {
    // Merges the two input sets using methods from merge sort
    int * mergedList = new int[this->indexOfLastElement + newList.indexOfLastElement + 2];
    int i, j, k;
    // Merge the arrays into mergedSet
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = 0; // Initial index of merged subarray
    while (i <= this->indexOfLastElement  &&
           j <= newList.indexOfLastElement) {
        if (values[i] == newList.values[j]){ // This is added to avoid duplicates in resulting set
            mergedList[k] = this->values[i];
            i++;
            j++;
        } else if (values[i] < newList.values[j]) {
            mergedList[k] = values[i];
            i++;
        }
        else {
            mergedList[k] = newList.values[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements of setOne, if there are any
    while (i <= this->indexOfLastElement) {
        mergedList[k] = values[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of setTwo, if there are any
    while (j <= newList.indexOfLastElement) {
        mergedList[k] = newList.values[j];
        j++;
        k++;
    }
    
    this->values = mergedList;
    this->indexOfLastElement = this->indexOfLastElement + newList.indexOfLastElement;
    this->arraySize = this->indexOfLastElement + newList.indexOfLastElement + 1;
    
    newList.values = new int[0];
    newList.indexOfLastElement = -1;
    newList.arraySize = 0;
}

void BaselineOne::display() {
    for (int i = 0; i <= indexOfLastElement; ++i) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
}
