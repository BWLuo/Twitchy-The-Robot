#ifndef EDGEDETECTOR_H
#define EDGEDETECTOR_H

#include <phys253.h>
#include "Ports.h"

bool isLeftAtEdge(uint16_t threshold);
bool isRightAtEdge(uint16_t threshold);
bool isAtEdge(uint16_t threshold);
void turnRightUntilEdge(uint8_t turnSpeed, uint16_t threshold);

#endif
