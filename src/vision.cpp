//
// Created by Lucas on 2020-06-11.
//

#include "shared_robot_api.hpp"
#include "main.h"

namespace shared_api
{
    Vision::Vision(int _port) : port(_port)
    {

    }

    int32_t Vision::set_led(const int32_t rgb)
    {
        return pros::c::vision_set_led(port, rgb);
    }
}
