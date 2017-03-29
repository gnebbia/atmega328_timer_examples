default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o tc_normal.o tc_normal.c
	avr-gcc -mmcu=atmega328p tc_normal.o -o tc_normal
	avr-objcopy -O ihex -R .eeprom tc_normal tc_normal.hex
	avrdude -v -p atmega328p -c arduino -P /dev/ttyUSB0 -b 57600 -D -U flash:w:tc_normal.hex:i
