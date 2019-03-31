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
#include "RedBlackTree.hpp"


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
    
//    int setValuesOne[] = {7, 9, 13, 20, 22, 25, 27, 28};
//    LinkedList listOne; listOne.createSet(setValuesOne, 8);
//    std::cout << "List 1:\n";
//    listOne.display();
//    std::cout << "Shifting list 1 by 12 gives:\n";
//    listOne.shift(12);
//    listOne.display();
//    LinkedList listTwo = listOne.split(5);
//    std::cout << "List 1 after splitting at 5:\n";
//    listOne.display();
//    std::cout << std::endl;
//
//    std::cout << "List 2:\n";
//    listTwo.display();
//    listTwo.shift(15);
//    std::cout << "Shifting list 2 by 15 gives:\n";
//    listTwo.display();
    
//    int setValuesOne[] = {7, 9, 13, 20, 22, 25, 27, 28};
    int setValuesOne[] = {7, 48, 9, 13, 20, 22, 25, 27, 28};
    RedBlackTree treeOne; treeOne.createTree(setValuesOne, 8);
//    treeOne.createNode(7);
//    treeOne.createNode(8);
//    treeOne.createNode(9);
//    treeOne.createNode(10);
//    treeOne.createNode(5);
    treeOne.display();
    std::cout << std::endl;
    std::string isTreeValid;
    isTreeValid = treeOne.isTreeValid()? "yes" : "no";
    std::cout << "Is tree valid? " << isTreeValid;
    
    std::cout << "\n\n";
//    treeOne.testDisplay();
    return 0;
}
