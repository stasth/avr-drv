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

/* avr/../io_pin/iom406_pin.h - definitions for ATmega406 */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iom406_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif 


#ifndef _AVR_PIN_ATMEGA406_H_
#define _AVR_PIN_ATMEGA406_H_ 1


/* Device Pin Definitions */
#define S_DDR   DDRSGND
#define S_PORT  PORTSGND
#define S_PIN   PINSGND
#define S_BIT   SGND

#define ADC0_DDR   DDRA
#define ADC0_PORT  PORTA
#define ADC0_PIN   PINA
#define ADC0_BIT   0

#define PCINT0_DDR   DDRA
#define PCINT0_PORT  PORTA
#define PCINT0_PIN   PINA
#define PCINT0_BIT   0

#define ADC1_DDR   DDRA
#define ADC1_PORT  PORTA
#define ADC1_PIN   PINA
#define ADC1_BIT   1

#define PCINT1_DDR   DDRA
#define PCINT1_PORT  PORTA
#define PCINT1_PIN   PINA
#define PCINT1_BIT   1

#define ADC2_DDR   DDRA
#define ADC2_PORT  PORTA
#define ADC2_PIN   PINA
#define ADC2_BIT   2

#define PCINT2_DDR   DDRA
#define PCINT2_PORT  PORTA
#define PCINT2_PIN   PINA
#define PCINT2_BIT   2

#define ADC3_DDR   DDRA
#define ADC3_PORT  PORTA
#define ADC3_PIN   PINA
#define ADC3_BIT   3

#define PCINT3_DDR   DDRA
#define PCINT3_PORT  PORTA
#define PCINT3_PIN   PINA
#define PCINT3_BIT   3

#define VREG_DDR   DDRVREG
#define VREG_PORT  PORTVREG
#define VREG_PIN   PINVREG
#define VREG_BIT   VREG

#define ADC4_DDR   DDRA
#define ADC4_PORT  PORTA
#define ADC4_PIN   PINA
#define ADC4_BIT   4

#define INT0_DDR   DDRA
#define INT0_PORT  PORTA
#define INT0_PIN   PINA
#define INT0_BIT   4

#define PCINT4_DDR   DDRA
#define PCINT4_PORT  PORTA
#define PCINT4_PIN   PINA
#define PCINT4_BIT   4

#define INT1_DDR   DDRA
#define INT1_PORT  PORTA
#define INT1_PIN   PINA
#define INT1_BIT   5

#define PCINT5_DDR   DDRA
#define PCINT5_PORT  PORTA
#define PCINT5_PIN   PINA
#define PCINT5_BIT   5

#define INT2_DDR   DDRA
#define INT2_PORT  PORTA
#define INT2_PIN   PINA
#define INT2_BIT   6

#define PCINT6_DDR   DDRA
#define PCINT6_PORT  PORTA
#define PCINT6_PIN   PINA
#define PCINT6_BIT   6

#define INT3_DDR   DDRA
#define INT3_PORT  PORTA
#define INT3_PIN   PINA
#define INT3_BIT   7

#define PCINT7_DDR   DDRA
#define PCINT7_PORT  PORTA
#define PCINT7_PIN   PINA
#define PCINT7_BIT   7

#define PCINT8_DDR   DDRB
#define PCINT8_PORT  PORTB
#define PCINT8_PIN   PINB
#define PCINT8_BIT   0

#define PCINT9_DDR   DDRB
#define PCINT9_PORT  PORTB
#define PCINT9_PIN   PINB
#define PCINT9_BIT   1

#define PCINT10_DDR   DDRB
#define PCINT10_PORT  PORTB
#define PCINT10_PIN   PINB
#define PCINT10_BIT   2

#define PCINT11_DDR   DDRB
#define PCINT11_PORT  PORTB
#define PCINT11_PIN   PINB
#define PCINT11_BIT   3

#define PCINT12_DDR   DDRB
#define PCINT12_PORT  PORTB
#define PCINT12_PIN   PINB
#define PCINT12_BIT   4

#define PCINT13_DDR   DDRB
#define PCINT13_PORT  PORTB
#define PCINT13_PIN   PINB
#define PCINT13_BIT   5

#define SCL_DDR   DDRSCL
#define SCL_PORT  PORTSCL
#define SCL_PIN   PINSCL
#define SCL_BIT   SCL

#define SDA_DDR   DDRSDA
#define SDA_PORT  PORTSDA
#define SDA_PIN   PINSDA
#define SDA_BIT   SDA

#define OC0A_DDR   DDRB
#define OC0A_PORT  PORTB
#define OC0A_PIN   PINB
#define OC0A_BIT   6

#define PCINT14_DDR   DDRB
#define PCINT14_PORT  PORTB
#define PCINT14_PIN   PINB
#define PCINT14_BIT   6

#define OC0B_DDR   DDRB
#define OC0B_PORT  PORTB
#define OC0B_PIN   PINB
#define OC0B_BIT   7

#define PCINT15_DDR   DDRB
#define PCINT15_PORT  PORTB
#define PCINT15_PIN   PINB
#define PCINT15_BIT   7

#define T0_DDR   DDRD
#define T0_PORT  PORTD
#define T0_PIN   PIND
#define T0_BIT   0

#define PD1_DDR   DDRD
#define PD1_PORT  PORTD
#define PD1_PIN   PIND
#define PD1_BIT   1

#define PC0_DDR   DDRC
#define PC0_PORT  PORTC
#define PC0_PIN   PINC
#define PC0_BIT   0

#define BATT_DDR   DDRBATT
#define BATT_PORT  PORTBATT
#define BATT_PIN   PINBATT
#define BATT_BIT   BATT

#define OPC_DDR   DDROPC
#define OPC_PORT  PORTOPC
#define OPC_PIN   PINOPC
#define OPC_BIT   OPC

#define OC_DDR   DDROC
#define OC_PORT  PORTOC
#define OC_PIN   PINOC
#define OC_BIT   OC

#define VFET_DDR   DDRVFET
#define VFET_PORT  PORTVFET
#define VFET_PIN   PINVFET
#define VFET_BIT   VFET

#define OD_DDR   DDROD
#define OD_PORT  PORTOD
#define OD_PIN   PINOD
#define OD_BIT   OD

#define PVT_DDR   DDRVT
#define PVT_PORT  PORTVT
#define PVT_PIN   PINVT
#define PVT_BIT   T

#define PV4_DDR   DDRV
#define PV4_PORT  PORTV
#define PV4_PIN   PINV
#define PV4_BIT   4

#define PV3_DDR   DDRV
#define PV3_PORT  PORTV
#define PV3_PIN   PINV
#define PV3_BIT   3

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

#define VREF_DDR   DDRVREF
#define VREF_PORT  PORTVREF
#define VREF_PIN   PINVREF
#define VREF_BIT   VREF

#define VREF_DDR   DDRVREFGND
#define VREF_PORT  PORTVREFGND
#define VREF_PIN   PINVREFGND
#define VREF_BIT   VREFGND

#define PPI_DDR   DDRPI
#define PPI_PORT  PORTPI
#define PPI_PIN   PINPI
#define PPI_BIT   I

#define PI_DDR   DDRI
#define PI_PORT  PORTI
#define PI_PIN   PINI
#define PI_BIT   

#define NI_DDR   DDRNI
#define NI_PORT  PORTNI
#define NI_PIN   PINNI
#define NI_BIT   NI

#define NNI_DDR   DDRNNI
#define NNI_PORT  PORTNNI
#define NNI_PIN   PINNNI
#define NNI_BIT   NNI

#endif /* _AVR_PIN_ATMEGA406_H_ */

