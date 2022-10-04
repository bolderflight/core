# v3.14 required for FetchContent_MakeAvailable
cmake_minimum_required(VERSION 3.14)
if (DEFINED MCU)
  include(FetchContent)
	FetchContent_Declare(
		mcu_support
		GIT_REPOSITORY https://github.com/bolderflight/mcu-support.git
		GIT_TAG v1.1.0
	)
	FetchContent_MakeAvailable(mcu_support)
  # Setting up the toolchain
  set(CMAKE_TOOLCHAIN_FILE "${mcu_support_SOURCE_DIR}/cmake/cortex.cmake")
  # Project information
  project(CORE 
    VERSION 3.1.2
    DESCRIPTION "Core files for BFS processors"
    LANGUAGES C CXX
  )
  # Grab the processor and set up definitions and compile options
  include(${mcu_support_SOURCE_DIR}/cmake/config_mcu.cmake)
  configMcu(${MCU} ${mcu_support_SOURCE_DIR})
  # Add the library target
  if (MCU STREQUAL "MK20DX128" OR MCU STREQUAL "MK20DX256" OR MCU STREQUAL "MK64FX512" OR MCU STREQUAL "MK66FX1M0" OR MCU STREQUAL "MKL26Z64")
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
      src/core/teensy3x/SPI.cpp
      src/core/teensy3x/micros64.c
      src/core/teensy3x/WireKinetis.cpp
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
      include/core/teensy3x/SPI.h
      include/core/teensy3x/EEPROMclass.h
      include/core/teensy3x/micros64.h
      include/core/teensy3x/WireKinetis.h
    )
  else ()
    add_library(core
      src/core/teensy4x/bootdata.c
      src/core/teensy4x/clockspeed.c
      src/core/teensy4x/delay.c
      src/core/teensy4x/analog.c
      src/core/teensy4x/DMAChannel.cpp
      src/core/teensy4x/eeprom.c
      src/core/teensy4x/HardwareSerial.cpp
      src/core/teensy4x/HardwareSerial1.cpp
      src/core/teensy4x/HardwareSerial2.cpp
      src/core/teensy4x/HardwareSerial3.cpp
      src/core/teensy4x/HardwareSerial4.cpp
      src/core/teensy4x/HardwareSerial5.cpp
      src/core/teensy4x/HardwareSerial6.cpp
      src/core/teensy4x/HardwareSerial7.cpp
      src/core/teensy4x/HardwareSerial8.cpp
      src/core/teensy4x/interrupt.c
      src/core/teensy4x/IntervalTimer.cpp
      src/core/teensy4x/nonstd.c
      src/core/teensy4x/Print.cpp
      src/core/teensy4x/pwm.c
      src/core/teensy4x/rtc.c
      src/core/teensy4x/startup.c
      src/core/teensy4x/Stream.cpp
      src/core/teensy4x/tempmon.c
      src/core/teensy4x/usb.c
      src/core/teensy4x/usb_desc.c
      src/core/teensy4x/usb_inst.cpp
      src/core/teensy4x/usb_serial.c
      src/core/teensy4x/yield.cpp
      src/core/teensy4x/digital.c
      src/core/teensy4x/debugprintf.c
      src/core/teensy4x/EventResponder.cpp
      src/core/teensy4x/serialEvent.cpp
      src/core/teensy4x/serialEvent1.cpp
      src/core/teensy4x/serialEvent2.cpp
      src/core/teensy4x/serialEvent3.cpp
      src/core/teensy4x/serialEvent4.cpp
      src/core/teensy4x/serialEvent5.cpp
      src/core/teensy4x/serialEvent6.cpp
      src/core/teensy4x/serialEvent7.cpp
      src/core/teensy4x/serialEvent8.cpp
      src/core/teensy4x/serialEventUSB1.cpp
      src/core/teensy4x/serialEventUSB2.cpp
      src/core/teensy4x/SPI.cpp
      src/core/teensy4x/WireIMXRT.cpp
      src/core/teensy4x/micros64.c
      include/core/teensy4x/core.h
      include/core/teensy4x/arm_math.h
      include/core/teensy4x/avr_emulation.h
      include/core/teensy4x/avr_functions.h
      include/core/teensy4x/core_cmInstr.h
      include/core/teensy4x/core_pins.h
      include/core/teensy4x/DMAChannel.h
      include/core/teensy4x/eeprom.h
      include/core/teensy4x/elapsedMillis.h
      include/core/teensy4x/HardwareSerial.h
      include/core/teensy4x/IntervalTimer.h
      include/core/teensy4x/imxrt.h
      include/core/teensy4x/pins_arduino.h
      include/core/teensy4x/Print.h
      include/core/teensy4x/printf.h
      include/core/teensy4x/Stream.h
      include/core/teensy4x/usb_desc.h
      include/core/teensy4x/usb_dev.h
      include/core/teensy4x/usb_names.h
      include/core/teensy4x/usb_serial.h
      include/core/teensy4x/EEPROMclass.h
      include/core/teensy4x/core_id.h
      include/core/teensy4x/EventResponder.h
      include/core/teensy4x/SPI.h
      include/core/teensy4x/WireIMXRT.h
      include/core/teensy4x/micros64.h
    )
  endif()
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
    include(${mcu_support_SOURCE_DIR}/cmake/flash_mcu.cmake)
    FlashMcu(blink ${MCU} ${mcu_support_SOURCE_DIR})
  endif()
endif()
