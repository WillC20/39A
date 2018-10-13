#include "main.h"

using namespace pros;
//forgot to use this for most of my code

//master is the main Controller
//put the tough stuff like driving on it
pros::Controller master(pros::E_CONTROLLER_MASTER);

//I swear slave is a technical word
//put the less demanding stuff here
//this driver will not need as much practice
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

//rename the motors for your own needs
//the number is the port that the motor is in
//adding a true/false will reverse the motor direction
    //ex. pros::Motor example(1, true);
pros::Motor pDriveLF(1);
pros::Motor pDriveLB(2);
pros::Motor pDriveRF(3);
pros::Motor pDriveRB(4);

pros::Motor catapultR(5);
pros::Motor catapultL(6);

pros::Motor intake(7);

pros::Motor arm(8);

//In case you want to loop through all the motors in a for
Motor motors[] = {pDriveLF, pDriveLB, pDriveRF, pDriveRB, catapultR, catapultL, intake, arm};

//The right and left speed are set seperately
void setDrive(int left, int right) {
  pDriveLF = pDriveLB = left;
  pDriveRF = pDriveRB = right;
}

//the speeds are set together (useful for autonomous)
void setDrive(int speed) {
  setDrive(speed, speed);
}

//for autonomous if you need to drive forward at full speed
void setDrive() {
  setDrive(127);
}

//I need to write something that winds this the right amount
//Calibrate the function when we get the motors
void setCatapult(int speed) {
  catapultR = catapultL = speed;
}

//tbh you will mostly be using this
//The catapult only needs to go one direction anyway
void setCatapult() {
  setCatapult(127);
}

//set it to a certain speed
void setIntake(int speed) {
  intake = speed;
}

//defaults to full speed
void setIntake() {
  setIntake(127);
}

//if you want to flip two directions
void setArm(int speed) {
  arm = speed;
}

//for autonomous you only really need to turn one way
void setArm() {
  setArm(127);
}

//run this continuously to lock a motor
void lockMotor(Motor motor, int lockPosition) {
  double k = .2;
  motor = k*(lockPosition - motor.get_position());
}

void lockBase(int position) {
  lockMotor(pDriveLF, position);
  lockMotor(pDriveLB, position);
  lockMotor(pDriveRF, position);
  lockMotor(pDriveRB, position);
}

//Here im going to put more logic based stuff

//this will turn a boolean button press into a power level
//useful for drivers control because the button presses have boolean outputs
int buttonToPower(pros::Controller control, pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int power) {
  return control.get_digital(upButton) ? power : control.get_digital(downButton) ? -power : 0;
}

//default to master controller
int buttonToPower(pros::controller_digital_e_t upButton, pros::controller_digital_e_t downButton, int power) {
  return buttonToPower(master, upButton, downButton, power);
}

//for devices that move in a single direction (catapult)
int buttonToPower(pros::Controller control, pros::controller_digital_e_t button, int power) {
  return control.get_digital(button) ? power : 0;
}

//default to the master controller
int buttonToPower(pros::controller_digital_e_t button, int power) {
  return buttonToPower(master, button, power);
}

//This stops the drift that controllers have
int joyDeadZone(pros::Controller control, pros::controller_analog_e_t joystick) {
  return abs(control.get_analog(joystick)) > 10 ? control.get_analog(joystick) : 0;
}

//default to master controller
int joyDeadZone(pros::controller_analog_e_t joystick) {
  return joyDeadZone(master, joystick);
}

//This section is for the tasks that i will need (i might move this to the main cpp file)
//To run a task, use  TaskHandle and taskCreate();

//this might be easier/unneeded with new v5 features we will see
//basically the idea is that the motor will slow more gradually (instead of going from 0 to 127, you go from 0 to 5 to 10 ... 127) to prevent burnout
void slewRate() {
  while (true) {
    //again i have to find the encoder information

    delay(20);
  }
}
