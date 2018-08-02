#include "DigitalServo.h"

// servo angles for robot arms
constexpr uint16_t DEFAULT_LEFT_ARM_SERVO_ANGLE =       80;
constexpr uint16_t RAISED_LEFT_ARM_SERVO_ANGLE =        25;
//constexpr uint16_t RAISED_LEFT_ARM_SERVO_ANGLE =        0;

constexpr uint16_t LOWERED_LEFT_ARM_SERVO_ANGLE =       180;

constexpr uint16_t DEFAULT_RIGHT_ARM_SERVO_ANGLE =      90;
constexpr uint16_t RAISED_RIGHT_ARM_SERVO_ANGLE =       127;
constexpr uint16_t LOWERED_RIGHT_ARM_SERVO_ANGLE =      1;

constexpr uint16_t DEFAULT_LEFT_CLAW_SERVO_ANGLE =      95;
constexpr uint16_t CLOSED_LEFT_CLAW_SERVO_ANGLE =       55;
constexpr uint16_t OPEN_LEFT_CLAW_SERVO_ANGLE =         180;

constexpr uint16_t DEFAULT_RIGHT_CLAW_SERVO_ANGLE =     80;
constexpr uint16_t CLOSED_RIGHT_CLAW_SERVO_ANGLE =      112;
constexpr uint16_t OPEN_RIGHT_CLAW_SERVO_ANGLE =        13;

// servo angles for bridge drops
constexpr uint16_t DEFAULT_LEFT_BRIDGE_SERVO_ANGLE =    85;
constexpr uint16_t DEFAULT_RIGHT_BRIDGE_SERVO_ANGLE =   90;
constexpr uint16_t BRIDGE1_LEFT_BRIDGE_SERVO_ANGLE =    0;
constexpr uint16_t BRIDGE1_RIGHT_BRIDGE_SERVO_ANGLE =   180;
constexpr uint16_t BRIDGE2_LEFT_BRIDGE_SERVO_ANGLE =    85;
constexpr uint16_t BRIDGE2_RIGHT_BRIDGE_SERVO_ANGLE =   90;

// delay between movements
constexpr uint32_t MOVEMENT_DELAY_MS = 500;

// servo objects for control
ServoTINAH leftArm;
ServoTINAH leftClaw;
ServoTINAH rightArm;
ServoTINAH rightClaw;
ServoTINAH leftBridge;
ServoTINAH rightBridge;

void initializeServos(void) {
  leftArm.attach(LEFT_ARM_SERVO);
  leftClaw.attach(LEFT_CLAW_SERVO);
  rightArm.attach(RIGHT_ARM_SERVO);
  rightClaw.attach(RIGHT_CLAW_SERVO);
  leftBridge.attach(LEFT_BRIDGE_SERVO);
  rightBridge.attach(RIGHT_BRIDGE_SERVO);

  leftArm.write(DEFAULT_LEFT_ARM_SERVO_ANGLE);
  leftClaw.write(DEFAULT_LEFT_CLAW_SERVO_ANGLE);
  rightArm.write(DEFAULT_RIGHT_ARM_SERVO_ANGLE);
  rightClaw.write(DEFAULT_RIGHT_CLAW_SERVO_ANGLE);
  leftBridge.write(DEFAULT_LEFT_BRIDGE_SERVO_ANGLE);
  rightBridge.write(DEFAULT_RIGHT_BRIDGE_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
}

// initialization routines setting up claw to pick up objects
void initializeRightClaw(void) {
  rightArm.write(LOWERED_RIGHT_ARM_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
  rightClaw.write(OPEN_RIGHT_CLAW_SERVO_ANGLE);
}

void initializeRightClaw2(void) {
  rightArm.write(LOWERED_RIGHT_ARM_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
  rightClaw.write(10);
}

void initializeLeftClaw(void) {
  leftArm.write(LOWERED_LEFT_ARM_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
  leftClaw.write(OPEN_LEFT_CLAW_SERVO_ANGLE);
}

void pickUpRightSide(void) {
  
  for (int i = OPEN_RIGHT_CLAW_SERVO_ANGLE; i < CLOSED_RIGHT_CLAW_SERVO_ANGLE; i++) {
    rightClaw.write(i);
    delay(11);
  }
  
  rightClaw.write(CLOSED_RIGHT_CLAW_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
  rightArm.write(RAISED_RIGHT_ARM_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
  rightClaw.write(OPEN_RIGHT_CLAW_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);

  rightClaw.write(DEFAULT_RIGHT_CLAW_SERVO_ANGLE);
  rightArm.write(DEFAULT_RIGHT_ARM_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
}

void pickUpLeftSide(void) {
  
  for (int i = OPEN_LEFT_CLAW_SERVO_ANGLE; i > CLOSED_LEFT_CLAW_SERVO_ANGLE; i--) {
    leftClaw.write(i);
    delay(10);
  }
  
  leftArm.write(RAISED_LEFT_ARM_SERVO_ANGLE);
  delay(1000);
  leftClaw.write(OPEN_LEFT_CLAW_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);

  leftClaw.write(DEFAULT_LEFT_CLAW_SERVO_ANGLE);
  leftArm.write(DEFAULT_LEFT_ARM_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
}
//
//void routine(void) {
//  leftClaw.write(CLOSED_LEFT_CLAW_SERVO_ANGLE);
//  delay(MOVEMENT_DELAY_MS);
//  moveStraight(90, -1, 100);
//  leftClaw.write(OPEN_LEFT_CLAW_SERVO_ANGLE);
//  moveStraight(100, -1, 70);
//  rotateLMotorAngle(100, 1, 30);
//}

// bridge routines
void dropFirstBridge(void) {

  rotateLMotorAngle(110, -1, 32);
  moveStraight(100, -1, 30);

  // deploy bridge
  leftBridge.write(BRIDGE1_LEFT_BRIDGE_SERVO_ANGLE);
  rightBridge.write(BRIDGE1_RIGHT_BRIDGE_SERVO_ANGLE);
  delay(1300);

  moveStraight(100, 1, 450);
}

void dropSecondBridge(void) {
  moveStraight(100, -1,100);
  leftBridge.write(BRIDGE2_LEFT_BRIDGE_SERVO_ANGLE);
  rightBridge.write(BRIDGE2_RIGHT_BRIDGE_SERVO_ANGLE);
  delay(2000);
  
  moveStraight(100, 1, 1000);
}

