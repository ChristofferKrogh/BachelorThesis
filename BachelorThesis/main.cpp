//
//  main.cpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 25/02/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//

#include <iostream>

void printArray(int array[], int arraySize);
int search(int searchSet[], int arraySize, int searchValue);
int * merge(int setOne, int setTwo, int setSizeOne, int setSizeTwo);

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
    std::cout << "\nSearching for '7' in set 1 results in:\n";
    std::cout << "Index = " << search(setOne, setSizeOne, 7) << "\n";
    std::cout << "\nSearching for '7' in set 2 results in:\n";
    std::cout << "Index = " << search(setTwo, setSizeTwo, 7) << "\n";
    std::cout << "\nSearching for '7' in set 3 results in:\n";
    std::cout << "Index = " << search(setThree, setSizeThree, 7) << "\n";
    
    std::cout << "End of program\n" << std::endl;
    return 0;
}

int search(int searchSet[], int setSize, int searchValue) {
    // Primarily a binary search - with the addition that it returns the index of the largest
    // element smaller than or equal to the search value.
    int leftmostOfSearchArray = 0;
    int rightmostOfSearchArray = setSize - 1;
    int middleOfSearchArray = 0;
    if (leftmostOfSearchArray > rightmostOfSearchArray) {
        return -1;
    } else if (searchSet[0] > searchValue) {
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
    }
    return middleOfSearchArray - 1;
}

int * merge(int setOne[], int setTwo[], int setSizeOne, int setSizeTwo) {
    int mergedSet[setSizeOne + setSizeTwo];
    for (int i = 0; i < setSizeOne; i++) {
        mergedSet[i] = setOne[i];
    }
    for (int i = 0; i < setSizeTwo; i++) {
        mergedSet[i + setSizeOne] = setTwo[i];
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
