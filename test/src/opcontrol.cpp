#include "main.h"
#include "../include/okapi/api.hpp"
#include <iostream>
#include "config.hpp"
#include "motorFunctions.hpp"

void opcontrol() {

	driveTrain.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
	catapult.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

	while (true) {
		try {
			distance("hi");
		} catch (const char* message) {
			std::cout << message << std::endl;
		}
	}
}
