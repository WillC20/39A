#include "main.h"
#include "../include/okapi/api.hpp"
#include <iostream>
#include "config.hpp"
#include "motorFunctions.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {

	std::string autoSelect;

	while (true) {
		if (leftAuto.get_value()) {
			autoSelect = "Front Left Auto";
		} else if (rightAuto.get_value()) {
			autoSelect = "Front Right Auto";
		} else if (backLeftAuto.get_value()) {
			autoSelect = "Back Left Auto";
		} else if (backRightAuto.get_value()) {
			autoSelect = "Back Right Auto";
		} else if (skillsAuto.get_value()) {
			autoSelect = "Skills Auto";
		} else {
			autoSelect = "None Selected";
		}

		pros::lcd::print(1, "Autonomous Selection: %s", autoSelect);
	}
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
