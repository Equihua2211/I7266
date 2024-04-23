#include <util/delay.h>
#include <avr/io.h>

#include "includes/usart.h"

#define DELAY_TIME_MS       100U
#define USART_BUFFER_SIZE   255U
#define BAUD_RATE           9600U

#define I2C_SCL             100000U
#define I2C_PRESCALER       4U

#define TWBR_CALC(__SCL, __PRES) ((F_CPU / __SCL - 16U) / 2 * __PRES )

char USART_buffer[USART_BUFFER_SIZE];

int main( void )
{
    USART_init(UBRR_CALC(BAUD_RATE));
    USART_puts( "\e[2J\e[H" );
    USART_puts( "\e[1;36m> USART Ready\r\n\n" );

    TWBR = TWBR_CALC(I2C_SCL, I2C_PRESCALER);
    TWCR = (1<<TWINT)|(1<<TWSTA|(1<<TWEN);

    while(1U)
    {
        
    }
}



