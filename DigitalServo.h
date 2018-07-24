#ifndef DIGITALSERVO_H
#define DIGITALSERVO_H

#include <ServoTINAH.h>

void initializeServos(void);
void initializeBridgeServos(void);

void dropFirstBridge(void);
void dropSecondBridge(void);
#endif 
