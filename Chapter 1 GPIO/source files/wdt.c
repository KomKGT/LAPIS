/*****************************************************************************
 wdt.c

******************************************************************************/
/**
 * @file    wdt.c
 *
 * This module is WDT(Watch Dog Timer) drivers.
 *
 */
#include <ml621367.h>

#include "wdt.h"

/*############################################################################*/
/*#                                  Macro                                   #*/
/*############################################################################*/

/*############################################################################*/
/*#                                Variable                                  #*/
/*############################################################################*/

/*############################################################################*/
/*#                               Prototype                                  #*/
/*############################################################################*/

/*############################################################################*/
/*#                                  API                                     #*/
/*############################################################################*/

/**
 * Initialize WDT
 *
 * @param[in]   window  Window open period
 *                      WDT_WINDOW_100, WDT_WINDOW_75, WDT_WINDOW_50 
 * @param[in]   wdtmod  Overflow period
 * @arg                 WDT_8MS, WDT_16MS, WDT_32MS, WDT_64MS, WDT_128MS, WDT_512MS, WDT_2S, WDT_8S
 * @return      None
 * 
 * @note
 *   In the case of the overflow period of less than 128ms, a window open period becomes 100%.
 *   In the case of RC1K of WDT clock, please do not use WDT_WINDOW_75 and WDT_WINDOW_50.  
 *    
 */
void wdt_init( unsigned char window, unsigned char period )
{
    wdt_clear();
    while(wdt_getWdtClr1() == 1) {};
    while(wdt_getWdtClr2() == 1) {};
    write_reg8( WDTMOD, (( window << 4 ) | period) );
}


/**
 * Clear WDT
 *
 * @param       -
 * @return      None
 */
void wdt_clear( void )
{
    if(wdt_getWdtClr1() == 1) {
        return;
    };

    if(wdt_getWdtClr2() == 1) {
        return;
    };

	__DI();
	do {
		write_reg8( WDTCON, 0x5A );
	} while ( get_bit( WDP ) != 1 ); 
	write_reg8( WDTCON, 0xA5 );
	__EI();
}


