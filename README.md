# core
This library contains startup code and a Hardware Abstraction Layer (HAL) for microcontrollers used by Bolder Flight Systems.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

## Installation
CMake is used to build this library, which is exported as a library target called *core*. The header is added as:

```
#include "core/core.h"
```
Note that you'll need CMake version 3.13 or above; it is recommended to build and install CMake from source, directions are located in the [CMake GitLab repository](https://github.com/Kitware/CMake).

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake .. -DMCU=MK66FX1M0
make
```

This will build the library and an example exutable called *blink*. The example executable source file is located at *examples/blink.cc*. This code is built and tested on AMD64 and AARCH64 systems running Linux and on an AMD64 system running the Windows Subsystem for Linux (WSL). The [arm-none-eabi](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads) toolchain must be installed in your Linux environment.

Notice that the *cmake* command includes a define specifying the microcontroller the code is being compiled for. This is required to correctly configure the code, CPU frequency, and compile/linker options. The available MCUs are:
   * MK20DX128
   * MK20DX256
   * MK64FX512
   * MK66FX1M0
   * MKL26Z64
   * IMXRT1062_T40
   * IMXRT1062_T41

These are known to work with the same packages used in Teensy products. Also switching the MK66FX1M0 or MK64FX512 from BGA to LQFP packages is known to work well. Swapping packages of other chips is probably fine, as long as it's only a package change.

The *blink* target creates the executable. *blink_hex* creates a hex file, which can be uploaded to the MCU and *blink_upload* will flash the MCU using the *teensy_loader_cli*.

## Wiring and Pinouts
[Pinouts are available](https://www.pjrc.com/teensy/pinout.html) for the Teensy packaging of these MCUs. If using the MCU on a custom board, converting the pin numbering from the Teensy to the MCU is possible using the published [Teensy schematics](https://www.pjrc.com/teensy/schematic.html). More pins are available on the MCU than on the Teensy boards, which requires updates to the *core_pins.h*. This README will be updated with the updated pin definitions as these modifications are made and validated. We will maintain backwards compatibility with the Teensy board pin numbering.

## Functions and Classes
Documentation of available functions and classes is in progress. Please submit pull requests updating this README.
