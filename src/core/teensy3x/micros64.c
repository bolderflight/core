/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#include "core/teensy3x/micros64.h"
#include "core/teensy3x/core_pins.h"

/* 64 bit micros */
uint64_t micros64() {
  static uint32_t low32, high32;
  uint32_t new_low32 = micros();
  if (new_low32 < low32) {
    high32++;
  }
  low32 = new_low32;
  return((uint64_t) high32 << 32 | low32);
}

