#!/bin/sh

HEX_FILE=$1

MCU=atmega32u4

#DFU_PROG=dfu-programmer 
#DFU_PROG=$HOME/local/bin/dfu-programmer 
DFU_PROG=$HOME/opt/dfu-programmer/1.1.0/bin/dfu-programmer

if [ ! -f $HEX_FILE ] ; then
  echo "hex file $HEX_FILE not exist!"
  exit 1
fi

$DFU_PROG $MCU get bootloader-version || exit 1

#$DFU_PROG $MCU erase
$DFU_PROG $MCU erase --force
$DFU_PROG $MCU flash $HEX_FILE
$DFU_PROG $MCU reset


