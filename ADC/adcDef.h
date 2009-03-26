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

/*! \file adcDef.h
 \brief This file declares \c typedef used by the ADC module.

 Not all part of the following \c enum are available to all devices.

 \author Frédéric Nadeau
 */
#ifndef ADCDEF_H_
#define ADCDEF_H_

#include "adcCoreSelection.h"

typedef enum ADC_Prescaler_e /*!< List of available prescaler. */
{
	ADC_DivFactor2 = 0, /*!< Oscillator clock divided by 2. */
	ADC_DivFactor2_, /*!< Oscillator clock divided by 2. Alternate setting. */
	ADC_DivFactor4, /*!< Oscillator clock divided by 4. */
	ADC_DivFactor8, /*!< Oscillator clock divided by 8. */
	ADC_DivFactor16, /*!< Oscillator clock divided by 16. */
	ADC_DivFactor32,/*!< Oscillator clock divided by 32. */
	ADC_DivFactor64,/*!< Oscillator clock divided by 64. */
	ADC_DivFactor128,/*!< Oscillator clock divided by 128. */
	ADC_DivFactorInvalid
/*!< Limit detection. Do not use! */
} ADC_Prescaler_t;/*!< List of available prescaler typedef. */

#if defined(__DOXYGEN__)
typedef enum ADC_VoltageRef_e /*!< List of available voltage reference. */
{
	ADC_VrefAtAREF = 0, /*!< ADC use Aref PIN as voltage reference. */
	ADC_VrefAtAVCC, /*!< ADC use VCC as voltage reference. */
	ADC_VrefReserved, /*!< Reserved setting, do not use!. */
	ADC_VrefInternal_1_1, /*!< ADC use internal 1.1 Voltage reference. */
	ADC_VrefInternal_2_56, /*!< ADC use internal 2.56 Voltage reference. */
	ADC_VrefInvalid /*!< Limit detection. Do not use! */
}ADC_VoltageRef_t; /*!< List of available voltage reference typedef. */

#else
typedef enum ADC_VoltageRef_e
{
	ADC_VrefAtAREF = 0, ADC_VrefAtAVCC,
#if !defined(ADC_1_1Vref)
	ADC_VrefReserved,
#else
	ADC_VrefInternal_1_1,
#endif
	ADC_VrefInternal_2_56, ADC_VrefInvalid
} ADC_VoltageRef_t;
#endif

#if defined(__DOXYGEN__)
typedef enum ADC_TriggerSource_e /*!< List of available trigger source. */
{
	ADC_FreeRunning = 0, /*!< ADC is in free running mode. */
	ADC_AnalogComparator, /*!< Start of conversion is trigged by the analog comparator. */
	ADC_ExtIntRequest0, /*!< Start of conversion is trigged by the external request 0. */
	ADC_Timer0CompareMatch, /*!< Start of conversion is trigged by timer 0 compare match. */
	ADC_Timer0Overflow, /*!< Start of conversion is trigged by timer 0 overflow. */
	ADC_Timer1CompareMatchB, /*!< Start of conversion is trigged by timer 1 compare match B. */
	ADC_Timer1Overflow, /*!< Start of conversion is trigged by timer 1 overflow. */
	ADC_Timer1CaptureEvent, /*!< Start of conversion is trigged by timer 1 capture event. */
	ADC_TriggerSourceInvalid, /*!< Limit detection. Do not use! */
}ADC_TriggerSource_t; /*!< List of available trigger source typedef. */
#else
typedef enum ADC_TriggerSource_e
{
	ADC_FreeRunning = 0,
#if defined(ADC_AutoTrigger)
	ADC_AnalogComparator,
	ADC_ExtIntRequest0,
	ADC_Timer0CompareMatch,
	ADC_Timer0Overflow,
	ADC_Timer1CompareMatchB,
	ADC_Timer1Overflow,
	ADC_Timer1CaptureEvent,
#endif
	ADC_TriggerSourceInvalid,
} ADC_TriggerSource_t;
#endif

