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
#define DEBOUNCE 200U

/*********************************************************************************************************************************
 *          << Area for includes >>
 ********************************************************************************************************************************/
#include <stdint.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


/*********************************************************************************************************************************
 *          << Main function >>
 ********************************************************************************************************************************/
int main()
{	

    DDRA |= (1 << PORTA0); 
    DDRD &= ~(1 << PORTD7); 

    uint8_t reading = 0;
    uint8_t latch = 0;
    uint8_t cycles = 0;

	while (1)
	{	
        reading = 0x80 & PIND;
        if(reading == 0x80)
        {
            if(cycles > 20)
            {
                PORTA ^= 1;
            }
        }
        else
        {
            // Do nothing
        }

        if (latch == 1)
        {
            cycles++;
        }
        
	}
	
}



