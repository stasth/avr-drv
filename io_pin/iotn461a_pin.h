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

/* avr/../io_pin/iotn461a_pin.h - definitions for ATtiny461A */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iotn461a_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif 


#ifndef _AVR_PIN_ATTINY461A_H_
#define _AVR_PIN_ATTINY461A_H_ 1


/* Device Pin Definitions */
#define DI_B_DDR   DDRMOSI
#define DI_B_PORT  PORTMOSI
#define DI_B_PIN   PINMOSI
#define DI_B_BIT   MOSI

#define SDA_B_DDR   DDRMOSI
#define SDA_B_PORT  PORTMOSI
#define SDA_B_PIN   PINMOSI
#define SDA_B_BIT   MOSI

#define _OC1A_DDR   DDRMOSI
#define _OC1A_PORT  PORTMOSI
#define _OC1A_PIN   PINMOSI
#define _OC1A_BIT   MOSI

#define PCINT8_DDR   DDRMOSI
#define PCINT8_PORT  PORTMOSI
#define PCINT8_PIN   PINMOSI
#define PCINT8_BIT   MOSI

#define PB0_DDR   DDRMOSI
#define PB0_PORT  PORTMOSI
#define PB0_PIN   PINMOSI
#define PB0_BIT   MOSI

#define DO_B_DDR   DDRMISO
#define DO_B_PORT  PORTMISO
#define DO_B_PIN   PINMISO
#define DO_B_BIT   MISO

#define OC1A_DDR   DDRMISO
#define OC1A_PORT  PORTMISO
#define OC1A_PIN   PINMISO
#define OC1A_BIT   MISO

#define PCINT9_DDR   DDRMISO
#define PCINT9_PORT  PORTMISO
#define PCINT9_PIN   PINMISO
#define PCINT9_BIT   MISO

#define PB1_DDR   DDRMISO
#define PB1_PORT  PORTMISO
#define PB1_PIN   PINMISO
#define PB1_BIT   MISO

#define USCK_B_DDR   DDRSCK
#define USCK_B_PORT  PORTSCK
#define USCK_B_PIN   PINSCK
#define USCK_B_BIT   SCK

#define SCL_B_DDR   DDRSCK
#define SCL_B_PORT  PORTSCK
#define SCL_B_PIN   PINSCK
#define SCL_B_BIT   SCK

#define OC1B_DDR   DDRSCK
#define OC1B_PORT  PORTSCK
#define OC1B_PIN   PINSCK
#define OC1B_BIT   SCK

#define PCINT10_DDR   DDRSCK
#define PCINT10_PORT  PORTSCK
#define PCINT10_PIN   PINSCK
#define PCINT10_BIT   SCK

#define PB2_DDR   DDRSCK
#define PB2_PORT  PORTSCK
#define PB2_PIN   PINSCK
#define PB2_BIT   SCK

#define PCINT11_DDR   DDROC1B
#define PCINT11_PORT  PORTOC1B
#define PCINT11_PIN   PINOC1B
#define PCINT11_BIT   OC1B

#define PB3_DDR   DDROC1B
#define PB3_PORT  PORTOC1B
#define PB3_PIN   PINOC1B
#define PB3_BIT   OC1B

#define PCINT12_DDR   DDRADC
#define PCINT12_PORT  PORTADC
#define PCINT12_PIN   PINADC
#define PCINT12_BIT   ADC7

#define _OC1D_DDR   DDRADC
#define _OC1D_PORT  PORTADC
#define _OC1D_PIN   PINADC
#define _OC1D_BIT   ADC7

#define CLKI_DDR   DDRADC
#define CLKI_PORT  PORTADC
#define CLKI_PIN   PINADC
#define CLKI_BIT   ADC7

#define PB4_DDR   DDRADC
#define PB4_PORT  PORTADC
#define PB4_PIN   PINADC
#define PB4_BIT   ADC7

#define PCINT13_DDR   DDRADC
#define PCINT13_PORT  PORTADC
#define PCINT13_PIN   PINADC
#define PCINT13_BIT   ADC8

#define OC1D_DDR   DDRADC
#define OC1D_PORT  PORTADC
#define OC1D_PIN   PINADC
#define OC1D_BIT   ADC8

#define CKLO_DDR   DDRADC
#define CKLO_PORT  PORTADC
#define CKLO_PIN   PINADC
#define CKLO_BIT   ADC8

#define PB5_DDR   DDRADC
#define PB5_PORT  PORTADC
#define PB5_PIN   PINADC
#define PB5_BIT   ADC8

#define INT0_DDR   DDRADC
#define INT0_PORT  PORTADC
#define INT0_PIN   PINADC
#define INT0_BIT   ADC9

#define T0_DDR   DDRADC
#define T0_PORT  PORTADC
#define T0_PIN   PINADC
#define T0_BIT   ADC9

#define PCINT14_DDR   DDRADC
#define PCINT14_PORT  PORTADC
#define PCINT14_PIN   PINADC
#define PCINT14_BIT   ADC9

