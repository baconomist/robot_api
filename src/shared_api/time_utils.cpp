//
// Created by Lucas on 2020-06-11.
//

#include "shared_robot_api.h"
#include "main.h"

namespace shared_api::time_utils
{
    void delay(const unsigned int millis)
    {
        pros::delay(millis);
    }
}
