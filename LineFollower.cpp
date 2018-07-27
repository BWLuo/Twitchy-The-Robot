#include "LineFollower.h"

constexpr int RIGHT_MOTOR = 0;
constexpr int LEFT_MOTOR = 1;

constexpr int OUTER_LEFT_SENSOR = 1;
constexpr int INNER_LEFT_SENSOR = 2;
constexpr int INNER_RIGHT_SENSOR = 3;
constexpr int OUTER_RIGHT_SENSOR = 4;

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

void straightScan(void) {
  motor.speed(LEFT_MOTOR, leftMotorSpeed);
  motor.speed(RIGHT_MOTOR, rightMotorSpeed);
  while(true) {
    if(analogRead(INNER_RIGHT_SENSOR) > THRESHOLD || analogRead(INNER_LEFT_SENSOR) > THRESHOLD || analogRead(OUTER_LEFT_SENSOR) > THRESHOLD ||  analogRead(OUTER_RIGHT_SENSOR) > THRESHOLD){
      delay(30);
      if(analogRead(INNER_RIGHT_SENSOR) > THRESHOLD || analogRead(INNER_LEFT_SENSOR) > THRESHOLD || analogRead(OUTER_LEFT_SENSOR) > THRESHOLD ||  analogRead(OUTER_RIGHT_SENSOR) > THRESHOLD){
        break;
      }
    }
    
  }
  return;
}

void crossBridge(void) {
  motor.speed(RIGHT_MOTOR,-100);
  motor.speed(LEFT_MOTOR,-100);
  delay(2000);
//  motor.speed(RIGHT_MOTOR,0);
//  motor.speed(LEFT_MOTOR,0);
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
  while(true) {
    if(analogRead(INNER_RIGHT_SENSOR) > THRESHOLD || analogRead(INNER_LEFT_SENSOR) > THRESHOLD || analogRead(OUTER_LEFT_SENSOR) > THRESHOLD ||  analogRead(OUTER_RIGHT_SENSOR) > THRESHOLD){
      stopMotors();
      break;
    }
  }  
}

void startLift(void) {
  motor.speed(2, -255);
}

void lowerRoutine(void) {
  motor.speed(RIGHT_MOTOR, 0);
  motor.speed(LEFT_MOTOR, -200);
  delay(1000);
  motor.speed(LEFT_MOTOR,0);
  
  motor.speed(2,255);
  delay(1000);
  motor.speed(LEFT_MOTOR,80);
  motor.speed(RIGHT_MOTOR, 80);
  delay(2000);
  motor.speed(2,0);
  delay(1000);
  stopMotors();
  motor.speed(LEFT_MOTOR, 100);
  delay(1500);
  
}

void bounce(void) {
  motor.speed(RIGHT_MOTOR, 100);
  motor.speed(LEFT_MOTOR, 100);
  delay(100);
  motor.speed(RIGHT_MOTOR, 0);
  motor.speed(LEFT_MOTOR, 0);
}

