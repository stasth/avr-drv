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

/* avr/../io_pin/iotn87_pin.h - definitions for ATtiny87 */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iotn87_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif 


#ifndef _AVR_PIN_ATTINY87_H_
#define _AVR_PIN_ATTINY87_H_ 1


/* Device Pin Definitions */
#define RXD_DDR   DDRRXLIN
#define RXD_PORT  PORTRXLIN
#define RXD_PIN   PINRXLIN
#define RXD_BIT   RXLIN

#define ADC0_DDR   DDRRXLIN
#define ADC0_PORT  PORTRXLIN
#define ADC0_PIN   PINRXLIN
#define ADC0_BIT   RXLIN

#define PCINT0_DDR   DDRRXLIN
#define PCINT0_PORT  PORTRXLIN
#define PCINT0_PIN   PINRXLIN
#define PCINT0_BIT   RXLIN

#define PA0_DDR   DDRRXLIN
#define PA0_PORT  PORTRXLIN
#define PA0_PIN   PINRXLIN
#define PA0_BIT   RXLIN

#define TXD_DDR   DDRTXLIN
#define TXD_PORT  PORTTXLIN
#define TXD_PIN   PINTXLIN
#define TXD_BIT   TXLIN

#define ADC1_DDR   DDRTXLIN
#define ADC1_PORT  PORTTXLIN
#define ADC1_PIN   PINTXLIN
#define ADC1_BIT   TXLIN

#define PCINT1_DDR   DDRTXLIN
#define PCINT1_PORT  PORTTXLIN
#define PCINT1_PIN   PINTXLIN
#define PCINT1_BIT   TXLIN

#define PA1_DDR   DDRTXLIN
#define PA1_PORT  PORTTXLIN
#define PA1_PIN   PINTXLIN
#define PA1_BIT   TXLIN

#define DO_DDR   DDRMISO
#define DO_PORT  PORTMISO
#define DO_PIN   PINMISO
#define DO_BIT   MISO

#define OC0A_DDR   DDRMISO
#define OC0A_PORT  PORTMISO
#define OC0A_PIN   PINMISO
#define OC0A_BIT   MISO

#define ADC2_DDR   DDRMISO
#define ADC2_PORT  PORTMISO
#define ADC2_PIN   PINMISO
#define ADC2_BIT   MISO

#define PCINT2_DDR   DDRMISO
#define PCINT2_PORT  PORTMISO
#define PCINT2_PIN   PINMISO
#define PCINT2_BIT   MISO

#define PA2_DDR   DDRMISO
#define PA2_PORT  PORTMISO
#define PA2_PIN   PINMISO
#define PA2_BIT   MISO

#define ISRC_DDR   DDRINT
#define ISRC_PORT  PORTINT
#define ISRC_PIN   PININT
#define ISRC_BIT   INT1

#define ADC3_DDR   DDRINT
#define ADC3_PORT  PORTINT
#define ADC3_PIN   PININT
#define ADC3_BIT   INT1

#define PCINT3_DDR   DDRINT
#define PCINT3_PORT  PORTINT
#define PCINT3_PIN   PININT
#define PCINT3_BIT   INT1

#define PA3_DDR   DDRINT
#define PA3_PORT  PORTINT
#define PA3_PIN   PININT
#define PA3_BIT   INT1

#define SDA_DDR   DDRMOSI
#define SDA_PORT  PORTMOSI
#define SDA_PIN   PINMOSI
#define SDA_BIT   MOSI

#define DI_DDR   DDRMOSI
#define DI_PORT  PORTMOSI
#define DI_PIN   PINMOSI
#define DI_BIT   MOSI

#define ICP1_DDR   DDRMOSI
#define ICP1_PORT  PORTMOSI
#define ICP1_PIN   PINMOSI
#define ICP1_BIT   MOSI

#define ADC4_DDR   DDRMOSI
#define ADC4_PORT  PORTMOSI
#define ADC4_PIN   PINMOSI
#define ADC4_BIT   MOSI