#if defined(__DOXYGEN__)
typedef enum ADC_InputChannelSelection_e /*!< List of available input for ADC. */
{
	ADC_Chan_0 = 0, /*!< ADC use ADCpin 0. */
	ADC_Chan_1, /*!< ADC use ADCpin 1. */
	ADC_Chan_2, /*!< ADC use ADCpin 2. */
	ADC_Chan_3, /*!< ADC use ADCpin 3. */
	ADC_Chan_4, /*!< ADC use ADCpin 4. */
	ADC_Chan_5, /*!< ADC use ADCpin 5. */
	ADC_Chan_6, /*!< ADC use ADCpin 6. */
	ADC_Chan_7, /*!< ADC use ADCpin 7. */
	ADC_Chan_p0_n0_10x, /*!< ADC use differential input (pin0 - pin0) * 10. */
	ADC_Chan_p1_n0_10x, /*!< ADC use differential input (pin1 - pin0) * 10. */
	ADC_Chan_p0_n0_200x, /*!< ADC use differential input (pin0 - pin0) * 200. */
	ADC_Chan_p1_n0_200x, /*!< ADC use differential input (pin1 - pin0) * 200. */
	ADC_Chan_p2_n2_10x, /*!< ADC use differential input (pin2 - pin2) * 10. */
	ADC_Chan_p3_n2_10x, /*!< ADC use differential input (pin3 - pin2) * 10. */
	ADC_Chan_p2_n2_200x, /*!< ADC use differential input (pin2 - pin2) * 200. */
	ADC_Chan_p3_n2_200x, /*!< ADC use differential input (pin3 - pin2) * 200. */
	ADC_Chan_p0_n1_1x, /*!< ADC use differential input (pin0 - pin1) * 1. */
	ADC_Chan_p1_n1_1x, /*!< ADC use differential input (pin1 - pin1) * 1. */
	ADC_Chan_p2_n1_1x, /*!< ADC use differential input (pin2 - pin1) * 1. */
	ADC_Chan_p3_n1_1x, /*!< ADC use differential input (pin3 - pin1) * 1. */
	ADC_Chan_p4_n1_1x, /*!< ADC use differential input (pin4 - pin1) * 1. */
	ADC_Chan_p5_n1_1x, /*!< ADC use differential input (pin5 - pin1) * 1. */
	ADC_Chan_p6_n1_1x, /*!< ADC use differential input (pin6 - pin1) * 1. */
	ADC_Chan_p7_n1_1x, /*!< ADC use differential input (pin7 - pin1) * 1. */
	ADC_Chan_p0_n2_1x, /*!< ADC use differential input (pin0 - pin2) * 1. */
	ADC_Chan_p1_n2_1x, /*!< ADC use differential input (pin1 - pin2) * 1. */
	ADC_Chan_p2_n2_1x, /*!< ADC use differential input (pin2 - pin2) * 1. */
	ADC_Chan_p3_n2_1x, /*!< ADC use differential input (pin3 - pin2) * 1. */
	ADC_Chan_p4_n2_1x, /*!< ADC use differential input (pin4 - pin2) * 1. */
	ADC_Chan_p5_n2_1x, /*!< ADC use differential input (pin5 - pin2) * 1. */
	ADC_Chan_VBG, /*!< ADC use Vbg(see documentation for per-device reference). */
	ADC_Chan_GND, /*!< ADC use ground. */
	ADC_Chan_8, /*!< ADC use ADCpin 8. */
	ADC_Chan_9, /*!< ADC use ADCpin 9. */
	ADC_Chan_10, /*!< ADC use ADCpin 10. */
	ADC_Chan_11, /*!< ADC use ADCpin 11. */
	ADC_Chan_12, /*!< ADC use ADCpin 12. */
	ADC_Chan_13, /*!< ADC use ADCpin 13. */
	ADC_Chan_14, /*!< ADC use ADCpin 14. */
	ADC_Chan_15, /*!< ADC use ADCpin 15. */
	ADC_Chan_p8_n8_10x, /*!< ADC use differential input (pin8 - pin8) * 10. */
	ADC_Chan_p9_n8_10x, /*!< ADC use differential input (pin9 - pin8) * 10. */
	ADC_Chan_p8_n8_200x, /*!< ADC use differential input (pin8 - pin8) * 200. */
	ADC_Chan_p9_n8_200x, /*!< ADC use differential input (pin9 - pin8) * 200. */
	ADC_Chan_p10_n10_10x, /*!< ADC use differential input (pin10 - pin10) * 10. */
	ADC_Chan_p11_n10_10x, /*!< ADC use differential input (pin11 - pin10) * 10. */
	ADC_Chan_p10_n10_200x, /*!< ADC use differential input (pin10 - pin10) * 200. */
	ADC_Chan_p11_n10_200x, /*!< ADC use differential input (pin11 - pin10) * 200. */
	ADC_Chan_p8_n9_1x, /*!< ADC use differential input (pin8 - pin9) * 1. */
	ADC_Chan_p9_n9_1x, /*!< ADC use differential input (pin9 - pin9) * 1. */
	ADC_Chan_p10_n9_1x, /*!< ADC use differential input (pin10 - pin9) * 1. */
	ADC_Chan_p11_n9_1x, /*!< ADC use differential input (pin11 - pin9) * 1. */
	ADC_Chan_p12_n9_1x, /*!< ADC use differential input (pin12 - pin9) * 1. */
	ADC_Chan_p13_n9_1x, /*!< ADC use differential input (pin13 - pin9) * 1. */
	ADC_Chan_p14_n9_1x, /*!< ADC use differential input (pin14 - pin9) * 1. */
	ADC_Chan_p15_n9_1x, /*!< ADC use differential input (pin15 - pin9) * 1. */
	ADC_Chan_p8_n10_1x, /*!< ADC use differential input (pin8 - pin10) * 1. */
	ADC_Chan_p9_n10_1x, /*!< ADC use differential input (pin9 - pin10) * 1. */
	ADC_Chan_p10_n10_1x, /*!< ADC use differential input (pin10 - pin10) * 1. */
	ADC_Chan_p11_n10_1x, /*!< ADC use differential input (pin11 - pin10) * 1. */
	ADC_Chan_p12_n10_1x, /*!< ADC use differential input (pin12 - pin10) * 1. */
	ADC_Chan_p13_n10_1x, /*!< ADC use differential input (pin13 - pin10) * 1. */
	ADC_Chan_Reserved_1, /*!< Reserved, do not use! */
	ADC_Chan_Reserved_2, /*!< Reserved, do not use! */
	ADC_ChanInvalid/*!< Limit detection. Do not use! */
}ADC_InputChannelSelection_t;/*!< List of available input for ADC typedef. */
#else
typedef enum ADC_InputChannelSelection_e
{
	ADC_Chan_0 = 0,
	ADC_Chan_1,
	ADC_Chan_2,
	ADC_Chan_3,
	ADC_Chan_4,
	ADC_Chan_5,
	ADC_Chan_6,
	ADC_Chan_7,
#if defined(ADC_DiffInput)
	ADC_Chan_p0_n0_10x,
	ADC_Chan_p1_n0_10x,
	ADC_Chan_p0_n0_200x,
	ADC_Chan_p1_n0_200x,
	ADC_Chan_p2_n2_10x,
	ADC_Chan_p3_n2_10x,
	ADC_Chan_p2_n2_200x,
	ADC_Chan_p3_n2_200x,
	ADC_Chan_p0_n1_1x,
	ADC_Chan_p1_n1_1x,
	ADC_Chan_p2_n1_1x,
	ADC_Chan_p3_n1_1x,
	ADC_Chan_p4_n1_1x,
	ADC_Chan_p5_n1_1x,
	ADC_Chan_p6_n1_1x,
	ADC_Chan_p7_n1_1x,
	ADC_Chan_p0_n2_1x,
	ADC_Chan_p1_n2_1x,
	ADC_Chan_p2_n2_1x,
	ADC_Chan_p3_n2_1x,
	ADC_Chan_p4_n2_1x,
	ADC_Chan_p5_n2_1x,
#endif
	ADC_Chan_VBG,
	ADC_Chan_GND,
#if !defined(ADC_16Channel)
	ADC_ChanInvalid,
#else
ADC_Chan_8,
ADC_Chan_9,
ADC_Chan_10,
ADC_Chan_11,
ADC_Chan_12,
ADC_Chan_13,
ADC_Chan_14,
ADC_Chan_15,
ADC_Chan_p8_n8_10x,
ADC_Chan_p9_n8_10x,
ADC_Chan_p8_n8_200x,
ADC_Chan_p9_n8_200x,
ADC_Chan_p10_n10_10x,
ADC_Chan_p11_n10_10x,
ADC_Chan_p10_n10_200x,
ADC_Chan_p11_n10_200x,
ADC_Chan_p8_n9_1x,
ADC_Chan_p9_n9_1x,
ADC_Chan_p10_n9_1x,
ADC_Chan_p11_n9_1x,
ADC_Chan_p12_n9_1x,
ADC_Chan_p13_n9_1x,
ADC_Chan_p14_n9_1x,
ADC_Chan_p15_n9_1x,
ADC_Chan_p8_n10_1x,
ADC_Chan_p9_n10_1x,
ADC_Chan_p10_n10_1x,
ADC_Chan_p11_n10_1x,
ADC_Chan_p12_n10_1x,
ADC_Chan_p13_n10_1x,
ADC_Chan_Reserved_1,
ADC_Chan_Reserved_2,
ADC_ChanInvalid
#endif
} ADC_InputChannelSelection_t;
#endif

