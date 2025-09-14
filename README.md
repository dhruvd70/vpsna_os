# vpsn_os

![Build Status](https://img.shields.io/badge/build-passing-brightgreen)
![ARM GCC](https://img.shields.io/badge/Toolchain-arm--none--eabi--gcc-blue)

A **minimal RTOS learning project** for the STM32F103RB microcontroller (ARM Cortex-M3).  
This repository contains a bare-metal workspace with CMSIS headers, startup code, and a Makefile-based build system.  

The goal of this project is to learn bare-metal programming on the STM32F103RB without relying on any abstractions. Currently, some initialization code and linker scripts are vendor-supplied, but as the project progresses, I plan to write my own startup code and linker files from scratch.

## Project Status

Currently, this is just a **test build** where the workspace, toolchains, and build system are set up.  
Future work will involve firstly writing some basic peripheral drivers like **GPIO** and **UART**..

## Project Structure
<pre>
├── cmsis
│   ├── cmsis_compiler.h
│   ├── cmsis_gcc.h
│   ├── cmsis_version.h
│   ├── core_cm3.h
│   ├── stm32f103xb.h
│   ├── stm32f1xx.h
│   ├── system_stm32f1xx.c
│   └── system_stm32f1xx.h
├── core
│   └── main.c
├── Makefile
├── README.md
├── startup
│   └── startup_stm32f103xb.s
└── STM32F103XX_FLASH.ld
</pre>

## Prerequisites

Make sure the following tools are installed:

- **ARM GCC Toolchain** (`arm-none-eabi-gcc`, `arm-none-eabi-objcopy`, `arm-none-eabi-size`)  
- **OpenOCD** (for flashing & debugging with ST-LINK)  
- **GDB Multiarch** (`gdb-multiarch`) for debugging  

Ubuntu/Debian example installation:

```bash
sudo apt update
sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi gdb-multiarch openocd
```
## Building

### To Build the project: 

```bash
make
```

This generates the following in the build/ directory:

- **vpsna_os.elf** – ELF binary (with symbols)

- **vpsna_os.hex** – Intel HEX file

- **vpsna_os.bin** – Raw binary

### To clean build files:

```bash
make clean
```

### To start the OpenOCD GDB server:

```bash
make debug
```

### In another terminal:

```bash
make gdb
```

This will:

- **Connect to OpenOCD at localhost:3333**

- **Reset & halt the MCU**

- **Set a breakpoint at main**

## Flashing

```bash
make flash
```

## Future Plans

- **Write a basic GPIO Driver**

- **Write a basic UART Driver for printf style Debugging**

- **Implement a simple task scheduler**

- **Add context switching**

- **Introduce basic synchronization primitives**

- **Eventually, grow into a minimal educational RTOS**

## References

1. [STM32F103 Reference Manual](https://www.st.com/resource/en/reference_manual/cd00171190-stm32f101xb-stm32f102xb-stm32f103xb-stm32f105xb-stm32f107xb-advanced-armbased-32bit-mcus-stmicroelectronics.pdf) – Official STM32F1 series reference manual.
2. [STM32F103 Datasheet](https://www.st.com/resource/en/datasheet/stm32f103c8.pdf) – Datasheet for STM32F103RB MCU.
3. [Cortex-M3 Devices Generic User Guide](https://developer.arm.com/documentation/dui0552/latest/) – ARM Cortex Microcontroller Software Interface Standard.

## License

This project is for educational purposes.
You may use, modify, and share it freely.