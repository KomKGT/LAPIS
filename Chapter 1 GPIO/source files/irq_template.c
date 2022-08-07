/*****************************************************************************
 irq_template.c

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
 * @file    irq_template.c
 *
 * This file is template for interrupt routine. <br>
 * Please customize for your application.
 *
 */
#include <ml621367.h>

#include "irq.h"
#include "rdwr_reg.h"

/*############################################################################*/
/*#                                  Macro                                   #*/
/*############################################################################*/

/*############################################################################*/
/*#                                Variable                                  #*/
/*############################################################################*/

/*############################################################################*/
/*#                               Prototype                                  #*/
/*############################################################################*/
static void s_handlerWDTINT( void );
static void s_handlerVLS0INT( void );
static void s_handlerEXI0INT( void );
static void s_handlerEXI1INT( void );
static void s_handlerEXI2INT( void );
static void s_handlerEXI3INT( void );
static void s_handlerEXI4INT( void );
static void s_handlerEXI5INT( void );
static void s_handlerEXI6INT( void );
static void s_handlerEXI7INT( void );
static void s_handlerDMACINT( void );
static void s_handlerSIU00INT( void );
static void s_handlerSIU01INT( void );
static void s_handlerSADINT( void );
static void s_handlerI2CM0INT( void );
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
	static void s_handlerI2CM1INT( void );
  #endif
static void s_handlerFTM0INT( void );
static void s_handlerFTM1INT( void );
static void s_handlerTM0INT( void );
static void s_handlerTM1INT( void );
static void s_handlerI2CU0INT( void );
static void s_handlerSIU10INT( void );
static void s_handlerSIU11INT( void );
static void s_handlerFTM2INT( void );
static void s_handlerFTM3INT( void );
static void s_handlerTM2INT( void );
static void s_handlerTM3INT( void );
static void s_handlerCMP0INT( void );
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
	static void s_handlerCMP1INT( void );
  #endif
  #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN)
    static void s_handlerTM4INT( void );
    static void s_handlerTM5INT( void );
  #endif  /* #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN) */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
	static void s_handlerFTM5INT( void );
    static void s_handlerFTM4INT( void );
  #endif
static void s_handlerLTBC0INT( void );
static void s_handlerLTBC1INT( void );
static void s_handlerLTBC2INT( void );
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
	static void s_handlerRTCINT( void );
  #endif
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
	static void s_handlerCBUINT( void );
  #endif

/*=== set Interrupt Vector ===*/
/* <Note 1>                                     */
/* If enables nested interrupts,                */
/* specify '2' in the INTERRUPT category field. */

#pragma INTERRUPT   s_handlerWDTINT     WDTINT   2 
#pragma INTERRUPT   s_handlerVLS0INT    VLS0INT  1
#pragma INTERRUPT   s_handlerEXI0INT    EXI0INT  1
#pragma INTERRUPT   s_handlerEXI1INT    EXI1INT  1
#pragma INTERRUPT   s_handlerEXI2INT    EXI2INT  1
#pragma INTERRUPT   s_handlerEXI3INT    EXI3INT  1
#pragma INTERRUPT   s_handlerEXI4INT    EXI4INT  1
#pragma INTERRUPT   s_handlerEXI5INT    EXI5INT  1
#pragma INTERRUPT   s_handlerEXI6INT    EXI6INT  1
#pragma INTERRUPT   s_handlerEXI7INT    EXI7INT  1
#pragma INTERRUPT   s_handlerDMACINT    DMACINT  1
#pragma INTERRUPT   s_handlerSIU00INT   SIU00INT 1
#pragma INTERRUPT   s_handlerSIU01INT   SIU01INT 1
#pragma INTERRUPT   s_handlerSADINT     SADINT   1
#pragma INTERRUPT   s_handlerI2CM0INT   I2CM0INT 1
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
	#pragma INTERRUPT   s_handlerI2CM1INT   I2CM1INT 1
  #endif
#pragma INTERRUPT   s_handlerFTM0INT    FTM0INT  1
#pragma INTERRUPT   s_handlerFTM1INT    FTM1INT  1
#pragma INTERRUPT   s_handlerTM0INT     TM0INT   1
#pragma INTERRUPT   s_handlerTM1INT     TM1INT   1
#pragma INTERRUPT   s_handlerI2CU0INT   I2CU0INT 1
#pragma INTERRUPT   s_handlerSIU10INT   SIU10INT 1
#pragma INTERRUPT   s_handlerSIU11INT   SIU11INT 1
#pragma INTERRUPT   s_handlerFTM2INT    FTM2INT  1
#pragma INTERRUPT   s_handlerFTM3INT    FTM3INT  1
#pragma INTERRUPT   s_handlerTM2INT     TM2INT   1
#pragma INTERRUPT   s_handlerTM3INT     TM3INT   1
#pragma INTERRUPT   s_handlerCMP0INT    CMP0INT  1
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
	#pragma INTERRUPT   s_handlerCMP1INT    CMP1INT  1
  #endif
  #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN)
    #pragma INTERRUPT   s_handlerTM4INT     TM4INT   1
    #pragma INTERRUPT   s_handlerTM5INT     TM5INT   1
  #endif  /* #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN) */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
	#pragma INTERRUPT   s_handlerFTM5INT    FTM5INT  1
    #pragma INTERRUPT   s_handlerFTM4INT    FTM4INT  1
  #endif
