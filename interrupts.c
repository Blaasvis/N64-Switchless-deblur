/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

#define _XTAL_FREQ 4000000

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include <eeprom_routines.h>
/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

/* Baseline devices don't have interrupts. Unfortunately the baseline detection 
 * macro is named _PIC12 */

#ifndef _PIC12

void interrupt isr(void) {
    // wait a bit since it might be a reset
    __delay_ms(2000);
    // check the interupt flag fist.
    if (INTF == 1) {
        // if it is high again go do a reset
        if (GPIO2 == 1) {
            // debounce 
            __delay_ms(100);
            if (GPIO2 == 1) {
                // reset low voor 600ms
                TRISIO5 = 0;
                GPIObits.GPIO5 = 0;
                __delay_ms(600);
                GPIObits.GPIO5 = 1;
                TRISIO5 = 1;
                INTF = 0; // Reset the external interrupt flag
                return;
            }
        }
        // well still low.
        if (GPIO2 == 0) {
            __delay_ms(100);
            // cycle until the reset button has been lifted.
            while (GPIO2 == 0) {
                // check the pin since this controls the blur filter.
                if (GPIObits.GPIO4) {
                    GPIObits.GPIO0 = 1; // set to high
                    GPIObits.GPIO1 = 0; // set to high
                    GPIObits.GPIO4 = 0;
                } else {
                    GPIObits.GPIO0 = 0; // set to high
                    GPIObits.GPIO1 = 1; // set to high
                    GPIObits.GPIO4 = 1;
                }
                //a few sec of waiting till next cycle
                __delay_ms(5000);
            }
            INTF = 0; // Reset the external interrupt flag
            // SAVE it !!!!
            EEPROM_WRITE(1, GP4);
        }
    }
}
#endif


