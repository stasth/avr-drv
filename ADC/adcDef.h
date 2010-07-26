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

/*! \file adcDef.h
 \brief This file declares \c typedef used by the ADC module.

 Not all part of the following \c enum are available to all devices.

 \author Frédéric Nadeau
 */
#ifndef ADCDEF_H_
#define ADCDEF_H_

/*! List of available prescaler. */
enum adc_prescaler_e
{
    adc_prescaler_2 = 0, /*!< Oscillator clock divided by 2. */
    adc_prescaler_2_, /*!< Oscillator clock divided by 2. Alternate setting. */
    adc_prescaler_4, /*!< Oscillator clock divided by 4. */
    adc_prescaler_8, /*!< Oscillator clock divided by 8. */
    adc_prescaler_16, /*!< Oscillator clock divided by 16. */
    adc_prescaler_32,/*!< Oscillator clock divided by 32. */
    adc_prescaler_64,/*!< Oscillator clock divided by 64. */
    adc_prescaler_128,/*!< Oscillator clock divided by 128. */
};

/*! List of available prescaler typedef. */
typedef enum adc_prescaler_e adc_prescaler_t;

#if defined(__DOXYGEN__)
/*! List of available voltage reference. */
enum adc_voltage_ref_e
{
    adc_voltage_ref_aref = 0, /*!< ADC use Aref PIN as voltage reference. */
    adc_voltage_ref_avcc, /*!< ADC use VCC as voltage reference. */
    adc_voltage_ref_internal_1_1_wcap, /*!< ADC use internal 1.1 Voltage reference. */
    adc_voltage_ref_internal_2_56_wcap, /*!< ADC use internal 2.56 Voltage reference. */
    adc_voltage_ref_internal_2_56_wocap, /*!< ADC use internal 2.56 Voltage reference. */
};

/*! List of available voltage reference typedef.
 *
 * Note that not all voltage references are available. Availability is determined
 * by the device used.
 * */
typedef enum adc_voltage_ref_e adc_voltage_ref_t;

#elif defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_AT90PWM1__) \
|| defined(__AVR_AT90PWM2__) \
|| defined(__AVR_AT90PWM2B__) \
|| defined(__AVR_AT90PWM3__) \
|| defined(__AVR_AT90PWM3B__)
typedef enum adc_voltage_ref_e
{
    adc_voltage_ref_aref = 0,
    adc_voltage_ref_avcc,
    adc_voltage_ref_internal_2_56_wcap = 3,
}adc_voltage_ref_t;

#else
#   error "adc_voltage_ref_t not defined for your device"
#endif

#if defined(__DOXYGEN__)
/*! List of available trigger source. */
enum adc_trigger_source_e
{
    adc_trigger_source_free_running = 0, /*!< ADC is in free running mode. */
    adc_trigger_source_analog_comparator, /*!< Start of conversion is triggered by the analog comparator. */
    adc_trigger_source_ext_int_request0, /*!< Start of conversion is triggered by the external request 0. */
    adc_trigger_source_timer_0_compare_match, /*!< Start of conversion is triggered by timer 0 compare match. */
    adc_trigger_source_timer_0_overflow, /*!< Start of conversion is triggered by timer 0 overflow. */
    adc_trigger_source_timer_1_compare_match_b, /*!< Start of conversion is triggered by timer 1 compare match B. */
    adc_trigger_source_timer_1_overflow, /*!< Start of conversion is triggered by timer 1 overflow. */
    adc_trigger_source_timer_1_capture_event, /*!< Start of conversion is triggered by timer 1 capture event. */
};

