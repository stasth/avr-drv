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

/* avr/../io_pin/iotn40_pin.h - definitions for ATtiny40 */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iotn40_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif 


#ifndef _AVR_PIN_ATTINY40_H_
#define _AVR_PIN_ATTINY40_H_ 1


/* Device Pin Definitions */
#define ADC6_DDR   DDRCINT
#define ADC6_PORT  PORTCINT
#define ADC6_PIN   PINCINT
#define ADC6_BIT   INT6

#define ADC5_DDR   DDRCINT
#define ADC5_PORT  PORTCINT
#define ADC5_PIN   PINCINT
#define ADC5_BIT   INT5

#define OC0B_DDR   DDRCINT
#define OC0B_PORT  PORTCINT
#define OC0B_PIN   PINCINT
#define OC0B_BIT   INT5

#define ADC4_DDR   DDRCINT
#define ADC4_PORT  PORTCINT
#define ADC4_PIN   PINCINT
#define ADC4_BIT   INT4

#define T0_DDR   DDRCINT
#define T0_PORT  PORTCINT
#define T0_PIN   PINCINT
#define T0_BIT   INT4

#define ADC3_DDR   DDR(PCINT
#define ADC3_PORT  PORT(PCINT
#define ADC3_PIN   PIN(PCINT
#define ADC3_BIT   (PCINT3

#define ADC2_DDR   DDR(PCINT
#define ADC2_PORT  PORT(PCINT
#define ADC2_PIN   PIN(PCINT
#define ADC2_BIT   (PCINT2

#define AIN1_DDR   DDR(PCINT
#define AIN1_PORT  PORT(PCINT
#define AIN1_PIN   PIN(PCINT
#define AIN1_BIT   (PCINT2

#define ADC1_DDR   DDRCINT
#define ADC1_PORT  PORTCINT
#define ADC1_PIN   PINCINT
#define ADC1_BIT   INT1

#define AIN0_DDR   DDRCINT
#define AIN0_PORT  PORTCINT
#define AIN0_PIN   PINCINT
#define AIN0_BIT   INT1

#define ADC0_DDR   DDRCINT
#define ADC0_PORT  PORTCINT
#define ADC0_PIN   PINCINT
#define ADC0_BIT   INT0

#define CLKI_DDR   DDRCINT1
#define CLKI_PORT  PORTCINT1
#define CLKI_PIN   PINCINT1
#define CLKI_BIT   INT17

#define SDA_DDR   DDR(MOSI
#define SDA_PORT  PORT(MOSI
#define SDA_PIN   PIN(MOSI
#define SDA_BIT   (MOSI

#define PCINT16_DDR   DDR(MOSI
#define PCINT16_PORT  PORT(MOSI
#define PCINT16_PIN   PIN(MOSI
#define PCINT16_BIT   (MOSI

#define PCINT15_DDR   DDRRESET
#define PCINT15_PORT  PORTRESET
#define PCINT15_PIN   PINRESET
#define PCINT15_BIT   RESET

#define CLKO_DDR   DDR(INT
#define CLKO_PORT  PORT(INT
#define CLKO_PIN   PIN(INT
#define CLKO_BIT   (INT0

#define MISO_DDR   DDR(INT
#define MISO_PORT  PORT(INT
#define MISO_PIN   PIN(INT
#define MISO_BIT   (INT0

#define PCINT14_DDR   DDR(INT
#define PCINT14_PORT  PORT(INT
#define PCINT14_PIN   PIN(INT
#define PCINT14_BIT   (INT0

#define SCL_DDR   DDR(SCK
#define SCL_PORT  PORT(SCK
#define SCL_PIN   PIN(SCK
#define SCL_BIT   (SCK

#define ICP1_DDR   DDR(SCK
#define ICP1_PORT  PORT(SCK
#define ICP1_PIN   PIN(SCK
#define ICP1_BIT   (SCK

#define T1_DDR   DDR(SCK
#define T1_PORT  PORT(SCK
#define T1_PIN   PIN(SCK
#define T1_BIT   (SCK

#define PCINT13_DDR   DDR(SCK
#define PCINT13_PORT  PORT(SCK
#define PCINT13_PIN   PIN(SCK
#define PCINT13_BIT   (SCK

#define SS_DDR   DDROC0A
#define SS_PORT  PORTOC0A
#define SS_PIN   PINOC0A
#define SS_BIT   OC0A

#define PCINT12_DDR   DDROC0A
#define PCINT12_PORT  PORTOC0A
#define PCINT12_PIN   PINOC0A
#define PCINT12_BIT   OC0A

#define PCINT11_DDR   DDRADC1
#define PCINT11_PORT  PORTADC1
#define PCINT11_PIN   PINADC1
#define PCINT11_BIT   ADC11

#define PCINT10_DDR   DDRADC1
#define PCINT10_PORT  PORTADC1
#define PCINT10_PIN   PINADC1
#define PCINT10_BIT   ADC10

#define ADC9/PCINT9_DDR   DDRADC9/PCINT
#define ADC9/PCINT9_PORT  PORTADC9/PCINT
#define ADC9/PCINT9_PIN   PINADC9/PCINT
#define ADC9/PCINT9_BIT   ADC9/PCINT9

#define PCINT8_DDR   DDRADC
#define PCINT8_PORT  PORTADC
#define PCINT8_PIN   PINADC
#define PCINT8_BIT   ADC8

#define PCINT7_DDR   DDRADC
#define PCINT7_PORT  PORTADC
#define PCINT7_PIN   PINADC
#define PCINT7_BIT   ADC7

#endif /* _AVR_PIN_ATTINY40_H_ */

