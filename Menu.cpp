#include "Menu.h"

constexpr uint16_t KP_ADDRESS = 1;
constexpr uint16_t KD_ADDRESS = 2;
constexpr uint16_t MOTOR_SPEED_ADDRESS = 3;

constexpr uint8_t MENU_ADUST_KNOB = 6;
constexpr uint8_t VALUE_ADJUST_KNOB = 7;


MenuItem KP = MenuItem("KP", KP_ADDRESS);
MenuItem KD = MenuItem("KD", KD_ADDRESS);
MenuItem SPEED = MenuItem("SPEED", MOTOR_SPEED_ADDRESS);

MenuItem items[] = {KP, KD, SPEED};
int itemCount = 3;
volatile int menuIndex = 0;



uint8_t getMenuItemValue(uint8_t index) {
  return items[index].getValue();
}

void displayMenu(void) {
  LCD.clear();
  LCD.home();
  LCD.print("Displaying Menu");
  delay(500);

  while (true) {
    menuIndex = knob(MENU_ADUST_KNOB) * (itemCount) / 1024;
    LCD.clear();
    LCD.home();
    LCD.print(items[menuIndex].getName() + " ");
    LCD.print(items[menuIndex].getValue());
    LCD.setCursor(0, 1);

    LCD.print("Set to ");
    LCD.print((knob(VALUE_ADJUST_KNOB)));
    LCD.print("?");

    /* Press start button to save the new value */
    if (startbutton()) {
      delay(100);
      
      if (startbutton()) {
        items[menuIndex].setValue(knob(VALUE_ADJUST_KNOB));
        delay(250);
      }
    }

    /* Press stop button to exit menu */
    if (stopbutton()) {
      delay(100);
      if (stopbutton()) {
        LCD.clear();
        LCD.home();
        LCD.print("Leaving menu");
        delay(500);
        return;
      }
    }
    delay(50);
  }
}
