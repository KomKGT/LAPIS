/*****************************************************************************
 irq.h

 Copyright (C) 2017 LAPIS Semiconductor Co., LTD.
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
    2016.07.28 ver 1.00
	2017.06.10 ver 1.10 - Support ML62Q14XX and ML62Q16XX

******************************************************************************/
/**
 * @file    irq.h
 *
 * This file is API definition for interrupt drivers.
 *
 */
#ifndef _IRQ_H_
#define _IRQ_H_

#include "rdwr_reg.h"

/*############################################################################*/
/*#                                  Macro                                   #*/
/*############################################################################*/
/*=== Priority Level ===*/
#define IRQ_PRIORITY_LEVEL_1            ( 0 )                   /**< Interrupt priority level 1 */
#define IRQ_PRIORITY_LEVEL_2            ( 1 )                   /**< Interrupt priority level 2 */
#define IRQ_PRIORITY_LEVEL_3            ( 2 )                   /**< Interrupt priority level 3 */
#define IRQ_PRIORITY_LEVEL_4            ( 3 )                   /**< Interrupt priority level 4 */

/*=== bit number of registers ===*/
/* ILCn */
#define ILCn_VLS0_BIT_NO                ( 12 - 8 )              /**< ILCn Register VLS0 bit No.     */
#define ILCn_EXI7_BIT_NO                ( 14 - 8 )              /**< ILCn Register EXI7 bit No.     */
#define ILCn_EXI6_BIT_NO                ( 12 - 8 )              /**< ILCn Register EXI6 bit No.     */
#define ILCn_EXI5_BIT_NO                ( 10 - 8 )              /**< ILCn Register EXI5 bit No.     */
#define ILCn_EXI4_BIT_NO                ( 8 - 8 )               /**< ILCn Register EXI4 bit No.     */
#define ILCn_EXI3_BIT_NO                ( 6 )                   /**< ILCn Register EXI3 bit No.     */
#define ILCn_EXI2_BIT_NO                ( 4 )                   /**< ILCn Register EXI2 bit No.     */
#define ILCn_EXI1_BIT_NO                ( 2 )                   /**< ILCn Register EXI1 bit No.     */
#define ILCn_EXI0_BIT_NO                ( 0 )                   /**< ILCn Register EXI0 bit No.     */
#define ILCn_SAD_BIT_NO                 ( 12 - 8 )              /**< ILCn Register SADINT bit No.   */
#define ILCn_SIU01_BIT_NO               ( 8 - 8 )               /**< ILCn Register SIU01INT bit No. */
#define ILCn_SIU00_BIT_NO               ( 6 )                   /**< ILCn Register SIU00INT bit No. */
#define ILCn_DMAC_BIT_NO                ( 2 )                   /**< ILCn Register DMACINT bit No.  */
#define ILCn_TM1_BIT_NO                 ( 14 - 8 )              /**< ILCn Register TM1INT bit No.   */
#define ILCn_TM0_BIT_NO                 ( 12 - 8 )              /**< ILCn Register TM0INT bit No.   */
#define ILCn_FTM1_BIT_NO                ( 10 - 8 )              /**< ILCn Register FTM1INT bit No.  */
#define ILCn_FTM0_BIT_NO                ( 8 - 8 )               /**< ILCn Register FTM0INT bit No.  */
#define ILCn_I2CM0_BIT_NO               ( 4 )                   /**< ILCn Register I2CM0INT bit No. */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define ILCn_I2CM1_BIT_NO               ( 6 )                   /**< ILCn Register I2CM1INT bit No. */
  #endif
#define ILCn_TM3_BIT_NO                 ( 14 - 8 )              /**< ILCn Register TM3INT bit No.   */
#define ILCn_TM2_BIT_NO                 ( 12 - 8 )              /**< ILCn Register TM2INT bit No.   */
#define ILCn_FTM3_BIT_NO                ( 10 - 8 )              /**< ILCn Register FTM3INT bit No.  */
#define ILCn_FTM2_BIT_NO                ( 8 - 8 )               /**< ILCn Register FTM2INT bit No.  */
#define ILCn_SIU11_BIT_NO               ( 4 )                   /**< ILCn Register SIU11INT bit No. */
#define ILCn_SIU10_BIT_NO               ( 2 )                   /**< ILCn Register SIU10INT bit No. */
#define ILCn_I2CU0_BIT_NO               ( 0 )                   /**< ILCn Register I2CU0INT bit No. */
  #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN)
    #define ILCn_TM5_BIT_NO                 ( 14 - 8 )              /**< ILCn Register TM5INT bit No.   */
    #define ILCn_TM4_BIT_NO                 ( 12 - 8 )              /**< ILCn Register TM4INT bit No.   */
  #endif  /* #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN) */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define ILCn_FTM5_BIT_NO                 ( 10 - 8 )              /**< ILCn Register FTM5INT bit No.  */
    #define ILCn_FTM4_BIT_NO                 ( 8 - 8 )               /**< ILCn Register FTM4INT bit No.  */
  #endif
