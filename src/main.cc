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
    NODE<int> IntNode(0, 12);
    std::cout << IntNode << std::endl;

    NODE<int> IntNode2(1, 69);
    std::cout << IntNode2 << std::endl;

    NODE<int> IntNode3(2, 70);
    NODE<int> IntNode4(3, 99);

#ifdef DEBUG
    NODE<double> DoubleNode(4, 12.22);
    std::cout << DoubleNode << std::endl;

    NODE<char> CharNode(5, 'c');
    std::cout << CharNode << std::endl;

    NODE<std::string> StringNode(6, "hello");
    std::cout << StringNode << std::endl;
#endif

    LINKED_LIST<int> LinkedList(
        std::make_shared<NODE<int>>(IntNode),
        std::make_shared<NODE<int>>(IntNode2));
    std::cout << std::endl << LinkedList << std::endl;

    LinkedList.appendLast(std::make_shared<NODE<int>>(IntNode3));
    LinkedList.insertFirst(std::make_shared<NODE<int>>(IntNode4));

    LinkedList.print();

    return 0;
}
