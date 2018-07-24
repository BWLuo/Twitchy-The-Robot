#include "LineFollower.h"

constexpr int RIGHT_MOTOR = 0;
constexpr int LEFT_MOTOR = 1;
constexpr int THRESHOLD = 185;
constexpr int OUTER_LEFT_SENSOR = 2;
constexpr int INNER_LEFT_SENSOR = 3;
constexpr int INNER_RIGHT_SENSOR = 4;
constexpr int OUTER_RIGHT_SENSOR = 5;

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
  kp = getMenuItemValue(0);
  kd = getMenuItemValue(1);
  leftMotorSpeed = -1 * getMenuItemValue(2);
  rightMotorSpeed = -1 * getMenuItemValue(2);
  motor.speed(LEFT_MOTOR, leftMotorSpeed);
  motor.speed(RIGHT_MOTOR, rightMotorSpeed);
}

void adjustDirection(void) {
  innerLeftSensorReadout = (analogRead(INNER_LEFT_SENSOR) > THRESHOLD) ? 0 : 1;
  innerRightSensorReadout = (analogRead(INNER_RIGHT_SENSOR) > THRESHOLD) ? 0 : 1;
  outerLeftSensorReadout = (analogRead(OUTER_LEFT_SENSOR) < THRESHOLD) ? 0 : 3;
  outerRightSensorReadout = (analogRead(OUTER_RIGHT_SENSOR) < THRESHOLD) ? 0 : 3;

  deviation = innerRightSensorReadout - innerLeftSensorReadout + outerLeftSensorReadout - outerRightSensorReadout ;

  // Case when all sensors are off tape
  if (deviation == 0) {
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

