#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>

ISR(PCINT0_vect)
{
    ;;
}

int main(void)
{
    DDRB = 0b00000001;	//All inputs except LED pin pb1
    PORTB &= ~(1<<PB0); //Turn PB0 off, and hence led off
    GIMSK |= (1<<PCIE); //Pin change interrupt enabled
    PCMSK |= (1<<PCINT3);	//Set PB3 able to wake from sleep (mask)
    sei();		//Enable global interrupts

/* 
    Begin Sleep Protocol
    1) Enable sleep mode
    2) Set the sleep mdoe
    3) Power down as much stuff as not needed (in my case, everything)
	You may also want to power down Brown-Out detect if it's enabled
    4) Enable global interrupts
    5) Execute sleep mode with `sleep_mode()`
    ...
    6) When you wake up, disable sleep mode with `sleep_disable()`
*/
    sleep_enable();	//Set the mode to 'sleep'
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);    //Specify the type of sleep
					    //SLEEP_MODE_IDLE, SLEEP_MODE_ADC
    power_all_disable(); //Minimize power (default BOD is already off)
    
    sei();		//Enable interrupts
    sleep_mode();	// Execute sleep....Zzzzz
    sleep_disable();	// What happens when things wake up

    //Turn LED ON to indicate that the sleep worked
    PORTB |= (1<<PB0);
    while(1)
    {
	;;
    }
}//EOF
