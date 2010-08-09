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
#include "tmrcnt5.h"

void
tmrcnt2_init (tmrcnt2_wgm_t wgm, tmrcnt2_clk_select_t prescale)
{
  // Force timer to stop
  TCCR5B &= ~((1 << CS52) | (1 << CS51) | (1 << CS50));

  switch (wgm)
    {
    case tmrcnt5_wgm_normal_ffff_imd_max:
      TCCR5B &= ~((1 << WGM53) | (1 << WGM52));
      TCCR5A &= ~((1 << WGM51) | (1 << WGM50));
      break;

    case tmrcnt5_wgm_pwm_phase_correct_8bit_00ff_top_btm:
      TCCR5B &= ~((1 << WGM53) | (1 << WGM52));
      TCCR5A &= ~(1 << WGM51);
      TCCR5A |= (1 << WGM50);
      break;

    case tmrcnt5_wgm_pwm_phase_correct_9bit_01ff_top_btm:
      TCCR5B &= ~((1 << WGM53) | (1 << WGM52));
      TCCR5A |= (1 << WGM51);
      TCCR5A &= ~(1 << WGM50);
      break;

    case tmrcnt5_wgm_pwm_phase_correct_10bit_03ff_top_btm:
      TCCR5B &= ~((1 << WGM53) | (1 << WGM52));
      TCCR5A |= ((1 << WGM51) | (1 << WGM50));
      break;

    case tmrcnt5_wgm_ctc_ocr5a_imd_max:
      TCCR5B &= ~(1 << WGM53);
      TCCR5B |= (1 << WGM52);
      TCCR5A &= ~((1 << WGM51) | (1 << WGM50));
      break;

    case tmrcnt5_wgm_fast_pwm_8bit_00ff_btm_top:
      TCCR5B &= ~(1 << WGM53);
      TCCR5B |= (1 << WGM52);
      TCCR5A &= ~(1 << WGM51);
      TCCR5A |= (1 << WGM50);
      break;

    case tmrcnt5_wgm_fast_pwm_9bit_01ff_btm_top:
      TCCR5B &= ~(1 << WGM53);
      TCCR5B |= (1 << WGM52);
      TCCR5A |= (1 << WGM51);
      TCCR5A &= ~(1 << WGM50);
      break;

    case tmrcnt5_wgm_fast_pwm_10bit_03ff_btm_top:
      TCCR5B &= ~(1 << WGM53);
      TCCR5B |= (1 << WGM52);
      TCCR5A |= ((1 << WGM51) | (1 << WGM50));
      break;

    case tmrcnt5_wgm_pwm_phase_freq_correct_icr5_btm_btm:
      TCCR5B |= (1 << WGM53);
      TCCR5B &= ~(1 << WGM52);
      TCCR5A &= ~((1 << WGM51) | (1 << WGM50));
      break;

    case tmrcnt5_wgm_pwm_phase_freq_correct_ocr5a_btm_btm:
      TCCR5B |= (1 << WGM53);
      TCCR5B &= ~(1 << WGM52);
      TCCR5A &= ~(1 << WGM51);
      TCCR5A |= (1 << WGM50);
      break;

    case tmrcnt5_wgm_pwm_phase_correct_icr5_top_btm:
      TCCR5B |= (1 << WGM53);
      TCCR5B &= ~(1 << WGM52);
      TCCR5A |= (1 << WGM51);
      TCCR5A &= ~(1 << WGM50);
      break;

    case tmrcnt5_wgm_pwm_phase_correct_ocr5a_top_btm:
      TCCR5B |= (1 << WGM53);
      TCCR5B &= ~(1 << WGM52);
      TCCR5A |= ((1 << WGM51) | (1 << WGM50));
      break;

    case tmrcnt5_wgm_ctc_icr5_imd_max:
      TCCR5B |= ((1 << WGM53) | (1 << WGM52));
      TCCR5A &= ~((1 << WGM51) | (1 << WGM50));
      break;

    case tmrcnt5_wgm_fast_pwm_icr5_top_top:
      TCCR5B |= ((1 << WGM53) | (1 << WGM52));
      TCCR5A |= (1 << WGM51);
      TCCR5A &= ~(1 << WGM50);
      break;

    case tmrcnt5_wgm_fast_pwm_ocr5a_top_top:
      TCCR5B |= ((1 << WGM53) | (1 << WGM52));
      TCCR5A |= ((1 << WGM51) | (1 << WGM50));
      break;

    default:
      break;
    }

#if !(CS52 == (CS50 + 2) && CS51 == (CS50 + 1))
#   error "tmrcnt2_init needs to be rewritten for this device"
#endif
  TCCR5B |= (prescale << CS50);
}

