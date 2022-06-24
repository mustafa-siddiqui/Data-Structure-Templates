/**
 * @file    node.h
 * @author  Mustafa Siddiqui
 * @brief   Template class for a node.
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _NODE_H_
#define _NODE_H_

/**
 * =====================================================
 * INCLUDES
 * =====================================================
 */
#include "../interfaces/node-intf.h"
#include <iostream>
#include <string>

/**
 * =====================================================
 * CLASS DEFINITIONS
 * =====================================================
 */

/**
 * @brief Template class for a node. Inherits from the
 * interface for a node class.
 * @tparam T typename
 */
template <typename T>
class NODE : public NODE_INTF<T> {
private:
    std::string myId;
    T myVal;

public:
    // delete default & copy constructors and assignment operator.
    NODE() = delete;
    NODE(NODE const&) = delete;
    NODE& operator=(NODE const&) = delete;

    // constructor
    explicit NODE(std::string id, T value)
        : NODE_INTF<T>()
        , myId(id)
        , myVal(value)
    {
    }

    // destructor
    ~NODE() override {};

    // return id of object
    std::string getID(void) const override
    {
        return this->myId;
    }

    // return value stored in object
    T getValue(void) const override
    {
        return this->myVal;
    }

    // declaration and definition is split due to
    // template specializations required.
    std::string toString(void) const override;

    /**
     * @brief Overload stream insertion operator.
     * @param out Output stream
     * @param node Object of Node<T> class.
     */
    friend std::ostream& operator<<(std::ostream& os, const NODE<T>& nodeObj)
    {
        os << nodeObj.toString();
        return os;
    }
};

// template method
template <typename T>
std::string NODE<T>::toString(void) const
{
    return "[Node Value: " + std::to_string(this->getValue())
        + ", Node ID: " + this->getID() + "]";
}

// template specialization when type = char
template <>
std::string NODE<char>::toString(void) const
{
    return "[Node Value: " + std::string(1, this->getValue())
        + ", Node ID: " + this->getID() + "]";
}

// template specialization when type = string
template <>
std::string NODE<std::string>::toString(void) const
{
    return "[Node Value: " + this->getValue()
        + ", Node ID: " + this->getID() + "]";
}

#endif /* _NODE_H_ */
