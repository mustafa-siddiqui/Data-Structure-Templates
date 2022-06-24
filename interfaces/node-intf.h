/**
 * @file node-intf.h
 * @author Mustafa Siddiqui
 * @brief Interface for the node class.
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _NODE_INTF_H_
#define _NODE_INTF_H_

/**
 * =====================================================
 * INCLUDES
 * =====================================================
 */
#include <string>

/**
 * =====================================================
 * CLASS DEFINITIONS
 * =====================================================
 */
template <typename T>
class NODE_INTF {
protected:
    NODE_INTF() = default;

public:
    virtual ~NODE_INTF() = default;

    /**
     * @brief Get the value stored in the node.
     * @return value of node of type T
     */
    virtual T getValue(void) const = 0;

    /**
     * @brief Get the ID of the node.
     * @return a string represting the ID.
     */
    virtual std::string getID(void) const = 0;

    /**
     * @brief Return a string representation of object.
     */
    virtual std::string toString(void) const = 0;
};

#endif /* _NODE_INTF_H_ */
