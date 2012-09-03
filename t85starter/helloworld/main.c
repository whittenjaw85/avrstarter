/*
Author:	Jonathan Whitten
Date:	02 SEPT 2012
Description: Hello World! Blink a light.
Comments:
	Please remember that <util/delay.h> will not work without
	properly defining the CPU frequency ('F_CPU'). Everything
	else should jog your memory. If you are unfamiliar with 
	programming, here is the skinny:
	1.  To do anything with the ports of a MCU, you must set their
	    direction FIRST. Hence DDRB
	2.  To output, you do a lot of ANDing and ORing with masks.
	    Assembly has a much cleaner way to do this, and I should
	    figure that out, maybe write a macro, and supplement libraries
	    to make things faster. Until then, please be content.
*/

#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/io.h>
//Define cpu frequency, last char is an 'L'

/*

	//The Important Things to Learn
	DDRx controls the tristate postion of outputs of 'x' (x = ABCD)
	PORTx controls the port settings (x = ABCD)
*/


int main(void)
{

	//Set Everything to Output, PORTB for t85
	DDRB=0b11111111;
	while(1)
	{
	    //Set Pin4 High
	    PORTB |= (1<<4);
	    _delay_ms(200);
	    //Set Pin4 Low
	    PORTB &= ~(1<<4);
	    _delay_ms(200);
	}
	return 1;
} //EOF
