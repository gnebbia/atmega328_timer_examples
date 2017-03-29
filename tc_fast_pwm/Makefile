default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o tc_fast_pwm.o tc_fast_pwm.c
	avr-gcc -mmcu=atmega328p tc_fast_pwm.o -o tc_fast_pwm
	avr-objcopy -O ihex -R .eeprom tc_fast_pwm tc_fast_pwm.hex
	avrdude -v -p atmega328p -c arduino -P /dev/ttyUSB0 -b 57600 -D -U flash:w:tc_fast_pwm.hex:i
