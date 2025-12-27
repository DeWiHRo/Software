#include "MMI_application.h"

static void GetUARTData ( void )
{
    volatile unsigned char RxData;

    if ( RxDataReady == 1 )
        RxData = Comm_Rx ();

    switch (RxData)
    {
    case COMM_DATA_RX_ERROR:
        /* code */
        break;
    
    default:
        break;
    }
}

static void SendBoardStateOK ( void )
{
    Comm_BoardReady ();
}

static void SendBoardStateError ( void )
{
    Comm_BoardError ();
}

static void SendBoardPushButtonUp ( void )
{
    Comm_PushButtonUp ();
}

static void SendBoardPushButtonDown ( void )
{
    Comm_PushButtonDown ();
}

static void SendBoardPushButtonLeft ( void )
{
    Comm_PushButtonLeft ();
}

static void SendBoardPushButtonRight ( void )
{
    Comm_PushButtonRight ();
}

static void SendBoardPushButtonOK ( void )
{
    Comm_PushButtonOK ();
}

static void SendBoardPushButtonBack ( void )
{
    Comm_PushButtonBack ();
}

static void SendBoardRotaryUp ( void )
{
    Comm_RotaryUp ();
}

static void SendBoardRotaryDown ( void )
{
    Comm_RotaryDown ();
}

void Board_Init ()
{
    // Initialize Board communication interface
    Comm_Init ();

    // Initialize MMI interfaces

    // Set Status LEDs to ready

    // send "ready" state to master board
    SendBoardStateOK ();

    // Enable global interrupts
    Interrupts ( GINT_ON );
}

void Application_run ()
{
    // check if data from master board were received
    GetUARTData ();

    // check internal voltages

    // check for push buttons

    // check for rotary
}