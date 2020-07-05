#!/bin/sh

erb zhong_keymap.c > keymap_zhong.c

make clean
make KEYMAP=zhong -j

#../scripts/prog-dfu.sh usb_usb.hex

