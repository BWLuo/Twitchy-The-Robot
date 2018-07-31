#include "Encoder.h"

volatile uint32_t left_rotations = 0;
volatile uint32_t right_rotations = 0;

ISR(INT0_vect) { left_rotations++; }
ISR(INT1_vect) { left_rotations++; }
ISR(INT2_vect) { right_rotations++; }
ISR(INT3_vect) { right_rotations++; }

void enableExternalInterrupt(unsigned int INTX, unsigned int mode) {
  if (INTX > 3 || mode > 3 || mode == 1) return;
  cli();
  /* Allow pin to trigger interrupts        */
  EIMSK |= (1 << INTX);
  /* Clear the interrupt configuration bits */
  EICRA &= ~(1 << (INTX*2+0));
  EICRA &= ~(1 << (INTX*2+1));
  /* Set new interrupt configuration bits   */
  EICRA |= mode << (INTX*2);
  sei();
}

void disableExternalInterrupt(unsigned int INTX) {
  if (INTX > 3) return;
  EIMSK &= ~(1 << INTX);
}

void initializeEncoders(void) {
  enableExternalInterrupt(INT0, RISING);
  enableExternalInterrupt(INT1, RISING);
  enableExternalInterrupt(INT2, RISING);
  enableExternalInterrupt(INT3, RISING);
}

