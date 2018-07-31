#ifndef DIGITALSERVO_H
#define DIGITALSERVO_H

#include <phys253.h>
#include "Ports.h"

void initializeServos(void);

void initializeRightClaw(void);
void pickUpRightSide(void);

void initializeLeftClaw(void);
void pickUpLeftSide(void);

void dropFirstBridge(void);
void dropSecondBridge(void);

void startLift(void);
void initializeBridge(void);
#endif 
