#include "ATM32_interrupts.h"

/*****************************************
 * Global Variables
*****************************************/
volatile bool RxDataReady = 0;
volatile unsigned int ADC_Result_5V = 0;
volatile unsigned int ADC_Result_3V3 = 0;
volatile unsigned int ADC_CurrentChannel = 0;

/*****************************************
 * USART interrupt vectors
*****************************************/
ISR ( USART_RXC_vect )
{
    RxDataReady = 1;
}

/*****************************************
 * ADC interrupt vectors
*****************************************/
ISR ( ADC_vect )
{
    if (ADC_CurrentChannel == 0)
    {
        ADC_Result_5V = ADC >> 2;
        ADC_CurrentChannel = 1;
        ADMUX = (ADMUX & ~0x1F) | 0x01;
    }
    else if (ADC_CurrentChannel == 1)
    {
        ADC_Result_3V3 = ADC >> 2;
        ADC_CurrentChannel = 0;
        ADMUX = (ADMUX & ~0x1F) | 0x00;
    }

    // start new conversion
    ADCSRA |= (1<<ADSC);
}