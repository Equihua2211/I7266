/*
 * File:                    main.c
 * Author:                  Daniel Martinez
 *                          dagmtzs@gmail.com
 * Date:                    Fri Feb 16 01:12:47 AM CST 2024
 * Target:                  ATmega328P
 * Description:             This is a template for ATmega328P programs written in C
 */

/*********************************************************************************************************************************
 *          << Area for macro definitions >>
 ********************************************************************************************************************************/
// Included in compilation command
// #define F_CPU 16000000U

#define DISPLAY_DDR     DDRC
#define DISPLAY_PORT    PORTC

#define DEFAULT_DELAY_MS    2

/*********************************************************************************************************************************
 *          << Area for includes >>
 ********************************************************************************************************************************/
#include <avr/io.h>
#include <util/delay.h>

/*********************************************************************************************************************************
 *          << Area for function definitions >>
 ********************************************************************************************************************************/
// Este es el PROTOTIPO de una función
void updateDigitValue(uint8_t);
void selectDigit(uint8_t);

/*********************************************************************************************************************************
 *          << Main function >>
 ********************************************************************************************************************************/
int main()
{	
    DDRC = 0x0F; // DDRC = 0b00001111
    DDRB = 0x0F; // DDRB = 0b00001111

    // Enter an infinite loop
    while (1)
    {        
        selectDigit(1);
        updateDigitValue(0);
        _delay_ms(DEFAULT_DELAY_MS);
        selectDigit(2);
        updateDigitValue(3);
        _delay_ms(DEFAULT_DELAY_MS);
        selectDigit(3);
        updateDigitValue(9);
        _delay_ms(DEFAULT_DELAY_MS);
        selectDigit(4);
        updateDigitValue(2);
        _delay_ms(DEFAULT_DELAY_MS);
        
    }
}

void updateDigitValue(uint8_t value)
{
    // Limpiar los primeros 4 bits del puerto
    PORTB &= 0b11110000;

    // Limitar el valor a 9 como máximo y evitar que se enciendan los bits 4 y mayores
    if (value <= 9)
    {
        PORTB |= value;
    }
    else
    {
        // Si el valor está fuera de rango, mostrar un caracter especial
        PORTB |= 10;
    }
    
}

void selectDigit(uint8_t digit)
{   
    // Limpiar los primeros 4 bits del puerto
    PORTC &= 0b11110000;

    // Limitar el valor a 4 como máximo y evitar que se enciendan los bits 4 y mayores
    if (digit < 5)
    {
        PORTB |= (1 << (digit - 1));
    }
    else
    {
        // No hacer nada
    }
}