#define ILCn_CMP0_BIT_NO                ( 4 )                   /**< ILCn Register CMP0INT bit No.  */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define ILCn_CMP1_BIT_NO                 ( 6 )                   /**< ILCn Register CMP1INT bit No.  */
  #endif
#define ILCn_LTBC2_BIT_NO               ( 10 - 8 )              /**< ILCn Register LTB2INT bit No.   */
#define ILCn_LTBC1_BIT_NO               ( 8 - 8 )               /**< ILCn Register LTB1INT bit No.   */
#define ILCn_LTBC0_BIT_NO               ( 4 )                   /**< ILCn Register LTB0INT bit No.   */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define ILCn_RTC_BIT_NO                  ( 12 - 8 )              /**< ILCn Register RTCINT bit No.   */
  #endif
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)  
    #define ILCn_CBU_BIT_NO                  ( 0 )                   /**< ILCn Register CBUINT bit No.   */
  #endif
  
/*############################################################################*/
/*#                                  API                                     #*/
/*############################################################################*/
/*--- Enables interrupts ---*/
#define         irq_exi7_ena()          set_bit( EPI7 )        /**< Enables EXI7INT  */
#define         irq_exi6_ena()          set_bit( EPI6 )        /**< Enables EXI6INT  */
#define         irq_exi5_ena()          set_bit( EPI5 )        /**< Enables EXI5INT  */
#define         irq_exi4_ena()          set_bit( EPI4 )        /**< Enables EXI4INT  */
#define         irq_exi3_ena()          set_bit( EPI3 )        /**< Enables EXI3INT  */
#define         irq_exi2_ena()          set_bit( EPI2 )        /**< Enables EXI2INT  */
#define         irq_exi1_ena()          set_bit( EPI1 )        /**< Enables EXI1INT  */
#define         irq_exi0_ena()          set_bit( EPI0 )        /**< Enables EXI0INT  */
#define         irq_vls0_ena()          set_bit( EVLS0 )       /**< Enables VLS0INT  */
#define         irq_tm1_ena()           set_bit( ETM1 )        /**< Enables TM1INT   */
#define         irq_tm0_ena()           set_bit( ETM0 )        /**< Enables TM0INT   */
#define         irq_ftm1_ena()          set_bit( EFTM1 )       /**< Enables FTM1INT  */
#define         irq_ftm0_ena()          set_bit( EFTM0 )       /**< Enables FTM0INT  */
#define         irq_i2cm0_ena()         set_bit( EI2CM0 )      /**< Enables I2CM0INT */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_i2cm1_ena()         set_bit( EI2CM1 )      /**< Enables I2CM1INT */
  #endif
#define         irq_sad_ena()           set_bit( ESAD )        /**< Enables SADINT   */
#define         irq_siu01_ena()         set_bit( ESIU01 )      /**< Enables SIU01INT */
#define         irq_siu00_ena()         set_bit( ESIU00 )      /**< Enables SIU00INT */
#define         irq_dmac_ena()          set_bit( EDMA )        /**< Enables DMACINT  */
  #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN)
    #define         irq_tm5_ena()           set_bit( ETM5 )        /**< Enables TM5INT   */
    #define         irq_tm4_ena()           set_bit( ETM4 )        /**< Enables TM4INT   */
  #endif  /* #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN) */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_ftm5_ena()          set_bit( EFTM5 )       /**< Enables FTM5INT  */
    #define         irq_ftm4_ena()          set_bit( EFTM4 )       /**< Enables FTM4INT  */
  #endif
#define         irq_cmp0_ena()          set_bit( ECMP0 )       /**< Enables CMP0INT  */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_cmp1_ena()          set_bit( ECMP1 )       /**< Enables CMP1INT  */
  #endif
#define         irq_tm3_ena()           set_bit( ETM3 )        /**< Enables TM3INT   */
#define         irq_tm2_ena()           set_bit( ETM2 )        /**< Enables TM2INT   */
#define         irq_ftm3_ena()          set_bit( EFTM3 )       /**< Enables FTM3INT  */
#define         irq_ftm2_ena()          set_bit( EFTM2 )       /**< Enables FTM2INT  */
#define         irq_siu11_ena()         set_bit( ESIU11 )      /**< Enables SIU11INT */
#define         irq_siu10_ena()         set_bit( ESIU10 )      /**< Enables SIU10INT */
#define         irq_i2cu0_ena()         set_bit( EI2CU0 )      /**< Enables I2CU0INT */
#define         irq_ltbc2_ena()         set_bit( ELTBC2 )      /**< Enables LTB2INT  */
#define         irq_ltbc1_ena()         set_bit( ELTBC1 )      /**< Enables LTB1INT  */
#define         irq_ltbc0_ena()         set_bit( ELTBC0 )      /**< Enables LTB0INT  */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_rtc_ena()           set_bit( ERTC )        /**< Enables RTCINT   */
  #endif
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)  
    #define         irq_cbu_ena()           set_bit( ECBU )        /**< Enables CBUINT   */
  #endif
  
