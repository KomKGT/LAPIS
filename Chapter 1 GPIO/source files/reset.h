/*****************************************************************************
 reset.h

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
 * @file    reset.h
 *
 * This file is API definition for 'RESET' drivers.
 *
 */

#ifndef _RESET_H_
#define _RESET_H_

#include "rdwr_reg.h"
#include "reset_common.h"

/*############################################################################*/
/*#                                  API                                     #*/
/*############################################################################*/
/**
 * Reading reset status
 *
 * @param       -
 * @return      A 8bit reset status data                                           <br>
 *              (Values of RSTAT register)                                         <br>
 *                      RESET_RSTAT_BRKR  : BRK command reset                      <br>
 *                      RESET_RSTAT_INITE : LSI boot up error                      <br>
 *                      RESET_RSTAT_RSTR  : RESET-N pin reset                      <br>
 *                      RESET_RSTAT_VLS0R : Voltage level supervisor(VLS0) reset   <br>  
 *                      RESET_RSTAT_WDTWR : Watchdog timer window reset            <br>  
 *                      RESET_RSTAT_WDTR  : Watchdog timer reset                   <br>  
 *                      RESET_RSTAT_POR   : Power-on reset                         <br>  
 * @note        In system reset mode, the contents of SFR whose initial value is undefined are not initialized and are undefined.      <br>
 *              Initialize them by software.                                                                                           <br>
 *              The system reset mode by BRK instruction performs endless loop of a startup.  
 */
#define         reset_getRStat()                read_reg16( RSTAT )


/**
 * Clear reset status
 *
 * @param       -
 * @return      None
 */
#define         reset_clrRStat()                write_reg16( RSTAT, 0x015D )


/**
 * Clear BRKR status
 *
 * @param       -
 * @return      None
 */
#define         reset_clrBrkr()                 write_reg16( RSTAT, 0x0100 )


/**
 * Clear RSTR status
 *
 * @param       -
 * @return      None
 */
#define         reset_clrRstr()                 write_reg16( RSTAT, 0x0040 )


/**
 * Clear VLS0R status
 *
 * @param       -
 * @return      None
 */
#define         reset_clrVls0r()                 write_reg16( RSTAT, 0x0010 )


/**
 * Clear WDTWR status
 *
 * @param       -
 * @return      None
 */
#define         reset_clrWdtwr()                 write_reg16( RSTAT, 0x0008 )


/**
 * Clear WDTR status
 *
 * @param       -
 * @return      None
 */
#define         reset_clrWdtr()                 write_reg16( RSTAT, 0x0004 )


/**
 * Clear POR status
 *
 * @param       -
 * @return      None
 */
#define         reset_clrPor()                 write_reg16( RSTAT, 0x0001 )


/**
 * Reading safety function reset status
 *
 * @param       -
 * @return      A 8bit safety function reset status data                           <br>
 *              (A value of SRSTAT register)                                       <br>
 *                      RESET_SRSTAT_FIAR : Invalid memory access reset            <br>  
 *                      RESET_SRSTAT_RPER : RAM parity-error reset
 * @note        In system reset mode, the contents of SFR whose initial value is undefined are not initialized and are undefined.      <br>
 *              Initialize them by software.
 */
#define         reset_getSrStat()               read_reg8( SRSTAT )
	
	
/**
 * Clear safety function reset status
 *
 * @param       -
 * @return      None
 */
#define         reset_clrSrStat()               write_reg8( SRSTAT, 0x03 )


/**
 * Clear RPER status
 *
 * @param       -
 * @return      None
 */
#define         reset_clrRper()                 write_reg8( SRSTAT, 0x02 )


/**
 * Clear FIAR status
 *
 * @param       -
 * @return      None
 */
#define         reset_clrFiar()                 write_reg8( SRSTAT, 0x01 )



void reset_detBrkr( void );
void reset_detRstr( void );
void reset_detVls0r( void );
void reset_detWdtwr( void );
void reset_detWdtr( void );
void reset_detPor( void );
void reset_detRper( void );
void reset_detFiar( void );

#endif /*_RESET_H_*/
