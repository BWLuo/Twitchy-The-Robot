#include "Test.h"

constexpr uint8_t LEFT_EDGE_SENSOR =    0;
constexpr uint8_t OUTER_LEFT_SENSOR =   1;
constexpr uint8_t INNER_LEFT_SENSOR =   2;
constexpr uint8_t INNER_RIGHT_SENSOR =  3;
constexpr uint8_t OUTER_RIGHT_SENSOR =  4;
constexpr uint8_t RIGHT_EDGE_SENSOR =   5;


void testSensors(void) {
  LCD.clear();
  LCD.home();
  LCD.print(analogRead(LEFT_EDGE_SENSOR)); LCD.print(" "); LCD.print(analogRead(OUTER_LEFT_SENSOR)); LCD.print(" "); LCD.print(analogRead(INNER_LEFT_SENSOR));
  LCD.setCursor(0, 1);
  LCD.print(analogRead(INNER_RIGHT_SENSOR)); LCD.print(" "); LCD.print(analogRead(OUTER_RIGHT_SENSOR)); LCD.print(" "); LCD.print(analogRead(RIGHT_EDGE_SENSOR));
}



