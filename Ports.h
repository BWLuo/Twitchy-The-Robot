#ifndef PORTS_H
#define PORTS_H


// digital output ports 
constexpr uint8_t LEFT_ARM_SERVO =         13;
constexpr uint8_t LEFT_CLAW_SERVO =        14;
constexpr uint8_t RIGHT_ARM_SERVO =        12;
constexpr uint8_t RIGHT_CLAW_SERVO =       11;
constexpr uint8_t LEFT_BRIDGE_SERVO =      15;
constexpr uint8_t RIGHT_BRIDGE_SERVO =     10;

// digital inpout ports
constexpr uint8_t RIGHT_ENCODER_1 =        0;
constexpr uint8_t RIGHT_ENCODER_2 =        1;
constexpr uint8_t LEFT_ENCODER_1 =         2;
constexpr uint8_t LEFT_ENCODER_2 =         3;

// analog ports
constexpr uint8_t LEFT_EDGE_SENSOR =       0;
constexpr uint8_t OUTER_LEFT_SENSOR =      1;
constexpr uint8_t INNER_LEFT_SENSOR =      2;
constexpr uint8_t INNER_RIGHT_SENSOR =     3;
constexpr uint8_t OUTER_RIGHT_SENSOR =     4;
constexpr uint8_t RIGHT_EDGE_SENSOR =      5;

// pwm outputs
constexpr uint8_t RIGHT_MOTOR =            0;
constexpr uint8_t LEFT_MOTOR =             1;
constexpr uint8_t LIFT_MOTOR =             2;
#endif
