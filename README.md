# My Keyboards

  Base on [TMK Core](https://github.com/tmk/tmk_core) firmware.

## Build

  update submodule:
  `git submodule update --init --recursive`

  cd into project dir and run `make`.

### Build BootloaderDFU

  cd tmk_keyboard/tmk_core/protocol/lufa/lufa-abcminiuser/Bootloaders/DFU
  make MCU=atmega32u4 F_CPU=16000000

## Commands:

