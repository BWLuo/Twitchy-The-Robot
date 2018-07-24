#include "DigitalServo.h"

// servo ports on TINAH
constexpr uint8_t LEFT_ARM_SERVO =         15;
constexpr uint8_t LEFT_CLAW_SERVO =        14;
constexpr uint8_t RIGHT_ARM_SERVO =        13;
constexpr uint8_t RIGHT_CLAW_SERVO =       12;
constexpr uint8_t LEFT_BRIDGE_SERVO =      11;
constexpr uint8_t RIGHT_BRIDGE_SERVO =     10;

// servo angles for robot arms
constexpr uint16_t RAISED_LEFT_ARM_SERVO_ANGLE =        135;
constexpr uint16_t LOWERED_LEFT_ARM_SERVO_ANGLE =       20;
constexpr uint16_t ClOSED_LEFT_CLAW_SERVO_ANGLE =       70;
constexpr uint16_t OPEN_LEFT_CLAW_SERVO_ANGLE =         180;
constexpr uint16_t RAISED_RIGHT_ARM_SERVO_ANGLE =       135;
constexpr uint16_t LOWERED_RIGHT_ARM_SERVO_ANGLE =      20;
constexpr uint16_t ClOSED_RIGHT_CLAW_SERVO_ANGLE =      110;
constexpr uint16_t OPEN_RIGHT_CLAW_SERVO_ANGLE =        0;

// servo angles for bridge drops
constexpr uint16_t DEFAULT_LEFT_BRIDGE_SERVO_ANGLE =    0;
constexpr uint16_t DEFAULT_RIGHT_BRIDGE_SERVO_ANGLE =   0;
constexpr uint16_t BRIDGE1_LEFT_BRIDGE_SERVO_ANGLE =    0;
constexpr uint16_t BRIDGE1_RIGHT_BRIDGE_SERVO_ANGLE =   0;
constexpr uint16_t BRIDGE2_LEFT_BRIDGE_SERVO_ANGLE =    0;
constexpr uint16_t BRIDGE2_RIGHT_BRIDGE_SERVO_ANGLE =   0;

// delay between movements 
constexpr uint32_t MOVEMENT_DELAY_MS = 1000;

// servo objects for control 
ServoTINAH leftArm; 
ServoTINAH leftClaw;  
ServoTINAH rightArm;  
ServoTINAH rightClaw; 
ServoTINAH leftBridge; 
ServoTINAH rightBridge; 


// basic movement functions 
void initializeServos(void) {
  leftArm.attach(LEFT_ARM_SERVO);
  leftClaw.attach(LEFT_CLAW_SERVO);
  rightArm.attach(RIGHT_ARM_SERVO);
  rightClaw.attach(RIGHT_CLAW_SERVO);
  leftBridge.attach(LEFT_BRIDGE_SERVO);
  rightBridge.attach(RIGHT_BRIDGE_SERVO);
}

void deinitializeServos(void) {
  leftArm.detach();
  leftClaw.detach();
  rightArm.detach();
  rightClaw.detach();
  leftBridge.detach();
  rightBridge.detach();
}

void liftLeftArm(void) {
  leftArm.write(RAISED_LEFT_ARM_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
}

void lowerLeftArm(void) {
  leftArm.write(LOWERED_LEFT_ARM_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
}

void openLeftClaw(void) {
  leftClaw.write(OPEN_LEFT_CLAW_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
}

void closeLeftClaw(void) {
  leftClaw.write(ClOSED_LEFT_CLAW_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
}

void liftRightArm(void) {
  rightArm.write(RAISED_RIGHT_ARM_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
}

void lowerRightArm(void) {
  rightArm.write(LOWERED_RIGHT_ARM_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
}

void openRightClaw(void) {
  rightClaw.write(OPEN_RIGHT_CLAW_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);  
}

void closeRightClaw(void) {
  rightClaw.write(ClOSED_RIGHT_CLAW_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
}

// routines 
void initializeBridgeServo(void) {
  leftBridge.write(DEFAULT_LEFT_BRIDGE_SERVO_ANGLE);
  rightBridge.write(DEFAULT_RIGHT_BRIDGE_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
}

void dropFirstBridge(void) {
  leftBridge.write(BRIDGE1_LEFT_BRIDGE_SERVO_ANGLE);
  rightBridge.write(BRIDGE1_RIGHT_BRIDGE_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
}

void dropSecondBridge(void) {
  leftBridge.write(BRIDGE2_LEFT_BRIDGE_SERVO_ANGLE);
  rightBridge.write(BRIDGE2_RIGHT_BRIDGE_SERVO_ANGLE);
  delay(MOVEMENT_DELAY_MS);
}

