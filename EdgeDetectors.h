#ifndef EDGEDETECTORS_H
#define EDGEDETECTORS_H

#include <phys253.h>
#include "Ports.h"
#include "Encoders.h"


/**
 * Checks if left edge sensor is off the platform
 * threshold: sensor value to be above before considered off platform
 * returns true if off platform, false otherwise
 */
bool isLeftSideAtEdge(uint16_t threshold);
/**
 * Checks if right edge sensor is off the platform
 * threshold: sensor value to be above before considered off platform
 * returns true if off platform, false otherwise
 */
bool isRightSideAtEdge(uint16_t threshold);
/**
 * Checks if either edge sensor is off the platform
 * threshold: sensor value to be above before considered off platform
 * returns true if off platform, false otherwise
 */
bool isAtEdge(uint16_t threshold);

/**
 * Turns right until edge sensor is off the platform (pivots on right wheel when turning)
 * turnSpeed: turning speed (set between 0-255)
 * threshold: sensor value to be above to be considered off the platform
 */
void turnRightUntilEdge(uint8_t turnSpeed, uint16_t threshold);
/**
 * Turns left until edge sensor is off the platform (pivots on left wheel when turning)
 * turnSpeed: turning speed (set between 0-255)
 * threshold: sensor value to be above to be considered off the platform
 */
void turnLeftUntilEdge(uint8_t turnSpeed, uint16_t threshold);

/**
 * Crosses the straight white bridge with no black line
 * distance: distance before stopping routine
 * turnSpeed: turning speed when avoiding edges (set between 0-255)
 * velocity: movement speed (set between 80-150)
 * threshold: sensor value to be above to be considered off the bridge
 */
void crossBridge(uint16_t distance, uint8_t turnSpeed, uint8_t velocity, uint16_t threshold);

#endif // EDGEDETECTORS_H
