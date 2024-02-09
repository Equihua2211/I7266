/*
 * File:                    main.c
 * Author:                  Daniel Martinez
 *                          dagmtzs@gmail.com
 * Date:                    2024-02-05
 * Target:                  ATmega328p
 * Description:             This program is a "Hello World!" implementation for the 
 *                          ATmega328p. It turns on an LED connected to PORTD2.
 */

#define F_CPU 16000000U

#include <avr/io.h>
#include <util/delay.h>

int main()
{	
    // Set PORTD bit 2 direction as output via Data Direction Register
	DDRC |= (1 << PORTC5);

    // Enter an infinite loop
	while (1)
	{	
        // Set PORTD bit 2 to HIGH state
		PORTC |= (1 << PORTC5);
	}
	
}
