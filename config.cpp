#include "main.h"
#include "config.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

pros::Motor pDriveLF(13, pros::E_MOTOR_GEARSET_18);
pros::Motor pDriveLM(12, pros::E_MOTOR_GEARSET_18);
pros::Motor pDriveLB(11, pros::E_MOTOR_GEARSET_18, true);
pros::Motor pDriveRF(19, pros::E_MOTOR_GEARSET_18, true);
pros::Motor pDriveRM(18, pros::E_MOTOR_GEARSET_18, false);
pros::Motor pDriveRB(17, pros::E_MOTOR_GEARSET_18, true);

pros::Motor catapult(15, pros::E_MOTOR_GEARSET_36);

pros::Motor intake(20, pros::E_MOTOR_GEARSET_06, true);

pros::Vision vision(14);

pros::ADIPotentiometer pot(3);

pros::ADIDigitalIn leftAuto(8);
pros::ADIDigitalIn rightAuto(7);
pros::ADIDigitalIn backAuto(6);
pros::ADIDigitalIn skillsAuto(5);
