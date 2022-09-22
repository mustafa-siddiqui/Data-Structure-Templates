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

    LINKED_LIST<int> LinkedList(
        std::make_shared<NODE<int>>(IntNode),
        std::make_shared<NODE<int>>(IntNode2));
    std::cout << std::endl << LinkedList << std::endl;
    std::cout << "Size: " << LinkedList.getSize() << std::endl;

    LinkedList.appendLast(std::make_shared<NODE<int>>(70));
    LinkedList.insertFirst(std::make_shared<NODE<int>>(1000));

    LinkedList.print();
    std::cout << "Size: " << LinkedList.getSize() << std::endl;

    // delete head node
    std::cout << "\nDeleting head node\n";
    auto nodeToDelete = std::shared_ptr<NODE_INTF<int>>(LinkedList.getHead());
    LinkedList.deleteNode(nodeToDelete);
    LinkedList.print();
    std::cout << "Size: " << LinkedList.getSize() << std::endl;

    // delete tail node
    std::cout << "\nDeleting tail node\n";
    nodeToDelete = std::shared_ptr<NODE_INTF<int>>(LinkedList.getTail());
    LinkedList.deleteNode(nodeToDelete);
    LinkedList.print();
    std::cout << "Size: " << LinkedList.getSize() << std::endl;

    return 0;
}
