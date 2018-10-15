#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

pros::Motor pDriveLF(1);
pros::Motor pDriveLB(2);
pros::Motor pDriveRF(3);
pros::Motor pDriveRB(4);

pros::Motor catapultR(5);
pros::Motor catapultL(6);

pros::Motor intake(7);

pros::Motor arm(8);

void setDrive(int left, int right);
void setDrive(int speed);
void setDrive();

void setCatapult(int speed);
void setCatapult();

void setIntake(int speed);
void setIntake();

void setArm(int speed);
void setArm();

void lockMotor(pros::Motor motor, int lockPosition);
void lockBase(int position);

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
