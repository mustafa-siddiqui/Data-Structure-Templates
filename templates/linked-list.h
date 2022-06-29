/**
 * @file linked-list.h
 * @author Mustafa Siddiqui
 * @brief Implementation of the linked list class template.
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

/**
 * =====================================================
 * INCLUDES
 * =====================================================
 */

#include "error/error-codes.h"
#include "interfaces/linked-list-intf.h"
#include "interfaces/node-intf.h"

/**
 * =====================================================
 * CLASS DEFINITIONS
 * =====================================================
 */

/**
 * @brief Implementation of the linked list template class.
 */
template <typename T>
class LINKED_LIST : public LINKED_LIST_INTF<T> {
private:
    std::shared_ptr<NODE_INTF<T>> headPtr;
    std::shared_ptr<NODE_INTF<T>> tailPtr;

public:
    // delete default constructor
    LINKED_LIST() = delete;

    // constructor
    LINKED_LIST(std::shared_ptr<NODE_INTF<T>> head,
                std::shared_ptr<NODE_INTF<T>> tail = nullptr)
        : LINKED_LIST_INTF<T>(), headPtr(head), tailPtr(tail) {
        this->headPtr->setNextNodePtr(this->tailPtr);
        this->tailPtr->setPrevNodePtr(this->headPtr);
        assert(this->headPtr != nullptr);
    }

    /**
     * =====================================================`
     * INTERFACE METHODS DEFINITIONS
     * =====================================================
     */

    // destructor
    ~LINKED_LIST() override {}

    // append to end of list
    void appendLast(NODE_INTF<T> node) override {}

    // append to end of list [overload]
    void appendLast(std::string const id, T value) override {}

    // insert at start of list
    void insertFirst(NODE_INTF<T> node) override {}

    // insert at start of list [overload]
    void insertFirst(std::string const id, T value) override {}

    // insert before a node
    nonstd::expected<void, ERROR_CODES> insertBefore(
        NODE_INTF<T>& nodePresent,
        NODE_INTF<T> nodeToBeInserted) override {}

    // insert before a node [overload]
    nonstd::expected<void, ERROR_CODES> insertBefore(
        std::string const presentNodeId, std::string const id,
        T value) override {}

    // insert after a node
    nonstd::expected<void, ERROR_CODES> insertAfter(
        NODE_INTF<T>& nodePresent,
        NODE_INTF<T> nodeToBeInserted) override {}

    // insert after a node [overload]
    nonstd::expected<void, ERROR_CODES> insertAfter(
        std::string const presentNodeId, std::string const id,
        T value) override {}

    // delete a node
    nonstd::expected<void, ERROR_CODES> deleteNode(
        NODE_INTF<T> nodeToBeDeleted) override {}

    // delete node(s) [overload]
    nonstd::expected<void, ERROR_CODES> deleteNode(
        std::string const id, T value = static_cast<T>(0)) override {}

    // find a node
    nonstd::expected<std::string, ERROR_CODES> find(
        NODE_INTF<T> node) const override {}

    // find a node [overload]
    nonstd::expected<int, ERROR_CODES> find(
        std::string const id) const override {}

    // convert to string
    // can get slow for very large lists
    std::string toString() const override {
        std::string strRepr("{");
        std::shared_ptr<NODE_INTF<T>> currPtr;
        for (currPtr = this->headPtr; currPtr != nullptr;
             currPtr = currPtr->getNextNodePtr()) {
            strRepr += currPtr->toString();

            // append comma except after last node
            if (currPtr != this->tailPtr) {
                strRepr += ", ";
            }
        }

        return strRepr += "}";
    }

    // '<<' operator overload
    friend std::ostream& operator<<(
        std::ostream& os, const LINKED_LIST<T>& linkedListObj) {
        os << linkedListObj.toString();
        return os;
    }
};

#endif /* _LINKED_LIST_H_ */
