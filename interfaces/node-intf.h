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

#include <memory>
#include <string>

/**
 * =====================================================
 * FORWARD DECLARATIONS
 * =====================================================
 */

template <typename T>
class NODE;

/**
 * =====================================================
 * CLASS DEFINITIONS
 * =====================================================
 */

/**
 * @brief Interface for a node class.
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
    virtual T getValue() const = 0;

    /**
     * @brief Get the ID of the node.
     * @return a string represting the ID.
     */
    virtual std::string getID() const = 0;

    /**
     * @brief Set the next node of this node to the
     * given node.
     * @param nodePtr Pointer to node to be set as next.
     */
    virtual void setNextNodePtr(std::shared_ptr<NODE_INTF<T>>& nodePtr) = 0;

    /**
     * @brief Get a shared pointer to the next node.
     */
    virtual std::shared_ptr<NODE_INTF<T>> getNextNodePtr() const = 0;

    /**
     * @brief Set the node previous of this node to
     * the given node.
     * @param nodePtr Pointer to node to be set as previous
     */
    virtual void setPrevNodePtr(std::shared_ptr<NODE_INTF<T>>& nodePtr) = 0;

    /**
     * @brief Get a shared pointer to the previous node.
     */
    virtual std::shared_ptr<NODE_INTF<T>> getPrevNodePtr() const = 0;

    /**
     * @brief Return a string representation of object.
     */
    virtual std::string toString() const = 0;
};

#endif /* _NODE_INTF_H_ */