/*! List of available trigger source typedef. */
typedef enum adc_trigger_source_e adc_trigger_source_t;
#elif defined(__AVR_ATmega8__) \
|| defined(__AVR_ATmega103__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega163__) \
|| defined(__AVR_ATmega323__) \
|| defined(__AVR_ATtiny15__) \
|| defined(__AVR_ATtiny26__)
typedef enum adc_trigger_source_e
{
    adc_trigger_source_free_running
} adc_trigger_source_t;
#elif defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__)
typedef enum adc_trigger_source_e
{
    adc_trigger_source_free_running = 0,
    adc_trigger_source_analog_comparator,
    adc_trigger_source_ext_int_request0,
    adc_trigger_source_timer_0_compare_match,
    adc_trigger_source_timer_0_overflow,
    adc_trigger_source_timer_1_compare_match_b,
    adc_trigger_source_timer_1_overflow,
    adc_trigger_source_timer_1_capture_event,
} adc_trigger_source_t;
#elif defined(__AVR_AT90PWM1__)
typedef enum adc_trigger_source_e
{
    adc_trigger_source_free_running = 0,
    adc_trigger_source_analog_comparator,
    adc_trigger_source_ext_int_request0,
    adc_trigger_source_timer_0_compare_match,
    adc_trigger_source_timer_0_overflow,
    adc_trigger_source_timer_1_compare_match_b,
    adc_trigger_source_timer_1_overflow,
    adc_trigger_source_timer_1_capture_event,
    adc_trigger_source_psc0asy_event,
    adc_trigger_source_psc2asy_event = 10,
    adc_trigger_source_analog_comparator_1,
    adc_trigger_source_analog_comparator_2
} adc_trigger_source_t;
#elif defined(__AVR_AT90PWM2__) \
|| defined(__AVR_AT90PWM2B__) \
|| defined(__AVR_AT90PWM3__) \
|| defined(__AVR_AT90PWM3B__)
typedef enum adc_trigger_source_e
{
    adc_trigger_source_free_running = 0,
    adc_trigger_source_analog_comparator,
    adc_trigger_source_ext_int_request0,
    adc_trigger_source_timer_0_compare_match,
    adc_trigger_source_timer_0_overflow,
    adc_trigger_source_timer_1_compare_match_b,
    adc_trigger_source_timer_1_overflow,
    adc_trigger_source_timer_1_capture_event,
    adc_trigger_source_psc0asy_event,
    adc_trigger_source_psc1asy_event,
    adc_trigger_source_psc2asy_event,
    adc_trigger_source_analog_comparator_1,
    adc_trigger_source_analog_comparator_2
} adc_trigger_source_t;
#else
#   error "adc_trigger_source_t not defined for your device"
#endif

