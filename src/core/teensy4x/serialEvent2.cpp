
// #include <Arduino.h>
#include "core/teensy4x/HardwareSerial.h"
void serialEvent2() __attribute__((weak));
void serialEvent2() {}		// No use calling this so disable if called...
uint8_t _serialEvent2_default PROGMEM = 1;
