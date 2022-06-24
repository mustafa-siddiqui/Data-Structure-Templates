/**
 * @file main.cc
 * @author Mustafa Siddiqui
 * @brief Test file.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "templates/node.h"
#include <iostream>

int main(void)
{
    NODE<int> IntNode("one", 12);
    std::cout << IntNode << std::endl;

    NODE<double> DoubleNode("two", 12.22);
    std::cout << DoubleNode << std::endl;

    NODE<char> CharNode("three", 'c');
    std::cout << CharNode << std::endl;

    NODE<std::string> StringNode("four", "hello");
    std::cout << StringNode << std::endl;

    return 0;
}
