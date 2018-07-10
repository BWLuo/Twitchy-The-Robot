#include "MenuItem.h"

MenuItem::MenuItem(String item, uint16_t address) {
  _item = item; 
  _address = address; 
  _value = EEPROM.read(address);
}

String MenuItem::getName(void){
  return _item;
}

uint8_t MenuItem::getValue(void){
  return _value;
}

void MenuItem::setValue(uint8_t value){ 
  _value = value; 
  EEPROM.write(_address, value);
  return; 
}
