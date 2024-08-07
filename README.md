# My Keyboards

  Base on [TMK Core](https://github.com/tmk/tmk_core) firmware.

  Because of the tmk/tmk_core is not sync with tmk/tmk_keyboard/tmk_core, I added tmk_keyboard as submodule here. But only tmk_core is used.

  Reference to [TMK Firmware](https://github.com/tmk/tmk_keyboard).

  Use GPLv3 License. TMK code and submodules have its own license.



## Project

Ergodone, is a try for Ergodox/Ergodone style keyboard, but I'm not used to it.

USB\_USB, is a usb keyboard converter (or key mapper) which I used for a long time.

## Build

  update submodule:
  `git submodule update --init --recursive`

  cd into project dir and run `make`.

### Build BootloaderDFU

- `cd tmk_keyboard/tmk_core/protocol/lufa/lufa-abcminiuser/Bootloaders/DFU` , goto DFU folder.
- `vi makefile` to modify flash size and bootloader size. (and MCU/F\_CPU)
- `make MCU=atmega32u4 F_CPU=16000000`

## Requirements:

- Basic build environment: `sudo apt install build-essential`
- AVR toolchain: `sudo apt install gcc-avr avr-libc`
- Programming tools:
   - `sudo apt install dfu-programmer`, dfu-programmer, work with DFU boot loader.
   - `sudo apt install avrdude`, powerful tools, use a "usbtiny" board to connect/program AVR MCU.

## Commands:

  See command.txt.

## Tools:

- [Key test tool](https://wiki.archlinux.org/title/Keyboard_input)
- [DFU Programmer Tool](https://github.com/dfu-programmer/dfu-programmer)


