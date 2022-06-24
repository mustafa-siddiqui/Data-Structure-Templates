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

enum class ERROR_CODES {
    // value of object not found in some sort of collection of objects
    VALUE_NOT_FOUND,

    // node to be searched does not exist
    NODE_NOT_FOUND,

    // data structure referenced is empty
    STRUCTURE_IS_EMPTY
};

#endif
