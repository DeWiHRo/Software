#include <MMI_application.h>

int main()
{
    Board_Init ();

    while (1)
        Application_run ();

    return 0;
}