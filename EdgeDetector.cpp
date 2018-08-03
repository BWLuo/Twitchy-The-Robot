#include "EdgeDetector.h"

constexpr uint16_t THRESHOLD = 300;
constexpr uint16_t DEBOUNCE_DELAY_MS = 10;

bool isLeftAtEdge(uint16_t threshold) {
  return (analogRead(LEFT_EDGE_SENSOR) >= threshold);
}

bool isRightAtEdge(uint16_t threshold) {
  return (analogRead(RIGHT_EDGE_SENSOR) >= threshold);
}

bool isAtEdge(uint16_t threshold) {
  if (isLeftAtEdge(threshold) || isRightAtEdge(threshold)) {
    delay(DEBOUNCE_DELAY_MS);
    if (isLeftAtEdge(threshold) || isRightAtEdge(threshold)) {
      return true;
    }
  }
  return false;
}

void turnLeftUntilEdge(uint8_t turnSpeed, uint16_t threshold) {
  motor.speed(RIGHT_MOTOR, -1 * turnSpeed);
  motor.speed(LEFT_MOTOR, 0);
  while (true) {
    if(isRightAtEdge(threshold)) {
      break;
    }
  }
  motor.speed(RIGHT_MOTOR, turnSpeed + 50);
  delay(100);
  motor.stop(RIGHT_MOTOR);
} 

void turnRightUntilEdge(uint8_t turnSpeed, uint16_t threshold) {
  motor.speed(RIGHT_MOTOR, 0);
  motor.speed(LEFT_MOTOR, -1 * turnSpeed);
  while (true) {
    if(isRightAtEdge(threshold)) {
      break;
    }
  }
  motor.speed(LEFT_MOTOR, turnSpeed + 50);
  delay(100);
  motor.stop(LEFT_MOTOR);
}

void turnUntilNotEdge(uint8_t turnSpeed, uint16_t threshold) {
  if(isLeftAtEdge(threshold)) {
    motor.speed(RIGHT_MOTOR, 0);
    motor.speed(LEFT_MOTOR, -1 * turnSpeed);
    while(true) {
      if(!isLeftAtEdge(threshold)) {
        break;
      }
    }
  } else if (isRightAtEdge(threshold)) {
    motor.speed(LEFT_MOTOR, 0);
    motor.speed(RIGHT_MOTOR, -1 * turnSpeed);
    while(true) {
      if(!isRightAtEdge(threshold)) {
        break;
      }
    }
  }

  motor.stop(RIGHT_MOTOR);
  motor.stop(LEFT_MOTOR);
}

void crossBridge(uint8_t velocity, uint16_t distance, uint16_t threshold) {
  while(getLeftDistance() < distance && getRightDistance() < distance) {
    moveStraightUntilEdge2(velocity, distance - getLeftDistance(), threshold);
    turnUntilNotEdge(110, threshold);
  }
}

//void crossBridge(uint8_t velocity, uint16_t threshold) {
//  while(true) {
//    moveStraightUntilEdge2(velocity, threshold);
//    if(isLeftAtEdge(threshold)) {
//      rotateLMotorAngle(110, 1, 10);
//    } else if (isRightAtEdge(threshold)){
//      rotateRMotorAngle(110, 1, 10);
//    }
//    
//  }
//}
