/*! \file usartCoreSelection.h
 \brief This file identify witch USART core to use.

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


#ifndef USARTCORESELECTION_H_
#define USARTCORESELECTION_H_

#include <stdbool.h>
#include <avr/io.h>

#if defined(__DOXYGEN__)
#	define USART_NUM_PORT 0 /*!< Number of port available per core */
#	define XCLK0_DDR DDRA /*!< Data Direction Register for clock source pin of USART 0. */
#	define XCLK0_DDx DDA0 /*!< Pin index for clock source pin of USART 0. */
#	define XCLK1_DDR DDRA /*!< Data Direction Register for clock source pin of USART 1. */
#	define XCLK1_DDx DDA0 /*!< Pin index for clock source pin of USART 1. */
#	define XCLK2_DDR DDRA /*!< Data Direction Register for clock source pin of USART 2. */
#	define XCLK2_DDx DDA0 /*!< Pin index for clock source pin of USART 2. */
#	define XCLK3_DDR DDRA /*!< Data Direction Register for clock source pin of USART 3. */
#	define XCLK3_DDx DDA0 /*!< Pin index for clock source pin of USART 3. */
#else
#	if defined (__AVR_ATmega8__)
#		define USART_NUM_PORT 1
#		define XCLK0_DDR DDRD
#		define XCLK0_DDx DDD4
#	endif
#endif
#endif /* USARTCORESELECTION_H_ */
