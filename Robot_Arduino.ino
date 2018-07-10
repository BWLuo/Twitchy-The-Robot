#include <phys253.h>
#include "Menu.h"


void setup() {
  // put your setup code here, to run once:
  LCD.begin(16, 2);
  LCD.clear();
  LCD.setCursor(0,0);
  displayMenu();
}
void loop() {
  // put your main code here, to run repeatedly:

}
