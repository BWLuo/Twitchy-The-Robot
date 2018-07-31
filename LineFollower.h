#ifndef LINEFOLLOWER_H
#define LINEFOLLOWER_H 

#include <phys253.h>
#include "Menu.h"
#include "Ports.h"

void initializeMotors(void);
void stopMotors(void);
void adjustDirection(void);

void straightScan(void);
void reverseRoutine(void);
void lowerRoutine(void);
void bounce(void);
#endif