/*--- Disables interrupts  ---*/
#define         irq_exi7_dis()          clear_bit( EPI7 )        /**< Disables EXI7INT  */
#define         irq_exi6_dis()          clear_bit( EPI6 )        /**< Disables EXI6INT  */
#define         irq_exi5_dis()          clear_bit( EPI5 )        /**< Disables EXI5INT  */
#define         irq_exi4_dis()          clear_bit( EPI4 )        /**< Disables EXI4INT  */
#define         irq_exi3_dis()          clear_bit( EPI3 )        /**< Disables EXI3INT  */
#define         irq_exi2_dis()          clear_bit( EPI2 )        /**< Disables EXI2INT  */
#define         irq_exi1_dis()          clear_bit( EPI1 )        /**< Disables EXI1INT  */
#define         irq_exi0_dis()          clear_bit( EPI0 )        /**< Disables EXI0INT  */
#define         irq_vls0_dis()          clear_bit( EVLS0 )       /**< Disables VLS0INT  */
#define         irq_tm1_dis()           clear_bit( ETM1 )        /**< Disables TM1INT   */
#define         irq_tm0_dis()           clear_bit( ETM0 )        /**< Disables TM0INT   */
#define         irq_ftm1_dis()          clear_bit( EFTM1 )       /**< Disables FTM1INT  */
#define         irq_ftm0_dis()          clear_bit( EFTM0 )       /**< Disables FTM0INT  */
#define         irq_i2cm0_dis()         clear_bit( EI2CM0 )      /**< Disables I2CM0INT */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_i2cm1_dis()         clear_bit( EI2CM1 )      /**< Disables I2CM1INT */
  #endif
#define         irq_sad_dis()           clear_bit( ESAD )        /**< Disables SADINT   */
#define         irq_siu01_dis()         clear_bit( ESIU01 )      /**< Disables SIU01INT */
#define         irq_siu00_dis()         clear_bit( ESIU00 )      /**< Disables SIU00INT */
#define         irq_dmac_dis()          clear_bit( EDMA )        /**< Disables DMACINT  */
  #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN)
    #define         irq_tm5_dis()           clear_bit( ETM5 )        /**< Disables TM5INT   */
    #define         irq_tm4_dis()           clear_bit( ETM4 )        /**< Disables TM4INT   */
  #endif  /* #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN) */
    #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_ftm5_dis()          clear_bit( EFTM5 )       /**< Disables FTM5INT  */
    #define         irq_ftm4_dis()          clear_bit( EFTM4 )       /**< Disables FTM4INT  */
  #endif
#define         irq_cmp0_dis()          clear_bit( ECMP0 )       /**< Disables CMP0INT  */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_cmp1_dis()          clear_bit( ECMP1 )       /**< Disables CMP1INT  */
  #endif
#define         irq_tm3_dis()           clear_bit( ETM3 )        /**< Disables TM3INT   */
#define         irq_tm2_dis()           clear_bit( ETM2 )        /**< Disables TM2INT   */
#define         irq_ftm3_dis()          clear_bit( EFTM3 )       /**< Disables FTM3INT  */
#define         irq_ftm2_dis()          clear_bit( EFTM2 )       /**< Disables FTM2INT  */
#define         irq_siu11_dis()         clear_bit( ESIU11 )      /**< Disables SIU11INT */
#define         irq_siu10_dis()         clear_bit( ESIU10 )      /**< Disables SIU10INT */
#define         irq_i2cu0_dis()         clear_bit( EI2CU0 )      /**< Disables I2CU0INT */
#define         irq_ltbc2_dis()         clear_bit( ELTBC2 )      /**< Disables LTB2INT  */
#define         irq_ltbc1_dis()         clear_bit( ELTBC1 )      /**< Disables LTB1INT  */
#define         irq_ltbc0_dis()         clear_bit( ELTBC0 )      /**< Disables LTB0INT  */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_rtc_dis()           clear_bit( ERTC )        /**< Disables RTCINT   */
  #endif
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)  
    #define         irq_cbu_dis()           clear_bit( ECBU )        /**< Disables CBUINT   */
  #endif


