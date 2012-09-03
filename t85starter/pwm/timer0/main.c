#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/io.h>
//Define cpu frequency, last char is an 'L'


void setPWM(uint8_t pwm)
{
    OCR0A = pwm;
}
int main(void)
{

	//Configure IO Pins, PB0 output
	DDRB = 0b00000001;
	
	//Set GTCCR (General Timer/Counter1 Control Register)

	//Set Duty Cycle
	OCR0A = 255;
	//Set Timer Control Register to:
	//1) Set the TCCR1 to Prescaler/1024
	//2) Set GTCCR to enable PWM on OC1B and set COM1B0 to '1'
	//   in order to set the OC1B pin when TIMER1 equals OCR1B.
//	TCCR0A |= (1 << COM0A1)|(1<<COM0A0)|(1<<WGM01)|(1<<WGM00); //Clear when match, fast PWM mode
	TCCR0A |= (1<< COM0A1)|(1<<WGM01)|(1<<WGM00); //Set on match
	TCCR0B |= (1 << CS01)|(1<<CS00);  //(Prescaler no prescaler)

	uint8_t duty = 0;
	//Main While
	while(1)
	{
	    _delay_ms(50);
	    duty++;
	    setPWM(duty);
	}
	return 1;
} //EOF
