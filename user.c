/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"
#define _XTAL_FREQ 4000000

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void) {
    CMCON = 0x07;// disable comparator.
    OPTION_REGbits.nGPPU = 0;  // pull up
    WPU2 = 0b1; // pull up on pin2 
    TRISIO = 0; // all low
    TRISIO2 = 0b1;// pin 2 is the reset out set to high else console will reset. 
	OSCCAL	= 0x3ff; // oscal value.
    GPIO5 = 1; // set to input ala reset in
    INTF = 0; // Reset the external interrupt flag
    INTE = 1; // Enable external interrupts from GP2
    INTEDG = 0; // falling edge on reset in.
    GIE = 1; // enable global interrupts
    
    // read the eeprom to set last mode
    if (EEPROM_READ(1) == 0) {
        GPIO0 = 1; // set to high
        GPIO1 = 0; // set to high
        GPIO4 = 0;
    } else {
        GPIO0 = 0; // set to high
        GPIO1 = 1; // set to high
        GPIO4 = 1;
    }
}