#if defined(__DOXYGEN__)
/*! List of available input for ADC. */
enum adc_input_channel_e
{
    adc_input_channel_0 = 0, /*!< ADC use ADCpin 0. */
    adc_input_channel_1, /*!< ADC use ADCpin 1. */
    adc_input_channel_2, /*!< ADC use ADCpin 2. */
    adc_input_channel_3, /*!< ADC use ADCpin 3. */
    adc_input_channel_4, /*!< ADC use ADCpin 4. */
    adc_input_channel_5, /*!< ADC use ADCpin 5. */
    adc_input_channel_6, /*!< ADC use ADCpin 6. */
    adc_input_channel_7, /*!< ADC use ADCpin 7. */
    adc_input_channel_p0_n0_10x, /*!< ADC use differential input (pin0 - pin0) * 10. */
    adc_input_channel_p1_n0_10x, /*!< ADC use differential input (pin1 - pin0) * 10. */
    adc_input_channel_p0_n0_200x, /*!< ADC use differential input (pin0 - pin0) * 200. */
    adc_input_channel_p1_n0_200x, /*!< ADC use differential input (pin1 - pin0) * 200. */
    adc_input_channel_p2_n2_10x, /*!< ADC use differential input (pin2 - pin2) * 10. */
    adc_input_channel_p3_n2_10x, /*!< ADC use differential input (pin3 - pin2) * 10. */
    adc_input_channel_p2_n2_200x, /*!< ADC use differential input (pin2 - pin2) * 200. */
    adc_input_channel_p3_n2_200x, /*!< ADC use differential input (pin3 - pin2) * 200. */
    adc_input_channel_p0_n1_1x, /*!< ADC use differential input (pin0 - pin1) * 1. */
    adc_input_channel_p1_n1_1x, /*!< ADC use differential input (pin1 - pin1) * 1. */
    adc_input_channel_p2_n1_1x, /*!< ADC use differential input (pin2 - pin1) * 1. */
    adc_input_channel_p3_n1_1x, /*!< ADC use differential input (pin3 - pin1) * 1. */
    adc_input_channel_p4_n1_1x, /*!< ADC use differential input (pin4 - pin1) * 1. */
    adc_input_channel_p5_n1_1x, /*!< ADC use differential input (pin5 - pin1) * 1. */
    adc_input_channel_p6_n1_1x, /*!< ADC use differential input (pin6 - pin1) * 1. */
    adc_input_channel_p7_n1_1x, /*!< ADC use differential input (pin7 - pin1) * 1. */
    adc_input_channel_p0_n2_1x, /*!< ADC use differential input (pin0 - pin2) * 1. */
    adc_input_channel_p1_n2_1x, /*!< ADC use differential input (pin1 - pin2) * 1. */
    adc_input_channel_p2_n2_1x, /*!< ADC use differential input (pin2 - pin2) * 1. */
    adc_input_channel_p3_n2_1x, /*!< ADC use differential input (pin3 - pin2) * 1. */
    adc_input_channel_p4_n2_1x, /*!< ADC use differential input (pin4 - pin2) * 1. */
    adc_input_channel_p5_n2_1x, /*!< ADC use differential input (pin5 - pin2) * 1. */
    adc_input_channel_VBG, /*!< ADC use Vbg, Band gap(see documentation for per-device reference). */
    adc_input_channel_GND, /*!< ADC use ground. */
    adc_input_channel_8, /*!< ADC use ADCpin 8. */
    adc_input_channel_9, /*!< ADC use ADCpin 9. */
    adc_input_channel_10, /*!< ADC use ADCpin 10. */
    adc_input_channel_11, /*!< ADC use ADCpin 11. */
    adc_input_channel_12, /*!< ADC use ADCpin 12. */
    adc_input_channel_13, /*!< ADC use ADCpin 13. */
    adc_input_channel_14, /*!< ADC use ADCpin 14. */
    adc_input_channel_15, /*!< ADC use ADCpin 15. */
    adc_input_channel_p8_n8_10x, /*!< ADC use differential input (pin8 - pin8) * 10. */
    adc_input_channel_p9_n8_10x, /*!< ADC use differential input (pin9 - pin8) * 10. */
    adc_input_channel_p8_n8_200x, /*!< ADC use differential input (pin8 - pin8) * 200. */
    adc_input_channel_p9_n8_200x, /*!< ADC use differential input (pin9 - pin8) * 200. */
    adc_input_channel_p10_n10_10x, /*!< ADC use differential input (pin10 - pin10) * 10. */
    adc_input_channel_p11_n10_10x, /*!< ADC use differential input (pin11 - pin10) * 10. */
    adc_input_channel_p10_n10_200x, /*!< ADC use differential input (pin10 - pin10) * 200. */
    adc_input_channel_p11_n10_200x, /*!< ADC use differential input (pin11 - pin10) * 200. */
    adc_input_channel_p8_n9_1x, /*!< ADC use differential input (pin8 - pin9) * 1. */
    adc_input_channel_p9_n9_1x, /*!< ADC use differential input (pin9 - pin9) * 1. */
    adc_input_channel_p10_n9_1x, /*!< ADC use differential input (pin10 - pin9) * 1. */
    adc_input_channel_p11_n9_1x, /*!< ADC use differential input (pin11 - pin9) * 1. */
    adc_input_channel_p12_n9_1x, /*!< ADC use differential input (pin12 - pin9) * 1. */
    adc_input_channel_p13_n9_1x, /*!< ADC use differential input (pin13 - pin9) * 1. */
    adc_input_channel_p14_n9_1x, /*!< ADC use differential input (pin14 - pin9) * 1. */
    adc_input_channel_p15_n9_1x, /*!< ADC use differential input (pin15 - pin9) * 1. */
    adc_input_channel_p8_n10_1x, /*!< ADC use differential input (pin8 - pin10) * 1. */
    adc_input_channel_p9_n10_1x, /*!< ADC use differential input (pin9 - pin10) * 1. */
    adc_input_channel_p10_n10_1x, /*!< ADC use differential input (pin10 - pin10) * 1. */
    adc_input_channel_p11_n10_1x, /*!< ADC use differential input (pin11 - pin10) * 1. */
    adc_input_channel_p12_n10_1x, /*!< ADC use differential input (pin12 - pin10) * 1. */
    adc_input_channel_p13_n10_1x, /*!< ADC use differential input (pin13 - pin10) * 1. */
};

