#!/bin/sh

erb zhong_keymap.c > keymap_zhong.c

make clean
make KEYMAP=zhong -j8
#make KEYMAP=zhong -f Makefile.8mhz -j8

#../scripts/prog-dfu.sh usb_usb.hex

