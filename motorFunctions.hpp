#ifndef _MOTORFUNCTIONS_HPP_
#define _MOTORFUNCTIONS_HPP_

#include "main.h"
#include "config.hpp"

void setBrakeMode(pros::motor_brake_mode_e mode);
void setDrive(int left, int right);
void setDrive(int speed);
//void setDrive(int left, int right, int ticks);
void setDrive(int left, int right, int time);
void setDrive();
void setCatapult(int speed);
void setCatapult(int speed, int time);
void setCatapult();
bool lowerCat(int level);
bool pLowerCat(int position);
void fire();
void setIntake(int speed);
void setIntake(int speed, int time);
void setIntake();
int buttonToPower(pros::Controller control, pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int upPower, int downPower, int offPower);
int buttonToPower(pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int upPower, int downPower, int offPower);
int buttonToPower(pros::Controller control, pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int upPower, int downPower);
int buttonToPower(pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int upPower, int downPower);
int buttonToPower(pros::Controller control, pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int power);
int buttonToPower(pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int power);
int buttonToPower(pros::Controller control, pros::controller_digital_e_t button, int power);
int buttonToPower(pros::controller_digital_e_t button, int power);
int joyDeadZone(pros::Controller control, pros::controller_analog_e_t joystick, int bound);
int joyDeadZone(pros::controller_analog_e_t joystick, int bound);
int joyDeadZone(pros::Controller control, pros::controller_analog_e_t joystick);
int joyDeadZone(pros::controller_analog_e_t joystick);
#endif //_MOTORFUNCTIONS_HPP_
