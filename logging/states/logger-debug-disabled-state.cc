/**
 * @file    logger-debug-disabled-state.cc
 * @author  Mustafa Siddiqui
 * @brief   Implementation of the logger debug disabled state class.
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
 * =====================================================
 * INCLUDES
 * =====================================================
 */
#include "logger-debug-disabled-state.h"

#include <iostream>

/**
 * =====================================================
 * IMPLEMENTATION
 * =====================================================
 */

// default ctor
LOGGER_DEBUG_DISABLED_STATE::LOGGER_DEBUG_DISABLED_STATE() {}

// dtor
LOGGER_DEBUG_DISABLED_STATE::~LOGGER_DEBUG_DISABLED_STATE() {}

// log fn in debug disabled state = do nothing
void LOGGER_DEBUG_DISABLED_STATE::log(std::string /*message*/) {
    return;
}
