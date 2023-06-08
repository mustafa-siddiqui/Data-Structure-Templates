/**
 * @file main.cc
 * @author Mustafa Siddiqui
 * @brief Driver code for testing and sample usgae.
 *
 * @copyright Copyright (c) 2023
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

    auto IntNodePtr = std::make_shared<NODE<int>>(IntNode);
    auto IntNode2Ptr = std::make_shared<NODE<int>>(IntNode2);

    LINKED_LIST<int> LinkedList(IntNodePtr, IntNode2Ptr);
    std::cout << std::endl << LinkedList << std::endl;
    std::cout << "Size: " << LinkedList.getSize() << std::endl;

    auto node = std::make_shared<NODE<int>>(70);
    LinkedList.appendLast(node);
    LinkedList.insertFirst(std::make_shared<NODE<int>>(1000));
    LinkedList.appendLast(std::make_shared<NODE<int>>(47));

    LinkedList.print();
    std::cout << "Size: " << LinkedList.getSize() << std::endl;

    // delete head node
    std::cout << "\nDeleting head node\n";
    auto nodeToDelete = LinkedList.getHead();
    auto retVal = LinkedList.deleteNode(nodeToDelete);
    if (retVal) {
        LinkedList.print();
        std::cout << "Size: " << LinkedList.getSize() << std::endl;
    } else {
        std::cout << ERROR_CODES_FUNC::toString(retVal.error()) << std::endl;
    }

    // delete tail node
    std::cout << "\nDeleting tail node\n";
    nodeToDelete = LinkedList.getTail();
    retVal = LinkedList.deleteNode(nodeToDelete);
    if (retVal) {
        LinkedList.print();
        std::cout << "Size: " << LinkedList.getSize() << std::endl;
    } else {
        std::cout << ERROR_CODES_FUNC::toString(retVal.error()) << std::endl;
    }

    // delete some node in middle
    std::cout << "\nDeleting node in middle\n";
    nodeToDelete = std::make_shared<NODE<int>>(IntNode2);
    retVal = LinkedList.deleteNode(nodeToDelete);
    if (retVal) {
        LinkedList.print();
        std::cout << "Size: " << LinkedList.getSize() << std::endl;
    } else {
        std::cout << ERROR_CODES_FUNC::toString(retVal.error()) << std::endl;
    }

    // find node
    std::cout << "\nFinding a node\n";
    auto retVal1 = LinkedList.find(node);
    if (retVal1) {
        std::cout << "Node with id {" << retVal1.value() << "} found"
                  << std::endl;
    } else {
        std::cout << ERROR_CODES_FUNC::toString(retVal1.error()) << std::endl;
    }

    // insert before
    std::cout << "\nInserting node before another node\n";
    auto retVal2 =
        LinkedList.insertBefore(node, std::make_shared<NODE<int>>(999));
    if (retVal2) {
        LinkedList.print();
        std::cout << "Size: " << LinkedList.getSize() << std::endl;

    } else {
        std::cout << ERROR_CODES_FUNC::toString(retVal2.error()) << std::endl;
    }

    // insert before head
    std::cout << "\nInserting before head node\n";
    retVal2 = LinkedList.insertBefore(LinkedList.getHead(),
                                      std::make_shared<NODE<int>>(999));
    if (retVal2) {
        LinkedList.print();
        std::cout << "Size: " << LinkedList.getSize() << std::endl;

    } else {
        std::cout << ERROR_CODES_FUNC::toString(retVal2.error()) << std::endl;
    }

    // insert after
    std::cout << "\nInserting after a node\n";
    retVal2 =
        LinkedList.insertAfter(IntNodePtr, std::make_shared<NODE<int>>(179));
    if (retVal2) {
        LinkedList.print();
        std::cout << "Size: " << LinkedList.getSize() << std::endl;

    } else {
        std::cout << ERROR_CODES_FUNC::toString(retVal2.error()) << std::endl;
    }

    // insert after tail
    std::cout << "\nInserting after tail node\n";
    retVal2 = LinkedList.insertAfter(LinkedList.getTail(),
                                     std::make_shared<NODE<int>>(200));
    if (retVal2) {
        LinkedList.print();
        std::cout << "Size: " << LinkedList.getSize() << std::endl;

    } else {
        std::cout << ERROR_CODES_FUNC::toString(retVal2.error()) << std::endl;
    }

    return 0;
}
