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

#include "expected-lite/include/nonstd/expected.hpp"
#include "interfaces/node-intf.h"
#include <string>

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

public:
    virtual ~LINKED_LIST_INTF() = default;

    /**
     * @brief Append a node to the end of the list.
     * @param node A node object
     */
    virtual void appendLast(NODE_INTF<T> node) = 0;

    /**
     * @brief Create a node given its id and value and
     * append to the end of the list.
     * @param id ID of node to be inserted
     * @param value Value stored in node to be inserted
     */
    virtual void appendLast(std::string const id, T value) = 0;

    /**
     * @brief Insert a node to the head of the list. Will
     * replace the head node of the list and will point to it.
     * @param node A node object
     */
    virtual void insertFirst(NODE_INTF<T> node) = 0;

    /**
     * @brief Create a node given its id and value and insert
     * to the head of the list.
     * @param id ID of node to be inserted
     * @param value Value stored in node to be inserted
     */
    virtual void insertFirst(std::string const id, T value) = 0;

    /**
     * @brief Insert a node after a specified node in the list
     * (if it exists in the list). If specified does not exist,
     * do nothing.
     * @param nodePresent Specified node in the list.
     * @param nodeToBeInserted Node object to be inserted in the list.
     */
    virtual nonstd::expected<void, ERROR_CODES> insertBefore(NODE_INTF<T>& nodePresent, NODE_INTF<T> nodeToBeInserted) = 0;

    /**
     * @brief Create a node given its id and value and insert
     * before the node in the list which has its id equal to
     * presentNodeId.
     * @param presentNodeId ID of node in the list
     * @param id ID of node to be inserted
     * @param value Value stored in node to be inserted
     * @return nothing if successful, error code otherwise
     */
    virtual nonstd::expected<void, ERROR_CODES> insertBefore(std::string const presentNodeId, std::string const id, T value) = 0;

    /**
     * @brief Insert a node before a specified node in the list (if
     * it exists in the list). If specified node does not exist,
     * do nothing.
     * @param nodePresent Specified node in the list.
     * @param nodeToBeInserted Node object to be inserted in the list.
     * @return nothing if successful, error code otherwise
     */
    virtual nonstd::expected<void, ERROR_CODES> insertAfter(NODE_INTF<T>& nodePresent, NODE_INTF<T> nodeToBeInserted) = 0;

    /**
     * @brief Create a node given its id and value and insert
     * after the node in the list which has its id equal to
     * presentNodeId.
     * @param presentNodeId ID of node in the list
     * @param id ID of node to be inserted
     * @param value Value stored in node to be inserted
     * @return nothing if successful, error code otherwise
     */
    virtual nonstd::expected<void, ERROR_CODES> insertAfter(std::string const presentNodeId, std::string const id, T value) = 0;

    /**
     * @brief Delete given node from the list. Do nothing if node
     * not present in the list.
     * @param nodeToBeDeleted Node to delete from list
     * @return nothing if successful, error code otherwise
     */
    virtual nonstd::expected<void, ERROR_CODES> deleteNode(NODE_INTF<T> nodeToBeDeleted) = 0;

    /**
     * @brief Delete a given node from the list either from its id
     * or value. If multiple nodes with the same value exist, delete
     * all of them.
     * @param id ID of node to delete
     * @param value Value of node(s) to delete
     * @return nothing if successful, error code otherwise
     */
    virtual nonstd::expected<void, ERROR_CODES> deleteNode(std::string const id, T value = static_cast<T>(0)) = 0;

    /**
     * @brief Search for a node in the list.
     * @param node Node to search for in the list
     * @return ID of string if present, error otherwise
     */
    virtual nonstd::expected<std::string, ERROR_CODES> find(NODE_INTF<T> node) const = 0;

    /**
     * @brief Search for a node with its id in the list.
     * @param id ID of node to search
     * @return Index of node, error otherwise
     */
    virtual nonstd::expected<int, ERROR_CODES> find(std::string const id) const = 0;

    /**
     * @brief Convert linked list into a string representation.
     */
    virtual std::string toString() const = 0;
};

#endif /* LINKED_LIST_INTF_H_ */
