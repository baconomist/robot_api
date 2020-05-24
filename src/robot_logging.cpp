//
// Created by Lucas on 2020-05-23.
//

#include <iostream>
#include "logging.h"

namespace logging
{
    void info(const std::string &message)
    {
        std::cout << "[INFO]: " << message << "\n";
    }

    void debug(const std::string &message)
    {
        std::cout << "[DEBUG]: " << message << "\n";
    }

    void warn(const std::string &message)
    {
        std::cout << "[WARN]: " << message << "\n";
    }

    void error(const std::string &message)
    {
        std::cout << "[ERROR]: " << message << "\n";
    }
}
