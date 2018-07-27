#ifndef DIGITALSERVO_H
#define DIGITALSERVO_H

#include <phys253.h>

void initializeServos(void);

void initializeRightClaw(void);
void initializeRightClaw2(void);
void pickUpRightSide(void);

void initializeLeftClaw(void);
void pickUpLeftSide(void);

void dropFirstBridge(void);
void dropSecondBridge(void);

#endif 
