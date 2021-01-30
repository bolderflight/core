
// #include <Arduino.h>
#include <cstdint>
#include "core/teensy4x/pgmspace.h"

void serialEvent() __attribute__((weak));
void serialEvent() {
}
uint8_t _serialEvent_default PROGMEM = 1;	
