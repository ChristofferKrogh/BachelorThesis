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
    Testing testing;
    testing.printTests();
    
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
    
//    RedBlackTree one;
//    one.createNode(101);
//    one.createNode(501);
//    one.createNode(401);
//    one.createNode(301);
//    one.createNode(201);
//    one.createNode(601);
//    one.createNode(701);
//    one.shift(-4);
//    one.display(false);
//    std::cout << "Is tree valid? " << one.isTreeValid() << "\n";
//
//
//    RedBlackTree two;
//    two.createNode(100);
//    two.createNode(547);
//    two.createNode(203);
//    two.createNode(212);
//    two.createNode(199);
//    two.createNode(275);
//    two.createNode(256);
//    two.createNode(243);
//    two.shift(2);
//    two.display(false);
//    std::cout << "Is tree valid? " << two.isTreeValid() << "\n";
//
//    RedBlackTree three;
//    three.createNode(5);
//    three.createNode(7);
//    three.createNode(15);
//    three.createNode(72);
//    three.createNode(54);
//    three.createNode(17);
//    three.createNode(24);
//    three.shift(3);
//    three.createNode(7);
//    three.display(false);
//    std::cout << "Is tree valid? " << three.isTreeValid() << "\n";
//
//    RedBlackTree four;
//    four.createNode(1015);
//    four.createNode(1115);
//    four.createNode(1005);
//    four.createNode(1018);
//    four.createNode(1275);
//    four.createNode(1073);
//    four.createNode(1058);
//    four.shift(14);
//    four.createNode(1050);
//    four.display(false);
//    std::cout << "Is tree valid? " << four.isTreeValid() << "\n";
//
//    std::cout << "\nJoining one and three...\n";
//    three.join(&one);
//    three.display(false);
//    std::cout << "Is tree valid? " << three.isTreeValid() << "\n";
//
//    std::cout << "\nJoining three and four...\n";
//    three.join(&four);
//    three.display(false);
//    std::cout << "Is tree valid? " << three.isTreeValid() << "\n";
//
//    std::cout << "\nMergeing three and two...\n";
//    three.merge(&two);
//    three.display(false);
//    std::cout << "Is tree valid? " << three.isTreeValid() << "\n";
//
//    std::cout << "\nSearching for 200...\n";
//    RBTNode * node = three.search(200);
//    std::cout << node->data + node->shift << std::endl;
//
//    one.createNode(17);
//    one.shift(4);
//    two.createNode(17);
//    two.shift(-2);
//    one.merge(&two);
//    one.display(true);
//    node = one.search(20);
//    std::cout << node->data << std::endl;
    
//    BaselineOne * base1 = new BaselineOne;
//    for (int i = 0; i < 100; i++) {
//        base1->insert(i);
//    }
//    base1->display();
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