/*--- Check IRQ ---*/
#define         irq_exi7_checkIRQ()          get_bit( QPI7 )        /**< Check EXI7INT  */
#define         irq_exi6_checkIRQ()          get_bit( QPI6 )        /**< Check EXI6INT  */
#define         irq_exi5_checkIRQ()          get_bit( QPI5 )        /**< Check EXI5INT  */
#define         irq_exi4_checkIRQ()          get_bit( QPI4 )        /**< Check EXI4INT  */
#define         irq_exi3_checkIRQ()          get_bit( QPI3 )        /**< Check EXI3INT  */
#define         irq_exi2_checkIRQ()          get_bit( QPI2 )        /**< Check EXI2INT  */
#define         irq_exi1_checkIRQ()          get_bit( QPI1 )        /**< Check EXI1INT  */
#define         irq_exi0_checkIRQ()          get_bit( QPI0 )        /**< Check EXI0INT  */
#define         irq_vls0_checkIRQ()          get_bit( QVLS0 )       /**< Check VLS0INT  */
#define         irq_wdt_checkIRQ()           get_bit( QWDT )        /**< Check WDTINT  */
#define         irq_tm1_checkIRQ()           get_bit( QTM1 )        /**< Check TM1INT   */
#define         irq_tm0_checkIRQ()           get_bit( QTM0 )        /**< Check TM0INT   */
#define         irq_ftm1_checkIRQ()          get_bit( QFTM1 )       /**< Check FTM1INT  */
#define         irq_ftm0_checkIRQ()          get_bit( QFTM0 )       /**< Check FTM0INT  */
#define         irq_i2cm0_checkIRQ()         get_bit( QI2CM0 )      /**< Check I2CM0INT */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_i2cm1_checkIRQ()         get_bit( QI2CM1 )      /**< Check I2CM1INT */
  #endif
#define         irq_sad_checkIRQ()           get_bit( QSAD )        /**< Check SADINT   */
#define         irq_siu01_checkIRQ()         get_bit( QSIU01 )      /**< Check SIU01INT */
#define         irq_siu00_checkIRQ()         get_bit( QSIU00 )      /**< Check SIU00INT */
#define         irq_dmac_checkIRQ()          get_bit( QDMA )        /**< Check DMACINT  */
  #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN)
    #define         irq_tm5_checkIRQ()           get_bit( QTM5 )        /**< Check TM5INT   */
    #define         irq_tm4_checkIRQ()           get_bit( QTM4 )        /**< Check TM4INT   */
  #endif  /* #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN) */
    #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_ftm5_checkIRQ()          get_bit( QFTM5 )       /**< Check FTM5INT  */
    #define         irq_ftm4_checkIRQ()          get_bit( QFTM4 )       /**< Check FTM4INT  */
  #endif
#define         irq_cmp0_checkIRQ()          get_bit( QCMP0 )       /**< Check CMP0INT  */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_cmp1_checkIRQ()          get_bit( QCMP1 )       /**< Check CMP1INT  */
  #endif
#define         irq_tm3_checkIRQ()           get_bit( QTM3 )        /**< Check TM3INT   */
#define         irq_tm2_checkIRQ()           get_bit( QTM2 )        /**< Check TM2INT   */
#define         irq_ftm3_checkIRQ()          get_bit( QFTM3 )       /**< Check FTM3INT  */
#define         irq_ftm2_checkIRQ()          get_bit( QFTM2 )       /**< Check FTM2INT  */
#define         irq_siu11_checkIRQ()         get_bit( QSIU11 )      /**< Check SIU11INT */
#define         irq_siu10_checkIRQ()         get_bit( QSIU10 )      /**< Check SIU10INT */
#define         irq_i2cu0_checkIRQ()         get_bit( QI2CU0 )      /**< Check I2CU0INT */
#define         irq_ltbc2_checkIRQ()         get_bit( QLTBC2 )      /**< Check LTB2INT  */
#define         irq_ltbc1_checkIRQ()         get_bit( QLTBC1 )      /**< Check LTB1INT  */
#define         irq_ltbc0_checkIRQ()         get_bit( QLTBC0 )      /**< Check LTB0INT  */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_rtc_checkIRQ()           get_bit( QRTC )        /**< Check RTCINT   */
  #endif
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)  
    #define         irq_cbu_checkIRQ()           get_bit( QCBU )        /**< Check CBUINT   */
  #endif
  
