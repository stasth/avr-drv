/*! \file usartDef.h
 \brief This file declares \c typedef used by the USART module.

 Not all part of the following \c enum are available to all devices.

 \author Frédéric Nadeau

 \warning Copyright (c) 2008 Frédéric Nadeau
 All rights reserved.


 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:\n
 1. Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.\n
 2. Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.\n
 3. The name of the author nor the names of its contributors may not
 be used to endorse or promote products derived from this software
 without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef USARTDEF_H_
#define USARTDEF_H_

#include "usartCoreSelection.h"

#if defined(__DOXYGEN__)
typedef enum USART_Port_e /*!< Enum of available port. */
{
	USART_Port_0,		/*!< USART port 0. */
	USART_Port_1,		/*!< USART port 1. */
	USART_Port_2,		/*!< USART port 2. */
	USART_Port_3,		/*!< USART port 3. */
	USART_Port_Last		/*!< Last element detection. */
}USART_Port_t; /*!< Typedef of #USART_Port_e. */
#else
typedef enum USART_Port_e
{
	USART_Port_0,
#if USART_NUM_PORT > 1
	USART_Port_1,
	USART_Port_Last = USART_Port_1
#elif USART_NUM_PORT == 4
	USART_Port_2,
	USART_Port_3,
	USART_Port_Last = USART_Port_3
#else
	USART_Port_Last = USART_Port_0
#endif
}USART_Port_t;
#endif

typedef enum USART_NumBits_e /*!< Number of bits used by the USART module. */
{
	USART_NumBits_5,	/*!< USART use 5 bits. */
	USART_NumBits_6,	/*!< USART use 6 bits. */
	USART_NumBits_7,	/*!< USART use 7 bits. */
	USART_NumBits_8,	/*!< USART use 8 bits. */
	USART_NumBits_9,	/*!< USART use 9 bits. */
	USART_NumBits_Last = USART_NumBits_9 	/*!< Limit detection. */
}USART_NumBits_t; /*!< Typedef of #USART_NumBits_e. */

typedef enum USART_Parity_e /*!< Parity bit that will be added to frame. */
{
	USART_Parity_None, /*!< No parity bit. */
	USART_Parity_Even, /*!< Use even parity bit. */
	USART_Parity_Odd, /*!< Use odd parity bit. */
	USART_Parity_Last = USART_Parity_Odd /*!< Limit detection. */
}USART_Parity_t; /*!< Typedef for #USART_Parity_e. */

typedef enum USART_StopBit_e /*!< How many stop bit will be added to frame. */
{
	USART_StopBit_1, /*!< Add one stop bit. */
	USART_StopBit_2, /*!< Add two stop bit. */
	USART_StopBit_Last = USART_StopBit_2 /*!< Limit detection. */
}USART_StopBit_t; /*!< Typedef for #USART_StopBit_e. */

typedef enum USART_Mode_e /*!< Mode into witch USART will be configured. */
{
	USART_Mode_Async, /*!< Asynchronous, Most likely what you need. */
	USART_Mode_SyncMaster, /*!< Synchronous mode. We are the clock source. */
	USART_Mode_SyncSlave, /*!< Synchronous mode. Clock source must be provided. */
	USART_Mode_Last = USART_Mode_SyncSlave
}USART_Mode_t;/*!< Typedef for USART_Mode_e. */

#endif /* USARTDEF_H_ */
