#include "MMI_Board.h"

static void Comm_Tx ( unsigned char data )
{
    USART_Transmit ( data );
}

void Comm_Init ( void )
{
    USART_Init ( USART_BAUD_9600 );
}

unsigned char Comm_Rx ( void )
{
    RxDataReady = 0;
    return USART_Receive();
}

void Comm_BoardReady ( void )
{
    Comm_Tx ( COMM_DATA_TX_READY );
}

void Comm_BoardError ( void )
{
    Comm_Tx ( COMM_DATA_TX_ERROR );
}

void Comm_PushButtonUp ( void )
{
    Comm_Tx ( COMM_DATA_TX_BUTTON_UP );
}

void Comm_PushButtonDown ( void )
{
    Comm_Tx ( COMM_DATA_TX_BUTTON_DOWN );
}

void Comm_PushButtonLeft ( void )
{
    Comm_Tx ( COMM_DATA_TX_BUTTON_LEFT );
}

void Comm_PushButtonRight ( void )
{
    Comm_Tx ( COMM_DATA_TX_BUTTON_RIGHT );
}

void Comm_PushButtonOK ( void )
{
    Comm_Tx ( COMM_DATA_TX_BUTTON_OK );
}

void Comm_PushButtonBack ( void )
{
    Comm_Tx ( COMM_DATA_TX_BUTTON_BACK );
}

void Comm_RotaryUp ( void )
{
    Comm_Tx ( COMM_DATA_TX_ROTARY_UP );
}

void Comm_RotaryDown ( void )
{
    Comm_Tx ( COMM_DATA_TX_ROTARY_DOWN );
}

void Interrupts ( bool state )
{
    if ( state == GINT_ON )
        IntEnable ();
    else
        IntDisable ();
}