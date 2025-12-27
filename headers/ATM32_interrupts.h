#include <avr/interrupt.h>
#include <stdbool.h>

// GLobal variables
extern volatile bool RxDataReady;
extern volatile unsigned int ADC_Result_5V;
extern volatile unsigned int ADC_Result_3V3;
extern volatile unsigned int ADC_CurrentChannel;