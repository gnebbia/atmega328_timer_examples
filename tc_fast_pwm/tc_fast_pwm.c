#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define TOTAL 125

volatile unsigned short T0IntCnt = 0;

void init();

int main(void)
{
	int i = 0;
	init();
	while(1)
	{
		for(i = 0;i <= 255;i++)
		{
			OCR0A = i;
			_delay_ms(10);
		}
		for(;i >= 0; i--)
		{
			OCR0A = i;
			_delay_ms(10);
		}

	}
	return 1; //EXIT BADLY
}

void init()
{
	/* We set port B and port D ad as outputs */
	DDRB  = 0xFF;
	PORTB = 0xFF;
	DDRD = 0xFF;

	/* now TCCR0A7:4 should be set to 5 (0101) to have outputs on both OCnA and OCnB (pin 5 and 6 UNO/2009) */
	/* these bits control the waveform generated from OC0A and OC0B, its frequency is given by
	f_OC0A = f_clk/(2N(1+OCR0A)
	where N is the prescaler value, in our case 256, 
	and f_clk is 16MHz, so in our case we get:
		16Mhz/(512(1+249)
	/* TCCR0A3:0 should be set to "0010" to have the WGM set to CTC mode */
	TCCR0A = 0xA3;
	/* now we set TCCR0B to "00000100" this is used in order to set the prescaler to 256*/

	TCCR0B = 0x05;

	/* We start from 0 */
	TCNT0  = 0x00;
	
	/* Our interrupt will be launched when TCNT0 will reach 249 */
	OCR0B = 192;

	/* We enable the interrupts coming on compare with OCR0A */
//	TIMSK0 = 0x02; 

	/* we enable interrupts */
	sei();
}

/*
ISR(TIMER0_COMPA_vect)
{
	if(++T0IntCnt == TOTAL)
	{
		PORTB ^= 0x20;
		T0IntCnt = 0;
	}
}
*/
/*
ISR(TIMER0_OVF_vect)
{
	if(++T0IntCnt == TOTAL)
	{
		PORTB ^= 0x20;
		T0IntCnt = 0;
	}
}
*/
