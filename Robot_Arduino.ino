#include <phys253.h>
#include "Menu.h"
#include "LineFollower.h"
#include "DigitalServo.h"
#include "EdgeDetector.h"

volatile int knob6 = 0;
volatile int knob7 = 0;

void setup() {
  LCD.begin(16,2);
  displayMenu();
  initializeServos();
  initializeMotors();
  initializeRightClaw();
}
void loop() {
//   put your main code here, to run repeatedly:
  
  while(true) {
    adjustDirection();
    if(isAtEdge()) {
      stopMotors();
      pickUpRightSide();
      break;
    }
  }

  while(true) {
    delay(10000);
  }

//  LCD.clear();
//  LCD.home();
//  LCD.print(readLeftEdgeSensor()); LCD.print("  "); LCD.print(readRightEdgeSensor());
//  delay(100);
}
