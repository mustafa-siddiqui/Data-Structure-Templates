/**
 * @file linked-list-intf.h
 * @author Mustafa Siddiqui
 * @brief Interface for linked list class.
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _LINKED_LIST_INTF_H_
#define _LINKED_LIST_INTF_H_

/**
 * =====================================================
 * INCLUDES
 * =====================================================
 */

#include <memory>
#include <string>

#include "expected-lite/include/nonstd/expected.hpp"
#include "interfaces/node-intf.h"

/**
 * =====================================================
 * FORWARD DECLARATIONS
 * =====================================================
 */

enum class ERROR_CODES;

/**
 * =====================================================
 * CLASS DEFINITIONS
 * =====================================================
 */

/**
 * @brief Interface for linked list class.
 */
template <typename T>
class LINKED_LIST_INTF {
protected:
    LINKED_LIST_INTF() = default;

    /**
     * @brief Set ID of node.
     * @param nodePtr pointer to node
     */
    virtual void setNodeID(std::shared_ptr<NODE_INTF<T>> nodePtr) = 0;

public:
    virtual ~LINKED_LIST_INTF() = default;

    /**
     * @brief Append a node to the end of the list.
     * @param nodePtr A node object pointer
     */
    virtual void appendLast(std::shared_ptr<NODE_INTF<T>> nodePtr) = 0;

    /**
     * @brief Insert a node to the head of the list. Will
     * replace the head node of the list and will point to it.
     * @param nodePtr A node object pointer
     */
    virtual void insertFirst(std::shared_ptr<NODE_INTF<T>> nodePtr) = 0;

    /**
     * @brief Insert a node after a specified node in the list
     * (if it exists in the list). If specified does not exist,
     * do nothing.
     * @param nodePresentPtr Specified node pointer in the list.
     * @param nodeToBeInsertedPtr Node object pointer to be inserted
     * in the list.
     * @return true if successful, error code otherwise
     */
    virtual nonstd::expected<bool, ERROR_CODES> insertBefore(
        std::shared_ptr<NODE_INTF<T>> nodePresentPtr,
        std::shared_ptr<NODE_INTF<T>> nodeToBeInsertedPtr) = 0;

    /**
     * @brief Insert a node before a specified node in the list (if
     * it exists in the list). If specified node does not exist,
     * do nothing.
     * @param nodePresentPtr Specified node pointer in the list.
     * @param nodeToBeInsertedPtr Node object pointer to be inserted
     * in the list.
     * @return true if successful, error code otherwise
     */
    virtual nonstd::expected<bool, ERROR_CODES> insertAfter(
        std::shared_ptr<NODE_INTF<T>> nodePresentPtr,
        std::shared_ptr<NODE_INTF<T>> nodeToBeInsertedPtr) = 0;

    /**
     * @brief Delete given node from the list. Do nothing if node
     * not present in the list.
     * @param nodeToBeDeletedPtr Pointer of node to delete from list
     * @return true if successful, error code otherwise
     */
    virtual nonstd::expected<bool, ERROR_CODES> deleteNode(
        std::shared_ptr<NODE_INTF<T>> nodeToBeDeletedPtr) = 0;

    /**
     * @brief Search for a node in the list.
     * @param nodePtr Pointer node to search for in the list
     * @return ID of node if present, error otherwise
     */
    virtual nonstd::expected<uint32_t, ERROR_CODES> find(
        std::shared_ptr<NODE_INTF<T>> nodePtr) const = 0;

    /**
     * @brief Get the size of the linked list.
     * @return # of nodes in the list
     */
    virtual int getSize() const = 0;

    /**
     * @brief Convert linked list into a string representation.
     */
    virtual std::string toString() const = 0;

    /**
     * @brief Print list to console.
     */
    virtual void print() const = 0;
};

#endif /* LINKED_LIST_INTF_H_ */
