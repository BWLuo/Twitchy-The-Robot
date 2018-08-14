#ifndef LINEFOLLOWER_H
#define LINEFOLLOWER_H 

#include <phys253.h>
#include "Ports.h"
#include "lib/Menu.h"
#include "Encoders.h"


/**
 * Sets up Motors, need to be called before using other functions
 */
void initializeMotors(void);

/**
 * Checks if any of the sensors are on the black line 
 * threshold: threshold for sensor value to be higher to be considered on black line
 * returns true if any of the sensors are on black line, false otherwise
 */
bool isOnLine(uint16_t threshold);
/**
 * Checks if any of the sensors are on the black line, countains debounce to prevent false triggers
 * threshold: threshold for sensor value to be higher to be considered on black line
 * returns true if any of the sensors are on black line, false otherwise
 */
bool isOnLineDebounce(uint16_t threshold);

/**
 * PID adjustment for direction to follow black line
 * Needs to be called continuously to adjust direction to follow line
 * velocity: movement speed (set between 80-150)
 * threshold: threshold for sensor value to be higher to be considered on black line
 */
void adjustDirection(uint8_t velocity, uint16_t threshold);
/**
 * Follows black line until robot has traveled certain distance
 * Needs to be called continuously to adjust direction to follow line
 * distance: distance to be traveled before stopping
 * velocity: movement speed (set between 80-150)
 * threshold: threshold for sensor value to be higher to be considered on black line
 */
void adjustDirectionUntilDistance(uint16_t distance, uint8_t velocity, uint16_t threshold);

/**
 * Moves straight until a sensor is on black line
 * velocity: movement speed (set between 0-255)
 * threshold: sensor value to be higher to be considered on black line
 */
void moveStraightLineScan(uint8_t velocity, uint16_t threshold);
/**
 * Turns right until a sensor is on black line (pivots on right wheel when turning)
 * turnSpeed: turning speed (set between 0-255)
 * threshold: sensor value to be higher to be considered on black line
 */
void turnRightLineScan(uint8_t turnSpeed, uint16_t threshold);
/**
 * Turns left until a sensor is on black line (pivots on left wheel when turning)
 * turnSpeed: turning speed (set between 0-255)
 * threshold: sensor value to be higher to be considered on black line
 */
void turnLeftLineScan(uint8_t turnSpeed, uint16_t threshold);

#endif
