#include "ATM32_interrupts.h"

/*****************************************
 * Global Variables
*****************************************/
// global variable: UART Rx data ready
volatile bool RxDataReady = 0;

/*****************************************
 * USART interrupt vectors
*****************************************/
ISR ( USART_RXC_vect )
{
    RxDataReady = 1;
}