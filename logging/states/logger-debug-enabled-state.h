/**
 * @file    logger-debug-enabled-state.h
 * @author  Mustafa Siddiqui
 * @brief   Class definition for logger debug enabled state.
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _LOGGER_DEBUG_ENABLED_STATE_
#define _LOGGER_DEBUG_ENABLED_STATE_

/**
 * =====================================================
 * INCLUDES
 * =====================================================
 */
#include "logger-state-intf.h"

/**
 * =====================================================
 * CLASS DEFINITIONS
 * =====================================================
 */

/**
 * @brief Logger state when debugging functionality is enabled.
 */
class LOGGER_DEBUG_ENABLED_STATE : public LOGGER_STATE_INTF {
public:
    LOGGER_DEBUG_ENABLED_STATE();
    ~LOGGER_DEBUG_ENABLED_STATE();

    /**
     * @brief Log error/debug message to error stream (std::cerr).
     * @param message Error/debug message
     */
    void log(std::string message) override;
};

#endif /* _LOGGER_DEBUG_ENABLED_STATE_ */
