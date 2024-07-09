#!/bin/sh

erb zhong_keymap.c > keymap_zhong.c

make clean
make KEYMAP=zhong -j8
cp usb_usb.hex usb_usb-16mhz.hex

make clean
make KEYMAP=zhong -f Makefile.8mhz -j8
cp usb_usb.hex usb_usb-8mhz.hex

#../scripts/prog-dfu.sh usb_usb.hex

