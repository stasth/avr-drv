/* Copyright (c) 2010 Frédéric Nadeau
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

#include <stdint.h>
#include <stdlib.h>
#include <avr/io.h>

#include "tmrcnt0.h"

#if defined(__AVR_AT90can32__) \
|| defined(__AVR_AT90can64__) \
|| defined(__AVR_AT90can128__) \
|| defined(__AVR_ATmega640__)
void tmrcnt0_init(tmrcnt0_wgm_t wgm, tmrcnt0_com_t, com, tmrcnt0_clk_select_t prescale)
{
    /* Force timer to stop */
    TCCR0A &= ~(_BV(CS02) | _BV(CS01) | _BV(CS00));

    switch (mode)
    {
    case tmrcnt0_wgm_normal_ff_imd_max:
        TCCR0A &= ~(_BV(WGMx1) | _BV(WGMx0));
        break;

    case tmrcnt0_wgm_pwm_phase_correct_ff_top_btm:
        TCCR0A &= ~_BV(WGMx1);
        TCCR0A |= _BV(WGMx0);
        break;

    case tmrcnt0_wgm_ctc_ocra_imd_max:
        TCCR0A |= _BV(WGMx1);
        TCCR0A &= ~_BV(WGMx0);
        break;

    case tmrcnt0_wgm_fast_pwm_ff_top_max:
        TCCR0A |= _BV(WGMx1);
        TCCR0A |= _BV(WGMx0);
        break;
    default:
        break;
    }

    switch (prescale)
    {
    case tmrcnt0_clk_src_halted:
        //We do not need to do anything since timer as been stop already
        break;

    case tmrcnt0_clk_src_clkio:
        TCCR0A |= _BV(CS00);
        break;

    case tmrcnt0_clk_src_clkio_8:
        TCCR0A |= _BV(CS01);
        break;

    case tmrcnt0_clk_src_clkio_64:
        TCCR0A |= (_BV(CS01) | _BV(CS00));
        break;

    case tmrcnt0_clk_src_clkio_256:
        TCCR0A |= _BV(CS02);
        break;

    case tmrcnt0_clk_src_clkio_1024:
        TCCR0A |= (_BV(CS02) | _BV(CS00));
        break;

    case tmrcnt0_clk_src_ext_clk_falling_edge:
        TCCR0A |= (_BV(CS02) | _BV(CS01));

        break;

    case tmrcnt0_clk_src_ext_clk_rising_edge:
        TCCR0A |= (_BV(CS02) | _BV(CS01) | _BV(CS00));
        break;

    default:
        break;

    }
}
#else
#endif

#if defined(__AVR_AT90can32__) \
|| defined(__AVR_AT90can64__) \
|| defined(__AVR_AT90can128__)
void tmrcnt0_set_ouput_compare_pin (tmrcnt0_ouput_compare_channel_t channel, tmrcnt0_com_t mode)
{
    switch (channel)
    {
        case tmrcnt0_ouput_compare_channel_a:
        TCCR0A &= ~(_BV(COM0A1) | _BV(COM0A0));
        TCCR0A |= (mode << COM0A0);
        break;
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
        case tmrcnt0_ouput_compare_channel_b:
        TCCR0A &= ~(_BV(COM0B1) | _BV(COM0B0));
        TCCR0A |= (mode << COM0B0);
        break;
#endif /* defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) */
        default:
        break;
    }
}

void timerCounterForceOuputCompare0(TimerOuputCompareChannel_Type2 channel)
{
    switch (channel)
    {
    case tmrcnt0_ouput_compare_channel_a:
        TCCR0A |= _BV(FOC0A);
        break;
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
        case tmrcnt0_ouput_compare_channel_b:
        TCCRnB |= _BV(FOCxB);
        break;
#endif /* defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) */
        default:
        break;
    }
}
#endif

uint8_t tmrcnt0_get_timer(void)
{
    return TCNT0;
}

void tmrcnt0_set_timer(uint8_t value)
{
    TCNT0 = value;
}

#if defined(__AVR_AT90can32__) \
|| defined(__AVR_AT90can64__) \
|| defined(__AVR_AT90can128__)
uint8_t tmrcnt0_get_output_compare(tmrcnt0_ouput_compare_channel_t channel)
{
    uint8_t retVal = 0;

    switch (channel)
    {
    case tmrcnt0_ouput_compare_channel_a:
        retVal = OCR0A;
        break;
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
        case tmrcnt0_ouput_compare_channel_b:
        retVal = OCRnB;
        break;
#endif /* defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) */
    default:
        break;
    }
    return retVal;
}

void tmrcnt0_set_output_compare(tmrcnt0_ouput_compare_channel_t channel,
        uint8_t value)
{
    switch (channel)
    {
    case tmrcnt0_ouput_compare_channel_a:
        OCR0A = value;
        break;
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
        case tmrcnt0_ouput_compare_channel_b:
        OCRnB = value;
        break;
#endif /* defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) */      
    default:
        break;
    }
}

void tmrcnt0_output_compare_match_int_enable(
        tmrcnt0_ouput_compare_channel_t channel)
{
    switch (channel)
    {
    case tmrcnt0_ouput_compare_channel_a:
        TIMSK0 |= _BV(OCIE0A);
        break;
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
        case tmrcnt0_ouput_compare_channel_b:
        TIMSKn |= _BV(OCIExB);
        break;
#endif /* defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) */
    default:
        break;
    }
}

void tmrcnt0_output_compare_match_int_disable(
        tmrcnt0_ouput_compare_channel_t channel)
{
    switch (channel)
    {
    case tmrcnt0_ouput_compare_channel_a:
        TIMSK0 &= ~_BV(OCIE0A);
        break;
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
        case tmrcnt0_ouput_compare_channel_b:
        TIMSKn &= ~_BV(OCIExB);
        break;
#endif /* defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) */
    default:
        break;
    }
}
#endif

void tmrcnt0_enable_overflow_int(void)
{
    TIMSK0 |= _BV(TOIE0);
}

void tmrcnt0_disable_overflow_int(void)
{
    TIMSK0 &= ~_BV(TOIE0);
}
