#ifndef TEST_H 
#define TEST_H

#include <phys253.h>
#include "Ports.h"
#include "lib/encoderinterrupts.h"
#include "lib/filter.h"


/**
 * Display QRD sensor values on TINAH LCD
 * Top row displays (from left to right) left edge sensor, outer left line sensor, inner left line sensor
 * Bottom row displays (from left to right) inner right line sensor, outer right line sensor, right edge sensor
 */
void testSensors(void);


/**
 * Display IR sensor values onto TINAH LCD
 */
void testIRSensor(void);


/** 
 * Display encoder values onto TINAH LCD
 */
void testEncoders(void);

#endif
