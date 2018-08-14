#include "Encoders.h"

constexpr uint16_t MM_PER_TURN        = 160;
constexpr uint16_t AXLE_LENGTH_MM     = 220;
constexpr uint16_t TICK_PER_CM        = 11;

uint16_t distanceTraveledLeftWheel = 0;
uint16_t distanceTraveledRightWheel = 0;

void initializeEncoders(void) {
  enableEncoderInterrupts();
}

void clearAllEncoderCount(void) {
  setEncoderCount(0, 0);
  setEncoderCount(1, 0);
}

int32_t getRightEncoderValue(void) {
  return abs(getEncoderCount(0));
}

int32_t getLeftEncoderValue(void) {
  return abs(getEncoderCount(1));
}


void rotateRightWheel(uint16_t angle, uint8_t velocity, bool forward) {
  motor.stop(LEFT_MOTOR);
  clearAllEncoderCount();
  int rightCount = 0;
  int rightDistance = angle * AXLE_LENGTH_MM / 60;

  do {
    rightCount = getRightEncoderValue();
    if (forward) {
      motor.speed(RIGHT_MOTOR, RIGHT_MOTOR_FORWARD * velocity);
    } else {
      motor.speed(RIGHT_MOTOR, RIGHT_MOTOR_BACKWARD * velocity);
    }
  } while (rightCount < rightDistance);

  motor.stop(RIGHT_MOTOR);
}

void rotateLeftWheel(uint16_t angle, uint8_t velocity, bool forward) {
  motor.stop(RIGHT_MOTOR);
  clearAllEncoderCount();
  int leftCount = 0;
  int leftDistance = angle * AXLE_LENGTH_MM / 60;

  do {
    leftCount = getLeftEncoderValue();
    if (forward) {
      motor.speed(LEFT_MOTOR, LEFT_MOTOR_FORWARD * velocity);
    } else {
      motor.speed(LEFT_MOTOR, LEFT_MOTOR_BACKWARD * velocity);
    }
  } while (leftCount < leftDistance);

  motor.stop(LEFT_MOTOR);
}


void moveStraight(uint16_t distance, uint8_t velocity, bool forward) {
  clearAllEncoderCount();
  int error;
  int rightCount;
  int leftCount;

  do {
    leftCount = getLeftEncoderValue();
    rightCount = getRightEncoderValue();
    error = (rightCount - leftCount) / 5;

    if (forward) {
      motor.speed(LEFT_MOTOR, (LEFT_MOTOR_FORWARD * velocity) - error);
      motor.speed(RIGHT_MOTOR, (RIGHT_MOTOR_FORWARD * velocity) + error);
    } else {
      motor.speed(LEFT_MOTOR, (LEFT_MOTOR_BACKWARD * velocity) + error);
      motor.speed(RIGHT_MOTOR, (RIGHT_MOTOR_BACKWARD  * velocity) - error);
    }

  } while (rightCount < distance || leftCount < distance);
  motor.stop(LEFT_MOTOR);
  motor.stop(RIGHT_MOTOR);
}

void moveStraightUntilEdge(uint8_t velocity, uint16_t threshold) {
  clearAllEncoderCount();
  int error;
  int rightCount;
  int leftCount;

  do {
    leftCount = getLeftEncoderValue();
    rightCount = getRightEncoderValue();
    error = (rightCount - leftCount) / 5;

    motor.speed(LEFT_MOTOR, (LEFT_MOTOR_FORWARD * velocity) - error);
    motor.speed(RIGHT_MOTOR, (RIGHT_MOTOR_FORWARD * velocity) + error);

  } while (!isAtEdge(threshold));
  motor.stop(LEFT_MOTOR);
  motor.stop(RIGHT_MOTOR);
}

void moveStraightUntilEdgeOrDistanceReached(uint8_t velocity, uint16_t distance, uint16_t threshold) {
  clearAllEncoderCount();
  int error;
  int rightCount;
  int leftCount;

  if (distance > 0) {
    do {
      rightCount = getRightEncoderValue();
      leftCount = getLeftEncoderValue();
      error = (rightCount - leftCount) / 5;
      
      motor.speed(LEFT_MOTOR, (LEFT_MOTOR_FORWARD * velocity) - error);
      motor.speed(RIGHT_MOTOR, (RIGHT_MOTOR_FORWARD * velocity) + error);
      
    } while (!isAtEdge(threshold) && ((rightCount < distance) && (leftCount < distance)));

    distanceTraveledLeftWheel += getLeftEncoderValue();
    distanceTraveledRightWheel += getRightEncoderValue();
  }
  motor.stop(LEFT_MOTOR);
  motor.stop(RIGHT_MOTOR);
}

uint16_t getDistanceTraveledLeftWheel(void){
  return distanceTraveledLeftWheel;
}

uint16_t getDistanceTraveledRightWheel(void){
  return distanceTraveledRightWheel;
}
