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
if (MCU STREQUAL "MK20DX128")
  add_definitions(
  -D__MK20DX128__
  -DF_CPU=48000000 
  -DUSB_SERIAL
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
)
elseif (MCU STREQUAL "MK20DX256")
add_definitions(
  -D__MK20DX256__
  -DF_CPU=72000000 
  -DUSB_SERIAL
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
)
elseif (MCU STREQUAL "MK64FX512")
# Definitions
add_definitions(
  -D__MK64FX512__
  -DF_CPU=120000000 
  -DUSB_SERIAL
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
elseif (MCU STREQUAL "MK66FX1M0")
# Definitions
add_definitions(
  -D__MK66FX1M0__
  -DF_CPU=180000000 
  -DUSB_SERIAL
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
elseif (MCU STREQUAL "MKL26Z64")
add_definitions(
  -D__MKL26Z64__
  -DF_CPU=48000000 
  -DUSB_SERIAL
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
  -mcpu=cortex-m0plus
)
else ()
  message(FATAL_ERROR "ERROR: Unknown MCU selected. Available MCUs are: MK20DX128, MK20DX256, MK64FX512, MK66FX1M0, and MKL26Z64. Use -DMCU to specify the target.")
endif ()
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
  src/core/SPI.cpp
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
  include/core/SPI.h
  include/core/EEPROMclass.h
)
# Setup include directories 
target_include_directories(core PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
 	$<INSTALL_INTERFACE:include>
)
