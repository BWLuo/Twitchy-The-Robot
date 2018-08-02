#ifndef LINEFOLLOWER_H
#define LINEFOLLOWER_H 

#include <phys253.h>
#include "Menu.h"
#include "Ports.h"
#include "EncoderInterrupts.h"
#include "EncoderFunctions.h"


void initializeMotors(void);
void stopMotors(void);
void adjustDirection(void);
void adjustDirection2(uint8_t velocity);
void trackDistance(uint16_t distance);

void straightScan(void);
void rightScan(void);
void LeftScan(void);

void reverseRoutine(void);
void lowerRoutine(void);
void bounce(void);
#endif
