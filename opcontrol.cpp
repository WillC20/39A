#include "main.h"
#include "motorFunctions.hpp"
//make sure that the above file is a .hpp file, not an .h file otherwise it will not work

//This means that you dont need to put the pros:: before stuff
using namespace pros;
//I added the above line after I wrote everything else
//Feel free not to be stupid like me though

void opcontrol() {

	//The direction that the arm is going to move in
	int dir = 1;
	//is the base locked? at what position
	bool isLocked = false;
	int position = 0;

	//This while loop is VERY important. If your program will not run, check to make sure that the while loop is here

	//Note to self: try to keep all my motor functions here. Use functions for other stuff. That way there are minimal conflicts of schedualling
	while (true) {

		isLocked = master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A) ? !isLocked : isLocked;
		if (!isLocked) {
			//This is the main drive. Im 90% sure that the Y axis is correct
			setDrive(joyDeadZone(pros::E_CONTROLLER_ANALOG_LEFT_Y),
				joyDeadZone(pros::E_CONTROLLER_ANALOG_RIGHT_Y));

			//this should get the last position the motors are at
			position = pDriveLF.get_position();
		} else {
			//lock the base (say we are on the platform)
			lockBase(position);
		}

		//I need to set the buttons. These are all temporary

		//I want to change this so that the motor only moves however much it needs to
		setCatapult(buttonToPower(pros::E_CONTROLLER_DIGITAL_R1, pros::E_CONTROLLER_DIGITAL_A, 127));

		setIntake(buttonToPower(pros::E_CONTROLLER_DIGITAL_L1, pros::E_CONTROLLER_DIGITAL_L2, 127));

		//The direction flips when button is pressed. New press only
		dir *= master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y) ? -1 : 1;
		setArm(buttonToPower(pros::E_CONTROLLER_DIGITAL_R2, pros::E_CONTROLLER_DIGITAL_B, 127*dir));

		//motors and joystick run on a 20ms delay
		delay(20);
	}
}