#define PB6_DDR   DDRADC
#define PB6_PORT  PORTADC
#define PB6_PIN   PINADC
#define PB6_BIT   ADC9

#define PCINT15_DDR   DDRADC1
#define PCINT15_PORT  PORTADC1
#define PCINT15_PIN   PINADC1
#define PCINT15_BIT   ADC10

#define PB7_DDR   DDRADC1
#define PB7_PORT  PORTADC1
#define PB7_PIN   PINADC1
#define PB7_BIT   ADC10

#define AIN1_DDR   DDRADC
#define AIN1_PORT  PORTADC
#define AIN1_PIN   PINADC
#define AIN1_BIT   ADC6

#define PCINT7_DDR   DDRADC
#define PCINT7_PORT  PORTADC
#define PCINT7_PIN   PINADC
#define PCINT7_BIT   ADC6

#define PA7_DDR   DDRADC
#define PA7_PORT  PORTADC
#define PA7_PIN   PINADC
#define PA7_BIT   ADC6

#define AIN0_DDR   DDRADC
#define AIN0_PORT  PORTADC
#define AIN0_PIN   PINADC
#define AIN0_BIT   ADC5

#define PCINT6_DDR   DDRADC
#define PCINT6_PORT  PORTADC
#define PCINT6_PIN   PINADC
#define PCINT6_BIT   ADC5

#define PA6_DDR   DDRADC
#define PA6_PORT  PORTADC
#define PA6_PIN   PINADC
#define PA6_BIT   ADC5

#define AIN2_DDR   DDRADC
#define AIN2_PORT  PORTADC
#define AIN2_PIN   PINADC
#define AIN2_BIT   ADC4

#define PCINT5_DDR   DDRADC
#define PCINT5_PORT  PORTADC
#define PCINT5_PIN   PINADC
#define PCINT5_BIT   ADC4

#define PA5_DDR   DDRADC
#define PA5_PORT  PORTADC
#define PA5_PIN   PINADC
#define PA5_BIT   ADC4

#define ICP0_DDR   DDRADC
#define ICP0_PORT  PORTADC
#define ICP0_PIN   PINADC
#define ICP0_BIT   ADC3

#define PCINT4_DDR   DDRADC
#define PCINT4_PORT  PORTADC
#define PCINT4_PIN   PINADC
#define PCINT4_BIT   ADC3

#define PA4_DDR   DDRADC
#define PA4_PORT  PORTADC
#define PA4_PIN   PINADC
#define PA4_BIT   ADC3

#define PCINT3_DDR   DDRAREF
#define PCINT3_PORT  PORTAREF
#define PCINT3_PIN   PINAREF
#define PCINT3_BIT   AREF

#define PA3_DDR   DDRAREF
#define PA3_PORT  PORTAREF
#define PA3_PIN   PINAREF
#define PA3_BIT   AREF

#define INT1_DDR   DDRADC
#define INT1_PORT  PORTADC
#define INT1_PIN   PINADC
#define INT1_BIT   ADC2

#define USCK_A_DDR   DDRADC
#define USCK_A_PORT  PORTADC
#define USCK_A_PIN   PINADC
#define USCK_A_BIT   ADC2

#define SCL_A_DDR   DDRADC
#define SCL_A_PORT  PORTADC
#define SCL_A_PIN   PINADC
#define SCL_A_BIT   ADC2

#define PCINT2_DDR   DDRADC
#define PCINT2_PORT  PORTADC
#define PCINT2_PIN   PINADC
#define PCINT2_BIT   ADC2

#define PA2_DDR   DDRADC
#define PA2_PORT  PORTADC
#define PA2_PIN   PINADC
#define PA2_BIT   ADC2

#define DO_A_DDR   DDRADC
#define DO_A_PORT  PORTADC
#define DO_A_PIN   PINADC
#define DO_A_BIT   ADC1

#define PCINT1_DDR   DDRADC
#define PCINT1_PORT  PORTADC
#define PCINT1_PIN   PINADC
#define PCINT1_BIT   ADC1

#define PA1_DDR   DDRADC
#define PA1_PORT  PORTADC
#define PA1_PIN   PINADC
#define PA1_BIT   ADC1

#define DI_A_DDR   DDRADC
#define DI_A_PORT  PORTADC
#define DI_A_PIN   PINADC
#define DI_A_BIT   ADC0

#define SDA_A_DDR   DDRADC
#define SDA_A_PORT  PORTADC
#define SDA_A_PIN   PINADC
#define SDA_A_BIT   ADC0

#define PCINT0_DDR   DDRADC
#define PCINT0_PORT  PORTADC
#define PCINT0_PIN   PINADC
#define PCINT0_BIT   ADC0

#define PA0_DDR   DDRADC
#define PA0_PORT  PORTADC
#define PA0_PIN   PINADC
#define PA0_BIT   ADC0

#endif /* _AVR_PIN_ATTINY461A_H_ */

