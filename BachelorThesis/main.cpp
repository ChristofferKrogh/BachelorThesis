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
    int setValuesOne[] = {7, 49, 9, 111, 57, 13, 21, 23, 25, 33, 133, 27, 29, 13};
    int setSizeOne = sizeof(setValuesOne) / sizeof(setValuesOne[0]);
    RedBlackTree treeOne; treeOne.createTree(setValuesOne, setSizeOne);
    treeOne.display(true);
    std::cout << std::endl;
    std::string isTreeValid = treeOne.isTreeValid()? "yes" : "no";
    std::cout << "Is tree valid? " << isTreeValid << "\n\n";
    
//    RedBlackTree treeThree;
//    treeThree.createNode(111);
//    treeThree.createNode(101);
//    treeThree.createNode(105);
//    treeThree.createNode(121);
//    treeThree.display(true);
//    std::cout << "\nIs tree valid? " << treeThree.isTreeValid() << "\n";
//    treeThree.deleteMaxNode();
//    treeThree.display(true);
//    std::cout << "\nIs tree valid? " << treeThree.isTreeValid() << "\n";
//    treeThree.deleteMaxNode();
//    treeThree.display(true);
//    std::cout << "\nIs tree valid? " << treeThree.isTreeValid() << "\n";
    
    RedBlackTree treeTwo;
    treeTwo.createNode(1);
    treeTwo.createNode(2);
    treeTwo.createNode(3);
    treeTwo.createNode(4);
    treeTwo.display(true);
    std::cout << "\nIs tree valid? " << treeTwo.isTreeValid() << "\n";
    treeTwo.join(&treeOne);
    std::cout << "Showing treeOne: \n";
    treeOne.display(true);
    std::cout << "\n\n";
    std::cout << "Showing treeTwo: \n";
    treeTwo.display(true);
    std::cout << "\nIs tree valid? " << treeTwo.isTreeValid() << "\n";
//    std::cout << "Min node: " << treeTwo.minNode->data << " max node: " << treeTwo.maxNode->data << std::endl;
    
    // Divider
    std::cout << "\n–––––––––––––––––––––––––––––––––––––––––––––––\n";
    
    RedBlackTree treeThree;
    treeThree.createNode(7);
    RedBlackTree treeFour;
    treeFour.createNode(9);
    treeFour.createNode(8);
    treeThree.join(&treeFour);
    std::cout << "\nTree Three:\n";
    treeThree.display(true);
    std::cout << "\nIs tree valid? " << treeThree.isTreeValid() << "\n";
    std::cout << "Min node: " << treeThree.minNode->data << " max node: " << treeThree.maxNode->data << std::endl;
    
    RedBlackTree treeFive;
    treeFive.createNode(11);
    RedBlackTree treeSix;
    treeSix.createNode(12);
    treeSix.createNode(13);
    treeFive.join(&treeSix);
    std::cout << "\nTree Five:\n";
    treeFive.display(true);
    std::cout << "\nIs tree valid? " << treeFive.isTreeValid() << "\n";
    std::cout << "Min node: " << treeFive.minNode->data << " max node: " << treeFive.maxNode->data << std::endl;
    
    std::cout << "\nJoining....\n";
    treeThree.join(&treeFive);
    treeThree.display(true);
    std::cout << "\nIs tree valid? " << treeThree.isTreeValid() << "\n";
    std::cout << "Min node: " << treeThree.minNode->data << " max node: " << treeThree.maxNode->data << std::endl;
    
    RedBlackTree treeSeven;
    treeSeven.createNode(67);
    
    treeThree.join(&treeSeven);
    std::cout << "" << treeThree.root->data << "->" << treeThree.root->rightChild->data << "->" << treeThree.root->rightChild->rightChild->data << std::endl;
    treeThree.display(true);
    std::cout << "\nIs tree valid? " << treeThree.isTreeValid() << "\n";
    std::cout << "Min node: " << treeThree.minNode->data << " max node: " << treeThree.maxNode->data << std::endl;
    
    // Divider
    std::cout << "\n–––––––––––––––––––––––––––––––––––––––––––––––\n";
    std::cout << "Original Tree:\n";
    treeTwo.display(false);
    RedBlackTree treeJAER = treeTwo.split(1);
    std::cout << "\nSplitting with 22\nFirst split:\n";
    treeTwo.display(false);
    std::cout << "\n\nSecond split:\n";
    treeJAER.display(false);
    
    std::cout << "\n\n";
//    treeOne.testDisplay();
    return 0;
}
