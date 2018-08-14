#include "SignalDetection.h"

uint16_t get1khzValueHardware(void) {
  return detect_1khz(1KHZ_IR_SENSOR);
}

uint16_t get10khzValueHardware(void) {
  return detect_10khz(10KHZ_IR_SENSOR);
}

bool is1khzHardware(void) {
  if (get1khzValueHardware() > get10khzValueHardware()) {
    delay(DEBOUNCE_DELAY_MS);
    if (get1khzValueHardware() > get10khzValueHardware()) {
      return true;
    }
  }
  return false;
}

bool is10khzHardware(void) {
  if (get10khzValueHardware() > get1khzValueHardware()) {
    delay(DEBOUNCE_DELAY_MS);
    if (get10khzValueHardware() > get1khzValueHardware()) {
      return true;
    }
  }
  return false;
}

void waitFor1khzHardware(void) {
  while (true) {
    if (is1khzHardware()) {
      while (true) {
        delay(SIGNAL_MEASUREMENT_INTERVAL_MS);
        if (is10khzHardware()) {
          goto SECOND;
        }
      }
    }

SECOND:
    if (is10khzHardware()) {
      while (true) {
        delay(SIGNAL_MEASUREMENT_INTERVAL_MS);
        if (is1khzHardware()) {
          return;
        }
      }
    }
  }
}

void waitFor10khzHardware(void) {
  while (true) {
    if (is10khzHardware()) {
      while (true) {
        delay(SIGNAL_MEASUREMENT_INTERVAL_MS);
        if (is1khzHardware()) {
          goto SECOND;
        }
      }
    }

SECOND:
    if (is1khzHardware()) {
      while (true) {
        delay(SIGNAL_MEASUREMENT_INTERVAL_MS);
        if (is10khzHardware()) {
          return;
        }
      }
    }
  }
}


uint32_t get1khzValueSoftware(void) {
  return detect_1khz(IR_SENSOR);
}

uint32_t get10khzValueSoftware(void) {
  return detect_10khz(IR_SENSOR);
}

bool is1khzSoftware(void) {
  if (get1khzValueSoftware() > get10khzValueSoftware()) {
    delay(DEBOUNCE_DELAY_MS);
    if (get1khzValueSoftware() > get10khzValueSoftware()) {
      return true;
    }
  }
  return false;
}

bool is10khzSoftware(void) {
  if (get10khzValueSoftware() > get1khzValueSoftware()) {
    delay(DEBOUNCE_DELAY_MS);
    if (get10khzValueSoftware() > get1khzValueSoftware()) {
      return true;
    }
  }
  return false;
}

void waitFor1khzSoftware(void) {
  while (true) {
    if (is1khzSoftware()) {
      while (true) {
        delay(SIGNAL_MEASUREMENT_INTERVAL_MS);
        if (is10khzSoftware()) {
          goto SECOND;
        }
      }
    }

SECOND:
    if (is10khzSoftware()) {
      while (true) {
        delay(SIGNAL_MEASUREMENT_INTERVAL_MS);
        if (is1khzSoftware()) {
          return;
        }
      }
    }
  }
}

void waitFor10khzSoftware(void) {
  while (true) {
    if (is10khzSoftware()) {
      while (true) {
        delay(SIGNAL_MEASUREMENT_INTERVAL_MS);
        if (is1khzSoftware()) {
          goto SECOND;
        }
      }
    }

SECOND:
    if (is1khzSoftware()) {
      while (true) {
        delay(SIGNAL_MEASUREMENT_INTERVAL_MS);
        if (is10khzSoftware()) {
          return;
        }
      }
    }
  }
}

