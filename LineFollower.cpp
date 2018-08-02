#include "LineFollower.h"

constexpr int THRESHOLD = 250;

volatile int innerLeftSensorReadout = 0;
volatile int outerLeftSensorReadout = 0;
volatile int innerRightSensorReadout = 0;
volatile int outerRightSensorReadout = 0;

int kp = 0;
int kd = 0;
int leftMotorSpeed = 0;
int rightMotorSpeed = 0;

volatile int p = 0;
volatile int d = 0;
volatile int g = 0;

volatile int deviation = 0;
volatile int error = 0;
volatile int lasterr = 0;



void initializeMotors(void) {
  kp = -1 * getMenuItemValue(0);
  kd = -1 * getMenuItemValue(1);
  leftMotorSpeed = -1 * getMenuItemValue(2);
  rightMotorSpeed = -1 * getMenuItemValue(2);
}

void stopMotors(void) {
  motor.speed(LEFT_MOTOR, 0);
  motor.speed(RIGHT_MOTOR, 0);
}

void adjustDirection(void) {
  innerLeftSensorReadout = (analogRead(INNER_LEFT_SENSOR) > THRESHOLD) ? 0 : 1;
  innerRightSensorReadout = (analogRead(INNER_RIGHT_SENSOR) > THRESHOLD) ? 0 : 1;
  outerLeftSensorReadout = (analogRead(OUTER_LEFT_SENSOR) < THRESHOLD) ? 0 : 3;
  outerRightSensorReadout = (analogRead(OUTER_RIGHT_SENSOR) < THRESHOLD) ? 0 : 3;

  deviation = innerRightSensorReadout - innerLeftSensorReadout + outerLeftSensorReadout - outerRightSensorReadout ;

  // Case when all sensors are off tape
  if (innerLeftSensorReadout == 1 && innerRightSensorReadout == 1 && outerLeftSensorReadout == 0 && outerRightSensorReadout == 0) {
    deviation = (lasterr < 0) ? -5 : 5;
  }

  error = deviation;

  p = kp * deviation;
  d = kd * (error - lasterr);
  g = p + d;

  lasterr = error;

  // Feedback into motor
  motor.speed(LEFT_MOTOR, leftMotorSpeed - g);
  motor.speed(RIGHT_MOTOR, rightMotorSpeed + g);
}

void adjustDirection2(uint8_t velocity) {
  innerLeftSensorReadout = (analogRead(INNER_LEFT_SENSOR) > THRESHOLD) ? 0 : 1;
  innerRightSensorReadout = (analogRead(INNER_RIGHT_SENSOR) > THRESHOLD) ? 0 : 1;
  outerLeftSensorReadout = (analogRead(OUTER_LEFT_SENSOR) < THRESHOLD) ? 0 : 3;
  outerRightSensorReadout = (analogRead(OUTER_RIGHT_SENSOR) < THRESHOLD) ? 0 : 3;

  deviation = innerRightSensorReadout - innerLeftSensorReadout + outerLeftSensorReadout - outerRightSensorReadout ;

  // Case when all sensors are off tape
  if (innerLeftSensorReadout == 1 && innerRightSensorReadout == 1 && outerLeftSensorReadout == 0 && outerRightSensorReadout == 0) {
    deviation = (lasterr < 0) ? -5 : 5;
  }

  error = deviation;

  p = kp * deviation;
  d = kd * (error - lasterr);
  g = p + d;

  lasterr = error;

  // Feedback into motor
  motor.speed(LEFT_MOTOR, (-1 * velocity) - g);
  motor.speed(RIGHT_MOTOR, (-1 * velocity) + g);
}

void trackDistance(uint16_t distance) {
  clearCount();
  while (getEncoderCount(0) < distance && getEncoderCount(0) < distance) {
    adjustDirection();
  }
  motor.stop(LEFT_MOTOR);
  motor.stop(RIGHT_MOTOR);

}

bool isOnLine(void) {
  bool result = (analogRead(INNER_RIGHT_SENSOR) > THRESHOLD) || (analogRead(INNER_LEFT_SENSOR) > THRESHOLD) || (analogRead(OUTER_LEFT_SENSOR) > THRESHOLD) || (analogRead(OUTER_RIGHT_SENSOR) > THRESHOLD);
  return result;
}

void straightScan(void) {
  motor.speed(LEFT_MOTOR, leftMotorSpeed);
  motor.speed(RIGHT_MOTOR, rightMotorSpeed);

  while (true) {
    if (isOnLine()) {
      delay(30);
      if (isOnLine()) {
        break;
      }
    }

  }
  return;
}

void rightScan(void) {
  motor.speed(LEFT_MOTOR, -100);
  motor.speed(RIGHT_MOTOR, 0);

  while (true) {
    if (isOnLine()) {
      delay(30);
      if (isOnLine()) {
        break;
      }
    }
  }
  motor.speed(LEFT_MOTOR, 0);
  motor.speed(RIGHT_MOTOR, 0);
}

void LeftScan(void) {
  motor.speed(LEFT_MOTOR, 0);
  motor.speed(RIGHT_MOTOR, -100);

  while (true) {
    if (isOnLine()) {
      delay(30);
      if (isOnLine()) {
        break;
      }
    }
  }
  motor.speed(LEFT_MOTOR, 0);
  motor.speed(RIGHT_MOTOR, 0);
}

void reverseRoutine(void) {
  motor.speed(RIGHT_MOTOR, 100);
  motor.speed(LEFT_MOTOR, 100);
  delay(1000);
  stopMotors();
  delay(500);
  motor.speed(RIGHT_MOTOR, 100);
  motor.speed(LEFT_MOTOR, -100);
  delay(500);
  while (true) {
    if (isOnLine()) {
      stopMotors();
      break;
    }
  }
}

void startLift(void) {
  motor.speed(LIFT_MOTOR, -255);
}

void lowerRoutine(void) {
  motor.speed(RIGHT_MOTOR, 0);
  motor.speed(LEFT_MOTOR, -200);
  delay(1000);
  motor.speed(LEFT_MOTOR, 0);

  motor.speed(2, 255);
  delay(1000);
  motor.speed(LEFT_MOTOR, 80);
  motor.speed(RIGHT_MOTOR, 80);
  delay(2000);
  motor.speed(2, 0);
  delay(1000);
  stopMotors();
  motor.speed(LEFT_MOTOR, 100);
  delay(1500);

}

void bounce(void) {
  motor.speed(RIGHT_MOTOR, 150);
  motor.speed(LEFT_MOTOR, 150);
  delay(100);
  motor.speed(RIGHT_MOTOR, 0);
  motor.speed(LEFT_MOTOR, 0);
}

