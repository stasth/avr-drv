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

#ifndef TMR_CNT_5_H_
#define TMR_CNT_5_H_

typedef enum tmrcnt5_clk_select_e
{
    tmrcnt5_clk_src_halted = 0,
    tmrcnt5_clk_src_clkio,
    tmrcnt5_clk_src_clkio_8,
    tmrcnt5_clk_src_clkio_64,
    tmrcnt5_clk_src_clkio_256,
    tmrcnt5_clk_src_clkio_1024,
    tmrcnt5_clk_src_ext_clk_falling_edge,
    tmrcnt5_clk_src_ext_clk_rising_edge,
} tmrcnt5_clk_select_t;

typedef enum tmrcnt5_wgm_e
{
    tmrcnt5_wgm_normal_ffff_imd_max = 0,
    tmrcnt5_wgm_pwm_phase_correct_8bit_00ff_top_btm,
    tmrcnt5_wgm_pwm_phase_correct_9bit_01ff_top_btm,
    tmrcnt5_wgm_pwm_phase_correct_10bit_03ff_top_btm,
    tmrcnt5_wgm_ctc_ocr5a_imd_max,
    tmrcnt5_wgm_fast_pwm_8bit_00ff_btm_top,
    tmrcnt5_wgm_fast_pwm_9bit_01ff_btm_top,
    tmrcnt5_wgm_fast_pwm_10bit_03ff_btm_top,
    tmrcnt5_wgm_pwm_phase_freq_correct_icr5_btm_btm,
    tmrcnt5_wgm_pwm_phase_freq_correct_ocr5a_btm_btm,
    tmrcnt5_wgm_pwm_phase_correct_icr5_top_btm,
    tmrcnt5_wgm_pwm_phase_correct_ocr5a_top_btm,
    tmrcnt5_wgm_ctc_icr5_imd_max,
    tmrcnt5_wgm_fast_pwm_icr5_top_top = 14,
    tmrcnt5_wgm_fast_pwm_ocr5a_top_top
} tmrcnt5_wgm_t;

typedef enum tmrcnt5_ouput_compare_channel_e
{
    tmrcnt5_ouput_compare_channel_a = 0,
    tmrcnt5_ouput_compare_channel_b,
    tmrcnt5_ouput_compare_channel_c
} tmrcnt5_ouput_compare_channel_t;

void tmrcnt2_init (tmrcnt5_wgm_t mode, tmrcnt5_clk_select_t prescale);

void timerCounterSetOuputComparePin5 (TimerOuputCompareChannel_Type1 channel, uint8_t mode);

void timerCounterForceOuputCompare5 (TimerOuputCompareChannel_Type1 channel);

uint16_t timerCounterReadTimer5 (void);
void timerCounterSetTimer5 (uint16_t value);

uint16_t timerCounterReadOutputCompare5 (TimerOuputCompareChannel_Type1 channel);
void timerCounterSetOutputCompare5 (TimerOuputCompareChannel_Type1 channel, uint16_t value);

uint16_t timerCounterReadInputCapture5 (void);

void timerCounterEnableInputCaptureInt5 (void);
void timerCounterDisableInputCaptureInt5 (void);

void timerCounterEnableOutputCompareMatchInt5 (TimerOuputCompareChannel_Type1 channel);
void timerCounterEnableDisableCompareMatchInt5 (TimerOuputCompareChannel_Type1 channel);

void timerCounterEnableOverflowInt5 (void);
void timerCounterDisableOverfloweInt5 (void);

#endif /* TMR_CNT_5_H_ */