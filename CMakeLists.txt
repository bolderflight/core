cmake_minimum_required(VERSION 3.13)
# Setting up the toolchain
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/cmake/cortex.cmake")
# Project information
project(CORE 
  VERSION 1.0.3
  DESCRIPTION "Core files for BFS processors"
  LANGUAGES C CXX
)
# Grab the processor and set up definitions and compile options
include(${CMAKE_SOURCE_DIR}/cmake/config_mcu.cmake)
configMcu(${MCU})
# Add the library target
add_library(core
  src/core/teensy3x/analog.c
  src/core/teensy3x/DMAChannel.cpp
  src/core/teensy3x/eeprom.c
  src/core/teensy3x/hardware_serial.cc
  src/core/teensy3x/IntervalTimer.cpp
  src/core/teensy3x/mk20dx128.c
  src/core/teensy3x/nonstd.c
  src/core/teensy3x/pins_teensy.c
  src/core/teensy3x/Print.cpp
  src/core/teensy3x/serial1.c
  src/core/teensy3x/serial2.c
  src/core/teensy3x/serial3.c
  src/core/teensy3x/serial4.c
  src/core/teensy3x/serial5.c
  src/core/teensy3x/serial6.c
  src/core/teensy3x/serial6_lpuart.c
  src/core/teensy3x/Stream.cpp
  src/core/teensy3x/usb_desc.c
  src/core/teensy3x/usb_dev.c
  src/core/teensy3x/usb_inst.cpp
  src/core/teensy3x/usb_mem.c
  src/core/teensy3x/usb_serial.c
  src/core/teensy3x/systick_isr.c
  src/core/teensy3x/yield.c
  src/core/teensy3x/i2c_t3.cpp
  src/core/teensy3x/SPI.cpp
  src/core/teensy3x/micros64.c
  src/core/teensy3x/Time.cpp
  include/core/teensy3x/core.h
  include/core/teensy3x/avr_emulation.h
  include/core/teensy3x/avr_functions.h
  include/core/teensy3x/core_pins.h
  include/core/teensy3x/DMAChannel.h
  include/core/teensy3x/eeprom.h
  include/core/teensy3x/elapsedMillis.h
  include/core/teensy3x/HardwareSerial.h
  include/core/teensy3x/IntervalTimer.h
  include/core/teensy3x/kinetis.h
  include/core/teensy3x/mk20dx128.h
  include/core/teensy3x/pins_arduino.h
  include/core/teensy3x/Print.h
  include/core/teensy3x/Stream.h
  include/core/teensy3x/usb_desc.h
  include/core/teensy3x/usb_dev.h
  include/core/teensy3x/usb_mem.h
  include/core/teensy3x/usb_names.h
  include/core/teensy3x/usb_serial.h
  include/core/teensy3x/i2c_t3.h
  include/core/teensy3x/SPI.h
  include/core/teensy3x/EEPROMclass.h
  include/core/teensy3x/micros64.h
  include/core/teensy3x/TimeLib.h
)
# Setup include directories 
target_include_directories(core PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
 	$<INSTALL_INTERFACE:include>
)
# Example if this project is built separately
if (PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
  # Add the example target
	add_executable(blink examples/blink.cc)
	# Add the includes
	target_include_directories(blink PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	)
	# Link libraries to the test target
	target_link_libraries(blink
		PRIVATE 
    core
  )
  # Add hex and upload targets
  include(${CMAKE_SOURCE_DIR}/cmake/flash_mcu.cmake)
  FlashMcu(blink ${MCU})
endif()
