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

/* avr/../io_pin/iom8hva_pin.h - definitions for ATmega8HVA */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iom8hva_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif 


#ifndef _AVR_PIN_ATMEGA8HVA_H_
#define _AVR_PIN_ATMEGA8HVA_H_ 1


/* Device Pin Definitions */
#define PV2_DDR   DDRV
#define PV2_PORT  PORTV
#define PV2_PIN   PINV
#define PV2_BIT   2

#define PV1_DDR   DDRV
#define PV1_PORT  PORTV
#define PV1_PIN   PINV
#define PV1_BIT   1

#define NV_DDR   DDRNV
#define NV_PORT  PORTNV
#define NV_PIN   PINNV
#define NV_BIT   NV

#define VFET_DDR   DDRVFET
#define VFET_PORT  PORTVFET
#define VFET_PIN   PINVFET
#define VFET_BIT   VFET

#define CF1P_DDR   DDRCF1P
#define CF1P_PORT  PORTCF1P
#define CF1P_PIN   PINCF1P
#define CF1P_BIT   CF1P

#define CF1N_DDR   DDRCF1N
#define CF1N_PORT  PORTCF1N
#define CF1N_PIN   PINCF1N
#define CF1N_BIT   CF1N

#define CF2P_DDR   DDRCF2P
#define CF2P_PORT  PORTCF2P
#define CF2P_PIN   PINCF2P
#define CF2P_BIT   CF2P

#define CF2N_DDR   DDRCF2N
#define CF2N_PORT  PORTCF2N
#define CF2N_PIN   PINCF2N
#define CF2N_BIT   CF2N

#define VREG_DDR   DDRVREG
#define VREG_PORT  PORTVREG
#define VREG_PIN   PINVREG
#define VREG_BIT   VREG

#define VREF_DDR   DDRVREF
#define VREF_PORT  PORTVREF
#define VREF_PIN   PINVREF
#define VREF_BIT   VREF

#define VREF_DDR   DDRVREFGND
#define VREF_PORT  PORTVREFGND
#define VREF_PIN   PINVREFGND
#define VREF_BIT   VREFGND

#define PI_DDR   DDRI
#define PI_PORT  PORTI
#define PI_PIN   PINI
#define PI_BIT   

#define NI_DDR   DDRNI
#define NI_PORT  PORTNI
#define NI_PIN   PINNI
#define NI_BIT   NI

#define PA0_DDR   DDRA
#define PA0_PORT  PORTA
#define PA0_PIN   PINA
#define PA0_BIT   0

#define PA1_DDR   DDRA
#define PA1_PORT  PORTA
#define PA1_PIN   PINA
#define PA1_BIT   1

#define PA2_DDR   DDRA
#define PA2_PORT  PORTA
#define PA2_PIN   PINA
#define PA2_BIT   2

#define PB0_DDR   DDRB
#define PB0_PORT  PORTB
#define PB0_PIN   PINB
#define PB0_BIT   0

#define PB1_DDR   DDRB
#define PB1_PORT  PORTB
#define PB1_PIN   PINB
#define PB1_BIT   1

#define PB2_DDR   DDRB
#define PB2_PORT  PORTB
#define PB2_PIN   PINB
#define PB2_BIT   2

#define PB3_DDR   DDRB
#define PB3_PORT  PORTB
#define PB3_PIN   PINB
#define PB3_BIT   3

#define PC0_DDR   DDRC
#define PC0_PORT  PORTC
#define PC0_PIN   PINC
#define PC0_BIT   0

#define BATT_DDR   DDRBATT
#define BATT_PORT  PORTBATT
#define BATT_PIN   PINBATT
#define BATT_BIT   BATT

#define OC_DDR   DDROC
#define OC_PORT  PORTOC
#define OC_PIN   PINOC
#define OC_BIT   OC

#endif /* _AVR_PIN_ATMEGA8HVA_H_ */

