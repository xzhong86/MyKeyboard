#!/bin/sh

HEX_FILE=$1
COM_DEV=$2

wait_reset() {
    if [ -e $COM_DEV ] ; then
	echo "waiting reset ..."
	while [ -e $COM_DEV ] ; do
            sleep 0.2
	done
    fi

    if [ ! -e $COM_DEV ] ; then
	echo "waiting device online ..."
	while [ ! -e $COM_DEV ] ; do
            sleep 0.2
	done
    fi
}
#wait_reset

ARDUINO=/dbase/pub/tools/arduino-1.8.4
AVRDUDE=$ARDUINO/hardware/tools/avr/bin/avrdude
CFG=$ARDUINO/hardware/tools/avr/etc/avrdude.conf

MCU=atmega32u4

#MODE="-cavr109 -b57600 -P$COM_DEV"
#MODE="-cstk500v1 -b19200 -P$COM_DEV"
MODE="-cusbtiny -b57600"
# -cstk500v1 -b19200  -Ulock:w:0x2F:m
#AVRDUDE=avrdude

CMD="$AVRDUDE -C$CFG -p$MCU $MODE -Uflash:w:$HEX_FILE:i"

echo $CMD
$CMD

