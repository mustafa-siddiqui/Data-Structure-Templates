/**
 * @file    logger.h
 * @author  Mustafa Siddiqui
 * @brief   Class definition for logger class handling the
 *          error logging mechanism.
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _LOGGER_H_
#define _LOGGER_H_

/**
 * =====================================================
 * INCLUDES
 * =====================================================
 */
#include <memory>

#include "states/logger-state-intf.h"

/**
 * =====================================================
 * CLASS DEFINITIONS
 * =====================================================
 */

/**
 * @brief Logger class that takes care of error/debug
 * message handling.
 */
class LOGGER {
private:
    std::unique_ptr<LOGGER_STATE_INTF> currentState;

public:
    LOGGER();

    // delete copy ctor and assignment operator
    LOGGER(const LOGGER&) = delete;
    LOGGER& operator=(const LOGGER&) = delete;

    ~LOGGER();

    /**
     * @brief Log a debug/error message to std::cerr depending
     * on the current state. If debug state enabled, only then
     * will the message be logged.
     * @param message
     */
    void log(std::string message);
};

#endif /* _LOGGER_H_ */
