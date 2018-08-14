#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"
#include <phys253.h>


/**
 * Brings up a menu interface on TINAH board
 */
void displayMenu(void);
/** 
 * returns the value stored at that Menu Index
 */
uint8_t getMenuItemValue(uint8_t index);

#endif