#if defined(__DOXYGEN__)
typedef enum ADC_DigitalChannel_e/*!< List of digital input channel. */
{
	ADC_DigChan0 = 0x0001,	/*!< Digital input on pin0. */
	ADC_DigChan1 = 0x0002,	/*!< Digital input on pin1. */
	ADC_DigChan2 = 0x0004,	/*!< Digital input on pin2. */
	ADC_DigChan3 = 0x0008,	/*!< Digital input on pin3. */
	ADC_DigChan4 = 0x0010,	/*!< Digital input on pin4. */
	ADC_DigChan5 = 0x0020,	/*!< Digital input on pin5. */
	ADC_DigChan6 = 0x0040,	/*!< Digital input on pin6. */
	ADC_DigChan7 = 0x0080,	/*!< Digital input on pin7. */
	ADC_DigChan8 = 0x0100,	/*!< Digital input on pin8. */
	ADC_DigChan9 = 0x0200,	/*!< Digital input on pin9. */
	ADC_DigChan10 = 0x0400,	/*!< Digital input on pin10. */
	ADC_DigChan11 = 0x0800,	/*!< Digital input on pin11. */
	ADC_DigChan12 = 0x1000,	/*!< Digital input on pin12. */
	ADC_DigChan13 = 0x2000,	/*!< Digital input on pin13. */
	ADC_DigChan14 = 0x4000,	/*!< Digital input on pin14. */
	ADC_DigChan15 = 0x8000	/*!< Digital input on pin15. */
}ADC_DigitalChannel_t;/*!< List of digital input channel typedef. */
#else
#if defined(ADC_DigitalInput)
typedef enum ADC_DigitalChannel_e
{
	ADC_DigChan0 = 0x0001,
	ADC_DigChan1 = 0x0002,
	ADC_DigChan2 = 0x0004,
	ADC_DigChan3 = 0x0008,
	ADC_DigChan4 = 0x0010,
	ADC_DigChan5 = 0x0020,
	ADC_DigChan6 = 0x0040,
	ADC_DigChan7 = 0x0080,
#	if defined(ADC_16DigitalInput)
	ADC_DigChan8 = 0x0100,
	ADC_DigChan9 = 0x0200,
	ADC_DigChan10 = 0x0400,
	ADC_DigChan11 = 0x0800,
	ADC_DigChan12 = 0x1000,
	ADC_DigChan13 = 0x2000,
	ADC_DigChan14 = 0x4000,
	ADC_DigChan15 = 0x8000
#	endif
}ADC_DigitalChannel_t;
#endif//defined(ADC_DigitalInput)
#endif//defined(__DOXYGEN__)


#endif /*ADCDEF_H_*/
