# Changelog

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
