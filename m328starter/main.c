//Author: Jonathan Whitten
//Copyright 2012
//Released under MIT License
//Purpose: Make things easier for getting an avr project off the ground

#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/io.h>
//Define cpu frequency, last char is an 'L'

/*

	//The Important Things to Learn
	DDRx controls the tristate postion of outputs of 'x'
	PORTx controls the port settings
	TCNTn is timer 'n'
        TIMSKn is the timer interrupt configuration (for PWM or interupt)
	TCCR0B controls the timer0 scaler	

//Seven Segment Digit Map
___A-G, DP1___
val, 0bpgfedcba(dp0), 0xVV
0, 0b11000000, 0xC0
1, 0b11111001, 0xF9
2, 0b10100100, 0xA4
3, 0b10110000, 0xB0
4, 0b10011001, 0x99
5, 0b10010010, 0x92
6, 0b10000010, 0x82
9, 0b10010000, 0x90
'l', 0b11111001, 0xF9
'A', 0b10001000, 0x88
'p', 0b10001100, 0x8C
'u', 0b11000111, 0xC7
't', 0b10001111, 0x8F
'o', 0b10100011, 0xA3
*/



int main(void)
{

	DDRD=0b11111111;
	while(1)
	{
	    PORTD |= (1<<4);
	    _delay_ms(200);
	    PORTD &= ~(1<<4);
	    _delay_ms(200);
	}
	return 1;
} //EOF
