//
// Created by Lucas on 2020-05-22.
//


#include "shared_robot_api.hpp"
#include "main.h"

namespace shared_api
{
    Motor::Motor(int _port) : port(_port)
    {
    }

    void Motor::move_voltage(int _voltage)
    {
        voltage = _voltage;
        pros::c::motor_move_voltage(port, _voltage);
    }

    Motor::~Motor() = default;
}
