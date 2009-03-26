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

/*! \file adcDigitalInput.c
 \brief This file handle the Digital Input option offered by some devices.

 Currently this option comes in two flavour:
 \li 8 Channels Digital Input
 \li 16 Channels Digital Input

 \author Frédéric Nadeau
 */
#include "avr-drv.h"
#include "avr_mod/io.h" //\TODO If avr-libc accept pin description, change me.

#if defined(DIDR0)

void adcDigitalInputDisable(ADC_DigitalChannel_t chanList)
{
	DIDR0 |= (uint8_t)chanList;
#if defined(DIDR2)
	DIDR2 |= (uint8_t)(chanList>>8);
#endif

}

void adcDigitalInputEnable(ADC_DigitalChannel_t chanList)
{
	DIDR0 &= ~((uint8_t)chanList);
#if defined(DIDR2)
	DIDR2 &= ~((uint8_t)(chanList>>8));
#endif
}

#endif
