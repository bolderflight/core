cmake_minimum_required(VERSION 3.13)
# Setting up the toolchain
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/cmake/cortex.cmake")
# Project information
project(CORE 
  VERSION 1.0
  DESCRIPTION "Core files for BFS processors"
  LANGUAGES C CXX
)
# Grab the processor and set up definitions and compile options
include(${CMAKE_SOURCE_DIR}/cmake/config_mcu.cmake)
configMcu(${MCU})
# Add the library target
add_library(core
  src/core/analog.c
  src/core/DMAChannel.cpp
  src/core/eeprom.c
  src/core/hardware_serial.cc
  src/core/IntervalTimer.cpp
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
  src/core/yield.c
  src/core/i2c_t3.cpp
  src/core/SPI.cpp
  include/core/core.h
  include/core/avr_emulation.h
  include/core/avr_functions.h
  include/core/core_pins.h
  include/core/DMAChannel.h
  include/core/eeprom.h
  include/core/elapsedMillis.h
  include/core/HardwareSerial.h
  include/core/IntervalTimer.h
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
  include/core/SPI.h
  include/core/EEPROMclass.h
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
