![Bolder Flight Systems Logo](img/logo-words_75.png)

# Core
This library contains startup code and a Hardware Abstraction Layer (HAL) for microcontrollers used by Bolder Flight Systems.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

## Installation
CMake is used to build this library, which is exported as a library target called *core*. The header is added as:

```
#include "core/core.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake .. -DMCU=MK66FX1M0
make
```

This will build the library and an example exutable called *blink*. The example executable source file is located at *examples/blink.cc*. Notice that the *cmake* command includes a define specifying the microcontroller the code is being compiled for. This is required to correctly configure the code, CPU frequency, and compile/linker options. The available MCUs are:
   * MK20DX128
   * MK20DX256
   * MK64FX512
   * MK66FX1M0
   * MKL26Z64
   * IMXRT1062_T40
   * IMXRT1062_T41

These are known to work with the same packages used in PJRC Teensy 3.x and 4.x products. Also switching packages is known to work well, as long as it's only a package change.

The *blink* target creates the executable. *blink_hex* creates a hex file, which can be uploaded to the MCU.

## Wiring and Pinouts
[Pinouts are available](https://www.pjrc.com/teensy/pinout.html) for the Teensy packaging of these MCUs. If using the MCU on a custom board, converting the pin numbering from the Teensy to the MCU is possible using the published [Teensy schematics](https://www.pjrc.com/teensy/schematic.html). More pins are available on some of the MCUs than on the Teensy boards, which requires updates to the *core_pins.h*. This README will be updated with the updated pin definitions as these modifications are made and validated. We will maintain backwards compatibility with the Teensy board pin numbering.

## Functions and Classes
Documentation of available functions and classes is in progress. Please submit pull requests updating this README.