/*! List of available input for ADC typedef. */
typedef enum adc_input_channel_e adc_input_channel_t;
#elif defined(__AVR_AT90PWM1__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_AMP0 = 0x0B,
    adc_input_channel_VBG = 0x0E,
    adc_input_channel_GND = 0x0F
} adc_input_channel_t;
#elif defined(__AVR_AT90PWM2__) \
|| defined(__AVR_AT90PWM2B__) \
|| defined(__AVR_AT90PWM3__) \
|| defined(__AVR_AT90PWM3B__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_8,
    adc_input_channel_9,
    adc_input_channel_10,
    adc_input_channel_AMP0,
    adc_input_channel_AMP1,
    adc_input_channel_VBG = 0x0E,
    adc_input_channel_GND = 0x0F
} adc_input_channel_t;
#elif defined(__AVR_ATmega8__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_VBG = 0x0E,
    adc_input_channel_GND = 0x0F
} adc_input_channel_t;
#elif defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega16__) \
|| defined(__AVR_ATmega16__) \
|| defined(__AVR_ATmega32__) \
|| defined(__AVR_ATmega64__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined (__AVR_ATmega1284P__) \
|| defined(__AVR_ATmega8535__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_p0_n0_10x,
    adc_input_channel_p1_n0_10x,
    adc_input_channel_p0_n0_200x,
    adc_input_channel_p1_n0_200x,
    adc_input_channel_p2_n2_10x,
    adc_input_channel_p3_n2_10x,
    adc_input_channel_p2_n2_200x,
    adc_input_channel_p3_n2_200x,
    adc_input_channel_p0_n1_1x,
    adc_input_channel_p1_n1_1x,
    adc_input_channel_p2_n1_1x,
    adc_input_channel_p3_n1_1x,
    adc_input_channel_p4_n1_1x,
    adc_input_channel_p5_n1_1x,
    adc_input_channel_p6_n1_1x,
    adc_input_channel_p7_n1_1x,
    adc_input_channel_p0_n2_1x,
    adc_input_channel_p1_n2_1x,
    adc_input_channel_p2_n2_1x,
    adc_input_channel_p3_n2_1x,
    adc_input_channel_p4_n2_1x,
    adc_input_channel_p5_n2_1x,
    adc_input_channel_VBG,
    adc_input_channel_GND
} adc_input_channel_t;
#elif defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_p0_n0_10x,
    adc_input_channel_p1_n0_10x,
    adc_input_channel_p0_n0_200x,
    adc_input_channel_p1_n0_200x,
    adc_input_channel_p2_n2_10x,
    adc_input_channel_p3_n2_10x,
    adc_input_channel_p2_n2_200x,
    adc_input_channel_p3_n2_200x,
    adc_input_channel_p0_n1_1x,
    adc_input_channel_p1_n1_1x,
    adc_input_channel_p2_n1_1x,
    adc_input_channel_p3_n1_1x,
    adc_input_channel_p4_n1_1x,
    adc_input_channel_p5_n1_1x,
    adc_input_channel_p6_n1_1x,
    adc_input_channel_p7_n1_1x,
    adc_input_channel_p0_n2_1x,
    adc_input_channel_p1_n2_1x,
    adc_input_channel_p2_n2_1x,
    adc_input_channel_p3_n2_1x,
    adc_input_channel_p4_n2_1x,
    adc_input_channel_p5_n2_1x,
    adc_input_channel_VBG,
    adc_input_channel_GND,
    adc_input_channel_8,
    adc_input_channel_9,
    adc_input_channel_10,
    adc_input_channel_11,
    adc_input_channel_12,
    adc_input_channel_13,
    adc_input_channel_14,
    adc_input_channel_15,
    adc_input_channel_p8_n8_10x,
    adc_input_channel_p9_n8_10x,
    adc_input_channel_p8_n8_200x,
    adc_input_channel_p9_n8_200x,
    adc_input_channel_p10_n10_10x,
    adc_input_channel_p11_n10_10x,
    adc_input_channel_p10_n10_200x,
    adc_input_channel_p11_n10_200x,
    adc_input_channel_p8_n9_1x,
    adc_input_channel_p9_n9_1x,
    adc_input_channel_p10_n9_1x,
    adc_input_channel_p11_n9_1x,
    adc_input_channel_p12_n9_1x,
    adc_input_channel_p13_n9_1x,
    adc_input_channel_p14_n9_1x,
    adc_input_channel_p15_n9_1x,
    adc_input_channel_p8_n10_1x,
    adc_input_channel_p9_n10_1x,
    adc_input_channel_p10_n10_1x,
    adc_input_channel_p11_n10_1x,
    adc_input_channel_p12_n10_1x,
    adc_input_channel_p13_n10_1x,
    adc_input_channel_Reserved_1,
    adc_input_channel_Reserved_2,
} adc_input_channel_t;
#elif defined(__AVR_ATtiny4__) \
|| defined(__AVR_ATtiny5__) \
|| defined(__AVR_ATtiny9__) \
|| defined(__AVR_ATtiny10__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3
} adc_input_channel_t;
#else
#   error "adc_input_channel_selection_t not coded for device"
#endif

