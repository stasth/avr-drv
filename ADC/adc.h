/*! \file adc.h
 \brief Function definition for ADC module.

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
#ifndef ADC_H_
#define ADC_H_

#include <stdbool.h>
#include <stdint.h>
#include "adcDef.h"

/*! \fn void adcSelectVref(ADC_VoltageRef_t ref)
 *  \brief Select voltage reference to be used by the ADC.
 *
 *  \warning Not all device have the same voltage reference.
 *
 *  \param ref Voltage reference to be used.
 *  \return 0 if successful or -1 if an error occured. See errno for detail:\
 *  #EINVAL Invalid argument.
 */
int adcSelectVref(ADC_VoltageRef_t ref);

/*! \fn void adcSelectInput(ADC_InputChannelSelection_t channel)
 *  \brief Select input channel of the ADC.
 *
 *  \warning Not all device have the same input channel.
 *
 *  \param channel Selected channel.
 *  \return 0 if successful or -1 if an error occured. See errno for detail:\
 *  #EINVAL Invalid argument.
 */
int adcSelectInput(ADC_InputChannelSelection_t channel);

/*! \fn void adcLeftAdjust(_Bool adjust)
 *  \brief Select how conversion result will be stored in register.
 *
 *  For 8-bits result, use:
 *  \li \c adcLeftAdjust(true)
 *  \li #adcReadHigh()
 *
 *	For 10-bits result, use:
 *  \li \c adcLeftAdjust(false)
 *  \li #adcRead()
 *
 *  \param adjust Alignment of the result register.
 */
void adcLeftAdjust(_Bool adjust);

/*! \fn void adcPrescalerSelection(ADC_Prescaler_t prescaler)
 *  \brief Select ADC core clock prescaler.
 *
 *  \param prescaler Prescaler clock. See #ADC_Prescaler_t for option list.
 *  \return 0 if successful or -1 if an error occured. See errno for detail:\
 *  #EINVAL Invalid argument.
 */
int adcPrescalerSelection(ADC_Prescaler_t prescaler);

/*! \fn void adcEnable(_Bool status)
 *  \brief Enable or disable ADC core.
 *
 *  \param status Status of the ADC core.
 */
void adcEnable(_Bool status);

/*! \fn void adcInterruptEnable (_Bool intEn)
 *  \brief Enable or disable ADC core interrupt.
 *
 *  \warning Interrupt service routine are not provided by AVR-drv.
 *  You have to write your own.
 *
 *  \param intEn New interrupt status.
 */
void adcInterruptEnable (_Bool intEn);

/*! \fn void adcStartConversion(void)
 *  \brief Start a conversion.
 */
void adcStartConversion(void);

/*! \fn uint16_t adcRead(void)
 *  \brief Read conversion result register.
 *
 *  \return Value in the conversion result register.
 */
uint16_t adcRead(void);

/*! \fn uint8_t adcReadHigh(void)
 *  \brief Read high byte of the conversion result register.
 *
 *  \return Value in the high byte of the conversion result register.
 */
uint8_t adcReadHigh(void);

/*! \fn uint8_t adcReadLow(void)
 *  \brief Read low byte of the conversion result register.
 *
 *  \return Value in the low byte of the conversion result register.
 */
uint8_t adcReadLow(void);

/*! \fn void adcTriggerSource (ADC_TriggerSource_t trigger)
 *  \brief Set the auto trigger source.
 *
 *  \warning Not all device have the trigger source.
 *  For devices like \c ATmega8 and \c ATmega128, this function does nothing
 *  except an \c assert on the input witch must be #ADC_FreeRunning.
 *  The function has been left for these device only for API compatibility.
 *
 *  \param trigger Trigger source. See #ADC_TriggerSource_t for option list.
 *  \return 0 if successful or -1 if an error occured. See errno for detail:\
 *  #EINVAL Invalid argument.
 */
int adcTriggerSource (ADC_TriggerSource_t trigger);

/*! \fn void adcTriggerEnable(_Bool trigEn)
 *  \brief Enable or disable the auto trigger.
 *
 *  \warning For devices like \c ATmega8 and \c ATmega128,
 *  this function enable the free running mode.
 *
 *  \param trigEn Trigger enable/disable.
 */
void adcTriggerEnable(_Bool trigEn);

#if defined(__DOXYGEN__)
/*! \fn void adcDigitalInputDisable(ADC_DigitalChannel_t chanList)
 *  \brief Disable digital input for selected channel.
 *
 *  \warning Devices that do not support this feature will not have
 *  access to this function. It should be considered during device migration.
 *
 *  \param chanList List of channel that will have digital input disabled.
 */
void adcDigitalInputDisable(ADC_DigitalChannel_t chanList);

/*! \fn void adcDigitalInputEnable(ADC_DigitalChannel_t chanList)
 *  \brief Enable digital input for selected channel.
 *
 *  \warning Devices that do not support this feature will not have
 *  access to this function. It should be considered during device migration.
 *
 *  \param chanList List of channel that will have digital input enabled.
 */

void adcDigitalInputEnable(ADC_DigitalChannel_t chanList);
#endif

#if defined(ADC_DigitalInput)
void adcDigitalInputDisable(ADC_DigitalChannel_t chanList);
void adcDigitalInputEnable(ADC_DigitalChannel_t chanList);
#endif

#endif /*ADC_H_*/
