#include "main.h"
#include "../include/okapi/api.hpp"
#include <iostream>
#include "config.hpp"
#include "motorFunctions.hpp"

void setDrive(int left, int right) {
  leftBase.moveVoltage(left);
  rightBase.moveVoltage(right);
}

void setDrive(int speed) {
  setDrive(speed, speed);
}

void setDrive(int left, int right, int time) {
  setDrive(left, right);
  pros::delay(time);
  setDrive(0);
}

void setCatapult(int speed) {
  catapult = speed;
}

void setCatapult(int speed, int time) {
  setCatapult(speed);
  pros::delay(time);
  setCatapult(0);
}

bool lowerCatapult(int position) {
  catapult = 127;
  return catPot.get_value() < position || master.get_digital(DIGITAL_R1);
}

bool lowerCatapult(int position, int kp) {
  catapult = kp*(position - catPot.get_value());
  return catPot.get_value() < position || master.get_digital(DIGITAL_R1);
}

void setIntake(int speed) {
  intake = speed;
}

void setIntake(int speed, int time) {
  setIntake(speed);
  pros::delay(time);
  setIntake(0);
}

int buttonToPower(pros::Controller controller, pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int upPower, int downPower, int offPower) {
  return controller.get_digital(upButton) && controller.get_digital(downButton) ? offPower : controller.get_digital(upButton) ? upPower : controller.get_digital(downButton) ? downPower : offPower;
}

int buttonToPower(pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int upPower, int downPower, int offPower) {
  return buttonToPower(master, upButton, downButton, upPower, downPower, offPower);
}

int buttonToPower(pros::Controller controller, pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int power) {
  return buttonToPower(controller, upButton, downButton, power, -power);
}

int buttonToPower(pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int power) {
  return buttonToPower(master, upButton, downButton, power);
}

int buttonToPower(pros::Controller controller, pros::controller_digital_e_t button, int power, int offPower) {
  return controller.get_digital(button) ? power : offPower;
}

int buttonToPower(pros::controller_digital_e_t button, int power, int offPower) {
  return buttonToPower(master, button, power, offPower);
}

int joyDeadZone(pros::Controller controller, pros::controller_analog_e_t joystick, int deadzone, int offPower) {
  return abs(controller.get_analog(joystick)) > deadzone ? controller.get_analog(joystick) : offPower;
}

int joyDeadZone(pros::controller_analog_e_t joystick, int deadzone, int offPower) {
  return joyDeadZone(master, joystick, deadzone, offPower);
}

int exponentialDrive(pros::Controller controller, pros::controller_analog_e_t joystick) {
  return 0;
}

int exponentialDrive(pros::controller_analog_e_t joystick) {
  return exponentialDrive(master, joystick);
}

int distance(int x, int y) {
  return (y/abs(y)) * pow(pow(x, 2) + pow(y, 2), 1/2);
}

int distance(pros::Controller controller, std::string side) {
  pros::controller_analog_e_t xjoy;
  pros::controller_analog_e_t yjoy;
  std::transform(side.begin(), side.end(), side.begin(), ::toupper);
  if (side == "left") {
    xjoy = ANALOG_LEFT_X;
    yjoy = ANALOG_LEFT_Y;
  } else if (side == "right") {
    xjoy = ANALOG_RIGHT_X;
    yjoy = ANALOG_RIGHT_Y;
  } else {
    throw "No side given";
  }
  return distance(controller.get_analog(xjoy), controller.get_analog(yjoy));
}

int distance(std::string side) {
  return distance(master, side);
}