#if defined(__DOXYGEN__)
/*! List of digital input channel. */
enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x0001,    /*!< Digital input on pin0. */
    adc_digital_channel_1 = 0x0002,    /*!< Digital input on pin1. */
    adc_digital_channel_2 = 0x0004,    /*!< Digital input on pin2. */
    adc_digital_channel_3 = 0x0008,    /*!< Digital input on pin3. */
    adc_digital_channel_4 = 0x0010,    /*!< Digital input on pin4. */
    adc_digital_channel_5 = 0x0020,    /*!< Digital input on pin5. */
    adc_digital_channel_6 = 0x0040,    /*!< Digital input on pin6. */
    adc_digital_channel_7 = 0x0080,    /*!< Digital input on pin7. */
    adc_digital_channel_8 = 0x0100,    /*!< Digital input on pin8. */
    adc_digital_channel_9 = 0x0200,    /*!< Digital input on pin9. */
    adc_digital_channel_10 = 0x0400,   /*!< Digital input on pin10. */
    adc_digital_channel_11 = 0x0800,   /*!< Digital input on pin11. */
    adc_digital_channel_12 = 0x1000,   /*!< Digital input on pin12. */
    adc_digital_channel_13 = 0x2000,   /*!< Digital input on pin13. */
    adc_digital_channel_14 = 0x4000,   /*!< Digital input on pin14. */
    adc_digital_channel_15 = 0x8000    /*!< Digital input on pin15. */
};

