
// #include <Arduino.h>
#include "core/teensy4x/HardwareSerial.h"
void serialEvent7() __attribute__((weak));
void serialEvent7() {}		// No use calling this so disable if called...
uint8_t _serialEvent7_default PROGMEM = 1;
