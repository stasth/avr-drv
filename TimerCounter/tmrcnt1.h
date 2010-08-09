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

#ifndef TIMERCOUNTER1_H_
#define TIMERCOUNTER1_H_

#include "Timer/timerDef.h"

void timerCounterInit1 (TimerWaveformGenMode_Type2 mode, PrescalerForSyncTimer prescale);

void timerCounterSetOuputComparePin1 (TimerOuputCompareChannel_Type1 channel, uint8_t mode);

void timerCounterForceOuputCompare1 (TimerOuputCompareChannel_Type1 channel);

uint16_t timerCounterReadTimer1 (void);
void timerCounterSetTimer1 (uint16_t value);

uint16_t timerCounterReadOutputCompare1 (TimerOuputCompareChannel_Type1 channel);
void timerCounterSetOutputCompare1 (TimerOuputCompareChannel_Type1 channel, uint16_t value);

uint16_t timerCounterReadInputCapture1 (void);

void timerCounterEnableInputCaptureInt1 (void);
void timerCounterDisableInputCaptureInt1 (void);

void timerCounterEnableOutputCompareMatchInt1 (TimerOuputCompareChannel_Type1 channel);
void timerCounterEnableDisableCompareMatchInt1 (TimerOuputCompareChannel_Type1 channel);

void timerCounterEnableOverflowInt1 (void);
void timerCounterDisableOverfloweInt1 (void);

#endif /* TIMERCOUNTER1_H_ */
