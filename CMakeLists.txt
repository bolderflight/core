cmake_minimum_required(VERSION 3.13)
# Setting up the toolchain
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/cmake/mk66fx1m0.cmake")
# Project information
project(CORE 
  VERSION 1.0
  DESCRIPTION "Core files for BFS processors"
  LANGUAGES C CXX
)
# Definitions
add_definitions(
  -D__MK66FX1M0__
  -DF_CPU=180000000 
  -DUSB_SERIAL
  -DPB_FIELD_16BIT
  -DTEENSYDUINO=141  
  -DARDUINO=10805
)
# Compile options
add_compile_options(
  $<$<COMPILE_LANGUAGE:C>:-std=c11>
  $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>
  $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
  $<$<COMPILE_LANGUAGE:CXX>:-felide-constructors>
  $<$<COMPILE_LANGUAGE:CXX>:-Wno-error=narrowing>
  $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
  -g 
  -Os 
  -Wno-psabi 
  -mthumb 
  -ffunction-sections 
  -fdata-sections 
  -nostdlib 
  -MMD
  -mcpu=cortex-m4 
  -mfloat-abi=hard 
  -mfpu=fpv4-sp-d16
)
# Add the library target
add_library(core
  src/core/analog.c
  src/core/DMAChannel.cpp
  src/core/eeprom.c
  src/core/hardware_serial.cc
  src/core/mk20dx128.c
  src/core/nonstd.c
  src/core/pins_teensy.c
  src/core/Print.cpp
  src/core/serial1.c
  src/core/serial2.c
  src/core/serial3.c
  src/core/serial4.c
  src/core/serial5.c
  src/core/serial6.c
  src/core/serial6_lpuart.c
  src/core/Stream.cpp
  src/core/usb_desc.c
  src/core/usb_dev.c
  src/core/usb_inst.cpp
  src/core/usb_mem.c
  src/core/usb_serial.c
  src/core/systick_isr.c
  src/core/i2c_t3.cpp
  include/core/core.h
  include/core/avr_emulation.h
  include/core/avr_functions.h
  include/core/core_pins.h
  include/core/DMAChannel.h
  include/core/eeprom.h
  include/core/elapsedMillis.h
  include/core/HardwareSerial.h
  include/core/kinetis.h
  include/core/mk20dx128.h
  include/core/pins_arduino.h
  include/core/Print.h
  include/core/Stream.h
  include/core/usb_desc.h
  include/core/usb_dev.h
  include/core/usb_mem.h
  include/core/usb_names.h
  include/core/usb_serial.h
  include/core/i2c_t3.h
)
# Setup include directories 
target_include_directories(core PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
 	$<INSTALL_INTERFACE:include>
)
