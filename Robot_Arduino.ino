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
//    testSensors();
//    delay(400);
//  }

  enableEncoderInterrupts();
//  displayMenu();
  initializeServos();
  initializeMotors();
}

void loop() {
//
//  // first section until bridge
//  trackDistance(300);
//  initializeRightClaw();
//  trackDistance(1000);
//  while (true) {
//    adjustDirection2(80);
//    if (isAtEdge(400)) {
//      stopMotors();
//      pickUpRightSide();
//      dropFirstBridge();
//      break;
//    }
//  }
//
//  rightScan();
//  initializeRightClaw2();
//  trackDistance(340);
//
//  pickUpRightSide();
//  moveStraight(100, -1, 120);
//  delay(200);
//  rotateRMotorAngle(120, -1, 27);
//  delay(200);
//  moveStraight(100, 1, 240);
//  LeftScan();
//  
//
//  // IR detection block
//  if (detect_10khz(0) > 250) {
//    while (true) {
//      delay(500);
//      if (detect_1khz(0) > 250) {
//        break;
//      }
//    }
//    while (true) {
//      delay(500);
//      if (detect_10khz(0) > 250) {
//        break;
//      }
//    }
//  } else if (detect_1khz(0) > 250) {
//    while (true) {
//      delay(500);
//      if (detect_10khz(0) > 250) {
//        break;
//      }
//    }
//  }
//  
//  trackDistance(1250);
//  initializeLeftClaw();
  while (true) {
    adjustDirection();
    if (isAtEdge(300)) {
      stopMotors;
      bounce();
      break;
    }
  }
  moveStraight(100, -1, 75);
  pickUpLeftSide();
  moveStraightUntilEdge(80, 300);
  delay(200);
  rotateRMotorAngle(110, -1, 70);
  motor.speed(0, 100);
  motor.speed(1, 100);
  delay(1500);
  motor.speed(0, 0);
  motor.speed(0, 0);
  delay(500);
  moveStraight(100, 1, 300);
  moveStraightUntilEdge(100, 300);  
  bounce();
  dropSecondBridge();
  
//  initializeLeftClaw();
  turnRightUntilEdge(90, 200);
  moveStraight(100, -1, 100);
  initializeLeftClaw2();
  delay(1000);
  pickUpLeftSide();
//  rotateRMotorAngle(120, -1, 60);


//  moveStraightUntilEdge(100, 300);
//  bounce();
//  dropSecondBridge();


  

 
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
