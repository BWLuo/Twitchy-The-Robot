#include "Test.h"

void testSensors(void) {
  LCD.clear();
  LCD.home();
  LCD.print(analogRead(LEFT_EDGE_SENSOR)); LCD.print(" "); LCD.print(analogRead(OUTER_LEFT_SENSOR)); LCD.print(" "); LCD.print(analogRead(INNER_LEFT_SENSOR));
  LCD.setCursor(0, 1);
  LCD.print(analogRead(INNER_RIGHT_SENSOR)); LCD.print(" "); LCD.print(analogRead(OUTER_RIGHT_SENSOR)); LCD.print(" "); LCD.print(analogRead(RIGHT_EDGE_SENSOR));
}

void testIRSensor(void) {
  LCD.clear();
  LCD.home();
  LCD.print("10khz: "); LCD.print(detect_10khz(IR_SENSOR));
  LCD.setCursor(0,1);
  LCD.print("1khz: "); LCD.print(detect_1khz(IR_SENSOR));
}

void testEncoders(void) {
  LCD.clear();
  LCD.setCursor(0,0);
  LCD.print(getEncoderCount(0));
  LCD.setCursor(0,1);
  LCD.print(getEncoderCount(1));
}



