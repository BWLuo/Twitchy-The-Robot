#include "EdgeDetector.h"

constexpr uint16_t THRESHOLD = 400;
constexpr uint16_t DEBOUNCE_DELAY_MS = 10;

bool isLeftAtEdge(void) {
  return (analogRead(LEFT_EDGE_SENSOR) >= THRESHOLD);
}

bool isRightAtEdge(void) {
  return (analogRead(RIGHT_EDGE_SENSOR) >= THRESHOLD);
}

bool isAtEdge(void) {
  if (isLeftAtEdge() || isRightAtEdge()) {
    delay(DEBOUNCE_DELAY_MS);
    if (isLeftAtEdge() || isRightAtEdge()) {
      return true;
    }
  }
  return false;
}
