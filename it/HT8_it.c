/**
  ******************************************************************************
  * @file HT8_it.c
  * @brief This file provides all the interrupt firmware functions.
  * @author Holtek Semiconductor Inc.
  * @version V1.0.0
  * @date 2019-05-20
  ******************************************************************************
  * @attention
  *
  * Firmware Disclaimer Information
  *
  * 1. The customer hereby acknowledges and agrees that the program technical documentation, including the
  *    code, which is supplied by Holtek Semiconductor Inc., (hereinafter referred to as "HOLTEK") is the
  *    proprietary and confidential intellectual property of HOLTEK, and is protected by copyright law and
  *    other intellectual property laws.
  *
  * 2. The customer hereby acknowledges and agrees that the program technical documentation, including the
  *    code, is confidential information belonging to HOLTEK, and must not be disclosed to any third parties
  *    other than HOLTEK and the customer.
  *
  * 3. The program technical documentation, including the code, is provided "as is" and for customer reference
  *    only. After delivery by HOLTEK, the customer shall use the program technical documentation, including
  *    the code, at their own risk. HOLTEK disclaims any expressed, implied or statutory warranties, including
  *    the warranties of merchantability, satisfactory quality and fitness for a particular purpose.
  *
  * <h2><center>Copyright (C) Holtek Semiconductor Inc. All rights reserved</center></h2>
  ************************************************************************************************************/


#include "HT8_it.h"

/**
  * @brief external Interruption 0 routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
void __attribute((interrupt(0x04))) INT0_ISR(void)
{
	_pc2 = ~_pc2;	
	GCC_NOP();
}

/**
  * @brief STM Interruption routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
void __attribute((interrupt(0x0C))) STM_ISR(void)
{
	/* user define */
}

/**
  * @brief PTM Interruption routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
void __attribute((interrupt(0x10))) PTM_ISR(void)
{
	/* user define */
}


/**
  * @brief ADC Interruption routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
void __attribute((interrupt(0x18))) ADC_ISR(void)
{
	/* user define */
}


/**
  * @brief timebase0 Interruption routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
void __attribute((interrupt(0x1C))) TB0_ISR(void)
{
	_pb4 = ~_pb4;
}


/**
  * @brief timebase1 Interruption routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
void __attribute((interrupt(0x20))) TB1_ISR(void)
{
	/* user define */
}


/**
  * @brief external Interruption 1 routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
void __attribute((interrupt(0x24))) INT1_ISR(void)
{
	_pc2 = ~_pc2;
	GCC_NOP();
}


/******************* (C) COPYRIGHT 2019 Holtek Semiconductor Inc *****END OF FILE****/