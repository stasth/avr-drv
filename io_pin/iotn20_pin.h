/* Copyright (c) 2010 Atmel Corporation
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

/* avr/../io_pin/iotn20_pin.h - definitions for ATtiny20 */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iotn20_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif 


#ifndef _AVR_PIN_ATTINY20_H_
#define _AVR_PIN_ATTINY20_H_ 1


/* Device Pin Definitions */
#define ADC4_DDR   DDRCINT
#define ADC4_PORT  PORTCINT
#define ADC4_PIN   PINCINT
#define ADC4_BIT   INT4

#define ADC3_DDR   DDRCINT
#define ADC3_PORT  PORTCINT
#define ADC3_PIN   PINCINT
#define ADC3_BIT   INT3

#define AIN1_DDR   DDRCINT
#define AIN1_PORT  PORTCINT
#define AIN1_PIN   PINCINT
#define AIN1_BIT   INT2

#define ADC2_DDR   DDRCINT
#define ADC2_PORT  PORTCINT
#define ADC2_PIN   PINCINT
#define ADC2_BIT   INT2

#define AIN0_DDR   DDRCINT
#define AIN0_PORT  PORTCINT
#define AIN0_PIN   PINCINT
#define AIN0_BIT   INT1

#define ADC1_DDR   DDRCINT
#define ADC1_PORT  PORTCINT
#define ADC1_PIN   PINCINT
#define ADC1_BIT   INT1

#define ADC0_DDR   DDRCINT
#define ADC0_PORT  PORTCINT
#define ADC0_PIN   PINCINT
#define ADC0_BIT   INT0

#define T0_DDR   DDRCLKI
#define T0_PORT  PORTCLKI
#define T0_PIN   PINCLKI
#define T0_BIT   CLKI

#define TPICLK_DDR   DDRCLKI
#define TPICLK_PORT  PORTCLKI
#define TPICLK_PIN   PINCLKI
#define TPICLK_BIT   CLKI

#define PCINT8_DDR   DDRCLKI
#define PCINT8_PORT  PORTCLKI
#define PCINT8_PIN   PINCLKI
#define PCINT8_BIT   CLKI

#define SDA_DDR   DDROC1A
#define SDA_PORT  PORTOC1A
#define SDA_PIN   PINOC1A
#define SDA_BIT   OC1A

#define MOSI_DDR   DDROC1A
#define MOSI_PORT  PORTOC1A
#define MOSI_PIN   PINOC1A
#define MOSI_BIT   OC1A

#define TPIDATA_DDR   DDROC1A
#define TPIDATA_PORT  PORTOC1A
#define TPIDATA_PIN   PINOC1A
#define TPIDATA_BIT   OC1A

#define PCINT9_DDR   DDROC1A
#define PCINT9_PORT  PORTOC1A
#define PCINT9_PIN   PINOC1A
#define PCINT9_BIT   OC1A

#define PCINT11_DDR   DDRRESET
#define PCINT11_PORT  PORTRESET
#define PCINT11_PIN   PINRESET
#define PCINT11_BIT   RESET

#define OC0A_DDR   DDRCKOUT
#define OC0A_PORT  PORTCKOUT
#define OC0A_PIN   PINCKOUT
#define OC0A_BIT   CKOUT

#define OC1B_DDR   DDRCKOUT
#define OC1B_PORT  PORTCKOUT
#define OC1B_PIN   PINCKOUT
#define OC1B_BIT   CKOUT

#define MISO_DDR   DDRCKOUT
#define MISO_PORT  PORTCKOUT
#define MISO_PIN   PINCKOUT
#define MISO_BIT   CKOUT

#define INT0_DDR   DDRCKOUT
#define INT0_PORT  PORTCKOUT
#define INT0_PIN   PINCKOUT
#define INT0_BIT   CKOUT

#define PCINT10_DDR   DDRCKOUT
#define PCINT10_PORT  PORTCKOUT
#define PCINT10_PIN   PINCKOUT
#define PCINT10_BIT   CKOUT

#define OC0B_DDR   DDR(ADC
#define OC0B_PORT  PORT(ADC
#define OC0B_PIN   PIN(ADC
#define OC0B_BIT   (ADC7

#define ICP1_DDR   DDR(ADC
#define ICP1_PORT  PORT(ADC
#define ICP1_PIN   PIN(ADC
#define ICP1_BIT   (ADC7

#define T1_DDR   DDR(ADC
#define T1_PORT  PORT(ADC
#define T1_PIN   PIN(ADC
#define T1_BIT   (ADC7

#define SCL_DDR   DDR(ADC
#define SCL_PORT  PORT(ADC
#define SCL_PIN   PIN(ADC
#define SCL_BIT   (ADC7

#define SCK_DDR   DDR(ADC
#define SCK_PORT  PORT(ADC
#define SCK_PIN   PIN(ADC
#define SCK_BIT   (ADC7

#define PCINT7_DDR   DDR(ADC
#define PCINT7_PORT  PORT(ADC
#define PCINT7_PIN   PIN(ADC
#define PCINT7_BIT   (ADC7

#define SS_DDR   DDRADC
#define SS_PORT  PORTADC
#define SS_PIN   PINADC
#define SS_BIT   ADC6

#define PCINT6_DDR   DDRADC
#define PCINT6_PORT  PORTADC
#define PCINT6_PIN   PINADC
#define PCINT6_BIT   ADC6

#define PCINT5_DDR   DDRADC
#define PCINT5_PORT  PORTADC
#define PCINT5_PIN   PINADC
#define PCINT5_BIT   ADC5

#endif /* _AVR_PIN_ATTINY20_H_ */

