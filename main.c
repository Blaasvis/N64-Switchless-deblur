// -----------------------------------------------------------------------
//   N64 'Overclock-Mod Multiplier Selector'
//
//   Copyright (C) 2016 by Arjan Timmerman <arjan_at_soulfly.nl>
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; version 2 of the License only.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program; if not, write to the Free Software
//   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// -----------------------------------------------------------------------
//
//   This program is designed to run on a PIC 12F629 microcontroller connected
//   to the PIF-NUS (Lockoutchip) of the N64. It allows you to select the
//   multiplier of the CPU via the reset button.
//
//   pin configuration: [PIF NUS / CPU]
//                              ,------_-----.
//    Vcc/3.3V [p1 N64RGB]      |1          8| Vss/GND [p2 N64RGB] 
//    Reset out [PIF-NUS Pad 27]|2  GP5 GP0 7| LED-color 0 out
//    RGB Blur [Altera P100]    |3  GP4 GP1 6| LED-color 1 out
//    GND                       |4  GP3 GP2 5| Reset in [PIF-NUS Pad 27]
//                              `------------'
//
//   As the internal oscillator is used, you should connect a capacitor of about 100nF between
//   Pin 1 (Vcc/+3.3V) and Pin 8 (Vss/GND) as close as possible to the PIC. This esures best
//   operation.
// -----------------------------------------------------------------------

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif
// 4 mhz
#define _XTAL_FREQ 4000000

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */
/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
void main(void)
{
    /* Initialize I/O and Peripherals for application */
    InitApp();
    while(1)
    {
        // we just wait for any interrupt, since it save power better for mother earth ;)
        SLEEP();
    }
}

