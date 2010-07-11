/* Copyright (c) 2008-2010 Frédéric Nadeau
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

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>

void adc_enable(_Bool status)
{
	if(status != false)
	{
		ADCSRA |= _BV(ADEN);
	}
	else
	{
		ADCSRA &= ~_BV(ADEN);
	}
}

void adc_interrupt_enable(_Bool intEn)
{
	if(intEn != false)
	{
		ADCSRA |= _BV(ADIE);
	}
	else
	{
		ADCSRA &= ~_BV(ADIE);
	}
}

void adc_left_adjust(_Bool adjust)
{
	if(adjust != false)
	{
		ADMUX |= _BV(ADLAR);
	}
	else
	{
		ADMUX &= ~_BV(ADLAR);
	}
}

//This function assume that ADPS2 == (ADPS0 + 2) && ADPS1 == (ADPS0 + 1)
//It seems it is always the case
#if !(ADPS2 == (ADPS0 + 2) && ADPS1 == (ADPS0 + 1))
#	error "adcPrescalerSelection needs to be rewritten for this device"
#endif
int adc_prescaler_selection(ADC_Prescaler_t prescaler)
{
#ifndef NDEBUG
	if (prescaler >= ADC_DivFactorInvalid)
	{
		errno = EINVAL;
		return -1;
	}
#endif

	ADCSRA &= ~(_BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0));
	ADCSRA |= prescaler << ADPS0;

	return 0;
}

uint16_t adc_read(void)
{
	return ADCW;
}

uint8_t adc_read_high(void)
{
	return ADCH;
}

uint8_t adc_read_low(void)
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


//This function assume that REFS1 == (REFS0 + 1)
//It seems it is always the case
#if REFS1 != (REFS0 +1)
#	error "adcSelectVref needs to be rewritten for this device"
#endif
int adc_select_vref(ADC_VoltageRef_t ref)
{
#ifndef NDEBUG
	if (ref >= ADC_VrefInvalid)
	{
		errno = EINVAL;
		return -1;
	}
#endif

	ADMUX &= ~(1 << REFS1 | 1 << REFS0);
	ADMUX |= ref << REFS0;

	return 0;
}

void adc_start_conversion(void)
{
	ADCSRA |= _BV(ADSC);
}

