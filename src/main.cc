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
    NODE<int> IntNode(99);
    std::cout << IntNode << std::endl;

    NODE<int> IntNode2(69);
    std::cout << IntNode2 << std::endl;

    NODE<int> IntNode3(70);
    NODE<int> IntNode4(1000);

    LINKED_LIST<int> LinkedList(
        std::make_shared<NODE<int>>(IntNode),
        std::make_shared<NODE<int>>(IntNode2));
    std::cout << std::endl << LinkedList << std::endl;
    std::cout << "Size: " << LinkedList.getSize() << std::endl;

    LinkedList.appendLast(std::make_shared<NODE<int>>(IntNode3));
    LinkedList.insertFirst(std::make_shared<NODE<int>>(IntNode4));

    LinkedList.print();
    std::cout << "Size: " << LinkedList.getSize() << std::endl;

    // test
    bool res = true;
    if (!(*LinkedList.getHead() == IntNode4)) {
        res = false;
        std::cout << LinkedList.getHead()->toString() << ", "
                  << IntNode4.toString() << std::endl;
    }
    std::cout << "\nres: " << res << std::endl;

    std::cout << "\nDeleting node\n";
    LinkedList.deleteNode(std::make_shared<NODE<int>>(IntNode4));
    LinkedList.print();
    std::cout << "Size: " << LinkedList.getSize() << std::endl;

    return 0;
}
