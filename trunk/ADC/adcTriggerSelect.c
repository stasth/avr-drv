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

/*! \file adcTriggerSelect.c
 \brief This file handle Trigger module of the ADC.

 \author Frédéric Nadeau
 */
#include "adcCoreSelection.h"
#include "adcDef.h"
#include "avr-drv-errno.h"
#include "avr_mod/io.h" //\TODO If avr-libc accept pin description, change me.

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(ADC_AutoTrigger)

#ifdef ADCSRB
#	define TARGET_REG ADCSRB
#else
#	define TARGET_REG SFIOR
#endif

int adcTriggerSource(ADC_TriggerSource_t trigger)
{
	if (trigger >= ADC_TriggerSourceInvalid)
	{
		errno = EINVAL;
		return -1;
	}

	TARGET_REG &= ~((1 << ADTS2) | (1 << ADTS1) | (1 << ADTS0));
	TARGET_REG |= trigger;

	return 0;
}

void adcTriggerEnable(_Bool trigEn)
{
	TARGET_REG &= ~_BV(ADATE);
	if(trigEn != false)
	{
		TARGET_REG |= _BV(ADATE);
	}
}

#else

int adcTriggerSource(ADC_TriggerSource_t trigger)
{
	if (trigger != ADC_FreeRunning)
	{
		errno = EINVAL;
		return -1;
	}

	return 0;
}

void adcTriggerEnable(_Bool trigEn)
{
	ADCSRA &= ~_BV(ADFR);
	if(trigEn != false)
	{
		ADCSRA |= _BV(ADFR);
	}
}

#endif
