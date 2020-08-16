#include "typedefs.h"
#include "DIO_driver.h"
#include <util/delay.h>

/* Guidelines for modules/drivers in general:

1. First thing to do is to setup the control registers --> init()
** By default, all the DDR bits are 0, meaning that all bits are in input mode

2. Write on the data registers using the PORT register
*OR* Read from the status registers using PIN register

*/

int main(void)
{
    ////////////////////////////////////////////////////////////////////////// STARTUP SEQUENCE
    _delay_ms(512);
    EN_DIO_config_t config;
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++)
        {
            _delay_ms(32);
            config[i][j] = output;
            DIO_init(config);
        }
        
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++)
        {
            _delay_ms(32);
            DIO_write(i, j, HIGH);
        }
        
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++)
        {
            _delay_ms(32);
            DIO_write(i, j, LOW);
        }
        
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++)
        {
            _delay_ms(32);
            config[i][j] = input;
            DIO_init(config);
        }
        
    _delay_ms(512);
    ////////////////////////////////////////////////////////////////////// STARTUP SEQUENCE END
    
    config[0][1] = output; // This expression means: for port 0 (aka port A), set pin '1' as output.
    config[0][2] = output; // PA2 ==> Output
    DIO_init(config);
    
    while (1)
    {
        // Test 1: Synchronizing LED with button push
        
        if (DIO_read(2, 0)) // This expression means: read from port 2 (C) the pin '0', if HIGH...
            DIO_write(0, 1, HIGH); // Set port 0's pin 1 as HIGH.
        else
            DIO_write(0, 1, LOW); // Otherwise, set it to LOW.
            
        // Test 2: Can one LED be toggled to flicker at 256ms rate based on the state of another LED?
        if (DIO_read(0, 1))
        {
            DIO_toggle(0, 2);
            _delay_ms(256);
        }
        else
            DIO_write(0, 2, LOW);
    }
    
    return 0;
}

