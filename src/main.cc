/**
 * @file main.cc
 * @author Mustafa Siddiqui
 * @brief Test file.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../templates/node.h"
#include <iostream>

int main(void)
{
    NODE<int> IntNode(12, "one");
    std::cout << IntNode << std::endl;

    NODE<double> DoubleNode(12.12, "two");
    std::cout << DoubleNode << std::endl;

    NODE<char> CharNode('c', "three");
    std::cout << CharNode << std::endl;

    NODE<std::string> StringNode("hello", "four");
    std::cout << StringNode << std::endl;

    return 0;
}
