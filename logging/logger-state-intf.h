/**
 * @file    logger-state-intf.h
 * @author  Mustafa Siddiqui
 * @brief   Interface for a logger state class.
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _LOGGER_STATE_INTF_
#define _LOGGER_STATE_INTF_

/**
 * =====================================================
 * INCLUDES
 * =====================================================
 */
#include <string>

/**
 * =====================================================
 * CLASS DEFINITIONS
 * =====================================================
 */

/**
 * @brief Interface for a logger state class.
 */
class LOGGER_STATE_INTF {
protected:
    LOGGER_STATE_INTF() = default;

public:
    virtual ~LOGGER_STATE_INTF() = default;

    /**
     * @brief Log a message to the std::cerr.
     * Will function differently according to current state.
     */
    virtual void log(std::string logMessage) = 0;
};

#endif /* _LOGGER_STATE_INTF_ */