#define PCINT4_DDR   DDRMOSI
#define PCINT4_PORT  PORTMOSI
#define PCINT4_PIN   PINMOSI
#define PCINT4_BIT   MOSI

#define PA4_DDR   DDRMOSI
#define PA4_PORT  PORTMOSI
#define PA4_PIN   PINMOSI
#define PA4_BIT   MOSI

#define SCL_DDR   DDRSCK
#define SCL_PORT  PORTSCK
#define SCL_PIN   PINSCK
#define SCL_BIT   SCK

#define USCK_DDR   DDRSCK
#define USCK_PORT  PORTSCK
#define USCK_PIN   PINSCK
#define USCK_BIT   SCK

#define T1_DDR   DDRSCK
#define T1_PORT  PORTSCK
#define T1_PIN   PINSCK
#define T1_BIT   SCK

#define ADC5_DDR   DDRSCK
#define ADC5_PORT  PORTSCK
#define ADC5_PIN   PINSCK
#define ADC5_BIT   SCK

#define PCINT5_DDR   DDRSCK
#define PCINT5_PORT  PORTSCK
#define PCINT5_PIN   PINSCK
#define PCINT5_BIT   SCK

#define PA5_DDR   DDRSCK
#define PA5_PORT  PORTSCK
#define PA5_PIN   PINSCK
#define PA5_BIT   SCK

#define AIN0_DDR   DDRSS
#define AIN0_PORT  PORTSS
#define AIN0_PIN   PINSS
#define AIN0_BIT   SS

#define ADC6_DDR   DDRSS
#define ADC6_PORT  PORTSS
#define ADC6_PIN   PINSS
#define ADC6_BIT   SS

#define PCINT6_DDR   DDRSS
#define PCINT6_PORT  PORTSS
#define PCINT6_PIN   PINSS
#define PCINT6_BIT   SS

#define PA6_DDR   DDRSS
#define PA6_PORT  PORTSS
#define PA6_PIN   PINSS
#define PA6_BIT   SS

#define XREF_DDR   DDRAREF
#define XREF_PORT  PORTAREF
#define XREF_PIN   PINAREF
#define XREF_BIT   AREF

#define AIN1_DDR   DDRAREF
#define AIN1_PORT  PORTAREF
#define AIN1_PIN   PINAREF
#define AIN1_BIT   AREF

#define ADC7_DDR   DDRAREF
#define ADC7_PORT  PORTAREF
#define ADC7_PIN   PINAREF
#define ADC7_BIT   AREF

#define PCINT7_DDR   DDRAREF
#define PCINT7_PORT  PORTAREF
#define PCINT7_PIN   PINAREF
#define PCINT7_BIT   AREF

#define PA7_DDR   DDRAREF
#define PA7_PORT  PORTAREF
#define PA7_PIN   PINAREF
#define PA7_BIT   AREF

#define OC1BX_DDR   DDRdW
#define OC1BX_PORT  PORTdW
#define OC1BX_PIN   PINdW
#define OC1BX_BIT   dW

#define ADC10_DDR   DDRdW
#define ADC10_PORT  PORTdW
#define ADC10_PIN   PINdW
#define ADC10_BIT   dW

#define PCINT15_DDR   DDRdW
#define PCINT15_PORT  PORTdW
#define PCINT15_PIN   PINdW
#define PCINT15_BIT   dW

#define PB7_DDR   DDRdW
#define PB7_PORT  PORTdW
#define PB7_PIN   PINdW
#define PB7_BIT   dW

#define OC1AX_DDR   DDRINT
#define OC1AX_PORT  PORTINT
#define OC1AX_PIN   PININT
#define OC1AX_BIT   INT0

#define ADC9_DDR   DDRINT
#define ADC9_PORT  PORTINT
#define ADC9_PIN   PININT
#define ADC9_BIT   INT0

