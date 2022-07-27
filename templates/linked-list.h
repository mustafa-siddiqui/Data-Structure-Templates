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
#include "logging/logging.h"
#include "templates/node.h"

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
    int size;

    // set id of specified node
    // ideally for unique allotment of ids, a hashmap
    // should be used
    void setNodeID(std::shared_ptr<NODE_INTF<T>> nodePtr) override {
        if (this->tailPtr) {
            nodePtr->setID(this->tailPtr->getID() + 1);
        }
    }

public:
    // delete default constructor
    LINKED_LIST() = delete;

    // constructor
    LINKED_LIST(std::shared_ptr<NODE_INTF<T>> head,
                std::shared_ptr<NODE_INTF<T>> tail = nullptr)
        : LINKED_LIST_INTF<T>(), headPtr(head), tailPtr(tail) {
        assert(this->headPtr != nullptr);

        // set size and id
        // we know that headPtr cannot be null
        this->headPtr->setID(0);
        if (this->tailPtr) {
            size = 2;
            this->tailPtr->setID(1);
        } else {
            size = 1;
        }

        // if tail node not given, set head as tail
        if (!tailPtr) {
            this->tailPtr = this->headPtr;
        }

        this->headPtr->setNextNodePtr(this->tailPtr);
        this->tailPtr->setPrevNodePtr(this->headPtr);

        LOGGING::logMessage("List with " + headPtr->toString() +
                            " at head created");
    }

    /**
     * =====================================================`
     * INTERFACE METHODS DEFINITIONS
     * =====================================================
     */

    // destructor
    ~LINKED_LIST() override {
        LOGGING::logMessage("List with " + headPtr->toString() +
                            " at head destroyed");
    }

    std::shared_ptr<NODE_INTF<T>> getHead() { return this->headPtr; }

    // append to end of list
    void appendLast(std::shared_ptr<NODE_INTF<T>> nodePtr) override {
        if (!nodePtr) {
            LOGGING::logMessage("Cannot append a null node!");
            return;
        }

        this->setNodeID(nodePtr);
        ++this->size;

        nodePtr->setPrevNodePtr(this->tailPtr);
        this->tailPtr->setNextNodePtr(nodePtr);
        this->tailPtr = nodePtr;
    }

    // insert at start of list
    void insertFirst(std::shared_ptr<NODE_INTF<T>> nodePtr) override {
        if (!nodePtr) {
            LOGGING::logMessage("Cannot insert a null node!");
            return;
        }

        this->setNodeID(nodePtr);
        ++this->size;

        nodePtr->setNextNodePtr(this->headPtr);
        this->headPtr->setPrevNodePtr(nodePtr);
        this->headPtr = nodePtr;
    }

    // insert before a node
    nonstd::expected<void, ERROR_CODES> insertBefore(
        std::shared_ptr<NODE_INTF<T>> nodePresentPtr,
        std::shared_ptr<NODE_INTF<T>> nodeToBeInsertedPtr) override {}

    // insert after a node
    nonstd::expected<void, ERROR_CODES> insertAfter(
        std::shared_ptr<NODE_INTF<T>> nodePresentPtr,
        std::shared_ptr<NODE_INTF<T>> nodeToBeInsertedPtr) override {}

    // delete a node
    nonstd::expected<bool, ERROR_CODES> deleteNode(
        std::shared_ptr<NODE_INTF<T>> nodeToBeDeletedPtr) override {
        bool deleted = false;

        // check boundary cases for faster execution
        if (nodeToBeDeletedPtr == this->headPtr) {
            this->headPtr->getNextNodePtr()->getPrevNodePtr().reset();
            this->headPtr = this->headPtr->getNextNodePtr();

            deleted = true;
            LOGGING::logMessage("Head node " + nodeToBeDeletedPtr->toString() +
                                " deleted");
        } else if (nodeToBeDeletedPtr == this->tailPtr) {
            this->tailPtr->getPrevNodePtr()->getNextNodePtr().reset();
            this->tailPtr = this->tailPtr->getPrevNodePtr();

            deleted = true;
            LOGGING::logMessage("Tail node " + nodeToBeDeletedPtr->toString() +
                                " deleted");
        } else {
            // iterate over list until we reach the node
            std::shared_ptr<NODE_INTF<T>> currPtr;
            for (currPtr = this->headPtr; currPtr != nullptr;
                 currPtr = currPtr->getNextNodePtr()) {
                if (currPtr == nodeToBeDeletedPtr) {
                    std::shared_ptr<NODE_INTF<T>> temp =
                        currPtr->getPrevNodePtr();
                    currPtr->getNextNodePtr()->setPrevNodePtr(temp);

                    temp = currPtr->getNextNodePtr();
                    currPtr->getPrevNodePtr()->setNextNodePtr(temp);
                    currPtr.reset();

                    deleted = true;
                    LOGGING::logMessage("Middle node " +
                                        nodeToBeDeletedPtr->toString() +
                                        " deleted");
                }
            }
        }

        if (!deleted) {
            LOGGING::logMessage(nodeToBeDeletedPtr->toString() +
                                " not found in list");
            return nonstd::make_unexpected<ERROR_CODES>(
                ERROR_CODES::NODE_NOT_FOUND);
        }

        --this->size;
        return true;
    }

    // find a node
    nonstd::expected<std::string, ERROR_CODES> find(
        std::shared_ptr<NODE_INTF<T>> nodePtr) const override {}

    // size of list
    int getSize() const override { return this->size; }

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

    // print list to console
    void print() const override {
        std::cout << this->toString() << std::endl;
    }

    // '<<' operator overload
    friend std::ostream& operator<<(
        std::ostream& os, const LINKED_LIST<T>& linkedListObj) {
        os << linkedListObj.toString();
        return os;
    }
};

#endif /* _LINKED_LIST_H_ */
