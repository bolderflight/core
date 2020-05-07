/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
* and associated documentation files (the "Software"), to deal in the Software without restriction, 
* including without limitation the rights to use, copy, modify, merge, publish, distribute, 
* sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is 
* furnished to do so, subject to the following conditions:
* The above copyright notice and this permission notice shall be included in all copies or 
* substantial portions of the Software.
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
* BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
* DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef CORE_H_
#define CORE_H_

#include "core/avr_emulation.h"
#include "core/avr_functions.h"
#include "core/core_pins.h"
#include "core/DMAChannel.h"
#include "core/eeprom.h"
#include "core/elapsedMillis.h"
#include "HardwareSerial.h"
#include "kinetis.h"
#include "mk20dx128.h"
#include "new.h"
#include "pins_arduino.h"
#include "Print.h"
#include "Stream.h"
#include "usb_desc.h"
#include "usb_dev.h"
#include "usb_mem.h"
#include "usb_names.h"
#include "usb_serial.h"
#include "i2c_t3.h"
#include "SPI.h"
#include "EEPROMclass.h"

#endif // CORE_H_