/*--- Clear IRQ ---*/
#define         irq_exi7_clearIRQ()          clear_bit( QPI7 )        /**< Clear EXI7INT  */
#define         irq_exi6_clearIRQ()          clear_bit( QPI6 )        /**< Clear EXI6INT  */
#define         irq_exi5_clearIRQ()          clear_bit( QPI5 )        /**< Clear EXI5INT  */
#define         irq_exi4_clearIRQ()          clear_bit( QPI4 )        /**< Clear EXI4INT  */
#define         irq_exi3_clearIRQ()          clear_bit( QPI3 )        /**< Clear EXI3INT  */
#define         irq_exi2_clearIRQ()          clear_bit( QPI2 )        /**< Clear EXI2INT  */
#define         irq_exi1_clearIRQ()          clear_bit( QPI1 )        /**< Clear EXI1INT  */
#define         irq_exi0_clearIRQ()          clear_bit( QPI0 )        /**< Clear EXI0INT  */
#define         irq_vls0_clearIRQ()          clear_bit( QVLS0 )       /**< Clear VLS0INT  */
#define         irq_wdt_clearIRQ()           clear_bit( QWDT )        /**< Clear WDTINT  */
#define         irq_tm1_clearIRQ()           clear_bit( QTM1 )        /**< Clear TM1INT   */
#define         irq_tm0_clearIRQ()           clear_bit( QTM0 )        /**< Clear TM0INT   */
#define         irq_ftm1_clearIRQ()          clear_bit( QFTM1 )       /**< Clear FTM1INT  */
#define         irq_ftm0_clearIRQ()          clear_bit( QFTM0 )       /**< Clear FTM0INT  */
#define         irq_i2cm0_clearIRQ()         clear_bit( QI2CM0 )      /**< Clear I2CM0INT */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_i2cm1_clearIRQ()         clear_bit( QI2CM1 )      /**< Clear I2CM1INT */
  #endif
#define         irq_sad_clearIRQ()           clear_bit( QSAD )        /**< Clear SADINT   */
#define         irq_siu01_clearIRQ()         clear_bit( QSIU01 )      /**< Clear SIU01INT */
#define         irq_siu00_clearIRQ()         clear_bit( QSIU00 )      /**< Clear SIU00INT */
#define         irq_dmac_clearIRQ()          clear_bit( QDMA )        /**< Clear DMACINT  */
  #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN)
    #define         irq_tm5_clearIRQ()           clear_bit( QTM5 )        /**< Clear TM5INT   */
    #define         irq_tm4_clearIRQ()           clear_bit( QTM4 )        /**< Clear TM4INT   */
  #endif  /* #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN) */
    #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_ftm5_clearIRQ()          clear_bit( QFTM5 )       /**< Clear FTM5INT  */
    #define         irq_ftm4_clearIRQ()          clear_bit( QFTM4 )       /**< Clear FTM4INT  */
  #endif
#define         irq_cmp0_clearIRQ()          clear_bit( QCMP0 )       /**< Clear CMP0INT  */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_cmp1_clearIRQ()          clear_bit( QCMP1 )       /**< Clear CMP1INT  */
  #endif
#define         irq_tm3_clearIRQ()           clear_bit( QTM3 )        /**< Clear TM3INT   */
#define         irq_tm2_clearIRQ()           clear_bit( QTM2 )        /**< Clear TM2INT   */
#define         irq_ftm3_clearIRQ()          clear_bit( QFTM3 )       /**< Clear FTM3INT  */
#define         irq_ftm2_clearIRQ()          clear_bit( QFTM2 )       /**< Clear FTM2INT  */
#define         irq_siu11_clearIRQ()         clear_bit( QSIU11 )      /**< Clear SIU11INT */
#define         irq_siu10_clearIRQ()         clear_bit( QSIU10 )      /**< Clear SIU10INT */
#define         irq_i2cu0_clearIRQ()         clear_bit( QI2CU0 )      /**< Clear I2CU0INT */
#define         irq_ltbc2_clearIRQ()         clear_bit( QLTBC2 )      /**< Clear LTB2INT  */
#define         irq_ltbc1_clearIRQ()         clear_bit( QLTBC1 )      /**< Clear LTB1INT  */
#define         irq_ltbc0_clearIRQ()         clear_bit( QLTBC0 )      /**< Clear LTB0INT  */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_rtc_clearIRQ()           clear_bit( QRTC )        /**< Clear RTCINT   */
  #endif
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)  
    #define         irq_cbu_clearIRQ()           clear_bit( QCBU )        /**< Clear CBUINT   */
  #endif
  
