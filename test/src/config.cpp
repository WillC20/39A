#include "main.h"
#include "config.hpp"
#include "../include/okapi/api.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

pros::Motor pDriveLF(1, MOTOR_GEARSET_18, false);
pros::Motor pDriveLM(2, MOTOR_GEARSET_18, false);
pros::Motor pDriveLB(3, MOTOR_GEARSET_18, false);

pros::Motor pDriveRF(4, MOTOR_GEARSET_18, true);
pros::Motor pDriveRM(5, MOTOR_GEARSET_18, true);
pros::Motor pDriveRB(6, MOTOR_GEARSET_18, true);

pros::Motor catapult(7, MOTOR_GEARSET_36, false);
pros::Motor intake(8, MOTOR_GEARSET_06, false);

okapi::MotorGroup driveTrain({1, 2, 3, 4, 5, 6});
okapi::MotorGroup leftBase({1, 2, 3});
okapi::MotorGroup rightBase({4, 5, 6});

pros::ADIPotentiometer catPot(3);
pros::ADIAccelerometer accel(2);
pros::ADIGyro gyro(1);

pros::ADIDigitalIn leftAuto(8);
pros::ADIDigitalIn rightAuto(7);
pros::ADIDigitalIn backLeftAuto(6);
pros::ADIDigitalIn backRightAuto(5);
pros::ADIDigitalIn skillsAuto(4);
