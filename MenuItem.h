#ifndef MENUITEM_H
#define MENUITEM_H

#include <Arduino.h>
#include <EEPROM.h>

class MenuItem {

  public:
    MenuItem(String item, uint16_t address);
    String getName(void);
    uint8_t getValue(void);
    void setValue(uint8_t value);
  
  private:
    String _item;
    uint8_t _value;
    uint16_t _address;
};
#endif

