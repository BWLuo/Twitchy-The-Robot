#ifndef ENCODERS_H
#define ENCODERS_H

#include <phys253.h>
#include "Ports.h"
#include "lib/encoderinterrupts.h"
#include "EdgeDetectors.h"


/**
 * Needs to be called before using other encoder functions
 */
void initializeEncoders(void);

/**
 * Clears the count of all wheel encoders
 */
void clearAllEncoderCount(void);
/**
 * Gets the count of the encoder for the right wheel
 * returns the magnitude of the value
 */
int32_t getRightEncoderValue(void);
/**
 * Gets the count of the encoder for the left wheel
 * returns the magnitude of the value
 */
int32_t getLeftEncoderValue(void);

/**
 * Rotates the robot by a certain angle by moving right wheel
 * angle: angle to rotate
 * velocity: rotation speed (set between 0-255)
 * forward: true to move wheel forward, false for backwards
 */
void rotateRightWheel(uint16_t angle, uint8_t velocity, bool forward);
/**
 * Rotates the robot by a certain angle by moving left wheel
 * angle: angle to rotate
 * velocity: rotation speed (set between 0-255)
 * forward: true to move wheel forward, false for backwards
 */
void rotateLeftWheel(uint16_t angle, uint8_t velocity, bool forward);

/**
 * Moves straight a certain distance
 * distance: distance to move
 * velocity: movement speed (set between 80-150)
 * forward: true to move forward, false for backwards
 */
void moveStraight(uint16_t distance, uint8_t velocity, bool forward);
/**
 * Moves straight until the edge of the platform is reached
 * velocity: movement speed (set between 80-150)
 * threshold: sensor value to be above to be considered off the platform
 */
void moveStraightUntilEdge(uint8_t velocity, uint16_t threshold);
/**
 * Moves straight until the edge of the platform is reached or distance specified has been reached
 * velocity: movement speed (set between 80-150)
 * distance: distance to stop at if reached before edge
 * threshold: sensor value to be above to be considered off the platform
 */
void moveStraightUntilEdgeOrDistanceReached(uint8_t velocity, uint16_t distance, uint16_t threshold);
/*
 * Left wheel distance tracker for moveStraightUntilEdgeOrDistanceReached
 */
uint16_t getDistanceTraveledLeftWheel(void);
/*
 * Right wheel distance tracker for moveStraightUntilEdgeOrDistanceReached
 */
uint16_t getDistanceTraveledRightWheel(void);

#endif // ENCODERS_H
