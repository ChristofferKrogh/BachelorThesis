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
#include <tuple>
#include "BaselineOne.hpp"
#include "LinkedList.hpp"
#include "RedBlackTree.hpp"
#include "Testing.hpp"

int main(int argc, const char * argv[]) {
//    BaselineOne baselineOne;
//    baselineOne.insert(8);
//    baselineOne.insert(13);
//    baselineOne.insert(17);
//    std::cout << "Showing baselineOne:\n";
//    baselineOne.display();
//    std::cout << "Shifting with 5:\n";
//    baselineOne.shift(5);
//    baselineOne.display();
//    BaselineOne baselineTwo;
//    baselineTwo.insert(10);
//    baselineTwo.insert(15);
//    baselineTwo.insert(19);
//    baselineTwo.insert(23);
//    std::cout << "Showing baselineTwo:\n";
//    baselineTwo.display();
//    std::cout << "Merging the sets:\nShowing baselineOne:\n";
//    baselineOne.merge(baselineTwo);
//    baselineOne.display();
//    std::cout << "Showing baselineTwo:\n";
//    baselineTwo.display();
//    std::cout << "Splitting baselineOne at 18:\n";
//    baselineOne.split(18);
//    baselineOne.display();
    
    
    
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
//    int setValuesOne[] = {7, 49, 9, 111, 57, 13, 21, 23, 25, 33, 133, 27, 29, 13};
//    int setSizeOne = sizeof(setValuesOne) / sizeof(setValuesOne[0]);
//    RedBlackTree treeOne; treeOne.createTree(setValuesOne, setSizeOne);
//    treeOne.display(true);
//    std::cout << std::endl;
//    std::string isTreeValid = treeOne.isTreeValid()? "yes" : "no";
//    std::cout << "Is tree valid? " << isTreeValid << "\n\n";
//
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
    
//    RedBlackTree treeTwo;
//    treeTwo.createNode(1);
//    treeTwo.createNode(2);
//    treeTwo.createNode(3);
//    treeTwo.createNode(4);
//    treeTwo.display(true);
//    std::cout << "\nIs tree valid? " << treeTwo.isTreeValid() << "\n";
//    treeTwo.join(&treeOne);
//    std::cout << "Showing treeOne: \n";
//    treeOne.display(true);
//    std::cout << "\n\n";
//    std::cout << "Showing treeTwo: \n";
//    treeTwo.display(true);
//    std::cout << "\nIs tree valid? " << treeTwo.isTreeValid() << "\n";
//    std::cout << "Min node: " << treeTwo.minNode->data << " max node: " << treeTwo.maxNode->data << std::endl;
    
    // Divider
//    std::cout << "\n–––––––––––––––––––––––––––––––––––––––––––––––\n";
//
//    RedBlackTree treeThree;
//    treeThree.createNode(7);
//    RedBlackTree treeFour;
//    treeFour.createNode(9);
//    treeFour.createNode(8);
//    treeThree.join(&treeFour);
//    std::cout << "\nTree Three:\n";
//    treeThree.display(true);
//    std::cout << "\nIs tree valid? " << treeThree.isTreeValid() << "\n";
//    std::cout << "Min node: " << treeThree.minNode->data << " max node: " << treeThree.maxNode->data << std::endl;
//
//    RedBlackTree treeFive;
//    treeFive.createNode(11);
//    RedBlackTree treeSix;
//    treeSix.createNode(12);
//    treeSix.createNode(13);
//    treeFive.join(&treeSix);
//    std::cout << "\nTree Five:\n";
//    treeFive.display(true);
//    std::cout << "\nIs tree valid? " << treeFive.isTreeValid() << "\n";
//    std::cout << "Min node: " << treeFive.minNode->data << " max node: " << treeFive.maxNode->data << std::endl;
    
//    std::cout << "\nJoining....\n";
//    treeThree.join(&treeFive);
//    treeThree.display(true);
//    std::cout << "\nIs tree valid? " << treeThree.isTreeValid() << "\n";
//    std::cout << "Min node: " << treeThree.minNode->data << " max node: " << treeThree.maxNode->data << std::endl;
//
//    RedBlackTree treeSeven;
//    treeSeven.createNode(67);
//
//    treeThree.join(&treeSeven);
//    std::cout << "" << treeThree.root->data << "->" << treeThree.root->rightChild->data << "->" << treeThree.root->rightChild->rightChild->data << std::endl;
//    treeThree.display(true);
//    std::cout << "\nIs tree valid? " << treeThree.isTreeValid() << "\n";
//    std::cout << "Min node: " << treeThree.minNode->data << " max node: " << treeThree.maxNode->data << std::endl;
    
    // Divider
//    std::cout << "\n–––––––––––––––––––––––––––––––––––––––––––––––\n";
//    std::cout << "Original Tree:\n";
//    treeTwo.display(false);
//    std::cout << "Min node: " << treeTwo.minNode->data << " max node: " << treeTwo.maxNode->data << std::endl;
//    RedBlackTree treeJAER = treeTwo.split(150);
//    std::cout << "\nSplitting with 22\nFirst split:\n";
//    treeTwo.display(false);
//    std::cout << "Min node: " << treeTwo.minNode->data << " max node: " << treeTwo.maxNode->data << std::endl;
//    std::cout << "\n\nSecond split:\n";
//    treeJAER.display(false);
//    std::cout << "Min node: " << treeJAER.minNode->data << " max node: " << treeJAER.maxNode->data << std::endl;
    
    // TESTING MERGE
//    std::cout << "\n–––––––––––––––––––––––––––––––––––––––––––––––\n";
//    std::cout << "TESTING MERGE...\n";
//    int setValuesJa[] = {1, 2, 12, 13, 15, 16, 17, 33, 44, 150};
//    int setSizeJa = sizeof(setValuesJa) / sizeof(setValuesJa[0]);
//    RedBlackTree treeJa; treeJa.createTree(setValuesJa, setSizeJa);
//    int setValuesNej[] = {5, 6, 30, 31, 32, 145};
//    int setSizeNej = sizeof(setValuesNej) / sizeof(setValuesNej[0]);
//    RedBlackTree treeNej;
//    treeNej.createTree(setValuesNej, setSizeNej);
//    std::cout << "Tree 1:\n";
//    treeJa.display(false);
//    std::cout << "\nTree 2:\n";
//    treeNej.display(false);
//    treeJa.merge(&treeNej);
//    treeJa.display(true);
//    std::cout << "Min node: " << treeJa.minNode->data << " max node: " << treeJa.maxNode->data << std::endl;
//    std::cout << "root: " << treeJa.root->data << " -> " << treeJa.root->rightChild->data << " -> " << treeJa.root->rightChild->rightChild->data << " -> " << treeJa.root->rightChild->rightChild->leftChild->data << std::endl;
    
//    std::cout << "max node: " << treeJa.maxNode->data << "^^" << treeJa.maxNode->parent->data << "^^" << treeJa.maxNode->parent->parent->data << "^^" << treeJa.maxNode->parent->parent->parent->data << std::endl;
    
//    RedBlackTree treeJeps; treeJeps.createNode(16);
//    treeJa.join(&treeJeps);
//    treeJa.display(false);
//    std::cout << "\n–––––––––––––––––––––––––––––––––––––––––––––––\n";
//    std::cout << "TESTING MERGE...\n";
//    int setValuesOne[] = {-2, 1, 2, 12, 13, 15, 16, 17, 332, 325, 456, 34};
//    int setSizeOne = sizeof(setValuesOne) / sizeof(setValuesOne[0]);
//    RedBlackTree treeOne; treeOne.createTree(setValuesOne, setSizeOne);
//    int setValuesTwo[] = {230, 175, 234, 455, 155, 12, 33, 32, 32, 45, 2, 4, -1, 43435043};
//    int setSizeTwo = sizeof(setValuesTwo) / sizeof(setValuesTwo[0]);
//    RedBlackTree treeTwo; treeTwo.createTree(setValuesTwo, setSizeTwo);
//
//
//    std::cout << "TreeOne before merge:\n";
//    treeOne.display(false);
//    std::cout << "TreeTwo before merge:\n";
//    treeTwo.display(false);
//    treeOne.merge(&treeTwo);
//    std::cout << std::endl;
//
//    std::cout << "TreeOne after merge:\n";
//    treeOne.display(true);
//    std::cout << "Is tree valid? " << treeOne.isTreeValid() << "\n";
//    std::cout << "\nTreeTwo after merge:\n";
//    treeTwo.display(false);
//    std::cout << "Is tree valid? " << treeTwo.isTreeValid() << "\n";
//    std::cout << treeOne.blackHeightAssumingValid(treeOne.minNode->rightChild);
    
//    std::cout << "\n–––––––––––––––––––––––––––––––––––––––––––––––\n";
//    std::cout << "TESTING SHIFT...\n";
//    RedBlackTree treeOne;
//    treeOne.createNode(7);
//    treeOne.createNode(3);
//    treeOne.createNode(11);
//    std::cout << "treeOne before shift:\n";
//    treeOne.display(false);
//    treeOne.shift(4);
//    std::cout << "treeOne after shifting with 4:\n";
//    treeOne.display(false);
//    treeOne.createNode(6);
//    std::cout << "treeOne after inserting 6:\n";
//    treeOne.display(false);
    
//    Testing testing;
//    testing.printTests();
    
    // Testing the linked list
//    LinkedList list1;
//    list1.createNode(7);
//    list1.createNode(4);
//    list1.shift(2);
//    list1.createNode(10);
//    list1.createNode(10);
//    list1.createNode(1);
//    list1.createNode(100);
//    list1.createNode(15);
//    list1.display();
//    for (int i = 20; i < 60; ++i) {
//        list1.createNode(i);
//    }
//    list1.display();
//    LinkedList list2;
//    for (int i = 50; i < 100; ++i) {
//        list2.createNode(i);
//    }
//    list2.display();
//    std::cout << "\nmerging...\n";
//    list1.merge(&list2);
//    list1.display();
//    LinkedList list2 = list1.split(30);
//    std::cout << "\nSplitting at 30:\n";
//    list1.display();
//    list2.display();
    
//    RedBlackTree treeOne;
//    treeOne.createNode(58);
//    treeOne.createNode(48);
//    treeOne.display(false);
//    std::cout << "Is tree valid? " << treeOne.isTreeValid() << "\n";
//    std::cout << "Shifting with 3:\n";
//    treeOne.shift(3);
//    treeOne.display(false);
//    std::cout << "Is tree valid? " << treeOne.isTreeValid() << "\n";
//    treeOne.createNode(68);
//    treeOne.createNode(38);
//    treeOne.createNode(34);
//    treeOne.display(false);
//    std::cout << "Is tree valid? " << treeOne.isTreeValid() << "\n";
//    std::cout << "Shifting with -2:\n";
//    treeOne.shift(-2);
//    treeOne.display(true);
//    std::cout << "Is tree valid? " << treeOne.isTreeValid() << "\n";
//    treeOne.createNode(12);
//    treeOne.display(false);
//    std::cout << "Is tree valid? " << treeOne.isTreeValid() << "\n";
//    treeOne.createNode(14);
//    treeOne.createNode(15);
//    treeOne.createNode(16);
//    treeOne.createNode(17);
//    treeOne.createNode(18);
//    treeOne.createNode(19);
//    treeOne.createNode(20);
//    treeOne.createNode(21);
//    treeOne.createNode(22);
//    treeOne.createNode(23);
//    treeOne.shift(5);
//    treeOne.display(false);
//    std::cout << "Is tree valid? " << treeOne.isTreeValid() << "\n";
    
//    std::cout << "----------JOIN-----------------\n";
//    RedBlackTree treeTwo;
//    treeTwo.createNode(73);
//    treeTwo.createNode(79);
//    treeTwo.createNode(74);
//    treeTwo.createNode(75);
//    treeTwo.createNode(76);
//    treeTwo.createNode(77);
//    treeTwo.createNode(83);
//    treeTwo.createNode(87);
//    treeTwo.createNode(85);
//    treeTwo.createNode(90);
//    treeTwo.shift(-1);
//    treeOne.display(true);
//    std::cout << "Is tree valid? " << treeOne.isTreeValid() << "\n";
//    treeTwo.display(true);
//    std::cout << "Is tree valid? " << treeTwo.isTreeValid() << "\n";
//    std::cout << "Joining...\n";
//    treeOne.join(&treeTwo);
//    treeOne.display(false);
//    std::cout << "Is tree valid? " << treeOne.isTreeValid() << "\n";
//    treeTwo.createNode(80);
//    treeTwo.createNode(85);
//    treeTwo.shift(13);
//    treeTwo.display(false);
//    std::cout << "Is tree valid? " << treeTwo.isTreeValid() << "\n";
//    std::cout << "Joining...\n";
//    treeOne.join(&treeTwo);
//    treeOne.display(false);
//    std::cout << "Is tree valid? " << treeOne.isTreeValid() << "\n";
    
//    std::cout << "Find max with total shift:\n";
//    std::tuple<RBTNode *, int> max = treeOne.findMaxNodeWithTotalShift();
//    std::cout << "Max value: " << std::get<0>(max)->data << "\nTotal shift: " << std::get<1>(max) << std::endl;
    
//    std::cout << "------------SPLIT-------------\n";
//    RedBlackTree treeTwo;
//    treeTwo.createNode(6);
//    treeTwo.createNode(8);
//    treeTwo.createNode(15);
//    treeTwo.createNode(26);
//    treeTwo.createNode(40);
//    treeTwo.createNode(65);
//    treeTwo.createNode(70);
//    treeTwo.createNode(174);
//    treeTwo.createNode(184);
//    treeTwo.shift(3);
//    treeOne.display(true);
//    std::cout << "Is tree valid? " << treeOne.isTreeValid() << "\n";
//    treeTwo.display(false);
//    std::cout << "Is tree valid? " << treeTwo.isTreeValid() << "\n";
//    std::cout << "Splitting at 36:\n";
//    RedBlackTree * treeThree = treeOne.split(36);
//    treeThree->display(false);
//    std::cout << "Is tree valid? " << treeThree->isTreeValid() << "\n";
//    treeOne.display(false);
//    std::cout << "Is tree valid? " << treeOne.isTreeValid() << "\n";
//    treeOne.merge(&treeTwo);
//    treeOne.display(false);
//    std::cout << "Is tree valid? " << treeOne.isTreeValid() << "\n";
//    treeTwo.display(false);
//    std::cout << "Is tree valid? " << treeTwo.isTreeValid() << "\n";
    
    
//    std::cout << "------------MERGE-------------\n";
//    RedBlackTree treeTwo;
//    treeTwo.createNode(6);
//    treeTwo.createNode(8);
//    treeTwo.createNode(15);
//    treeTwo.createNode(26);
//    treeTwo.createNode(40);
//    treeTwo.createNode(65);
//    treeTwo.createNode(70);
//    treeTwo.createNode(174);
//    treeTwo.createNode(184);
//    treeTwo.shift(30);
//    treeOne.display(false);
//    std::cout << "Is tree valid? " << treeOne.isTreeValid() << "\n";
//    treeTwo.display(false);
//    std::cout << "Is tree valid? " << treeTwo.isTreeValid() << "\n";
//    std::cout << "merging...\n";
//    treeOne.merge(&treeTwo);
//    treeOne.display(false);
//    std::cout << "Is tree valid? " << treeOne.isTreeValid() << "\n";
//    treeTwo.display(false);
//    std::cout << "Is tree valid? " << treeTwo.isTreeValid() << "\n";
//    treeTwo.createNode(5);
//    treeTwo.createNode(-5);
//    treeTwo.createNode(-7);
//    treeTwo.createNode(15);
//    treeTwo.createNode(98);
//    treeTwo.shift(2);
//    treeTwo.display(false);
//    std::cout << "Is tree valid? " << treeTwo.isTreeValid() << "\n";
//    std::cout << "merging...\n";
//    treeOne.merge(&treeTwo);
//    treeOne.display(false);
//    std::cout << "Is tree valid? " << treeOne.isTreeValid() << "\n";
//
//    std::cout << "---------SEARCHING---------\n";
//    std::cout << "Searching for 40:\n";
//    RBTNode * foundNode;
//    int totalShift;
//    std::tie(foundNode, totalShift) = treeOne.search(40);
//    std::cout << foundNode->data + totalShift << std::endl;
//
//    RedBlackTree * NikErSj = treeOne.split(40);
//    treeOne.display(false);
//    NikErSj->display(false);
//    treeOne.merge(NikErSj);
//    treeOne.display(false);
    
    
    // Test split
//    RedBlackTree testTree;
//    testTree.createNode(57);
//    testTree.createNode(5);
//    testTree.createNode(46);
//    testTree.createNode(50);
//    testTree.createNode(40);
//    testTree.createNode(33);
//    testTree.createNode(99);
//    testTree.createNode(14);
//    testTree.createNode(28);
//    testTree.createNode(1);
//    testTree.createNode(100);
//    testTree.createNode(-2);
//    testTree.display(false);
//    std::cout << "Is tree valid? " << testTree.isTreeValid() << "\n";
//    std::cout << "\nSplitting at 40...\n";
//    RedBlackTree * newTree = testTree.newSplit(40, true);
//    newTree->display(false);
//    std::cout << "Is tree valid? " << newTree->isTreeValid() << "\n";
//    testTree.display(false);
//    std::cout << "Is tree valid? " << testTree.isTreeValid() << "\n";
//
//    testTree.erase();
//    testTree.display(false);
//    for (int i = 0; i < 1000; ++i) {
//        testTree.createNode(i);
//    }
//    testTree.display(false);
//    std::cout << "Is tree valid? " << testTree.isTreeValid() << "\n";
//    std::cout << "\nSplitting at 4...\n";
//    newTree->setTree(testTree.newSplit(77, false));
//    newTree->display(false);
//    std::cout << "Is tree valid? " << newTree->isTreeValid() << "\n";
//    testTree.display(false);
//    std::cout << "Is tree valid? " << testTree.isTreeValid() << "\n";
    
    // Test join
//    RedBlackTree two;
//    two.createNode(100);
//    two.createNode(547);
//    two.createNode(203);
//    two.createNode(212);
//    two.createNode(199);
//    two.createNode(275);
//    two.createNode(256);
//    two.createNode(243);
//    two.display(false);
//    std::cout << "Is tree valid? " << two.isTreeValid() << "\n";
//    testTree.join(&two);
    // Test merge
    
    RedBlackTree one;
    one.createNode(101);
    one.createNode(501);
    one.createNode(401);
    one.createNode(301);
    one.createNode(201);
    one.createNode(601);
    one.createNode(701);
    one.shift(-4);
    one.display(false);
    std::cout << "Is tree valid? " << one.isTreeValid() << "\n";
    
    
    RedBlackTree two;
    two.createNode(100);
    two.createNode(547);
    two.createNode(203);
    two.createNode(212);
    two.createNode(199);
    two.createNode(275);
    two.createNode(256);
    two.createNode(243);
    two.shift(2);
    two.display(false);
    std::cout << "Is tree valid? " << two.isTreeValid() << "\n";
    
    RedBlackTree three;
    three.createNode(5);
    three.createNode(7);
    three.createNode(15);
    three.createNode(72);
    three.createNode(54);
    three.createNode(17);
    three.createNode(24);
    three.shift(3);
    three.createNode(7);
    three.display(false);
    std::cout << "Is tree valid? " << three.isTreeValid() << "\n";
    
    RedBlackTree four;
    four.createNode(1015);
    four.createNode(1115);
    four.createNode(1005);
    four.createNode(1018);
    four.createNode(1275);
    four.createNode(1073);
    four.createNode(1058);
    four.shift(14);
    four.createNode(1050);
    four.display(false);
    std::cout << "Is tree valid? " << four.isTreeValid() << "\n";
    
    std::cout << "\nJoining one and three...\n";
    three.join(&one);
    three.display(false);
    std::cout << "Is tree valid? " << three.isTreeValid() << "\n";
    
    std::cout << "\nJoining three and four...\n";
    three.join(&four);
    three.display(false);
    std::cout << "Is tree valid? " << three.isTreeValid() << "\n";
    
    std::cout << "\nMergeing three and two...\n";
    three.merge(&two);
    three.display(false);
    std::cout << "Is tree valid? " << three.isTreeValid() << "\n";
    
    std::cout << "\nSearching for 200...\n";
    three.search(200);
    
    
//    BaselineOne base1;
//    base1.insert(7);
//    base1.insert(9);
//    base1.insert(3);
//    base1.insert(20);
//    base1.insert(95);
//    base1.insert(74);
//    base1.insert(90);
//    base1.insert(32);
//    base1.insert(20);
//    base1.insert(19);
//    base1.insert(57);
//    base1.insert(79);
//    base1.insert(93);
//    base1.insert(200);
//    base1.insert(11);
//    base1.display();
//    std::cout << "\nSplitting at 50...\n";
//    BaselineOne base2 = base1.split(50);
//    base2.display();
//    base1.display();
//    base2.insert(27);
//    base2.insert(83);
//    base2.insert(90);
//    base1.insert(15);
//    std::cout << std::endl;
//    base2.display();
//    base1.display();
//    std::cout << "\nMerging...\n";
//    base1.merge(base2);
//    base1.display();
    
    std::cout << "\n\n";
    return 0;
}
