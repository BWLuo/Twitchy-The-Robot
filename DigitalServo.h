#ifndef DIGITALSERVO_H
#define DIGITALSERVO_H

#include <ServoTINAH.h>

void initializeServos(void);

void liftLeftArm(void);
void lowerLeftArm(void);

void initializeRightClaw(void);
void pickUpRightSide(void);
void dropFirstBridge(void);
void dropSecondBridge(void);

void changeArm(int angle);
void changeClaw(int angle);
#endif 
