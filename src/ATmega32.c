#include "ATmega32.h"

void USART_Init ( unsigned int baudrate )
{
    // set baud rate
    UBRRH = (unsigned char) (baudrate >> 8);
    UBRRL = (unsigned char) baudrate;

    // enable Tx and Rx mode
    UCSRB = (1 << RXEN) | (1 << TXEN);
    // enable UCSRC Register read, Even Parity mode, 1 stop bit and 8 data bits
    UCSRC = (1 << URSEL) | (1 << UPM1) | (1 << UCSZ1) | (1 << UCSZ0);
}

void USART_Transmit ( unsigned char data )
{
    /* Wait for empty transmit buffer */
    while ( !( UCSRA & (1<<UDRE)) );
    
    /* Put data into buffer, sends the data */
    UDR = data;
}

unsigned char USART_Receive ( void )
{
    // check for partiy error
    if (UCSRA & (1<<PE))
    {
        return UDR;
    }
    else
    {
        return USART_ERROR_CHAR;
    }    
}

void IntEnable ( void )
{
    sei();
}

void IntDisable ( void )
{
    cli();
}