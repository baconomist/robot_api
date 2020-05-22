//
// Created by Lucas on 2020-05-22.
//

#include "main.h"
#include "robot_api.h"

namespace shared_api
{
    void Motor::move_voltage(int voltage)
    {
        pros::c::motor_move_voltage(port, voltage);
    }

    Motor::Motor(int _port) : port(_port)
    {

    }

    Motor::~Motor()
    {

    }
}