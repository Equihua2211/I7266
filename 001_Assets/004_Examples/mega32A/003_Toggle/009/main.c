/*
 * File:                    main.c
 * Author:                  Daniel Martinez
 *                          dagmtzs@gmail.com
 * Date:                    yyyy-mm-dd 
 * Target:                  ATmega32A
 * Description:             This is a template for ATmega32A programs written in C
 */

/*********************************************************************************************************************************
 *          << Area for macro definitions >>
 ********************************************************************************************************************************/
#define F_CPU 1000000U
#define LED_DELAY 500U

/*********************************************************************************************************************************
 *          << Area for includes >>
 ********************************************************************************************************************************/
#include <stdint.h>

#include <avr/io.h>
#include <util/delay.h>


/*********************************************************************************************************************************
 *          << Main function >>
 ********************************************************************************************************************************/
int main()
{	
    // Set Interrupt Sense Control 2 to zero so it triggers an interrupt on a falling edge on INT2
    MCUCSR &= ~(_BV(ISC2));

    sei();
    
    DDRA |= (1 << PORTA0); 

	while (1)
	{	
        PORTA ^= (1 << PORTA0);
        _delay_ms(LED_DELAY);
	}
	
}

ISR(INT2_vect)
{
    // user code here
}