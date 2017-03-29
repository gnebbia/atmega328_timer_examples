default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o tc_ctc.o tc_ctc.c
	avr-gcc -mmcu=atmega328p tc_ctc.o -o tc_ctc
	avr-objcopy -O ihex -R .eeprom tc_ctc tc_ctc.hex
	avrdude -v -p atmega328p -c arduino -P /dev/ttyUSB0 -b 57600 -D -U flash:w:tc_ctc.hex:i
