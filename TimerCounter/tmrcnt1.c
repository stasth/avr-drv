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

#include <assert.h>
#include <avr/io.h>
#include <stdlib.h>
#include <stdint.h>

#include "timerCounter1_16BitSync.h"

#define TCCRnA   TCCR1A
#define TCCRnB   TCCR1B
#define TCCRnC   TCCR1C
#define TCNTn    TCNT1
#define OCRnA    OCR1A
#define OCRnB    OCR1B
#define OCRnC    OCR1C
#define ICRn     ICR1
#define TIMSKn   TIMSK1

#define CSx0     CS10
#define CSx1     CS11
#define CSx2     CS12

#define WGMx0    WGM10
#define WGMx1    WGM11
#define WGMx2    WGM12
#define WGMx3    WGM13

#define COMxA0   COM1A0
#define COMxA1   COM1A1
#define COMxB0   COM1B0
#define COMxB1   COM1B1
#define COMxC0   COM1C0
#define COMxC1   COM1C1

#define FOCxA    FOC1A
#define FOCxB    FOC1B
#define FOCxC    FOC1C

#define ICIEx    ICIE1

#define OCIExA   OCIE1A
#define OCIExB   OCIE1B
#define OCIExC   OCIE1C

#define TOIEx    TOIE1

void
timerCounterInit1 (TimerWaveformGenMode_Type2 mode, PrescalerForSyncTimer prescale)
{
  // Argument check, bypass with NDEBUG
  assert (mode < TWGM2_InvalidTimerWaveformGenMode_Type2);
  assert (prescale < InvalidPrescalerForSyncTimer);

  // Force timer to stop
  TCCRnB &= ~((1 << CSx2) | (1 << CSx1) | (1 << CSx0));

  switch (mode)
    {
    case TWGM2_Normal:
      TCCRnB &= ~((1 << WGMx3) | (1 << WGMx2));
      TCCRnA &= ~((1 << WGMx1) | (1 << WGMx0));
      break;

    case TWGM2_PWMPhaseCorrect_8bits:
      TCCRnB &= ~((1 << WGMx3) | (1 << WGMx2));
      TCCRnA &= ~(1 << WGMx1);
      TCCRnA |= (1 << WGMx0);
      break;

    case TWGM2_PWMPhaseCorrect_9bits:
      TCCRnB &= ~((1 << WGMx3) | (1 << WGMx2));
      TCCRnA |= (1 << WGMx1);
      TCCRnA &= ~(1 << WGMx0);
      break;

    case TWGM2_PWMPhaseCorrect_10bits:
      TCCRnB &= ~((1 << WGMx3) | (1 << WGMx2));
      TCCRnA |= ((1 << WGMx1) | (1 << WGMx0));
      break;

    case TWGM2_CTC_TopAtOCRnA:
      TCCRnB &= ~(1 << WGMx3);
      TCCRnB |= (1 << WGMx2);
      TCCRnA &= ~((1 << WGMx1) | (1 << WGMx0));
      break;

    case TWGM2_FastPWM_8bits:
      TCCRnB &= ~(1 << WGMx3);
      TCCRnB |= (1 << WGMx2);
      TCCRnA &= ~(1 << WGMx1);
      TCCRnA |= (1 << WGMx0);
      break;

    case TWGM2_FastPWM_9bits:
      TCCRnB &= ~(1 << WGMx3);
      TCCRnB |= (1 << WGMx2);
      TCCRnA |= (1 << WGMx1);
      TCCRnA &= ~(1 << WGMx0);
      break;

    case TWGM2_FastPWM_10bits:
      TCCRnB &= ~(1 << WGMx3);
      TCCRnB |= (1 << WGMx2);
      TCCRnA |= ((1 << WGMx1) | (1 << WGMx0));
      break;

    case TWGM2_PWMPhaseAndFreqCorrect_TopAtICRn:
      TCCRnB |= (1 << WGMx3);
      TCCRnB &= ~(1 << WGMx2);
      TCCRnA &= ~((1 << WGMx1) | (1 << WGMx0));
      break;

    case TWGM2_PWMPhaseAndFreqCorrect_TopAtOCRnA:
      TCCRnB |= (1 << WGMx3);
      TCCRnB &= ~(1 << WGMx2);
      TCCRnA &= ~(1 << WGMx1);
      TCCRnA |= (1 << WGMx0);
      break;

    case TWGM2_PWMPhaseCorrect_TopAtICRn:
      TCCRnB |= (1 << WGMx3);
      TCCRnB &= ~(1 << WGMx2);
      TCCRnA |= (1 << WGMx1);
      TCCRnA &= ~(1 << WGMx0);
      break;

    case TWGM2_PWMPhaseCorrect_TopAtOCRnA:
      TCCRnB |= (1 << WGMx3);
      TCCRnB &= ~(1 << WGMx2);
      TCCRnA |= ((1 << WGMx1) | (1 << WGMx0));
      break;

    case TWGM2_CTC_TopAtICRn:
      TCCRnB |= ((1 << WGMx3) | (1 << WGMx2));
      TCCRnA &= ~((1 << WGMx1) | (1 << WGMx0));
      break;

    case TWGM2_FastPWM_TopAtICRn:
      TCCRnB |= ((1 << WGMx3) | (1 << WGMx2));
      TCCRnA |= (1 << WGMx1);
      TCCRnA &= ~(1 << WGMx0);
      break;

    case TWGM2_FastPWM_TopAtOCRnA:
      TCCRnB |= ((1 << WGMx3) | (1 << WGMx2));
      TCCRnA |= ((1 << WGMx1) | (1 << WGMx0));
      break;

    default:
    case TWGM2_RESERVED:
      assert (0);
      break;
    }

  switch (prescale)
    {
    case PFST_clkHalted:
      //We do not need to do anything since timer as been stop already
      //TCCRnB &= ~((1 << CSx2) | (1 << CSx1) | (1 << CSx0));
      break;

    case PFST_clk_1:
      //TCCRnB &= ~((1 << CSx2) | (1 << CSx1));
      TCCRnB |= (1 << CSx0);
      break;

    case PFST_clk_8:
      //TCCRnB &= ~((1 << CSx2) | (1 << CSx0));
      TCCRnB |= (1 << CSx1);
      break;

    case PFST_clk_64:
      //TCCRnB &= ~(1 << CSx2);
      TCCRnB |= ((1 << CSx1) | (1 << CSx0));
      break;

    case PFST_clk_256:
      TCCRnB |= (1 << CSx2);
      //TCCRnB &= ~((1 << CSx1) | (1 << CSx0));
      break;

    case PFST_clk_1024:
      TCCRnB |= ((1 << CSx2) | (1 << CSx0));
      //TCCRnB &= ~(1 << CSx1);
      break;

    case PFST_clkTn_NegativeEdge:
      TCCRnB |= ((1 << CSx2) | (1 << CSx1));
      //TCCRnB &= ~(1 << CSx0);
      break;

    case PFST_clkTn_PositiveEdge:
      TCCRnB |= ((1 << CSx2) | (1 << CSx1) | (1 << CSx0));
      break;

    default:
      assert(0);
      break;

    }
}