/*--- Set IRQ ---*/
#define         irq_exi7_setIRQ()          set_bit( QPI7 )        /**< Set EXI7INT  */
#define         irq_exi6_setIRQ()          set_bit( QPI6 )        /**< Set EXI6INT  */
#define         irq_exi5_setIRQ()          set_bit( QPI5 )        /**< Set EXI5INT  */
#define         irq_exi4_setIRQ()          set_bit( QPI4 )        /**< Set EXI4INT  */
#define         irq_exi3_setIRQ()          set_bit( QPI3 )        /**< Set EXI3INT  */
#define         irq_exi2_setIRQ()          set_bit( QPI2 )        /**< Set EXI2INT  */
#define         irq_exi1_setIRQ()          set_bit( QPI1 )        /**< Set EXI1INT  */
#define         irq_exi0_setIRQ()          set_bit( QPI0 )        /**< Set EXI0INT  */
#define         irq_vls0_setIRQ()          set_bit( QVLS0 )       /**< Set VLS0INT  */
#define         irq_wdt_setIRQ()           set_bit( QWDT )        /**< Set WDTINT  */
#define         irq_tm1_setIRQ()           set_bit( QTM1 )        /**< Set TM1INT   */
#define         irq_tm0_setIRQ()           set_bit( QTM0 )        /**< Set TM0INT   */
#define         irq_ftm1_setIRQ()          set_bit( QFTM1 )       /**< Set FTM1INT  */
#define         irq_ftm0_setIRQ()          set_bit( QFTM0 )       /**< Set FTM0INT  */
#define         irq_i2cm0_setIRQ()         set_bit( QI2CM0 )      /**< Set I2CM0INT */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_i2cm1_setIRQ()         set_bit( QI2CM1 )      /**< Set I2CM1INT */
  #endif
#define         irq_sad_setIRQ()           set_bit( QSAD )        /**< Set SADINT   */
#define         irq_siu01_setIRQ()         set_bit( QSIU01 )      /**< Set SIU01INT */
#define         irq_siu00_setIRQ()         set_bit( QSIU00 )      /**< Set SIU00INT */
#define         irq_dmac_setIRQ()          set_bit( QDMA )        /**< Set DMACINT  */
  #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN)
    #define         irq_tm5_setIRQ()           set_bit( QTM5 )        /**< Set TM5INT   */
    #define         irq_tm4_setIRQ()           set_bit( QTM4 )        /**< Set TM4INT   */
  #endif  /* #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN) */
    #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_ftm5_setIRQ()          set_bit( QFTM5 )       /**< Set FTM5INT  */
    #define         irq_ftm4_setIRQ()          set_bit( QFTM4 )       /**< Set FTM4INT  */
  #endif
#define         irq_cmp0_setIRQ()          set_bit( QCMP0 )       /**< Set CMP0INT  */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_cmp1_setIRQ()          set_bit( QCMP1 )       /**< Set CMP1INT  */
  #endif
#define         irq_tm3_setIRQ()           set_bit( QTM3 )        /**< Set TM3INT   */
#define         irq_tm2_setIRQ()           set_bit( QTM2 )        /**< Set TM2INT   */
#define         irq_ftm3_setIRQ()          set_bit( QFTM3 )       /**< Set FTM3INT  */
#define         irq_ftm2_setIRQ()          set_bit( QFTM2 )       /**< Set FTM2INT  */
#define         irq_siu11_setIRQ()         set_bit( QSIU11 )      /**< Set SIU11INT */
#define         irq_siu10_setIRQ()         set_bit( QSIU10 )      /**< Set SIU10INT */
#define         irq_i2cu0_setIRQ()         set_bit( QI2CU0 )      /**< Set I2CU0INT */
#define         irq_ltbc2_setIRQ()         set_bit( QLTBC2 )      /**< Set LTB2INT  */
#define         irq_ltbc1_setIRQ()         set_bit( QLTBC1 )      /**< Set LTB1INT  */
#define         irq_ltbc0_setIRQ()         set_bit( QLTBC0 )      /**< Set LTB0INT  */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    #define         irq_rtc_setIRQ()           set_bit( QRTC )        /**< Set RTCINT   */
  #endif
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)  
    #define         irq_cbu_setIRQ()           set_bit( QCBU )        /**< Set CBUINT   */
  #endif


/*--- Control interrupts priority level ---*/
/**
 * Enables interrupts priority level control
 *
 * @param   -
 * @return  None
 */
#define         irq_enaPriorityCtrl()      set_bit( ILE )

/**
 * Disables interrupts priority level control
 *
 * @param   -
 * @return  None
 */
#define         irq_disPriorityCtrl()      clear_bit( ILE )

/**
 * Get executing interrupts priority level
 *
 * @param   -
 * @return  The state of executing interrupts priority level
 *          (The value of CIL register)
 */
#define         irq_getPriorityState()     read_reg8( CIL )

/**
 * Clear executing interrupts priority level
 *
 * @param   -
 * @return  None
 * @note    If interrupts priority level control is enabled,
 *          You must call this macro in end of ALL interrupts handler.
 */
#define         irq_clearTopPriorityState()   write_reg8( CIL, 0 )

/**
 * Setting interrupts priority level
 *
 * @param   symbol     interrupt register
 * @param   bit        bit number
 * @param   level      interrupt level
 * @return  None
 */
#define         irq_common_setPriority( symbol, bit, level )    do {                                                                    \
                                                                    /* Setting register */                                              \
                                                                    clear_reg8( (symbol), (unsigned char)(0x3 << (bit)) );              \
                                                                    set_reg8( (symbol), (unsigned char)(((level) & 0x3) << (bit)) );    \
                                                                } while(0)

