#include "ATmega32.h"
#include "ATM32_interrupts.h"

// set CPU clock
#ifndef F_CPU
#define F_CPU 1000000UL
#endif

/*****************************************
 * Board communication
*****************************************/
// Baud rates (for U2X = 0)
#define USART_BAUD_4800 12U
#define USART_BAUD_9600 6U
#define USART_BAUD_19200 2U
#define USART_BAUD_57600 0U

// Tx data
#define COMM_DATA_TX_READY 0x01
#define COMM_DATA_TX_ERROR 0x02
#define COMM_DATA_TX_BUTTON_UP 0x03
#define COMM_DATA_TX_BUTTON_DOWN 0x04
#define COMM_DATA_TX_BUTTON_LEFT 0x05
#define COMM_DATA_TX_BUTTON_RIGHT 0x06
#define COMM_DATA_TX_BUTTON_OK 0x07
#define COMM_DATA_TX_BUTTON_BACK 0x08
#define COMM_DATA_TX_ROTARY_UP 0x09
#define COMM_DATA_TX_ROTARY_DOWN 0x0A

// Rx data
#define COMM_DATA_RX_ERROR 0x12

// Initialization, with 9600 bauds
void Comm_Init ( void );
// Transmit
void Comm_BoardReady ( void );
void Comm_BoardError ( void );
void Comm_PushButtonUp ( void );
void Comm_PushButtonDown ( void );
void Comm_PushButtonLeft ( void );
void Comm_PushButtonRight ( void );
void Comm_PushButtonOK ( void );
void Comm_PushButtonBack ( void );
void Comm_RotaryUp ( void );
void Comm_RotaryDown ( void );
// Receive
unsigned char Comm_Rx ( void );

/*****************************************
 * Interrupts
*****************************************/
// global interrupt state
#define GINT_ON 0
#define GINT_OFF 1

// set interrupt state
void Interrupts ( bool state );

/*****************************************
 * Analog-Digital Cpnversion
*****************************************/
#define ADC0_VOLTAGE 5.0
#define ADC1_VOLTAGE 3.3
#define ADC_STARTCHANNEL 0

void VoltageMeas_Init ( void );
float GetVoltage (unsigned int channel );