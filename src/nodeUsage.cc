/**
 * @file nodeUsage.cc
 * @author Mustafa Siddiqui
 * @brief Driver code for testing and sample usgae.
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

#include "templates/node.h"

int main(void) {
    auto node1 = std::make_shared<NODE<int>>(12);
    auto node2 = std::make_shared<NODE<int>>(99, 1);

    std::cout << node1->toString() << std::endl;
    std::cout << node2->toString() << std::endl;

    std::cout << "Node 1: " << node1->getValue() << std::endl;
    std::cout << "Node 2 value: " << node2->getValue() << std::endl;
    std::cout << "Node 2 ID: " << node2->getID() << std::endl;

    auto nodeWithStringData = std::make_shared<NODE<std::string>>("hello");
    auto node2WithStringData =
        std::make_shared<NODE<std::string>>("Mustafa", 7);

    std::cout << nodeWithStringData->toString() << std::endl;
    std::cout << node2WithStringData->toString() << std::endl;

    NODE<char> nodeWithChar('m');
    std::cout << nodeWithChar.toString() << std::endl;

    return 0;
}
