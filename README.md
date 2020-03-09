# core
This library contains startup code and a Hardware Abstraction Layer (HAL) for microcontrollers used by Bolder Flight Systems.
   * [License](LICENSE.md)

## Installation
CMake is used to build this library, which is exported as a library target called *core*. The header is added as:

```
#include "core/core.h"
```
Note that you'll need CMake version 3.13 or above; it is recommended to build and install CMake from source, directions are located in the [CMake GitLab repository](https://github.com/Kitware/CMake).

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library, an example executable called *polytools_example*, and an executable for testing using the Google Test framework, called *polytools_test*. The example executable source file is located at *examples/polytools_example.cc*. This code is built and tested on an AMD64 system running Linux and is likely to build on AMD64 systems running the Windows Subsystem for Linux (WSL). As an alternative, a Docker container has been [built](https://hub.docker.com/r/flybrianfly/gcc-cmake) which extends the gcc container to include CMake support and supports building this library.

## Functions and Classes

### Timing

### Digital I/O

### Analog I/O

### PWM

### Serial

### USB

### I2C

### SPI

### EEPROM