/*! List of digital input channel typedef. */
typedef enum adc_digital_channel_e adc_digital_channel_t
#elif defined(__AVR_AT90PWM1__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x0001,
    adc_digital_channel_1 = 0x0002,
    adc_digital_channel_2 = 0x0004,
    adc_digital_channel__acmp2d = 0x0004,
    adc_digital_channel_3 = 0x0008,
    adc_digital_channel__acmpm = 0x0008,
    adc_digital_channel_4 = 0x0010,
    adc_digital_channel_5 = 0x0020,
    adc_digital_channel_6 = 0x0040,
    adc_digital_channel_7 = 0x0080,
    adc_digital_channel__amp0nd = 0x0800,
    adc_digital_channel__amp0pd = 0x1000,
    adc_digital_channel__acmp0d = 0x2000,
}adc_digital_channel_t;
#elif defined(__AVR_AT90PWM2__) \
|| defined(__AVR_AT90PWM2B__) \
|| defined(__AVR_AT90PWM3__) \
|| defined(__AVR_AT90PWM3B__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x0001,
    adc_digital_channel_1 = 0x0002,
    adc_digital_channel_2 = 0x0004,
    adc_digital_channel__acmp2d = 0x0004,
    adc_digital_channel_3 = 0x0008,
    adc_digital_channel__acmpm = 0x0008,
    adc_digital_channel_4 = 0x0010,
    adc_digital_channel_5 = 0x0020,
    adc_digital_channel_6 = 0x0040,
    adc_digital_channel_7 = 0x0080,
    adc_digital_channel_8 = 0x0100,
    adc_digital_channel__amp1nd = 0x0100,
    adc_digital_channel_9 = 0x0200,
    adc_digital_channel__amp1pd = 0x0200,
    adc_digital_channel_10 = 0x0400,
    adc_digital_channel__acmp1d = 0x0400,
    adc_digital_channel__amp0nd = 0x0800,
    adc_digital_channel__amp0pd = 0x1000,
    adc_digital_channel__acmp0d = 0x2000,
}adc_digital_channel_t;
#elif defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x0001,
    adc_digital_channel_1 = 0x0002,
    adc_digital_channel_2 = 0x0004,
    adc_digital_channel_3 = 0x0008,
    adc_digital_channel_4 = 0x0010,
    adc_digital_channel_5 = 0x0020,
    adc_digital_channel_6 = 0x0040,
    adc_digital_channel_7 = 0x0080
}adc_digital_channel_t;
#elif defined (__AVR_ATmega16U4__) \
|| defined (__AVR_ATmega32U4__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x0001,
    adc_digital_channel_1 = 0x0002,
    adc_digital_channel_4 = 0x0010,
    adc_digital_channel_5 = 0x0020,
    adc_digital_channel_6 = 0x0040,
    adc_digital_channel_7 = 0x0080,
    adc_digital_channel_8 = 0x0100,
    adc_digital_channel_9 = 0x0200,
    adc_digital_channel_10 = 0x0400,
    adc_digital_channel_11 = 0x0800,
    adc_digital_channel_12 = 0x1000,
    adc_digital_channel_13 = 0x2000
}adc_digital_channel_t;
#elif defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x0001,
    adc_digital_channel_1 = 0x0002,
    adc_digital_channel_2 = 0x0004,
    adc_digital_channel_3 = 0x0008,
    adc_digital_channel_4 = 0x0010,
    adc_digital_channel_5 = 0x0020,
    adc_digital_channel_6 = 0x0040,
    adc_digital_channel_7 = 0x0080,
    adc_digital_channel_8 = 0x0100,
    adc_digital_channel_9 = 0x0200,
    adc_digital_channel_10 = 0x0400,
    adc_digital_channel_11 = 0x0800,
    adc_digital_channel_12 = 0x1000,
    adc_digital_channel_13 = 0x2000,
    adc_digital_channel_14 = 0x4000,
    adc_digital_channel_15 = 0x8000
}adc_digital_channel_t;
#elif defined(__AVR_ATtiny4__) \
|| defined(__AVR_ATtiny5__) \
|| defined(__AVR_ATtiny9__) \
|| defined(__AVR_ATtiny10__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x0001,
    adc_digital_channel_1 = 0x0002,
    adc_digital_channel_2 = 0x0004,
    adc_digital_channel_3 = 0x0008
}adc_digital_channel_t;
#else
#   error "adc_digital_channel_t not defined for your device"
#endif

#endif /*ADCDEF_H_*/
