#include "EncoderFunctions.h"
#include "EncoderInterrupts.h"
#include "Ports.h"
#include "EdgeDetector.h"

#define SPEED 120

#define MM_PER_TURN 160
#define AXLE_LENTH_MM 220
#define TICK_PER_CM 11

void clearCount(void) {
  setEncoderCount(0, 0);
  setEncoderCount(1, 0);
}

void rotateRMotorAngle(int velocity, int dir, int angle) {
  clearCount();
  int rightCount = 0;
  int rightDistance = angle * AXLE_LENTH_MM / 60;

  do {
    rightCount = abs(getEncoderCount(0));
    motor.speed(RIGHT_MOTOR, -1 * dir * velocity);
  } while (rightCount < rightDistance);

  motor.stop(RIGHT_MOTOR);
  motor.stop(LEFT_MOTOR);
}

void rotateLMotorAngle(int velocity, int dir, int angle) {
  clearCount();
  int leftCount = 0;
  int leftDistance = angle * AXLE_LENTH_MM / 60;

  do {
    leftCount = abs(getEncoderCount(1));
    motor.speed(LEFT_MOTOR, -1 * dir * velocity);
  } while (leftCount < leftDistance);

  motor.stop(RIGHT_MOTOR);
  motor.stop(LEFT_MOTOR);
}

void moveStraight(int velocity, int dir, int distance) {
  clearCount();
  int error = 0;
  int rightCount;
  int leftCount;

  do {
    
    rightCount = abs(getEncoderCount(0));
    leftCount = abs(getEncoderCount(1));

    error = (rightCount - leftCount) / 5;
    motor.speed(RIGHT_MOTOR, (-1 * dir * velocity) + error);
    motor.speed(LEFT_MOTOR, (-1 * dir * velocity) - error);
    
  } while (rightCount < distance || leftCount < distance);
  
  motor.speed(RIGHT_MOTOR, 0);
  motor.speed(LEFT_MOTOR, 0);
}

void moveStraightUntilEdge(int velocity, int threshold) {
  clearCount();
  int error = 0;
  int rightCount;
  int leftCount;

  do {
    
    rightCount = getEncoderCount(0);
    leftCount = getEncoderCount(1);

    error = (rightCount - leftCount) / 5;
    motor.speed(RIGHT_MOTOR, (-1 * velocity) + error);
    motor.speed(LEFT_MOTOR, (-1 * velocity) - error);
    
  } while (!isAtEdge(threshold));
  motor.speed(RIGHT_MOTOR, 100);
  motor.speed(LEFT_MOTOR, 100);
  
  delay(100);
  
  motor.speed(RIGHT_MOTOR, 0);
  motor.speed(LEFT_MOTOR, 0);
}

void moveStraightUntilEdge2(int velocity, int threshold) {
  clearCount();
  int error = 0;
  int rightCount;
  int leftCount;

  do {
    
    rightCount = getEncoderCount(0);
    leftCount = getEncoderCount(1);

    error = (rightCount - leftCount) / 5;
    motor.speed(RIGHT_MOTOR, (-1 * velocity) + error);
    motor.speed(LEFT_MOTOR, (-1 * velocity) - error);
    
  } while (!isAtEdge(threshold));
  motor.speed(RIGHT_MOTOR, 0);
  motor.speed(LEFT_MOTOR, 0);
}



