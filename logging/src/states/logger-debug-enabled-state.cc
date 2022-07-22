/**
 * @file    logger-debug-enabled-state.cc
 * @author  Mustafa Siddiqui
 * @brief   Implementation of the logger debug enabled state class.
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
 * =====================================================
 * INCLUDES
 * =====================================================
 */
#include "logger-debug-enabled-state.h"

#include <iostream>

/**
 * =====================================================
 * IMPLEMENTATION
 * =====================================================
 */

// default ctor
LOGGER_DEBUG_ENABLED_STATE::LOGGER_DEBUG_ENABLED_STATE() {
    // this->log("Logger Instantiated...");
}

// dtor
LOGGER_DEBUG_ENABLED_STATE::~LOGGER_DEBUG_ENABLED_STATE() {
    // this->log("Logger Destructed...");
}

// log fn in debug enabled state = log msg to std::cerr
void LOGGER_DEBUG_ENABLED_STATE::log(std::string message) {
    std::cerr << "[ DEBUG ] : " << message << std::endl;
}
