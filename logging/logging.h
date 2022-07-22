/**
 * @file    logging.h
 * @author  Mustafa Siddiqui
 * @brief   Main include file for using the logging functionality.
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _LOGGING_H_
#define _LOGGING_H_

/**
 * =====================================================
 * INCLUDES
 * =====================================================
 */

#include <memory>
#include <string>

#include "src/logger.h"

/**
 * =====================================================
 * NAMESPACE FUNCTIONS
 * =====================================================
 */

namespace LOGGING {
void logMessage(std::string message) {
    std::unique_ptr<LOGGER> loggerObjPtr = std::make_unique<LOGGER>();
    loggerObjPtr->log(message);
}
}  // namespace LOGGING

#endif /* _LOGGING_H_ */
