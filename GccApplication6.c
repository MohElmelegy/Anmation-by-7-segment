#include "avr/io.h"
#define F_CPU 8000000
#include "avr/delay.h"

/* Include Standard types */
#include "STY_TYPES.h"


u8 Arr_DecToSeg[10] = {0b01000000,   /* 0 */
0b11111001,   /* 1 */
0b10100100,   /* 2 */
0b10110000,   /* 3 */
0b10011001,   /* 4 */
0b10010010,   /* 5 */
0b10000010,   /* 6 */
0b11111000,   /* 7 */
0b10000000,   /* 8 */
0b10010000,   /* 9 */
					  };





void main(void)
{
	u8 LoopCounter;
	/* Set PORTA as Output Pins */
	DDRD   = 0xff;
	PORTD = 0b01000000;
	DDRA = 0xff;
	PORTA =0;
	
	/* Toggle forever */
	while(1)
	{
		/* Shift LEDs Left */
		for(LoopCounter=0; LoopCounter<8;LoopCounter++)
		{
			PORTA = 1 << LoopCounter;
			PORTD = Arr_DecToSeg[LoopCounter];
			_delay_ms(500);
		}
		
		for(LoopCounter=7; LoopCounter > 0;LoopCounter--)
		{
			PORTA = 1 << LoopCounter;
			PORTD = Arr_DecToSeg[LoopCounter];
			_delay_ms(500);
		}
		PORTA =1;
		_delay_ms(150);
		
		PORTA = 0;
		
		
		
		
		
		
		
		
	}
}