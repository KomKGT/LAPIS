/*****************************************************************************
 wdt.h

 Copyright (C) 2016-2017 LAPIS Semiconductor Co., LTD.
 All rights reserved.

 This software is provided "as is" and any expressed or implied
  warranties, including, but not limited to, the implied warranties of
  merchantability and fitness for a particular purpose are disclaimed.
 LAPIS SEMICONDUCTOR shall not be liable for any direct, indirect,
 consequential or incidental damages arising from using or modifying
 this software.
 You (customer) can modify and use this software in whole or part on
 your own responsibility, only for the purpose of developing the software
 for use with microcontroller manufactured by LAPIS SEMICONDUCTOR.

 History
    2016.07.27 ver 1.00
	2017.01.16 ver 1.10 - Overflow period updated
******************************************************************************/
/**
 * @file    wdt.h
 *
 * This file is API definition for 'WDT(Watch Dog Timer)' drivers.
 *
 */
#ifndef _WDT_H_
#define _WDT_H_

#include "rdwr_reg.h"

/*############################################################################*/
/*#                                  Macro                                   #*/
/*############################################################################*/

/*=== API parameters value ===*/
#define WDT_WINDOW_100 ( 0x00 )    /**< Window open period : 100%   */
#define WDT_WINDOW_75  ( 0x01 )    /**< Window open period :  75%   */
#define WDT_WINDOW_50  ( 0x02 )    /**< Window open period :  50%   */

#define WDT_8MS        ( 0x00 )    /**< Overflow period : 7.8ms       */
#define WDT_16MS       ( 0x01 )    /**< Overflow period : 15.6ms      */
#define WDT_31MS       ( 0x02 )    /**< Overflow period : 31.3ms      */
#define WDT_63MS       ( 0x03 )    /**< Overflow period : 62.5ms      */
#define WDT_125MS      ( 0x04 )    /**< Overflow period : 125ms     */
#define WDT_500MS      ( 0x05 )    /**< Overflow period : 500ms     */
#define WDT_2S         ( 0x06 )    /**< Overflow period : 2s    */
#define WDT_8S         ( 0x07 )    /**< Overflow period : 8s    */

/*############################################################################*/
/*#                                  API                                     #*/
/*############################################################################*/

/**
 * Get WDT counter (16-bit)
 *
 * @param       -
 * @return      WDT counter
 */
#define wdt_getCnt()        read_reg16( WDTMC )

/**
 * Get WDT window status
 *
 * @param       -
 * @return      0:Window close
 * @return      1:Window open
 */
#define wdt_getWdtWin()     get_bit( WDTWIN )

/**
 * Get WDT clear wait status
 *
 * @param       -
 * @return      0:Clear no wait
 * @return      1:Clear wait
 */
#define wdt_getWdtClr1()     get_bit( WDTCLR1 )

/**
 * Get WDT clear status
 *
 * @param       -
 * @return      0:Complete clear
 * @return      1:Execute clear
 */
#define wdt_getWdtClr2()     get_bit( WDTCLR2 )

void wdt_init( unsigned char window, unsigned char period );
void    wdt_clear( void );

#endif /*_WDT_H_*/

