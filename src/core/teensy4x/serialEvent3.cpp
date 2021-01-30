
// #include <Arduino.h>
#include "core/teensy4x/HardwareSerial.h"
void serialEvent3() __attribute__((weak));
void serialEvent3() {}		// No use calling this so disable if called...
uint8_t _serialEvent3_default PROGMEM = 1;
