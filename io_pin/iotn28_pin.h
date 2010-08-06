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

/* avr/../io_pin/iotn28_pin.h - definitions for ATtiny28 */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iotn28_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif 


#ifndef _AVR_PIN_ATTINY28_H_
#define _AVR_PIN_ATTINY28_H_ 1


/* Device Pin Definitions */
#define PD3_DDR   DDRD
#define PD3_PORT  PORTD
#define PD3_PIN   PIND
#define PD3_BIT   3

#define PD4_DDR   DDRD
#define PD4_PORT  PORTD
#define PD4_PIN   PIND
#define PD4_BIT   4

#define PD5_DDR   DDRD
#define PD5_PORT  PORTD
#define PD5_PIN   PIND
#define PD5_BIT   5

#define PD6_DDR   DDRD
#define PD6_PORT  PORTD
#define PD6_PIN   PIND
#define PD6_BIT   6

#define PD7_DDR   DDRD
#define PD7_PORT  PORTD
#define PD7_PIN   PIND
#define PD7_BIT   7

#define PB0_DDR   DDRAIN
#define PB0_PORT  PORTAIN
#define PB0_PIN   PINAIN
#define PB0_BIT   AIN0

#define PB1_DDR   DDRAIN
#define PB1_PORT  PORTAIN
#define PB1_PIN   PINAIN
#define PB1_BIT   AIN1

#define PB2_DDR   DDRT
#define PB2_PORT  PORTT
#define PB2_PIN   PINT
#define PB2_BIT   T0

#define PB3_DDR   DDRINT
#define PB3_PORT  PORTINT
#define PB3_PIN   PININT
#define PB3_BIT   INT0

#define PB4_DDR   DDRINT
#define PB4_PORT  PORTINT
#define PB4_PIN   PININT
#define PB4_BIT   INT1

#define PB5_DDR   DDRB
#define PB5_PORT  PORTB
#define PB5_PIN   PINB
#define PB5_BIT   5

#define PB6_DDR   DDRB
#define PB6_PORT  PORTB
#define PB6_PIN   PINB
#define PB6_BIT   6

#define PB7_DDR   DDRB
#define PB7_PORT  PORTB
#define PB7_PIN   PINB
#define PB7_BIT   7

#define IR_DDR   DDRA
#define IR_PORT  PORTA
#define IR_PIN   PINA
#define IR_BIT   2

#define PA3_DDR   DDRA
#define PA3_PORT  PORTA
#define PA3_PIN   PINA
#define PA3_BIT   3

#define PA1_DDR   DDRA
#define PA1_PORT  PORTA
#define PA1_PIN   PINA
#define PA1_BIT   1

#define PA0_DDR   DDRA
#define PA0_PORT  PORTA
#define PA0_PIN   PINA
#define PA0_BIT   0

#define PD0_DDR   DDRD
#define PD0_PORT  PORTD
#define PD0_PIN   PIND
#define PD0_BIT   0

#define PD1_DDR   DDRD
#define PD1_PORT  PORTD
#define PD1_PIN   PIND
#define PD1_BIT   1

#define PD2_DDR   DDRD
#define PD2_PORT  PORTD
#define PD2_PIN   PIND
#define PD2_BIT   2

#endif /* _AVR_PIN_ATTINY28_H_ */

