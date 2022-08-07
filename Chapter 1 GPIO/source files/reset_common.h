/*****************************************************************************
 reset_common.h

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
 * @file    reset_common.h
 *
 * This file is common definition for 'RESET' drivers.
 *
 */
#ifndef _RESET_COMMON_H_
#define _RESET_COMMON_H_

/*############################################################################*/
/*#                                  Macro                                   #*/
/*############################################################################*/
/*=== bit field of registers ===*/
/* RSTAT */
#define RESET_RSTAT_BRKR       ( 0x0100 )              /**< RSTAT Register BRKR bit                             */
#define RESET_RSTAT_INITE      ( 0x0080 )              /**< RSTAT Register INITE bit                            */
#define RESET_RSTAT_RSTR       ( 0x0040 )              /**< RSTAT Register RSTR bit                             */
#define RESET_RSTAT_VLS0R      ( 0x0010 )              /**< RSTAT Register VLS0R bit                            */
#define RESET_RSTAT_WDTWR      ( 0x0008 )              /**< RSTAT Register WDTWR bit                            */
#define RESET_RSTAT_WDTR       ( 0x0004 )              /**< RSTAT Register WDTR bit                             */
#define RESET_RSTAT_POR        ( 0x0001 )              /**< RSTAT Register POR bit                              */

/* SRSTAT */
#define RESET_SRSTAT_RPER       ( 0x02 )               /**< SRSTAT Register RPER bit                            */
#define RESET_SRSTAT_FIAR       ( 0x01 )               /**< SRSTAT Register FIAR bit                            */

#endif /*_RESET_COMMON_H_*/