/**
 * Setting interrupt priority level (VLS0INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after VLS0INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_vls0_setPriority( level )                      irq_common_setPriority( ILC01, ILCn_VLS0_BIT_NO, level )

/**
 * Setting interrupt priority level (EXI7INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after EXI7INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_exi7_setPriority( level )                      irq_common_setPriority( ILC11, ILCn_EXI7_BIT_NO, level )

/**
 * Setting interrupt priority level (EXI6INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after EXI6INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_exi6_setPriority( level )                      irq_common_setPriority( ILC11, ILCn_EXI6_BIT_NO, level )

/**
 * Setting interrupt priority level (EXI5INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after EXI5INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_exi5_setPriority( level )                      irq_common_setPriority( ILC11, ILCn_EXI5_BIT_NO, level )

/**
 * Setting interrupt priority level (EXI4INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after EXI4INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_exi4_setPriority( level )                      irq_common_setPriority( ILC11, ILCn_EXI4_BIT_NO, level )

/**
 * Setting interrupt priority level (EXI3INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after EXI3INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_exi3_setPriority( level )                      irq_common_setPriority( ILC10, ILCn_EXI3_BIT_NO, level )

/**
 * Setting interrupt priority level (EXI2INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after EXI2INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_exi2_setPriority( level )                      irq_common_setPriority( ILC10, ILCn_EXI2_BIT_NO, level )

/**
 * Setting interrupt priority level (EXI1INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after EXI1INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_exi1_setPriority( level )                      irq_common_setPriority( ILC10, ILCn_EXI1_BIT_NO, level )

/**
 * Setting interrupt priority level (EXI0INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after EXI0INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_exi0_setPriority( level )                      irq_common_setPriority( ILC10, ILCn_EXI0_BIT_NO, level )

/**
 * Setting interrupt priority level (SADINT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after SADINT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_sad_setPriority( level )                      irq_common_setPriority( ILC21, ILCn_SAD_BIT_NO, level )

/**
 * Setting interrupt priority level (SIU01INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after SIU01INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_siu01_setPriority( level )                    irq_common_setPriority( ILC21, ILCn_SIU01_BIT_NO, level )

/**
 * Setting interrupt priority level (SIU00INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after SIU00INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_siu00_setPriority( level )                    irq_common_setPriority( ILC20, ILCn_SIU00_BIT_NO, level )

/**
 * Setting interrupt priority level (DMACINT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after DMACINT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_dmac_setPriority( level )                    irq_common_setPriority( ILC20, ILCn_DMAC_BIT_NO, level )

/**
 * Setting interrupt priority level (TM1INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after TM1INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_tm1_setPriority( level )                    irq_common_setPriority( ILC31, ILCn_TM1_BIT_NO, level )

/**
 * Setting interrupt priority level (TM0INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after TM0INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_tm0_setPriority( level )                    irq_common_setPriority( ILC31, ILCn_TM0_BIT_NO, level )

/**
 * Setting interrupt priority level (FTM1INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after FTM1INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_ftm1_setPriority( level )                    irq_common_setPriority( ILC31, ILCn_FTM1_BIT_NO, level )

/**
 * Setting interrupt priority level (FTM0INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after FTM0INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_ftm0_setPriority( level )                    irq_common_setPriority( ILC31, ILCn_FTM0_BIT_NO, level )

/**
 * Setting interrupt priority level (I2CM0INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after I2CM0INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_i2cm0_setPriority( level )                   irq_common_setPriority( ILC30, ILCn_I2CM0_BIT_NO, level )

  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    /**
     * Setting interrupt priority level (I2CM1INT)
     *
     * @param[in]   level   Setting value of interrupt priority level <br>
     *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
     * @return      None
     *
     * @note    Don't call this macro, after I2CM0INT enabled.
     * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
     */
    #define         irq_i2cm1_setPriority( level )                   irq_common_setPriority( ILC30, ILCn_I2CM1_BIT_NO, level )
  #endif

