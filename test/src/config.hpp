#ifndef _CONFIG_HPP_
#define _CONFIG_HPP_

#include "main.h"
#include "../include/okapi/api.hpp"

extern pros::Controller master;
extern pros::Controller partner;

extern pros::Motor pDriveLF;
extern pros::Motor pDriveLM;
extern pros::Motor pDriveLB;

extern pros::Motor pDriveRF;
extern pros::Motor pDriveRM;
extern pros::Motor pDriveRB;

extern okapi::MotorGroup driveTrain;
extern okapi::MotorGroup leftBase;
extern okapi::MotorGroup rightBase;

extern pros::Motor catapult;
extern pros::Motor intake;

extern pros::ADIPotentiometer catPot;
extern pros::ADIAccelerometer accel;
extern pros::ADIGyro gyro;

extern pros::ADIDigitalIn leftAuto;
extern pros::ADIDigitalIn rightAuto;
extern pros::ADIDigitalIn backLeftAuto;
extern pros::ADIDigitalIn backRightAuto;
extern pros::ADIDigitalIn skillsAuto;

#endif // _CONFIG_HPP_
