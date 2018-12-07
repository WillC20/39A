#include "main.h"
#include "config.hpp"
#include "motorFunctions.hpp"

void setBrakeMode(pros::motor_brake_mode_e mode) {
  pDriveLF.set_brake_mode(mode);
  pDriveLM.set_brake_mode(mode);
  pDriveLB.set_brake_mode(mode);
  pDriveRF.set_brake_mode(mode);
  pDriveRM.set_brake_mode(mode);
  pDriveRB.set_brake_mode(mode);
}

//The right and left speed are set seperately
void setDrive(int left, int right) {
  pDriveLF = left;
  pDriveLM = left;
  pDriveLB = left;
  pDriveRF = right;
  pDriveRM = right;
  pDriveRB = right;
}

//the speeds are set together (useful for autonomous)
void setDrive(int speed) {
  setDrive(speed, speed);
}

/*void setDrive(int left, int right, int ticks) {
  int start = pDriveRM.get_position();
  while (ticks < abs((int) (start-pDriveRM.get_position()))) {
    setDrive(left, right);
  }
  setDrive(0);
}*/

void setDrive(int left, int right, int time) {
  setDrive(left, right);
  pros::delay(time);
  setDrive(0);
}

//for autonomous if you need to drive forward at full speed
void setDrive() {
  setDrive(127);
}

//I need to write something that winds this the right amount
//Calibrate the function when we get the motors
void setCatapult(int speed) {
  catapult = speed;
}

void setCatapult(int speed, int time) {
  setCatapult(speed);
  pros::delay(time);
  setCatapult(0);
}

//tbh you will mostly be using this
//The catapult only needs to go one direction anyway
void setCatapult() {
  setCatapult(127);
}

bool lowerCat(int level) {
	if (pot.get_value() < level) {
		setCatapult();
		return true;
	} else {
		return false;
	}
}

bool pLowerCat(int position) {
	if (position > pot.get_value()) {
		double kp = .8;
		setCatapult(kp * (position - pot.get_value()));
		return true;
	} else {
		setCatapult(0);
		return false;
	}
}

void fire() {
  setCatapult(127, 500);
}

//set it to a certain speed
void setIntake(int speed) {
  intake = speed;
}

void setIntake(int speed, int time) {
  setIntake(speed);
  pros::delay(time);
  setIntake(0);
}

//defaults to full speed
void setIntake() {
  setIntake(127);
}

//Here im going to put more logic based stuff

//this will turn a boolean button press into a power level
//useful for drivers control because the button presses have boolean outputs

//for times when you want the robot to move when not powered, and go up and down at different speeds
int buttonToPower(pros::Controller control, pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int upPower, int downPower, int offPower) {
  return control.get_digital(upButton) ? upPower : control.get_digital(downButton) ? downPower : offPower;
}

//defaults to master
int buttonToPower(pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int upPower, int downPower, int offPower) {
  return buttonToPower(master, upButton, downButton, upPower, downPower, offPower);
}

//offpower defaults at 0
int buttonToPower(pros::Controller control, pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int upPower, int downPower) {
  return buttonToPower(control, upButton, downButton, upPower, downPower, 0);
}

//defaults to master
int buttonToPower(pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int upPower, int downPower) {
  return buttonToPower(master, upButton, downButton, upPower, downPower);
}

//up and down speeds are the same
int buttonToPower(pros::Controller control, pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int power) {
  return buttonToPower(control, upButton, downButton, power, -power);
}

//default to master controller
int buttonToPower(pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int power) {
  return buttonToPower(master, upButton, downButton, power);
}

//for devices that move in a single direction (catapult)
int buttonToPower(pros::Controller control, pros::controller_digital_e_t button, int power) {
  return control.get_digital(button) ? power : 0;
}

//default to the master controller
int buttonToPower(pros::controller_digital_e_t button, int power) {
  return buttonToPower(master, button, power);
}

//joydeadzone definitions

//set the bound
int joyDeadZone(pros::Controller control, pros::controller_analog_e_t joystick, int bound) {
  return abs(control.get_analog(joystick)) > bound ? control.get_analog(joystick) : 0;
}

//default to master
int joyDeadZone(pros::controller_analog_e_t joystick, int bound) {
  return joyDeadZone(master, joystick, bound);
}

//This stops the drift that controllers have
//default at 10
int joyDeadZone(pros::Controller control, pros::controller_analog_e_t joystick) {
  return joyDeadZone(control, joystick, 10);
}

//default to master controller
int joyDeadZone(pros::controller_analog_e_t joystick) {
  return joyDeadZone(master, joystick);
}