/**
 * Setting interrupt priority level (TM3INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after TM3INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_tm3_setPriority( level )                    irq_common_setPriority( ILC41, ILCn_TM3_BIT_NO, level )

/**
 * Setting interrupt priority level (TM2INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after TM2INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_tm2_setPriority( level )                    irq_common_setPriority( ILC41, ILCn_TM2_BIT_NO, level )

/**
 * Setting interrupt priority level (FTM3INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after FTM3INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_ftm3_setPriority( level )                    irq_common_setPriority( ILC41, ILCn_FTM3_BIT_NO, level )

/**
 * Setting interrupt priority level (FTM2INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after FTM2INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_ftm2_setPriority( level )                    irq_common_setPriority( ILC41, ILCn_FTM2_BIT_NO, level )

/**
 * Setting interrupt priority level (SIU11INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after SIU11INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_siu11_setPriority( level )                  irq_common_setPriority( ILC40, ILCn_SIU11_BIT_NO, level )

/**
 * Setting interrupt priority level (SIU10INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after SIU10INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_siu10_setPriority( level )                  irq_common_setPriority( ILC40, ILCn_SIU10_BIT_NO, level )

/**
 * Setting interrupt priority level (I2CU0INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after I2CU0INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_i2cu0_setPriority( level )                  irq_common_setPriority( ILC40, ILCn_I2CU0_BIT_NO, level )

  #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN)
    /**
     * Setting interrupt priority level (TM5INT)
     *
     * @param[in]   level   Setting value of interrupt priority level <br>
     *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
     * @return      None
     *
     * @note    Don't call this macro, after TM5INT enabled.
     * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
     */
    #define         irq_tm5_setPriority( level )                  irq_common_setPriority( ILC51, ILCn_TM5_BIT_NO, level )

    /**
     * Setting interrupt priority level (TM4INT)
     *
     * @param[in]   level   Setting value of interrupt priority level <br>
     *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
     * @return      None
     *
     * @note    Don't call this macro, after TM4INT enabled.
     * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
     */
    #define         irq_tm4_setPriority( level )                  irq_common_setPriority( ILC51, ILCn_TM4_BIT_NO, level )

  #endif  /* #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN) */
  
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    /**
     * Setting interrupt priority level (FTM5INT)
     *
     * @param[in]   level   Setting value of interrupt priority level <br>
     *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
     * @return      None
     *
     * @note    Don't call this macro, after TM5INT enabled.
     * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
     */
    #define         irq_ftm5_setPriority( level )                  irq_common_setPriority( ILC51, ILCn_FTM5_BIT_NO, level )
	
    /**
     * Setting interrupt priority level (FTM4INT)
     *
     * @param[in]   level   Setting value of interrupt priority level <br>
     *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
     * @return      None
     *
     * @note    Don't call this macro, after TM5INT enabled.
     * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
     */
    #define         irq_ftm4_setPriority( level )                  irq_common_setPriority( ILC51, ILCn_FTM4_BIT_NO, level )
  #endif
  
/**
 * Setting interrupt priority level (CMP0INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after CMP0INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_cmp0_setPriority( level )                irq_common_setPriority( ILC50, ILCn_CMP0_BIT_NO, level )

  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)	
    /**
     * Setting interrupt priority level (CMP1INT)
     *
     * @param[in]   level   Setting value of interrupt priority level <br>
     *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
     * @return      None
     *
     * @note    Don't call this macro, after TM5INT enabled.
     * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
     */
    #define         irq_cmp1_setPriority( level )                  irq_common_setPriority( ILC50, ILCn_CMP1_BIT_NO, level )
  #endif
  
/**
 * Setting interrupt priority level (LTB2INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after LTB2INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_ltbc2_setPriority( level )             irq_common_setPriority( ILC71, ILCn_LTBC2_BIT_NO, level )

/**
 * Setting interrupt priority level (LTB1INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after LTB1INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_ltbc1_setPriority( level )             irq_common_setPriority( ILC71, ILCn_LTBC1_BIT_NO, level )

/**
 * Setting interrupt priority level (LTB0INT)
 *
 * @param[in]   level   Setting value of interrupt priority level <br>
 *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
 * @return      None
 *
 * @note    Don't call this macro, after LTB0INT enabled.
 * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
 */
#define         irq_ltbc0_setPriority( level )             irq_common_setPriority( ILC70, ILCn_LTBC0_BIT_NO, level )

  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    /**
     * Setting interrupt priority level (RTCINT)
     *
     * @param[in]   level   Setting value of interrupt priority level <br>
     *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
     * @return      None
     *
     * @note    Don't call this macro, after TM5INT enabled.
     * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
     */
    #define         irq_rtc_setPriority( level )                  irq_common_setPriority( ILC71, ILCn_RTC_BIT_NO, level )
  #endif
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)  
    /**
     * Setting interrupt priority level (CBUINT)
     *
     * @param[in]   level   Setting value of interrupt priority level <br>
     *                      IRQ_PRIORITY_LEVEL_1, IRQ_PRIORITY_LEVEL_2, IRQ_PRIORITY_LEVEL_3, IRQ_PRIORITY_LEVEL_4
     * @return      None
     *
     * @note    Don't call this macro, after TM5INT enabled.
     * @note    Don't call this macro, in the state that disabled the interrupt priority level control.
     */
    #define         irq_cbu_setPriority( level )                  irq_common_setPriority( ILC20, ILCn_CBU_BIT_NO, level )
  #endif

#endif /*_IRQ_H_*/
