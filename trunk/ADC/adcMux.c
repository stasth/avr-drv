/*! \file adcMux.c
 \brief This file handle MUX module of the ADC.

 Currently this option comes in three flavour:
 \li 3 bits MUX
 \li 4 bits MUX
 \li 5 bits MUX

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

#if defined(__DOXYGEN__)
#	define MUX_MASK /*!< ADMUX register mask for MUX bits. */
#else
#	if defined(MUX4)
#		define MUX_MASK ((1 << MUX4) | (1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0))
#	else
#		define MUX_MASK ((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0))
#	endif
#endif
void adcSelectInput(ADC_InputChannelSelection_t channel)
{
	assert (channel < ADC_ChanInvalid);

	ADMUX &= ~MUX_MASK;
	ADMUX |= channel;

#if defined(MUX5)
	ADCSRB &= ~_BV(MUX5);
	if(channel >= ADC_Chan_8)
	{
		ADCSRB |= _BV(MUX5);
	}

#endif

}
