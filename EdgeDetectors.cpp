#include "EdgeDetectors.h"

bool isLeftSideAtEdge(uint16_t threshold) {
  return (analogRead(LEFT_EDGE_SENSOR) >= threshold);
}

bool isRightSideAtEdge(uint16_t threshold) {
  return (analogRead(RIGHT_EDGE_SENSOR) >= threshold);
}

bool isAtEdge(uint16_t threshold) {
  if (isLeftSideAtEdge(threshold) || isRightSideAtEdge(threshold)) {
    delay(DEBOUNCE_DELAY_MS);
    if (isLeftSideAtEdge(threshold) || isRightSideAtEdge(threshold)) {
      return true;
    }
  }
  return false;
}


void turnLeftUntilEdge(uint8_t turnSpeed, uint16_t threshold) {
  motor.stop(LEFT_MOTOR);
  motor.speed(RIGHT_MOTOR, RIGHT_MOTOR_FORWARD * turnSpeed);
  while (true) {
    if (isAtEdge(threshold)) {
      break;
    }
  }
  motor.stop(RIGHT_MOTOR);
}

void turnRightUntilEdge(uint8_t turnSpeed, uint16_t threshold) {
  motor.stop(RIGHT_MOTOR);
  motor.speed(LEFT_MOTOR, LEFT_MOTOR_FORWARD * turnSpeed);
  while (true) {
    if (isAtEdge(threshold)) {
      break;
    }
  }
  motor.stop(LEFT_MOTOR);
}

void turnUntilNotEdge(uint8_t turnSpeed, uint16_t threshold) {
  if (isLeftSideAtEdge(threshold)) {
    motor.speed(RIGHT_MOTOR, 0);
    motor.speed(LEFT_MOTOR, LEFT_MOTOR_FORWARD * turnSpeed);
    while (true) {
      if (!isLeftSideAtEdge(threshold)) {
        break;
      }
    }
  } else if (isRightSideAtEdge(threshold)) {
    motor.speed(LEFT_MOTOR, 0);
    motor.speed(RIGHT_MOTOR, RIGHT_MOTOR_FORWARD * turnSpeed);
    while (true) {
      if (!isRightSideAtEdge(threshold)) {
        break;
      }
    }
  }
  motor.stop(RIGHT_MOTOR);
  motor.stop(LEFT_MOTOR);
}


void crossBridge(uint16_t distance, uint8_t turnSpeed, uint8_t velocity, uint16_t threshold) {
  int distanceTraveled;
  while (getDistanceTraveledLeftWheel() < distance && getDistanceTraveledRightWheel() < distance) {
    distanceTraveled = (getDistanceTraveledLeftWheel() + getDistanceTraveledRightWheel()) / 2;
    moveStraightUntilEdgeOrDistanceReached(velocity, distance - distanceTraveled, threshold);
    turnUntilNotEdge(turnSpeed, threshold);
  }
  motor.stop(RIGHT_MOTOR);
  motor.stop(LEFT_MOTOR);
}
