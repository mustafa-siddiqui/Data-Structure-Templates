#include <memory>

#include "logger.h"

int main(void) {
    std::unique_ptr<LOGGER> logging = std::make_unique<LOGGER>();

    logging->log("Testing logger");

    return 0;
}