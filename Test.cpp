#include "Test.h"
#include "Ports.h"

void testSensors(void) {
  LCD.clear();
  LCD.home();
  LCD.print(analogRead(LEFT_EDGE_SENSOR)); LCD.print(" "); LCD.print(analogRead(OUTER_LEFT_SENSOR)); LCD.print(" "); LCD.print(analogRead(INNER_LEFT_SENSOR));
  LCD.setCursor(0, 1);
  LCD.print(analogRead(INNER_RIGHT_SENSOR)); LCD.print(" "); LCD.print(analogRead(OUTER_RIGHT_SENSOR)); LCD.print(" "); LCD.print(analogRead(RIGHT_EDGE_SENSOR));
}



