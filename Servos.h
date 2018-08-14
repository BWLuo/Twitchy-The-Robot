#ifndef SERVOS_H
#define SERVOS_H

#include <phys253.h>
#include "Ports.h"
#include "Encoders.h"


/**
 * moves servos of robot into correct starting position at beginning of run
 */
void initializeServos(void);

/**
 * moves right claw into position to objects
 */
void initializeRightClaw(void);
/**
 * moves right claw into position to objects
 */
void initializeLeftClaw(void);

/**
 * routine to operate right claw to pick up object (claw has to be initialized first)
 */
void pickUpRightSide(void);
/**
 * routine to operate left claw to pick up object (claw has to be initialized first)
 */
void pickUpLeftSide(void);

/**
 * routine to drop bridge to cross first gap
 */
void dropFirstBridge(void);
/**
 * routine to drop bridge to cross second gap
 */
void dropSecondBridge(void);

#endif // SERVOS_H
