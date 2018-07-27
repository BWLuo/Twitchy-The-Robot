#include <phys253.h>
#include "Menu.h"
#include "LineFollower.h"
#include "DigitalServo.h"
#include "EdgeDetector.h"
#include "Test.h"

void setup() {
  LCD.begin(16,2);
//  while(true) {
//    testSensors();
//  }
  displayMenu();
  initializeServos();
  initializeMotors();
}

void loop() {

  // first section until bridge
  initializeRightClaw();
  while(true) {
    adjustDirection();
    if(isAtEdge()) {
      stopMotors();
      pickUpRightSide();
      dropFirstBridge();
      break;
    }
  }

  unsigned long clawCloseTime = millis() + 4200;
//  crossBridge();
  straightScan();
  initializeRightClaw2();
  do {
    adjustDirection();
  } while (millis() < clawCloseTime);

  stopMotors();
  pickUpRightSide();

  unsigned long clawOpenTime = millis() + 6000;
  do {
    adjustDirection();
  } while (millis() < clawOpenTime);
  stopMotors();
  initializeLeftClaw();
  while(true) {
    adjustDirection();
    if(isAtEdge()) {
      stopMotors;
      bounce();
      pickUpLeftSide();
      break;
    }
  }
  
  reverseRoutine();
  initializeBridge();
  unsigned long lowerTimer = millis() + 5000;
  startLift();
  delay(2000);
  do {
    adjustDirection();
  } while( millis() < lowerTimer);

  stopMotors();
  lowerRoutine();
  
  while(true) {
    delay(10000);
  }

//testSensors();
//delay(500);
}
