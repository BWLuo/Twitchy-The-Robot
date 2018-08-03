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
//  while (true) {
//    testSensors();
//    delay(400);
//  }

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
    if (isAtEdge(400)) {
      stopMotors();
      pickUpRightSide();
      dropFirstBridge();
      break;
    }
  }

  // find line again and start picking up second ewok
  rightScan();
  initializeRightClaw2();
  trackDistance(340);
  pickUpRightSide();

  // adjust to move into position for IR detection
  moveStraight(100, -1, 140);
  delay(200);
  rotateRMotorAngle(120, -1, 27);
  delay(200);
  moveStraight(100, 1, 240);
  LeftScan();

  // IR detection block
  while (true) {
    if (detect_10khz(0) > 50) {
      while (true) {
        delay(500);
        if (detect_1khz(0) > 50) {
          break;
        }
      }
      while (true) {
        delay(500);
        if (detect_10khz(0) > 50) {
          break;
        }
      }
      break;
    } else if (detect_1khz(0) > 50) {
      while (true) {
        delay(500);
        if (detect_10khz(0) > 50) {
          break;
        }
      }
      break;
    }
  }

  // wait before starting next claw
  trackDistance(1250);
  initializeLeftClaw();

  while (true) {
    adjustDirection();
    if (isAtEdge(300)) {
      stopMotors;
      bounce();
      break;
    }
  }

  // adjustment for picking up third ewok
  moveStraight(100, -1, 75);
  pickUpLeftSide();

  // alignment for bridge deployment
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

  // pick up last ewok
  turnRightUntilEdge(90, 200);
  moveStraight(100, -1, 100);
  initializeLeftClaw2();
  delay(1000);
  pickUpLeftSide();

  // getting accross bridge
  rotateLMotorAngle(110, -1, 10);
  crossBridge(80, 200);
  
  while (true) {
    delay(10000);
  }
}
