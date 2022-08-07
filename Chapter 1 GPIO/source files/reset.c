/*****************************************************************************
 reset.c

 Copyright (C) 2016 LAPIS Semiconductor Co., LTD.
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
    2016.08.05 ver 1.00
	
******************************************************************************/
/**
 * @file    reset.c
 *
 * This module is 'RESET' drivers.
 *
 */
#include <ml621367.h>

#include "rdwr_reg.h"
#include "reset.h"

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
 * Called by BRK command reset
 *
 * @param       -
 * @return      None
 * @note        This function is called without clearing reset status.                        <br>
 *              Please clear reset status if needed.                                          <br>
 *              And add code to system reset mode.
 */
void reset_detBrkr( void ) {
	
}


/**
 * Called by RESET_N pin reset

 *
 * @param       -
 * @return      None
 * @note        This function is called without clearing reset status.                        <br>
 *              Please clear reset status if needed.                                          <br>
 *              And add code to system reset mode.
 */
void reset_detRstr( void ) {

}


/**
 * Called by Voltage level supervisor(VLS0) reset
 *
 * @param       -
 * @return      None
 * @note        This function is called without clearing reset status.                        <br>
 *              Please clear reset status if needed.                                          <br>
 *              And add code to system reset mode.
 */
void reset_detVls0r( void ) {

}


/**
 * Called by Watchdog timer window reset
 *
 * @param       -
 * @return      None
 * @note        This function is called without clearing reset status.                        <br>
 *              Please clear reset status if needed.                                          <br>
 *              And add code to system reset mode.
 */
void reset_detWdtwr( void ) {
	
}


/**
 * Called by Watchdog timer reset
 *
 * @param       -
 * @return      None
 * @note        This function is called without clearing reset status.                        <br>
 *              Please clear reset status if needed.                                          <br>
 *              And add code to system reset mode.
 */
void reset_detWdtr( void ) {
	
}


/**
 * Called by Power-on reset
 *
 * @param       -
 * @return      None
 * @note        This function is called after reset status are cleared.                       <br>
 *              Add code to system reset mode.
 */
void reset_detPor( void ) {
	
}


/**
 * Called by RAM parity-error reset
 *
 * @param       -
 * @return      None
 * @note        This function is called without clearing safety function reset status.                        <br>
 *              Please clear safety function reset status if needed.                                          <br>
 *              And add code to system reset mode.
 */
void reset_detRper( void ) {

}


/**
 * Called by Invalid memory access reset
 *
 * @param       -
 * @return      None
 * @note        This function is called without clearing safety function reset status.                        <br>
 *              Please clear safety function reset status if needed.                                          <br>
 *              And add code to system reset mode.
 */
void reset_detFiar( void ) {

}
