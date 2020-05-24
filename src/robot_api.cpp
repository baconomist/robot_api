//
// Created by Lucas on 2020-05-22.
//

#include "entry.h"
#include "shared_robot_api.hpp"
#include "robot_api.h"

namespace shared_api
{
    void Motor::move_voltage(int _voltage)
    {
        pros::c::motor_move_voltage(port, _voltage);
    }

    Motor::Motor(int _port) : port(_port)
    {

    }

    Motor::~Motor()
    {

    }
}