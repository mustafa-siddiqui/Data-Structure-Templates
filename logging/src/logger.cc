/**
 * @file    logger.cc
 * @author  Mustafa Siddiqui
 * @brief   Implementation of the logger class.
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
 * =====================================================
 * INCLUDES
 * =====================================================
 */

#include "logger.h"

#include "states/logger-debug-disabled-state.h"
#include "states/logger-debug-enabled-state.h"

/**
 * =====================================================
 * IMPLEMENTATION
 * =====================================================
 */

// ctor creates current state
LOGGER::LOGGER() {
#ifdef DEBUG
    this->currentState =
        std::make_unique<LOGGER_DEBUG_ENABLED_STATE>();
#else
    this->currentState =
        std::make_unique<LOGGER_DEBUG_DISABLED_STATE>();
#endif
}

// dtor
LOGGER::~LOGGER() {}

// log message to error stream
void LOGGER::log(std::string message) {
    this->currentState->log(message);
}