void
timerCounterSetOuputComparePin1 (TimerOuputCompareChannel_Type1 channel,
				 uint8_t mode)
{
  assert (mode < 4);

  switch (channel)
    {
    case TOCC1_A:
      TCCRnA &= ~((1 << COMxA1) | (1 << COMxA0));
      TCCRnA |= (mode << COMxA0);
      break;

    case TOCC1_B:
      TCCRnA &= ~((1 << COMxB1) | (1 << COMxB0));
      TCCRnA |= (mode << COMxB0);
      break;

    case TOCC1_C:
      TCCRnA &= ~((1 << COMxC1) | (1 << COMxC0));
      TCCRnA |= (mode << COMxC0);
      break;

    default:
      assert (0);
      break;
    }
}

void
timerCounterForceOuputCompare1 (TimerOuputCompareChannel_Type1 channel)
{
  switch (channel)
    {
    case TOCC1_A:
      TCCRnC |= (1 << FOCxA);
      break;

    case TOCC1_B:
      TCCRnC |= (1 << FOCxB);
      break;

    case TOCC1_C:
      TCCRnC |= (1 << FOCxC);
      break;

    default:
      assert (0);
      break;
    }
}

uint16_t
timerCounterReadTimer1 (void)
{
  return TCNTn;
}

void
timerCounterSetTimer1 (uint16_t value)
{
  TCNTn = value;
}

uint16_t
timerCounterReadOutputCompare1 (TimerOuputCompareChannel_Type1 channel)
{
  uint16_t retVal;

  switch (channel)
    {
    case TOCC1_A:
      retVal = OCRnA;
      break;

    case TOCC1_B:
      retVal = OCRnB;
      break;

    case TOCC1_C:
      retVal = OCRnC;
      break;

    default:
      assert (0);
      retVal = 0;
      break;
    }
  return retVal;
}

void
timerCounterSetOutputCompare1 (TimerOuputCompareChannel_Type1 channel, uint16_t value)
{
  switch (channel)
    {
    case TOCC1_A:
      OCRnA = value;
      break;

    case TOCC1_B:
      OCRnB = value;
      break;

    case TOCC1_C:
      OCRnC = value;
      break;

    default:
      assert (0);
      break;
    }
}

uint16_t
timerCounterReadInputCapture1 (void)
{
  return ICRn;
}

void
timerCounterEnableInputCaptureInt1 (void)
{
  TIMSKn |= (1 << ICIEx);
}

void
timerCounterDisableInputCaptureInt1 (void)
{
  TIMSKn &= ~(1 << ICIEx);
}

void
timerCounterEnableOutputCompareMatchInt1 (TimerOuputCompareChannel_Type1 channel)
{
  switch (channel)
    {
    case TOCC1_A:
      TIMSKn |= (1 << OCIExA);
      break;

    case TOCC1_B:
      TIMSKn |= (1 << OCIExB);
      break;

    case TOCC1_C:
      TIMSKn |= (1 << OCIExC);
      break;

    default:
      assert (0);
      break;
    }
}

void
timerCounterEnableDisableCompareMatchInt1 (TimerOuputCompareChannel_Type1 channel)
{
  switch (channel)
    {
    case TOCC1_A:
      TIMSKn &= ~(1 << OCIExA);
      break;

    case TOCC1_B:
      TIMSKn &= ~(1 << OCIExB);
      break;

    case TOCC1_C:
      TIMSKn &= ~(1 << OCIExC);
      break;

    default:
      assert (0);
      break;
    }
}

void
timerCounterEnableOverflowInt1 (void)
{
  TIMSKn |= (1 << TOIEx);
}

void
timerCounterDisableOverfloweInt1 (void)
{
  TIMSKn &= ~(1 << TOIEx);
}
