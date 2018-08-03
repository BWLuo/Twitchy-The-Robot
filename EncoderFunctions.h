#ifndef ENCODERFUNCTIONS_H
#define ENCODERFUNCTIONS_H
#include <phys253.h>

void clearCount(void);

void rotateRMotor(int dir, int count);
void rotateRMotorAngle(int velocity, int dir, int angle);

void rotateLMotor(int dir, int count);
void rotateLMotorAngle(int velocity, int dir, int angle);
void moveStraight(int velocity, int dir, int distance);
void moveStraightUntilEdge(int velocity, int threshold);

int moveStraightUntilEdge2(int velocity,int distance, int threshold);
void testEncoders(void);

int getLeftDistance(void);
int getRightDistance(void);

#endif
