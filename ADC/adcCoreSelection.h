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

/*! \file adcCoreSelection.h
 \brief This file identify witch option of the ADC are available for a
 specific AVR device.

 Not all device have the same option in their respective ADC module.

 Currently supported option
 \li Differential input
 \li Auto trigger
 \li Digital input
 \li 16 channel mode
 \li 16 digital input
 \li 1.1 Volt reference

 \author Frédéric Nadeau
 */
#ifndef ADCCORESELECTION_H_
#define ADCCORESELECTION_H_

#include "avr_mod/io.h" //\TODO If avr-libc accept pin description, change me.


#if !(defined(ADCSRA)  || defined(ADMUX)  || defined(ADCW) || defined(ADCH) || defined(ADCL))
#	error "Device not supported"
#endif

#ifdef MUX4
#	define ADC_DiffInput
#endif

#ifdef MUX5
#	define ADC_16Channel
#endif

#ifdef ADATE
#	define ADC_AutoTrigger
#endif

#ifdef DIDR0
#	define ADC_DigitalInput
#	ifdef DIDR1
#		define ADC_16DigitalInput
#	endif
#endif

#if defined(__DOXYGEN__)

#	define ADC_16DigitalInput 	/*!< Device has 16 digital input. */
#	define ADC_DiffInput		/*!< Device has differential inputs. */
#	define ADC_16Channel		/*!< Device has 16 analog input. */
#	define ADC_1_1Vref			/*!< Device has the 1.1Volt voltage reference. */
#	define ADC_AutoTrigger		/*!< Device has auto trigger module. */
#	define ADC_DigitalInput		/*!< Device has digital input. */

#else//defined(__DOXYGEN__)
//I don't know how to detect 1.1V reference based on register
//Device that has 1.1V has to be added here manually
#	if defined (__AVR_ATmega1280__)
#		define ADC_1_1Vref
#	endif
#endif//defined(__DOXYGEN__)

#endif /* ADCCORESELECTION_H_ */
