#include "Menu.h"

MenuItem exampleItem1 = MenuItem("example1", testAddress1);
MenuItem exampleItem2 = MenuItem("example2", testAddress2);
MenuItem exampleItem3 = MenuItem("example3", testAddress3);
MenuItem items[] = {exampleItem1, exampleItem2, exampleItem3};
int itemCount = 3;

// void displayMenu(void)
// {
//     int knobValue = knob(VALUE_ADJUST_KNOB);
//     int selectedItem = knob(MENU_ADJUST_KNOB) / (1024 / itemCount - 1);
//     if (selectedItem > itemCount - 1) { selectedItem = itemCount - 1; }

//     LCD.clear(); LCD.home();
//     LCD.print(items[selectedItem].getName() + " ");
//     LCD.print(items[selectedItem].getValue());
//     LCD.setCursor(0, 1);

//     LCD.print("Set to "); LCD.print(knobValue); LCD.print("?");

//     if (StopButton(200)) { items[selectedItem].setValue(knobValue); }
//     delay(50);
// }

void displayMenu(void)
{
  LCD.clear();
  LCD.home();
  LCD.print("Displaying Menu");
  delay(500);

  while (true)
  {
    int menuIndex = knob(menuAdjustKnob) * (itemCount) / 1024;
    LCD.clear();
    LCD.home();
    LCD.print(items[menuIndex].getName() + " ");
    LCD.print(items[menuIndex].getValue());
    LCD.setCursor(0, 1);

    LCD.print("Set to ");
    LCD.print(knob(valueAdjustKnob));
    LCD.print("?");

    /* Press start button to save the new value */
    if (startbutton())
    {
      delay(100);
      if (startbutton())
      {
        items[menuIndex].setValue(knob(valueAdjustKnob));
        delay(250);
      }
    }

    /* Press stop button to exit menu */
    if (stopbutton())
    {
      delay(100);
      if (stopbutton())
      {
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
