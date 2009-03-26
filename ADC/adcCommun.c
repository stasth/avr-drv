/* Copyright (c) 2008,2009 Frédéric Nadeau
   All rights reserved.

   Redistribution and use in source and binary forms,
   with or without modification, are permitted provided
   that the following conditions are met:

   1.Redistributions of source code must retain the above
   copyright notice, this list of conditions and the following
   disclaimer.

   2.Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

   3.Neither the name of the AVR-DRV nor the names of its
   contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

/*! \file adcCommun.c
 \brief This file contains common code for ADC.

 This file contains common function for all supported ADC.
 This file may eventually get modified as more AVR device get supported.

 Currently only use the following register:
 \li \c ADMUX
 \li \c ADCSRA
 \li \c ADCW
 \li \c ADCH
 \li \c ADCL

 \author Frédéric Nadeau
 */
#include "avr-drv-errno.h"
#include "avr_mod/io.h" //\TODO If avr-libc accept pin description, change me.

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

void adcEnable(_Bool status)
{
	ADCSRA &= ~_BV(ADEN);
	if(status != false)
	{
		ADCSRA |= _BV(ADEN);
	}
}

void adcInterruptEnable(_Bool intEn)
{
	ADCSRA &= ~_BV(ADIE);
	if(intEn != false)
	{
		ADCSRA |= _BV(ADIE);
	}
}

void adcLeftAdjust(_Bool adjust)
{
	ADMUX &= ~_BV(ADLAR);
	if(adjust != false)
	{
		ADMUX |= _BV(ADLAR);
	}
}

int adcPrescalerSelection(ADC_Prescaler_t prescaler)
{
	if (prescaler >= ADC_DivFactorInvalid)
	{
		errno = EINVAL;
		return -1;
	}

	ADCSRA &= ~((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));
	ADCSRA |= prescaler;

	return 0;
}

uint16_t adcRead(void)
{
	return ADCW;
}

uint8_t adcReadHigh(void)
{
	return ADCH;
}

uint8_t adcReadLow(void)
{
	return ADCL;
}

_Bool adcReadIntFlag(void)
{
	return (ADCSRA & _BV(ADIF)) == 0 ? false:true;
}

void adcClearIntFlag(void)
{
	//Write a logical 1 to clear the flag
	ADCSRA |= _BV(ADIF);
}

int adcSelectVref(ADC_VoltageRef_t ref)
{
	if (ref >= ADC_VrefInvalid)
	{
		errno = EINVAL;
		return -1;
	}

	ADMUX &= ~(1 << REFS1 | 1 << REFS0);
	ADMUX |= ref << REFS0;

	return 0;
}

void adcStartConversion(void)
{
	ADCSRA |= 1 << ADSC;
}

