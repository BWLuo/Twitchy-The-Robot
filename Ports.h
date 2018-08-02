#ifndef PORTS_H
#define PORTS_H


// digital output ports 
constexpr uint8_t LEFT_ARM_SERVO =         13;
constexpr uint8_t LEFT_CLAW_SERVO =        14;
constexpr uint8_t RIGHT_ARM_SERVO =        12;
constexpr uint8_t RIGHT_CLAW_SERVO =       11;
constexpr uint8_t LEFT_BRIDGE_SERVO =      15;
constexpr uint8_t RIGHT_BRIDGE_SERVO =     10;

// digital input ports
constexpr uint8_t RIGHT_ENCODER_A =        0;
constexpr uint8_t RIGHT_ENCODER_B =        1;
constexpr uint8_t LEFT_ENCODER_A =         2;
constexpr uint8_t LEFT_ENCODER_B =         3;

// analog ports
constexpr uint8_t IR_SENSOR =              0;
constexpr uint8_t LEFT_EDGE_SENSOR =       1;
constexpr uint8_t OUTER_LEFT_SENSOR =      2;
constexpr uint8_t INNER_LEFT_SENSOR =      3;
constexpr uint8_t INNER_RIGHT_SENSOR =     4;
constexpr uint8_t OUTER_RIGHT_SENSOR =     5;
constexpr uint8_t RIGHT_EDGE_SENSOR =      6;

// pwm outputs
constexpr uint8_t RIGHT_MOTOR =            0;
constexpr uint8_t LEFT_MOTOR =             1;
constexpr uint8_t LIFT_MOTOR =             2;
#endif
