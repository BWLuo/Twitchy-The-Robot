#ifndef SIGNALDETECTION_H 
#define SIGNALDETECTION_H

#include <phys253.h>
#include "Ports.h"
#include "lib/filter.h"


/**
 * finds strength of 1khz signal (uses hardware circuit)
 * returns intensity of 1khz signal found (range: 0-1024)
 */
uint16_t get1khzValueHardware(void);
/**
 * finds strength of 10khz signal (uses hardware circuit)
 * returns intensity of 10khz signal found (range: 0-1024)
 */
uint16_t get10khzValueHardware(void);
/**
 * determines whether the signal is 1khz
 * returns true if signal most likely 1khz, false otherwise
 */
bool is1khzHardware(void);
/**
 * determines whether the signal is 10khz
 * returns true if signal most likely 10khz, false otherwise
 */
bool is10khzHardware(void);
/**
 * blocks until signal is 1khz
 */
void waitFor1khzHardware(void);
/**
 * blocks until signal is 10khz
 */
void waitFor10khzHardware(void);


/**
 * finds strength of 1khz signal (uses software library function)
 * returns intensity of 1khz signal found
 */
uint32_t get1khzValueSoftware(void);
/**
 * finds strength of 10khz signal (uses software library function)
 * returns intensity of 10khz signal found
 */
uint32_t get10khzValueSoftware(void);
/**
 * determines whether the signal is 1khz
 * returns true if signal most likely 1khz, false otherwise
 */
bool is1khzSoftware(void);
/**
 * determines whether the signal is 10khz
 * returns true if signal most likely 10khz, false otherwise
 */
bool is10khzSoftware(void);
/**
 * blocks until signal is 1khz
 */
void waitFor1khzSoftware(void);
/**
 * blocks until signal is 10khz
 */
void waitFor10khzSoftware(void);

#endif // SIGNALDETECTION_H
