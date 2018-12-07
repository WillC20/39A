
#include "main.h"
#include "headers/motorFunctions.hpp"
//#include "okapi/api.hpp"

//okapi::MotorGroup drive({6, 7, 8, 17, 18, 19});

//okapi::ContinuousRotarySensor baseSensor();

//auto pidTuning = okapi::PIDTunerFactory::create(, drive, 5, 100, .1, 1, .1, 1, .1, 1);

//auto drivePID = okapi::AsyncControllerFactory::posPID

void left() {
  setDrive(-50, -50, 300);
  pros::delay(500);
  //setDrive(127, 127, 300);
  setDrive(60, 60, 700);
  pros::delay(1000);
  fire();
  setDrive(127, 127, 1250);
  pros::delay(500);
  setDrive(-127, -127, 1530);
  pros::delay(500);
  setDrive(-127, 127, 260); // turn
  pros::delay(500);
  setDrive(127, 127, 500);
  pros::delay(500);
  setDrive(-127, -127, 1600);
}

void right() {
  setDrive(-50, -50, 300);
  pros::delay(500);
  //setDrive(127, 127, 300);
  setDrive(60, 60, 700);
  pros::delay(1000);
  fire();
  setDrive(50, -50, 100);
  pros::delay(500);
  setDrive(127, 127, 1250);
  pros::delay(500);
  setDrive(-127, -127, 1530);
  pros::delay(500);
  setDrive(127, -127, 260); // turn
  pros::delay(500);
  setDrive(127, 127, 500);
  pros::delay(500);
  setDrive(-127, -127, 1600);
}

void back() {
  setIntake(127);
  setDrive(-127, -127, 600);
}

void skills() {
  left();
  setDrive(-127, -127, 1000);
}

void autonomous() {

  setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  //setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);

  if (leftAuto.get_value()) {
    left();
  } else if (rightAuto.get_value()) {
    right();
  } else if (backAuto.get_value()) {
    back();
  } else if (skillsAuto.get_value()) {
    skills();
  } else {
    left();
  }
}
