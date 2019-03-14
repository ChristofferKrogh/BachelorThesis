//
//  main.cpp
//  BachelorThesis
//
//  Created by Christoffer Krogh on 25/02/2019.
//  Copyright © 2019 Christoffer Krogh. All rights reserved.
//
//#include <stdlib.h>
#include <stdio.h>
#include <iostream>
//#include <tuple>
#include "BaselineOne.hpp"
#include "LinkedList.hpp"

LinkedList split(LinkedList listToSplit, int splitValue);
void merge(LinkedList * listOne, LinkedList * listTwo);

int main(int argc, const char * argv[]) {
//    BaselineOne baselineOne;
//    int setOne[] = {1, 2, 6, 8, 9, 10};
//    int setSizeOne = sizeof(setOne) / sizeof(setOne[0]);
//    int setTwo[] = {3, 4, 5, 7, 11, 12};
//    int setSizeTwo = sizeof(setTwo) / sizeof(setTwo[0]);
//    int setThree[] = {13, 16, 18, 19, 20};
//    int setSizeThree = sizeof(setThree) / sizeof(setThree[0]);
//    std::cout << "The sets are:\n";
//    std::cout << "Set 1 = ";
//    baselineOne.display(setOne, setSizeOne);
//    std::cout << ", size = " << setSizeOne << "\n";
//    std::cout << "Set 2 = ";
//    baselineOne.display(setTwo, setSizeTwo);
//    std::cout << ", size = " << setSizeTwo << "\n";
//    std::cout << "Set 3 = ";
//    baselineOne.display(setThree, setSizeThree);
//    std::cout << ", size = " << setSizeThree << "\n";
//    std::cout << "\nSearching for '3' in set 1 results in:\n";
//    std::cout << "Index = " << baselineOne.search(setOne, setSizeOne, 3) << "\n";
//    std::cout << "\nSearching for '7' in set 2 results in:\n";
//    std::cout << "Index = " << baselineOne.search(setTwo, setSizeTwo, 7) << "\n";
//    std::cout << "\nSearching for '7' in set 3 results in:\n";
//    std::cout << "Index = " << baselineOne.search(setThree, setSizeThree, 7) << "\n";
//    std::cout << "Merging set 1 and set 3 results in:\n";
//    int * mergedSet = baselineOne.merge(setOne, setThree, setSizeOne, setSizeThree);
//    baselineOne.display(mergedSet, setSizeOne + setSizeThree);
//    std::cout << ", size = " << setSizeOne + setSizeThree << "\n";
//    std::cout << "Shifting set 1 by 3 results in:\n";
//    baselineOne.shift(setOne, setSizeOne, 3);
//    baselineOne.display(setOne, setSizeOne);
//    std::cout << ", size = " << setSizeOne << "\n";
//    std::cout << "Splitting set 3 at 18 results in:\n";
//    std::tuple <int *, int, int *, int> splitSets;
//    splitSets = baselineOne.split(setThree, setSizeThree, 18);
//    int * setFour = std::get<0>(splitSets);
//    int setSizeFour = std::get<1>(splitSets);
//    int * setFive = std::get<2>(splitSets);
//    int setSizeFive = std::get<3>(splitSets);
//    baselineOne.display(setFour, setSizeFour); std::cout << ", size = " << setSizeFour << "\n";
//    baselineOne.display(setFive, setSizeFive); std::cout << ", size = " << setSizeFive << "\n";
    
    
    LinkedList listOne;
    listOne.createNode(7);
    listOne.createNode(9);
    listOne.createNode(13);
    listOne.createNode(20);
    std::cout << "List 1:\n";
    listOne.display();
    std::cout << "Shifting list 1 by 2 gives:\n";
    listOne.shift(2);
    listOne.display();
    std::cout << std::endl;
    
    LinkedList listTwo;
    listTwo.createNode(1);
    listTwo.createNode(2);
    listTwo.createNode(3);
    listTwo.createNode(4);
    listTwo.createNode(5);
    std::cout << "List 2:\n";
    listTwo.display();
    listTwo.shift(4);
    std::cout << "Shifting list 2 by 4 gives:\n";
    listTwo.display();
    merge(&listOne, &listTwo);
    std::cout << "List 1:\n";
    listOne.display();
    std::cout << "List 2:\n";
    listTwo.display();
    std::cout << "Shift values are now: " << listOne.shiftValue << " and " << listTwo.shiftValue << std::endl;
    
    std::cout << "\n\n";
    return 0;
}

LinkedList split(LinkedList listToSplit, int splitValue) {
    // TODO:
    //  make more robust
    //  add it to LinkedList class
    LinkedList newList;
    newList.shiftValue = listToSplit.shiftValue;
    Node * newTail = listToSplit.search(splitValue);
    newList.setTail(listToSplit.getTail());
    newList.setHead(newTail -> next);
    newTail -> next = NULL;
    listToSplit.setTail(newTail);
    return newList;
}

void merge(LinkedList * listOne, LinkedList * listTwo) { // Maybe save the resulting list in one of the existing ones.
    // The two lists need to have the same shift value
    int shiftValueDiff = listTwo->shiftValue - listOne->shiftValue;
    shiftValueDiff < 0? listOne->updateShiftValue(-shiftValueDiff) : listTwo->updateShiftValue(shiftValueDiff);
    
    // Now we are ready for the actual merging.
    Node * i = listOne -> getHead();  // Initial index of first list
    Node * j = listTwo -> getHead();  // Initial index of second list
    Node * k;                         // Initial index of merged list
    if ((i -> data) <= (j -> data)) {
        k = i;
        i = i -> next;
    } else {
        k = j;
        j = j -> next;
    }
    listOne -> setHead(k);
    
    while (i != NULL && j != NULL) {
        if ((i -> data) <= (j -> data)) {
            k -> next = i;
            k = k -> next;
            i = i -> next;
        } else {
            k -> next = j;
            k = k -> next;
            j = j -> next;
        }
    }
    
    if (i != NULL) {
        k -> next = i;
    } else if (j != NULL) {
        k -> next = j;
        listOne -> setTail(listTwo -> getTail());
    }
}

//LinkedList createSet(int values[]) {
//    LinkedList newList;
//    for (int &value : values) {
//        newList.createNode(value);
//    }
//}
