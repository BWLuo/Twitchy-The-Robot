#ifndef DIGITALSERVO_H
#define DIGITALSERVO_H

#include <phys253.h>
#include "Ports.h"
#include "EncoderFunctions.h"

void initializeServos(void);

void initializeRightClaw(void);
void initializeRightClaw2(void);
void pickUpRightSide(void);
void pickUpRightSide2(void);

void initializeLeftClaw(void);
void pickUpLeftSide(void);

void dropFirstBridge(void);
void dropSecondBridge(void);

void startLift(void);
void initializeBridge(void);

//void routine(void);
#endif 
