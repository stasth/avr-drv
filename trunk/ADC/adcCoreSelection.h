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

#ifndef ADCCORESELECTION_H_
#define ADCCORESELECTION_H_

//TODO Eliminate ADC_16DigitalInput using ADC_DigitalInput and ADC_16Channel

#if defined(__DOXYGEN__)

#	define ADC_16DigitalInput 	/*!< Device has 16 digital input. */
#	define ADC_DiffInput		/*!< Device has differential inputs. */
#	define ADC_16Channel		/*!< Device has 16 analog input. */
#	define ADC_1_1Vref			/*!< Device has the 1.1Volt voltage reference. */
#	define ADC_AutoTrigger		/*!< Device has auto trigger module. */
#	define ADC_DigitalInput		/*!< Device has digital input. */

#else//defined(__DOXYGEN__)
#	if defined (__AVR_ATmega8__)
//Most basic driver, no special feature to be enabled
#	elif defined (__AVR_ATmega32__)
#		define ADC_DiffInput
#		define ADC_AutoTrigger
#	elif defined (__AVR_AT90CAN128__)
#		define ADC_DiffInput
#		define ADC_AutoTrigger
#		define ADC_DigitalInput
#	elif defined (__AVR_ATmega128__)
#		define ADC_DiffInput
#	elif defined (__AVR_ATmega1280__)
#		define ADC_16DigitalInput
#		define ADC_DiffInput
#		define ADC_16Channel
#		define ADC_1_1Vref
#		define ADC_AutoTrigger
#		define ADC_DigitalInput
#	else
#    	error "Device not supported"
#	endif
#endif//defined(__DOXYGEN__)

#endif /* ADCCORESELECTION_H_ */
