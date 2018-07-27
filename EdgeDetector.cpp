#include "EdgeDetector.h"

constexpr uint8_t LEFT_EDGE_SENSOR = 0;
constexpr uint8_t RIGHT_EDGE_SENSOR = 5;

constexpr uint16_t THRESHOLD = 400;

uint16_t readLeftEdgeSensor(void) {
  return analogRead(LEFT_EDGE_SENSOR);
}

uint16_t readRightEdgeSensor(void) {
  return analogRead(RIGHT_EDGE_SENSOR);
}

bool isAtEdge(void) {
  bool isLeftEdge = (readLeftEdgeSensor() >= THRESHOLD);
  bool isRightEdge = (readRightEdgeSensor() >= THRESHOLD);
  return (isLeftEdge || isRightEdge);
}
