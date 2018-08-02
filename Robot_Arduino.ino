#include <phys253.h>
#include "Menu.h"
#include "LineFollower.h"
#include "DigitalServo.h"
#include "EdgeDetector.h"
#include "Test.h"
#include "EncoderInterrupts.h"
#include "EncoderFunctions.h"
#include "filter.h"

void setup() {
  LCD.begin(16, 2);
  //  while(true) {
  //    testIRSensor();
  //      delay(500);

  enableEncoderInterrupts();
//  displayMenu();
  initializeServos();
  initializeMotors();
}

void loop() {

  // first section until bridge
  trackDistance(300);
  initializeRightClaw();
  trackDistance(1000);
  while (true) {
    adjustDirection2(80);
    if (isAtEdge()) {
      stopMotors();
      pickUpRightSide();
      dropFirstBridge();
      break;
    }
  }

  rightScan();
  initializeRightClaw2();
  trackDistance(340);

  pickUpRightSide();
  moveStraight(100, -1, 120);
  delay(200);
  rotateRMotorAngle(120, -1, 27);
  delay(200);
  moveStraight(100, 1, 240);
  LeftScan();
  

  // IR detection block
  if (detect_10khz(0) > 250) {
    while (true) {
      delay(500);
      if (detect_1khz(0) > 250) {
        break;
      }
    }
    while (true) {
      delay(500);
      if (detect_10khz(0) > 250) {
        break;
      }
    }
  } else if (detect_1khz(0) > 250) {
    while (true) {
      delay(500);
      if (detect_10khz(0) > 250) {
        break;
      }
    }
  }
  
  trackDistance(1250);
  initializeLeftClaw();
  while (true) {
    adjustDirection();
    if (isAtEdge()) {
      stopMotors;
      bounce();
      break;
    }
  }
  moveStraight(100, -1, 75);
  pickUpLeftSide();
//  rotateRMotorAngle(120, -1, 60);
//  moveStraightUntilEdge(100);
//  dropSecondBridge();


  
  //  while (true) {
  //    adjustDirection();
  //    if (isAtEdge()) {
  //      stopMotors;
  //      bounce();
  //      pickUpLeftSide();
  //      break;
  //    }
  //  }
  //  do {
  //    adjustDirection();
  //  } while (millis() < clawCloseTime);
  //
  //  stopMotors();
  //  pickUpRightSide();
  //
  //  unsigned long clawOpenTime = millis() + 6000;
  //  do {
  //    adjustDirection();
  //  } while (millis() < clawOpenTime);
  //  stopMotors();
  //  initializeLeftClaw();
  //  while(true) {
  //    adjustDirection();
  //    if(isAtEdge()) {
  //      stopMotors;
  //      bounce();
  //      pickUpLeftSide();
  //      break;
  //    }
  //  }
  //
  //  reverseRoutine();
  //  unsigned long lowerTimer = millis() + 5000;
  //  startLift();
  //  delay(2000);
  //  do {
  //    adjustDirection();
  //  } while( millis() < lowerTimer);
  //
  //  stopMotors();
  //  lowerRoutine();
  //
  while (true) {
    delay(10000);
  }

  //testSensors();
  //delay(500);
}
