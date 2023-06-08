/**
 * @file error-codes.h
 * @author Mustafa Siddiqui
 * @brief Error codes to return for data structure interactions.
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _ERROR_CODES_H_
#define _ERROR_CODES_H_

#include <string>

enum class ERROR_CODES {
    // value of object not found in some sort of collection of objects
    VALUE_NOT_FOUND,

    // node to be searched does not exist
    NODE_NOT_FOUND,

    // data structure referenced is empty
    STRUCTURE_IS_EMPTY
};

namespace ERROR_CODES_FUNC {
std::string toString(ERROR_CODES error) {
    switch (error) {
        case ERROR_CODES::VALUE_NOT_FOUND:
            return "Value not found";
        case ERROR_CODES::NODE_NOT_FOUND:
            return "Node not found";
        case ERROR_CODES::STRUCTURE_IS_EMPTY:
            return "Structure is empty";
        default:
            return "None";
    }
}
}  // namespace ERROR_CODES_FUNC

#endif
