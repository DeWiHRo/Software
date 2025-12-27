#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*****************************************
 * USART
*****************************************/
// special data codes
#define USART_ERROR_CHAR 0xFF

// Initialization
void USART_Init ( unsigned int baudrate );
// Transmit
void USART_Transmit ( unsigned char data );
// Receive
unsigned char USART_Receive ( void );

/*****************************************
 * Interrupts
*****************************************/
// Enable global interrupts
void IntEnable ( void );

// Disable global interrupts
void IntDisable (void );