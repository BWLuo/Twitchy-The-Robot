#ifndef EDGEDETECTOR_H
#define EDGEDETECTOR_H

#include <phys253.h>

uint16_t readLeftEdgeSensor(void);
uint16_t readRightEdgeSensor(void);
bool isAtEdge(void);
#endif
