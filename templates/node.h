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

#include <iostream>
#include <string>

template <typename T>
class NODE {
private:
    T myVal;
    std::string myId;

public:
    /**
     * @brief Construct a new NODE object.
     */
    NODE() {};

    NODE(T value, std::string id)
        : myVal(value)
        , myId(id)
    {
    }

    /**
     * @brief Destroy the NODE object.
     */
    ~NODE() {};

    /**
     * @brief Get the value stored in the node.
     * @return value of node of type T
     */
    T getValue(void) const { return this->myVal; }

    /**
     * @brief Get the ID of the node.
     * @return a string represting the ID.
     */
    std::string getID(void) const { return this->myId; }

    /**
     * @brief Return a string representation of object.
     * Note: declarationa and definition is split to provide
     * template specialization.
     */
    std::string toString(void) const;

    /**
     * @brief Overload stream insertion operator.
     * @param out Output stream
     * @param node Object of Node<T> class.
     * @return Output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const NODE<T>& nodeObj)
    {
        os << nodeObj.toString();
        return os;
    }
};

/**
 * @brief Template method definition for toString().
 */
template <typename T>
std::string NODE<T>::toString(void) const
{
    return "[Node Value: " + std::to_string(this->getValue())
        + ", Node ID: " + this->getID() + "]";
}

/**
 * @brief Template specialization for toString() when type = char.
 */
template <>
std::string NODE<char>::toString(void) const
{
    return "[Node Value: " + std::string(1, this->getValue())
        + ", Node ID: " + this->getID() + "]";
}

/**
 * @brief Template specialization for toString() when type = std::string.
 */
template <>
std::string NODE<std::string>::toString(void) const
{
    return "[Node Value: " + this->getValue()
        + ", Node ID: " + this->getID() + "]";
}

#endif /* _NODE_H_ */
