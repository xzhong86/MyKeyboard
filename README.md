# My Keyboards

  Base on [TMK Core](https://github.com/tmk/tmk_core) firmware.

## Build

  cd into project dir and run `make`.

  Add submodule if compile usb_usb converter:
  `git submodule add https://github.com/tmk/USB_Host_Shield_2.0.git tmk_core/protocol/usb_hid/USB_Host_Shield_2.0-tmk`
  `git submodule add https://github.com/abcminiuser/lufa.git tmk_core/protocol/lufa/lufa-abcminiuser`

## Commands:

  `git submodule update --init --recursive` update submodule
  