#define PCINT14_DDR   DDRINT
#define PCINT14_PORT  PORTINT
#define PCINT14_PIN   PININT
#define PCINT14_BIT   INT0

#define PB6_DDR   DDRINT
#define PB6_PORT  PORTINT
#define PB6_PIN   PININT
#define PB6_BIT   INT0

#define OC1BW_DDR   DDRCLKO
#define OC1BW_PORT  PORTCLKO
#define OC1BW_PIN   PINCLKO
#define OC1BW_BIT   CLKO

#define ADC8_DDR   DDRCLKO
#define ADC8_PORT  PORTCLKO
#define ADC8_PIN   PINCLKO
#define ADC8_BIT   CLKO

#define PCINT13_DDR   DDRCLKO
#define PCINT13_PORT  PORTCLKO
#define PCINT13_PIN   PINCLKO
#define PCINT13_BIT   CLKO

#define PB5_DDR   DDRCLKO
#define PB5_PORT  PORTCLKO
#define PB5_PIN   PINCLKO
#define PB5_BIT   CLKO

#define OC1AW_DDR   DDRCLKI
#define OC1AW_PORT  PORTCLKI
#define OC1AW_PIN   PINCLKI
#define OC1AW_BIT   CLKI

#define PCINT12_DDR   DDRCLKI
#define PCINT12_PORT  PORTCLKI
#define PCINT12_PIN   PINCLKI
#define PCINT12_BIT   CLKI

#define PB4_DDR   DDRCLKI
#define PB4_PORT  PORTCLKI
#define PB4_PIN   PINCLKI
#define PB4_BIT   CLKI

#define PCINT11_DDR   DDROC1BV
#define PCINT11_PORT  PORTOC1BV
#define PCINT11_PIN   PINOC1BV
#define PCINT11_BIT   OC1BV

#define PB3_DDR   DDROC1BV
#define PB3_PORT  PORTOC1BV
#define PB3_PIN   PINOC1BV
#define PB3_BIT   OC1BV

#define USCK_DDR   DDRSCL
#define USCK_PORT  PORTSCL
#define USCK_PIN   PINSCL
#define USCK_BIT   SCL

#define OC1AV_DDR   DDRSCL
#define OC1AV_PORT  PORTSCL
#define OC1AV_PIN   PINSCL
#define OC1AV_BIT   SCL

#define PCINT10_DDR   DDRSCL
#define PCINT10_PORT  PORTSCL
#define PCINT10_PIN   PINSCL
#define PCINT10_BIT   SCL

#define PB2_DDR   DDRSCL
#define PB2_PORT  PORTSCL
#define PB2_PIN   PINSCL
#define PB2_BIT   SCL

#define OC1BU_DDR   DDRDO
#define OC1BU_PORT  PORTDO
#define OC1BU_PIN   PINDO
#define OC1BU_BIT   DO

#define PCINT9_DDR   DDRDO
#define PCINT9_PORT  PORTDO
#define PCINT9_PIN   PINDO
#define PCINT9_BIT   DO

#define PB1_DDR   DDRDO
#define PB1_PORT  PORTDO
#define PB1_PIN   PINDO
#define PB1_BIT   DO

#define DI_DDR   DDRSDA
#define DI_PORT  PORTSDA
#define DI_PIN   PINSDA
#define DI_BIT   SDA

#define OC1AU_DDR   DDRSDA
#define OC1AU_PORT  PORTSDA
#define OC1AU_PIN   PINSDA
#define OC1AU_BIT   SDA

#define PCINT8_DDR   DDRSDA
#define PCINT8_PORT  PORTSDA
#define PCINT8_PIN   PINSDA
#define PCINT8_BIT   SDA

#define PB0_DDR   DDRSDA
#define PB0_PORT  PORTSDA
#define PB0_PIN   PINSDA
#define PB0_BIT   SDA

#endif /* _AVR_PIN_ATTINY87_H_ */