#pragma INTERRUPT   s_handlerLTBC0INT   LTB0INT  1
#pragma INTERRUPT   s_handlerLTBC1INT   LTB1INT  1
#pragma INTERRUPT   s_handlerLTBC2INT   LTB2INT  1
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
	#pragma INTERRUPT   s_handlerRTCINT     RTCINT   1
  #endif
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
	#pragma INTERRUPT   s_handlerCBUINT     CBUINT   1
  #endif

/*############################################################################*/
/*#                          Interrupt handler                               #*/
/*############################################################################*/
static void s_handlerWDTINT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by WDTINT,         */
	/* add to your application's code this.                                    */
}

static void s_handlerVLS0INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by VLS0INT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerEXI0INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by EXI0INT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerEXI1INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by EXI1INT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerEXI2INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by EXI2INT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerEXI3INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by EXI3INT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerEXI4INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by EXI4INT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerEXI5INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by EXI5INT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerEXI6INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by EXI6INT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerEXI7INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by EXI7INT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerDMACINT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by DMACINT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerSIU00INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by SIU00INT,       */
	/* add to your application's code this.                                    */
}

static void s_handlerSIU01INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by FTM1INT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerSADINT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by SADINT,         */
	/* add to your application's code this.                                    */
}

static void s_handlerI2CM0INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by I2CM0INT,       */
	/* add to your application's code this.                                    */
}
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
	static void s_handlerI2CM1INT( void )
	{
	    /*===ToDo.===*/
	    /* If you need a application's interrupt handler called by I2CM1INT,        */
	    /* add to your application's code this.                                    */
	}
  #endif

static void s_handlerFTM0INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by FTM0INT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerFTM1INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by FTM1INT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerTM0INT( void )
{
	Timer0_Interrupt();
	CIL =0;
}

static void s_handlerTM1INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by TM1INT,         */
	/* add to your application's code this.                                    */
}

static void s_handlerI2CU0INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by I2CU0INT,       */
	/* add to your application's code this.                                    */
}

static void s_handlerSIU10INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by SIU10INT,       */
	/* add to your application's code this.                                    */
}

static void s_handlerSIU11INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by SIU11INT,       */
	/* add to your application's code this.                                    */
}

static void s_handlerFTM2INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by FTM2INT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerFTM3INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by FTM3INT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerTM2INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by TM2INT,         */
	/* add to your application's code this.                                    */
}

static void s_handlerTM3INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by TM3INT,         */
	/* add to your application's code this.                                    */
}

static void s_handlerCMP0INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by CMP0INT,        */
	/* add to your application's code this.                                    */
}
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
	static void s_handlerCMP1INT( void )
	{
	    /*===ToDo.===*/
	    /* If you need a application's interrupt handler called by CMP1INT,        */
	    /* add to your application's code this.                                    */
	}
  #endif

  #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN)
    static void s_handlerTM4INT( void )
    {
    	/*===ToDo.===*/
    	/* If you need a application's interrupt handler called by TM4INT,         */
    	/* add to your application's code this.                                    */
    }

    static void s_handlerTM5INT( void )
    {
    	/*===ToDo.===*/
    	/* If you need a application's interrupt handler called by TM5INT,         */
    	/* add to your application's code this.                                    */
    }
  #endif  /* #if !defined(_ML62Q1XXX16PIN) && !defined(_ML62Q1XXX20PIN) */
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
    static void s_handlerFTM5INT( void )
	{
	    /*===ToDo.===*/
	    /* If you need a application's interrupt handler called by FTM5INT,        */
	    /* add to your application's code this.                                    */
	}
	
	static void s_handlerFTM4INT( void )
	{
	    /*===ToDo.===*/
	    /* If you need a application's interrupt handler called by FTM4INT,        */
	    /* add to your application's code this.                                    */
	}
  #endif

static void s_handlerLTBC0INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by LTB0INT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerLTBC1INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by LTB1INT,        */
	/* add to your application's code this.                                    */
}

static void s_handlerLTBC2INT( void )
{
	/*===ToDo.===*/
	/* If you need a application's interrupt handler called by LTB2INT,        */
	/* add to your application's code this.                                    */
}
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
	static void s_handlerRTCINT( void )
	{
	    /*===ToDo.===*/
	    /* If you need a application's interrupt handler called by RTCINT,        */
	    /* add to your application's code this.                                    */
	}
  #endif
  #if defined(_ML62Q14XX) || defined(_ML62Q16XX)
	static void s_handlerCBUINT( void )
	{
	    /*===ToDo.===*/
	    /* If you need a application's interrupt handler called by CBUINT,        */
	    /* add to your application's code this.                                    */
	}
  #endif

