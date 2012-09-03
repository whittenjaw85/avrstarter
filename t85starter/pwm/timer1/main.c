#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/io.h>
//Define cpu frequency, last char is an 'L'

void setPWM(uint8_t pwm)
{
    OCR1B = pwm;
}
int main(void)
{

	//Configure IO Pins, PB4 output
	DDRB = 0b00010000;
	
	//Set GTCCR (General Timer/Counter1 Control Register)

	//Set Duty Cycle
	OCR1B = 255;
	
	//Set Timer Control Register to:
	//1) Set the TCCR1 to Prescaler/1024
	//2) Set GTCCR to enable PWM on OC1B and set COM1B0 to '1'
	//   in order to set the OC1B pin when TIMER1 equals OCR1B.
	TCCR1 |= (1<<CS12)|(1<<CS11)|(1<<CS10);
	GTCCR |= (1<<PWM1B)|(1<<COM1B0);
//	TCCR1A |= (1 << COM0A1); //none-inverting mode
//	TCCR1B |= (1 << CS02) | (1 << CS00);  //(Prescaler/1024)

	uint8_t duty = 255;
	//Main While
	while(1)
	{
	    _delay_ms(50);
	    duty--;
	    setPWM(duty);
	}
	return 1;
} //EOF
