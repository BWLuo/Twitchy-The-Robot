#include <phys253.h>
#include "Ports.h"
#include "lib/Menu.h"

#include "EdgeDetectors.h"
#include "Encoders.h"
#include "LineFollower.h"
#include "Servos.h"
#include "SignalDetection.h"

//#include "Test.h"

void setup() {
  LCD.begin(16, 2); // required to initiliaze LCD on TINAH
  displayMenu();
  initializeEncoders();
  initializeServos();
  initializeMotors();
}


void loop() {

  // first section until bridge
  adjustDirectionUntilDistance(300, 100, 250);
  initializeRightClaw(); // deploy to prevent claw getting stuck on ramp
  adjustDirectionUntilDistance(1000, 100, 250);
  
  while (true) {
    adjustDirection(80, 250); // slow down when reaching first ewok
    if (isAtEdge(400)) {
      stopMotors();

      // alignment to pick up first ewok
      moveStraight(50, 110, false);
      rotateRightWheel(15, 110, true);

      pickUpRightSide();
      
      // alignment to deploy first bridge
      rotateLeftWheel(9, 110, false);
      moveStraight(30, 100, false);
      
      dropFirstBridge();

      // crossing first bridge
      moveStraight(533, 100, true);
      break;
    }
  }
  
  initializeRightClaw();

  // alignment to get into position to see IR Signal
  rotateLeftWheel(10, 110, true);
  waitFor1khzSoftware();
  delay(3900); // moves early before 10khz to give room for error
  
  // find line again and start picking up second ewok
  turnRightLineScan(110, 250);
  adjustDirectionUntilDistance(340, 100, 250);

  // alignment to pick up second ewok
  moveStraight(8, 80, false);
  rotateLeftWheel(4, 85, false);
  pickUpRightSide();

  // alignment to detect IR Signal again before crossing gate
  moveStraight(150, 100, false);
  rotateRightWheel(30, 120, false);
  moveStraight(145, 100, true);
  turnLeftLineScan(110, 250);
  waitFor10khzSoftware();

  // wait before deploying claw again to not hit stormtroopers
  adjustDirectionUntilDistance(1380, 100, 250);
  initializeLeftClaw();

  while (true) {
    adjustDirection(80, 250);
    if (isAtEdge(300)) {
      stopMotors();
      break;
    }
  }

  // adjustment for picking up third ewok
  moveStraight(80, 100, false);
  pickUpLeftSide();

  // alignment for second bridge deployment
  moveStraightUntilEdge(80, 300);
  rotateRightWheel(70, 110, false);

  // straightens itself by bumping onto the back wall (do not use encoders to prevent getting stuck)
  motor.speed(LEFT_MOTOR, LEFT_MOTOR_BACKWARD * 100);
  motor.speed(RIGHT_MOTOR, RIGHT_MOTOR_BACKWARD * 100);
  delay(1500);

  moveStraight(300, 100, true); // move straight first before until edge to prevent black line from triggering function
  moveStraightUntilEdge(100, 300);

  // alignment for second bridge 
  moveStraight(130, 100, false);
  dropSecondBridge();

  // crossing second bridge
  moveStraight(100, 1, 550);

  // pick up last ewok
  turnRightUntilEdge(110, 400);
  moveStraight(140, 80, false);
  initializeLeftClaw();
  pickUpLeftSide();

  // getting accross inclined platform with no tape to follow
  rotateLeftWheel(10, 110, false);
  crossBridge(80, 1500, 200);

  // alignment to hold up chewie (cannot pick up due to basket capacity)
  rotateLeftWheel(35, 110, true);
  moveStraight(18, 80, false);
  initializeRightClaw(); // move down both claws to get ready for basket deployment
  initializeLeftClaw();

  // alignment to deploy basket
  moveStraight(45, 80, false);
  rotateRightWheel(17, 110, false);

  // raise basket
  motor.speed(LIFT_MOTOR, LIFT_MOTOR_UP * 255);
  delay(3000);
  motor.stop(LIFT_MOTOR);

  // move forward to place basket onto zipline
  motor.speed(LEFT_MOTOR, LEFT_MOTOR_FORWARD * 80);
  motor.speed(RIGHT_MOTOR, RIGHT_MOTOR_FORWARD * 80);
  delay(1400);
  motor.stop(LEFT_MOTOR);
  motor.stop(RIGHT_MOTOR);

  // lower basket onto zipline
  motor.speed(LIFT_MOTOR, LIFT_MOTOR_DOWN * 255);
  delay(3000);
  motor.stop(LIFT_MOTOR);

  // move out of baskets path 
  moveStraight(115, 100, false);
  rotateRightWheel(14, 110, true);

  motor.speed(LIFT_MOTOR, -255);
  delay(1000);
  motor.stop(LIFT_MOTOR);
  
  delay(4000);
  raiseLeftSide();
  detachAll();

  // blocks any code execution after it has finished the course
  while (true) {
    delay(10000);
  }
}
