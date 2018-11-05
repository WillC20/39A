#pragma once
#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

pros::Motor pDriveLF(8, pros::E_MOTOR_GEARSET_18);
pros::Motor pDriveLM(7, pros::E_MOTOR_GEARSET_18);
pros::Motor pDriveLB(6, pros::E_MOTOR_GEARSET_18);
pros::Motor pDriveRF(20, pros::E_MOTOR_GEARSET_18);
pros::Motor pDriveRM(19, pros::E_MOTOR_GEARSET_18);
pros::Motor pDriveRB(18, pros::E_MOTOR_GEARSET_18);

pros::Motor catapult(1, pros::E_MOTOR_GEARSET_36);

pros::Motor intake(9, pros::E_MOTOR_GEARSET_06);

//pros::Vision vision(9);

//pros::ADIPotentiometer pot(1);
