/**
 * @file    logger-debug-disabled-state.h
 * @author  Mustafa Siddiqui
 * @brief   Class definition for logger debug disabled state.
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _LOGGER_DEBUG_DISABLED_STATE_
#define _LOGGER_DEBUG_DISABLED_STATE_

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
 * @brief Logger state when debugging functionality is
 * disabled.
 */
class LOGGER_DEBUG_DISABLED_STATE : public LOGGER_STATE_INTF {
public:
    LOGGER_DEBUG_DISABLED_STATE();
    ~LOGGER_DEBUG_DISABLED_STATE();

    /**
     * @brief Logging functionality in this state is disabled,
     * so nothing happens.
     * @param message => Not used
     */
    void log(std::string /*message*/) override;
};

#endif /* _LOGGER_DEBUG_DISABLED_STATE_ */
