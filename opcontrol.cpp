
#include "main.h"
//#include "okapi/api.hpp"
#include "headers/motorFunctions.hpp"
#include <iostream>

//auto catPID = okapi::AsyncControllerFactory::posPID(1, 1, 1, 1);

void lockMotor(pros::Motor motor, int current, int target) { // only a P lock
	motor = current - target;
}

void lockBase(int position) {
	int current = pDriveLF.get_position();
	lockMotor(pDriveLF, current, position);
	lockMotor(pDriveLM, current, position);
	lockMotor(pDriveLB, current, position);
	lockMotor(pDriveRF, current, position);
	lockMotor(pDriveRM, current, position);
	lockMotor(pDriveRB, current, position);
	pros::lcd::print(4, "Base Difference: %d\n", current - position);
}

int distance(int x, int y) {
	return (int) (y == 0 ? x : (y/abs(y)) * sqrt(pow(x, 2.0) + pow(y, 2.0)));
}

int distance(pros::Controller controller, pros::controller_analog_e_t x, pros::controller_analog_e_t y) {
	return distance(controller.get_analog(x), controller.get_analog(y));
}

int distance(pros::controller_analog_e_t x, pros::controller_analog_e_t y) {
	return distance(master, x, y);
}

void opcontrol() {

	setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
	catapult.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

	//is the base locked? at what position
	bool isLocked = false;
	int position = 0;

	bool catDown = false;

	bool baseFlip = false;

	std::string autoType;

	int right;
	int left;

	#define JOYDEAD 10
	#define VOLTDEAD 5
	#define NPOWER 2.5
	//#define DRIVECONSTANT (pow(127-JOYDEAD, NPOWER) / (127-VOLTDEAD))
	//#define POSPIECE(x) ((pow(x-JOYDEAD, NPOWER) / DRIVECONSTANT) + VOLTDEAD)
	//#define NEGPIECE(x) ((-pow(-x-JOYDEAD, NPOWER) / DRIVECONSTANT) - VOLTDEAD)

	#define DRIVECONSTANT (log(118) / 117)
	#define POSPIECE(x) (exp(DRIVECONSTANT*(x-JOYDEAD))+VOLTDEAD-1)
	#define NEGPIECE(x) (-exp(-DRIVECONSTANT*(x+JOYDEAD))-VOLTDEAD+1)

	while (true) {

		baseFlip = master.get_digital_new_press(DIGITAL_R2) ? !baseFlip : baseFlip;

		isLocked = master.get_digital_new_press(DIGITAL_Y) ? !isLocked : isLocked;

		/*if (!isLocked) {
			if (baseFlip) {
				left = joyDeadZone(ANALOG_LEFT_Y, JOYDEAD);
				right = joyDeadZone(ANALOG_RIGHT_Y, JOYDEAD);
				setDrive(left >= JOYDEAD ? POSPIECE(left) : left <= -JOYDEAD ? NEGPIECE(left) : 0,
					right >= JOYDEAD ? POSPIECE(right) : right < -JOYDEAD ? NEGPIECE(right) : 0);
			} else {
				left = -joyDeadZone(ANALOG_RIGHT_Y, JOYDEAD);
				right = -joyDeadZone(ANALOG_LEFT_Y, JOYDEAD);
				setDrive(left >= JOYDEAD ? POSPIECE(left) : left <= -JOYDEAD ? NEGPIECE(left) : 0,
					right >= JOYDEAD ? POSPIECE(right) : right < -JOYDEAD ? NEGPIECE(right) : 0);
			}
			position = pDriveLF.get_position();
		} else {
			lockBase(position);
		*/

		if (baseFlip) {
			left = distance(ANALOG_LEFT_X, ANALOG_LEFT_Y);
			right = distance(ANALOG_RIGHT_X, ANALOG_RIGHT_Y);
			pros::lcd::print(5, "LEFT JOYSTICK: %i", left);
			pros::lcd::print(6, "X: %i", master.get_analog(ANALOG_RIGHT_X));
			pros::lcd::print(7, "Y: %i", master.get_analog(ANALOG_RIGHT_Y));
			setDrive(left >= JOYDEAD ? POSPIECE(left) : left <= -JOYDEAD ? NEGPIECE(left) : 0,
				right >= JOYDEAD ? POSPIECE(right) : right < -JOYDEAD ? NEGPIECE(right) : 0);
			//master.rumble("--------");
		} else {
			left = -distance(ANALOG_RIGHT_X, ANALOG_RIGHT_Y);
			right = -distance(ANALOG_LEFT_X, ANALOG_LEFT_Y);
			pros::lcd::print(5, "LEFT JOYSTICK: %i", left);
			pros::lcd::print(6, "X: %i", master.get_analog(ANALOG_RIGHT_X));
			pros::lcd::print(7, "Y: %i", master.get_analog(ANALOG_RIGHT_Y));
			setDrive(left >= JOYDEAD ? POSPIECE(left) : left <= -JOYDEAD ? NEGPIECE(left) : 0,
				right >= JOYDEAD ? POSPIECE(right) : right < -JOYDEAD ? NEGPIECE(right) : 0);
			//master.rumble("- * - *");
		}


		if (!catDown) {
			setCatapult(buttonToPower(DIGITAL_R1, 127));
			catDown = master.get_digital(DIGITAL_RIGHT);
		} else {
			catDown = master.get_digital(DIGITAL_R1) ? false : pLowerCat(3650);
			//master.rumble("--");
		}

		pros::lcd::print(1, "Pot Value: %d\n", pot.get_value());

		setIntake(buttonToPower(DIGITAL_L1, DIGITAL_L2, 127));

		if (leftAuto.get_value()) {
			autoType = "Left Auto";
		} else if (rightAuto.get_value()) {
			autoType = "Right Auto";
		} else if (backAuto.get_value()) {
			autoType = "Back Auto";
		} else if (skillsAuto.get_value()) {
			autoType = "Skills Auto";
		} else {
			autoType = "Left Auto";
		}

		pros::lcd::print(3, "Jumper: %s\n", autoType);

		pros::lcd::print(2, "Battery Value: %d\n", pros::battery::get_capacity());
		if (pros::battery::get_capacity() == .80) {
			master.rumble("----");
		}

		//motors and joystick run on a 20ms delay

		pros::delay(20);

	}
}
