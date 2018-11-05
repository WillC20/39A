#include "main.h"
#include "motorFunctions.hpp"
////make sure that the above file is a .hpp file, not an .h file otherwise it will not work

//This means that you dont need to put the pros:: before stuff
//using namespace pros;
//I added the above line after I wrote everything else
//Feel free not to be stupid like me though
//rename the motors for your own needs
//the number is the port that the motor is in
//adding a true/false will reverse the motor direction



void opcontrol() {

	//is the base locked? at what position
	bool isLocked = false;
	int position = 0;

	//This while loop is VERY important. If your program will not run, check to make sure that the while loop is here



	while (true) {

		//Note to self: try to keep all my motor functions here. Use functions for other stuff. That way there are minimal conflicts of schedualling


		/*isLocked = master.get_digital_new_press(DIGITAL_A) ? !isLocked : isLocked;
		if (!isLocked) {
			//This is the main drive. Im 90% sure that the Y axis is correct
			setDrive(joyDeadZone(master, ANALOG_LEFT_Y),
				joyDeadZone(master, ANALOG_RIGHT_Y));

			//this should get the last position the motors are at
			position = pDriveLF.get_position();
		} else {
			//lock the base (say we are on the platform)
			lockBase(position);
		}*/

		setDrive(joyDeadZone(ANALOG_LEFT_Y), joyDeadZone(ANALOG_RIGHT_Y));

		//I need to set the buttons. These are all temporary

		//I want to change this so that the motor only moves however much it needs to
		setCatapult(buttonToPower(DIGITAL_R1, 127));

		setIntake(buttonToPower(DIGITAL_L1, DIGITAL_L2, 127));

		//master.print(1, 1, "Potentiometer is %s", pot.get_value());

		//motors and joystick run on a 20ms delay

		pros::delay(20);

	}
}
