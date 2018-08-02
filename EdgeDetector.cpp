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

