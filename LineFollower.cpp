#include "LineFollower.h"

int16_t kp = 0;
int16_t kd = 0;

volatile int prevDeviation = 0;

void initializeMotors(void) {
  kp = getMenuItemValue(0);
  kd = getMenuItemValue(1);
}

bool isOnLine(uint16_t threshold) {
  return (analogRead(INNER_RIGHT_SENSOR) > threshold) || (analogRead(INNER_LEFT_SENSOR) > threshold) || (analogRead(OUTER_LEFT_SENSOR) > threshold) || (analogRead(OUTER_RIGHT_SENSOR) > threshold);
}

bool isOnLineDebounce(uint16_t threshold) {
  if (isOnLine(threshold)) {
    delay(DEBOUNCE_DELAY_MS);
    if (isOnLine(threshold)) {
      return true;
    }
  } else {
    return false;
  }
}

void adjustDirection(uint8_t velocity, uint16_t threshold) {
  int innerLeftSensor = (analogRead(INNER_LEFT_SENSOR) > threshold) ? 0 : 1;
  int innerRightSensor = (analogRead(INNER_RIGHT_SENSOR) > threshold) ? 0 : 1;
  int outerLeftSensor = (analogRead(OUTER_LEFT_SENSOR) > threshold) ? 3 : 0;
  int outerRightSensor = (analogRead(OUTER_RIGHT_SENSOR) > threshold) ? 3 : 0;

  int deviation = innerRightSensor + outerRightSensor - innerLeftSensor - outerLeftSensor;

  // Case when all sensors are off tape
  if (innerLeftSensor == 1 && innerRightSensor == 1 && outerLeftSensor == 0 && outerRightSensor == 0) {
    deviation = (prevDeviation < 0) ? -5 : 5;
  }

  int proportionalError = kp * deviation;
  int derivativeError = kd * (deviation - prevDeviation);
  int totalError = proportionalError + derivativeError;

  motor.speed(LEFT_MOTOR, (LEFT_MOTOR_FORWARD * velocity) - totalError);
  motor.speed(RIGHT_MOTOR, (RIGHT_MOTOR_FORWARD * velocity) + totalError);
  prevDeviation = deviation;
}


void adjustDirectionUntilDistance(uint16_t distance, uint8_t velocity, uint16_t threshold) {
  clearAllEncoderCount();
  while (getRightEncoderValue() < distance && getLeftEncoderValue() < distance) {
    adjustDirection(velocity, threshold);
  }
  motor.stop(LEFT_MOTOR);
  motor.stop(RIGHT_MOTOR);
}


void moveStraightLineScan(uint8_t velocity, uint16_t threshold) {
  motor.speed(LEFT_MOTOR, LEFT_MOTOR_FORWARD * velocity);
  motor.speed(RIGHT_MOTOR, RIGHT_MOTOR_FORWARD * velocity);
  while (true) {
    if (isOnLineDebounce(threshold)) {
      break;
    }
  }
  motor.stop(LEFT_MOTOR);
  motor.stop(RIGHT_MOTOR);
}


void turnRightLineScan(uint8_t turnSpeed, uint16_t threshold) {
  motor.stop(RIGHT_MOTOR);
  motor.speed(LEFT_MOTOR, LEFT_MOTOR_FORWARD * turnSpeed);
  while (true) {
    if (isOnLineDebounce(threshold)) {
      break;
    }
  }
  motor.stop(LEFT_MOTOR);
  motor.stop(RIGHT_MOTOR);
}


void turnLeftLineScan(uint8_t turnSpeed, uint16_t threshold) {
  motor.stop(LEFT_MOTOR);
  motor.speed(RIGHT_MOTOR, RIGHT_MOTOR_FORWARD * turnSpeed);
  while (true) {
    if (isOnLineDebounce(threshold)) {
      break;
    }
  }
  motor.stop(LEFT_MOTOR);
  motor.stop(RIGHT_MOTOR);
}
