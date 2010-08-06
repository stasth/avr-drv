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

/* avr/../io_pin/iotn5_pin.h - definitions for ATtiny5 */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iotn5_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif 


#ifndef _AVR_PIN_ATTINY5_H_
#define _AVR_PIN_ATTINY5_H_ 1


/* Device Pin Definitions */
#define SPDATA_DDR   DDRCINT
#define SPDATA_PORT  PORTCINT
#define SPDATA_PIN   PINCINT
#define SPDATA_BIT   INT0

#define OC0A_DDR   DDRCINT
#define OC0A_PORT  PORTCINT
#define OC0A_PIN   PINCINT
#define OC0A_BIT   INT0

#define ADC0_DDR   DDRCINT
#define ADC0_PORT  PORTCINT
#define ADC0_PIN   PINCINT
#define ADC0_BIT   INT0

#define AIN0_DDR   DDRCINT
#define AIN0_PORT  PORTCINT
#define AIN0_PIN   PINCINT
#define AIN0_BIT   INT0

#define PB0_DDR   DDRCINT
#define PB0_PORT  PORTCINT
#define PB0_PIN   PINCINT
#define PB0_BIT   INT0

#define SPCLK_DDR   DDRCINT
#define SPCLK_PORT  PORTCINT
#define SPCLK_PIN   PINCINT
#define SPCLK_BIT   INT1

#define CLKI_DDR   DDRCINT
#define CLKI_PORT  PORTCINT
#define CLKI_PIN   PINCINT
#define CLKI_BIT   INT1

#define ICP0_DDR   DDRCINT
#define ICP0_PORT  PORTCINT
#define ICP0_PIN   PINCINT
#define ICP0_BIT   INT1

#define OC0B_DDR   DDRCINT
#define OC0B_PORT  PORTCINT
#define OC0B_PIN   PINCINT
#define OC0B_BIT   INT1

#define ADC1_DDR   DDRCINT
#define ADC1_PORT  PORTCINT
#define ADC1_PIN   PINCINT
#define ADC1_BIT   INT1

#define AIN1_DDR   DDRCINT
#define AIN1_PORT  PORTCINT
#define AIN1_PIN   PINCINT
#define AIN1_BIT   INT1

#define PB1_DDR   DDRCINT
#define PB1_PORT  PORTCINT
#define PB1_PIN   PINCINT
#define PB1_BIT   INT1

#define CLKO_DDR   DDRT
#define CLKO_PORT  PORTT
#define CLKO_PIN   PINT
#define CLKO_BIT   T0

#define PCINT2_DDR   DDRT
#define PCINT2_PORT  PORTT
#define PCINT2_PIN   PINT
#define PCINT2_BIT   T0

#define INT0_DDR   DDRT
#define INT0_PORT  PORTT
#define INT0_PIN   PINT
#define INT0_BIT   T0

#define ADC2_DDR   DDRT
#define ADC2_PORT  PORTT
#define ADC2_PIN   PINT
#define ADC2_BIT   T0

#define PB2_DDR   DDRT
#define PB2_PORT  PORTT
#define PB2_PIN   PINT
#define PB2_BIT   T0

#define PCINT3_DDR   DDRRESET
#define PCINT3_PORT  PORTRESET
#define PCINT3_PIN   PINRESET
#define PCINT3_BIT   RESET

#define ADC3_DDR   DDRRESET
#define ADC3_PORT  PORTRESET
#define ADC3_PIN   PINRESET
#define ADC3_BIT   RESET

#define PB3_DDR   DDRRESET
#define PB3_PORT  PORTRESET
#define PB3_PIN   PINRESET
#define PB3_BIT   RESET

#endif /* _AVR_PIN_ATTINY5_H_ */

