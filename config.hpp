#ifndef _CONFIG_HPP_
#define _CONFIG_HPP_

#include "main.h"

extern pros::Controller master;
extern pros::Controller partner;

extern pros::Motor pDriveLF;
extern pros::Motor pDriveLM;
extern pros::Motor pDriveLB;
extern pros::Motor pDriveRF;
extern pros::Motor pDriveRM;
extern pros::Motor pDriveRB;

extern pros::Motor catapult;

extern pros::Motor intake;

extern pros::Vision vision;

extern pros::ADIPotentiometer pot;

extern pros::ADIDigitalIn leftAuto;
extern pros::ADIDigitalIn rightAuto;
extern pros::ADIDigitalIn backAuto;
extern pros::ADIDigitalIn skillsAuto;

#endif //_CONFIG_HPP_