void
timerCounterSetOuputComparePin5 (TimerOuputCompareChannel_Type1 channel,
				 uint8_t mode)
{
  assert (mode < 4);

  switch (channel)
    {
    case TOCC1_A:
      TCCR5A &= ~((1 << COM5A1) | (1 << COM5A0));
      TCCR5A |= (mode << COM5A0);
      break;

    case TOCC1_B:
      TCCR5A &= ~((1 << COM5B1) | (1 << COM5B0));
      TCCR5A |= (mode << COM5B0);
      break;

    case TOCC1_C:
      TCCR5A &= ~((1 << COM5C1) | (1 << COM5C0));
      TCCR5A |= (mode << COM5C0);
      break;

    default:
      assert (0);
      break;
    }
}

void
timerCounterForceOuputCompare5 (TimerOuputCompareChannel_Type1 channel)
{
  switch (channel)
    {
    case TOCC1_A:
      TCCR5C |= (1 << FOC5A);
      break;

    case TOCC1_B:
      TCCR5C |= (1 << FOC5B);
      break;

    case TOCC1_C:
      TCCR5C |= (1 << FOC5C);
      break;

    default:
      assert (0);
      break;
    }
}

uint16_t
timerCounterReadTimer5 (void)
{
  return TCNT5;
}

void
timerCounterSetTimer5 (uint16_t value)
{
  TCNT5 = value;
}

uint16_t
timerCounterReadOutputCompare5 (TimerOuputCompareChannel_Type1 channel)
{
  uint16_t retVal;

  switch (channel)
    {
    case TOCC1_A:
      retVal = OCR5A;
      break;

    case TOCC1_B:
      retVal = OCR5B;
      break;

    case TOCC1_C:
      retVal = OCR5C;
      break;

    default:
      assert (0);
      retVal = 0;
      break;
    }
    
    return retVal;
}

void
timerCounterSetOutputCompare5 (TimerOuputCompareChannel_Type1 channel, uint16_t value)
{
  switch (channel)
    {
    case TOCC1_A:
      OCR5A = value;
      break;

    case TOCC1_B:
      OCR5B = value;
      break;

    case TOCC1_C:
      OCR5C = value;
      break;

    default:
      assert (0);
      break;
    }
}

uint16_t
timerCounterReadInputCapture5 (void)
{
  return ICR5;
}

void
timerCounterEnableInputCaptureInt5 (void)
{
  TIMSK5 |= (1 << ICIE5);
}

void
timerCounterDisableInputCaptureInt5 (void)
{
  TIMSK5 &= ~(1 << ICIE5);
}

void
timerCounterEnableOutputCompareMatchInt5 (TimerOuputCompareChannel_Type1 channel)
{
  switch (channel)
    {
    case TOCC1_A:
      TIMSK5 |= (1 << OCIE5A);
      break;

    case TOCC1_B:
      TIMSK5 |= (1 << OCIE5B);
      break;

    case TOCC1_C:
      TIMSK5 |= (1 << OCIE5C);
      break;

    default:
      assert (0);
      break;
    }
}

void
timerCounterEnableDisableCompareMatchInt5 (TimerOuputCompareChannel_Type1 channel)
{
  switch (channel)
    {
    case TOCC1_A:
      TIMSK5 &= ~(1 << OCIE5A);
      break;

    case TOCC1_B:
      TIMSK5 &= ~(1 << OCIE5B);
      break;

    case TOCC1_C:
      TIMSK5 &= ~(1 << OCIE5C);
      break;

    default:
      assert (0);
      break;
    }
}

void
timerCounterEnableOverflowInt5 (void)
{
  TIMSK5 |= (1 << TOIE5);
}

void
timerCounterDisableOverfloweInt5 (void)
{
  TIMSK5 &= ~(1 << TOIE5);
}
