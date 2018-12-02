#ifndef _MOTORFUNCTIONS_HPP_
#define _MOTORFUNCTIONS_HPP_

#include "main.h"
#include "../include/okapi/api.hpp"
#include <iostream>
#include "config.hpp"

extern void setDrive(int left, int right);
extern void setDrive(int speed);
extern void setDrive(int speed = 127);
extern void setDrive(int left, int right, int time);

extern void setCatapult(int speed);
extern void setCatapult(int speed = 127);
extern void setCatapult(int speed, int time);

extern bool lowerCatapult(int position);
extern bool lowerCatapult(int position, int kp);

extern void setIntake(int speed);
extern void setIntake(int speed = 127);
extern void setIntake(int speed, int time);

extern int buttonToPower(pros::Controller controller, pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int upPower, int downPower, int offPower);
extern int buttonToPower(pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int upPower, int downPower, int offPower);

extern int buttonToPower(pros::Controller controller, pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int upPower, int downPower, int offPower = 0);
extern int buttonToPower(pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int upPower, int downPower, int offPower = 0);

extern int buttonToPower(pros::Controller controller, pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int power);
extern int buttonToPower(pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int power);

extern int buttonToPower(pros::Controller controller, pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int power = 127);
extern int buttonToPower(pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int power = 127);

extern int buttonToPower(pros::Controller controller, pros::controller_digital_e_t button, int power, int offPower);
extern int buttonToPower(pros::controller_digital_e_t button, int power, int offPower);

extern int buttonToPower(pros::Controller controller, pros::controller_digital_e_t button, int power, int offPower = 0);
extern int buttonToPower(pros::controller_digital_e_t button, int power, int offPower = 0);

extern int buttonToPower(pros::Controller controller, pros::controller_digital_e_t button, int power = 127);
extern int buttonToPower(pros::controller_digital_e_t, int power = 127);

extern int joyDeadZone(pros::Controller controller, pros::controller_analog_e_t joystick, int deadzone, int offPower);
extern int joyDeadZone(pros::controller_analog_e_t joystick, int deadzone, int offPower);

extern int joyDeadZone(pros::Controller controller, pros::controller_analog_e_t joystick, int deadzone, int offPower = 0);
extern int joyDeadZone(pros::controller_analog_e_t joystick, int deadzone, int offPower = 0);

extern int joyDeadZone(pros::Controller controller, pros::controller_analog_e_t joystick, int deadzone = 10);
extern int joyDeadZone(pros::controller_analog_e_t joystick, int deadzone = 10);

extern int exponentialDrive(pros::Controller controller, pros::controller_analog_e_t joystick);
extern int exponentialDrive(pros::controller_analog_e_t joystick);

extern int distance(int x, int y);
extern int distance(pros::Controller controller, std::string side);
extern int distance(std::string side);

#endif // _MOTORFUNCTIONS_HPP_
