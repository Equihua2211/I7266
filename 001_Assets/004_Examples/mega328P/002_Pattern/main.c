/*
 * File:                    main.c
 * Author:                  Daniel Martinez
 *                          dagmtzs@gmail.com
 * Date:                    2024-02-05
 * Target:                  ATmega328p
 * Description:             This program shows a light pattern in 4 LEDs 
 *                          
 */

#define F_CPU 16000000U

#define REPETITIONS 4
#define DELAY_TIME 200

#include <avr/io.h>
#include <util/delay.h>

int main()
{	
    // Set all PORTD bits as outputs
	DDRD |= 0xFF;
    PORTD = 1;
    char count = 0;
    
    // Enter an infinite loop
	while (1)
	{	
		while(count < REPETITIONS)
        {
            _delay_ms(DELAY_TIME);
            PORTD = (PIND << 1);
            if( PORTD >= 0x10 )
            {
                PORTD = 1;
                count++;
            }
        }
        
        count = 0;
        PORTD = 8;

        while(count < REPETITIONS)
        {
            _delay_ms(DELAY_TIME);
            PORTD = (PIND >> 1);
            if( PORTD <= 0 )
            {
                PORTD = 8;
                count++;
            }
        }
        
        count = 0;
        PORTD = 1;

	}
	
}
