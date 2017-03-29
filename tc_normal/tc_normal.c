#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define TOTAL 125

volatile unsigned short T0IntCnt = 0;

void init();

int main(void)
{
	init();
	while(1)
	{
	}
	return 1; //EXIT BADLY
}

void init()
{
	DDRB  = 0xFF;
	PORTB = 0xFF;

	TCCR0A = 0x00;
	TCCR0B = 0x04;
	TCNT0  = 6;
	
	TIMSK0 = 0x01; 

	sei();
}

ISR(TIMER0_OVF_vect)
{
	TCNT0 = 6;
	if(++T0IntCnt == TOTAL)
	{
		PORTB ^= 0x20;
		T0IntCnt = 0;
	}
}

