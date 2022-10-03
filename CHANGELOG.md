# Changelog

## v3.1.1
- Fixed support for Teensy 4 MMOD. Had issue where pinMode wasn't working properly, should be good now.

## v3.1.0
- Added support for Teensy 4 MMOD

## v3.0.2
- Accidentally used FetchContent_Populate instead of FetchContent_MakeAvailable

## v3.0.1
- Updaing to pull in mcu-support repo for cmake, lib, ld, and tools libs

## v3.0.0
- Removing define for ARDUINO to make it easier to write libraries supporting both CMake and Arduino build tools.
- Switched ARDUINO_TEENSY40 to ARDUINO_TEENSY41 for Teensy 4.1
- Removed C++20 back to C++14

## v2.0.5
- Updated to support C++20

## v2.0.4
- Updated documentation

## v2.0.3
- Switched from using i2c_t3 to Wire for Teensy 3.x I2C in order to provide a consistent class and API for I2C calls across Teensy 3.x and 4.x processors

## v2.0.2
- Removed the definition of PI in the Teensy 4.x arm_math.h file. This macro easily conflicts with other definitions of PI.

## v2.0.1
- Updated cmake config and flash files to support upload to the Teensy 4.x boards

## v2.0.0
- Added support for the IMXRT1062 processor

## v1.0.3
- Updated *flash_mcu* to work with WSL 1 and WSL 2

## v1.0.2
- Added CONTRIBUTING and CHANGELOG
- Updated *flash_mcu* for Linux to flash without requiring button press

## v1.0.1
- Updated README

## v1.0.0
- Initial baseline
