/*
Author : Jonathan Whitten
Date : 24 AUG 2012
Title : Motor Driver
Description : The motor driver program executes a simple up-down linear actuator, which should never be simultaneously driven in the up and down position. It is by this necessity that I am writing a program that supports a short delay during the interrupts preventing the movement of any motors.

*/
#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/interrupt.h>
#define TIMER_MAX_VALUE 65535

uint16_t timer;
int main(void)
{
    //Configure timers first
    timer = TIMER_MAX_VALUE;

    //Configure button inputs
    DDRB = 0b00000011;

    //Configure button interrupt
    GIMSK = (1<<PCIE);//Pin Change Interrupt 
    PCMSK = (1<<PCINT4)|(1<<PCINT5);
    sei();
    uint8_t mask = 0b00110000;
    uint8_t temp;
    while(1)
    {
	//Decrement timer to zero
	if(timer == 0){
	    temp = PINB&mask;
	    temp = (temp>>4); //Shift by 4 to make this easier.
	    switch(temp)
	    {
		case 0b00000010: //down
		    PORTB = (1<<PB1);

		break;
		case 0b00000001: //up
		    PORTB |= (1<<PB0);
		break;
		default: //OFF
		    PORTB &= ~((1<<PB0)|(1<<PB1));

		    //Sleep to reduce power
		    sleep_enable();
		    set_sleep_mode(SLEEP_MODE_PWR_DOWN);

		    power_all_disable(); //minimize power consumption

		    sei();
		    sleep_mode();///Execute sleep
		    sleep_disable();
		    timer = TIMER_MAX_VALUE; //Make sure timer resets
	    }//End switch case	
	}//End If
	else{
	    timer--;
	}
	
		

    }//END MAIN WHILE

}//EOF

ISR(PCINT0_vect)
{
;;//Wake UP!
}//End PCINT
