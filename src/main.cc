/**
 * @file main.cc
 * @author Mustafa Siddiqui
 * @brief Test file.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

#include "templates/linked-list.h"
#include "templates/node.h"

int main(void) {
    NODE<int> IntNode("one", 12);
    std::cout << IntNode << std::endl;

    NODE<int> IntNode2("one-two", 69);
    std::cout << IntNode2 << std::endl;

    NODE<int> IntNode3("one-three", 70);
    NODE<int> IntNode4("one-four", 99);

    NODE<double> DoubleNode("two", 12.22);
    std::cout << DoubleNode << std::endl;

    NODE<char> CharNode("three", 'c');
    std::cout << CharNode << std::endl;

    NODE<std::string> StringNode("four", "hello");
    std::cout << StringNode << std::endl;

    LINKED_LIST<int> LinkedList(
        std::make_shared<NODE<int>>(IntNode),
        std::make_shared<NODE<int>>(IntNode2));
    std::cout << std::endl << LinkedList << std::endl;

    LinkedList.appendLast(std::make_shared<NODE<int>>(IntNode3));
    LinkedList.insertFirst(std::make_shared<NODE<int>>(IntNode4));

    std::cout << std::endl << LinkedList << std::endl;

    return 0;
}
