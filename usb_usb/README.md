# USB2USB keyboard mapper

  Base on [tmk/converter/usb_usb](https://github.com/tmk/tmk_keyboard/tree/master/converter/usb_usb).

## Features:
  * Use SpaceFn for major keymap.
      * i/k/j/l map to up/down/left/right.
      * u/n => PageUp/PageDown,  h/o => Home/End
      * 1-0,-,+ Map to F1-F12
  * CapsLock map to LeftCtrl when press and keep, CapsLock when Tap.
  * Desktop switch:
    * SPC + E map to Ctrl + GUI + Left
    * SPC + R map to Ctrl + GUI + Right

## Other

  Run build.sh to clean/compile Firmware. Use DFU to update Firmware.

