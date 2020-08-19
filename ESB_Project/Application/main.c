#include "typedefs.h"
#include "../MCAL/DIO/DIO_Driver.h"
#include "../ECUAL/LED/LED_Driver.h"
#include "../ECUAL/BTN/BTN_Driver.h"
#include <util/delay.h>

/* Guidelines for modules/drivers in general:

1. First thing to do is to setup the control registers --> init()
** By default, all the DDR bits are 0, meaning that all bits are in input mode

2. Write on the data registers using the PORT register
*OR* Read from the status registers using PIN register
*/

int main(void)
{

    LED_init(A1, LOW);
    LED_init(A2, LOW);
    LED_init(A3, HIGH); // For testing purposes, unused
    LED_init(A4, LOW); // For testing purposes, unused
    BTN_init(C0); // It doesn't make sense to set an initial state for a button input.
    
    while (1)
    {
        // Test 1: Synchronizing LED with button push
        if (BTN_read(C0))
            LED_setState(A1, HIGH);
        else
            LED_setState(A1, LOW);
            
        // Test 2: Can one LED be toggled to flicker at 256ms rate based on the state of another LED?
        if (LED_read(A1))
        {
            LED_toggle(A2);
            _delay_ms(256);
        }
        else
            LED_setState(A2, LOW);
    }
    
    return 0;
}

