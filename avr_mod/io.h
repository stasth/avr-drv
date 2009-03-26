/* Copyright (c) 2002,2003,2005,2006,2007 Marek Michalkiewicz, Joerg Wunsch
   Copyright (c) 2007 Eric B. Weddington
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

/* $Id: io.h,v 1.72 2009/03/20 05:54:41 arcanum Exp $ */

/** \file */
/** \defgroup avr_io "avr_mod/io.h": AVR device-specific IO definitions
    \code #include "avr_mod/io.h" \endcode

    This header file includes the apropriate IO definitions for the
    device that has been specified by the <tt>-mmcu=</tt> compiler
    command-line switch.  This is done by diverting to the appropriate
    file <tt>&lt;avr/io</tt><em>XXXX</em><tt>.h&gt;</tt> which should
    never be included directly.  Some register names common to all
    AVR devices are defined directly within <tt>&lt;avr/common.h&gt;</tt>,
    which is included in <tt>&lt;avr/io.h&gt;</tt>,
    but most of the details come from the respective include file.

    Note that this file always includes the following files:
    \code
    #include "avr_mod/sfr_defs.h"
    #include "avr_mod/portpins.h"
    #include "avr_mod/common.h"
    #include "avr_mod/version.h"
    \endcode
    See \ref avr_sfr for more details about that header file.

    Included are definitions of the IO register set and their
    respective bit values as specified in the Atmel documentation.
    Note that inconsistencies in naming conventions,
    so even identical functions sometimes get different names on
    different devices.

    Also included are the specific names useable for interrupt
    function definitions as documented
    \ref avr_signames "here".

    Finally, the following macros are defined:

    - \b RAMEND
    <br>
    The last on-chip RAM address.
    <br>
    - \b XRAMEND
    <br>
    The last possible RAM location that is addressable. This is equal to
    RAMEND for devices that do not allow for external RAM. For devices
    that allow external RAM, this will be larger than RAMEND.
    <br>
    - \b E2END
    <br>
    The last EEPROM address.
    <br>
    - \b FLASHEND
    <br>
    The last byte address in the Flash program space.
    <br>
    - \b SPM_PAGESIZE
    <br>
    For devices with bootloader support, the flash pagesize
    (in bytes) to be used for the \c SPM instruction.
    - \b E2PAGESIZE
    <br>
    The size of the EEPROM page.

*/

#ifndef _AVR_IO_H_
#define _AVR_IO_H_

#include "avr_mod/sfr_defs.h"

#if defined (__AVR_AT94K__)
#  include "avr_mod/ioat94k.h"
#elif defined (__AVR_AT43USB320__)
#  include "avr_mod/io43u32x.h"
#elif defined (__AVR_AT43USB355__)
#  include "avr_mod/io43u35x.h"
#elif defined (__AVR_AT76C711__)
#  include "avr_mod/io76c711.h"
#elif defined (__AVR_AT86RF401__)
#  include "avr_mod/io86r401.h"
#elif defined (__AVR_AT90PWM1__)
#  include "avr_mod/io90pwm1.h"
#elif defined (__AVR_AT90PWM2__)
#  include "avr_mod/io90pwmx.h"
#elif defined (__AVR_AT90PWM2B__)
#  include "avr_mod/io90pwm2b.h"
#elif defined (__AVR_AT90PWM3__)
#  include "avr_mod/io90pwmx.h"
#elif defined (__AVR_AT90PWM3B__)
#  include "avr_mod/io90pwm3b.h"
#elif defined (__AVR_AT90PWM216__)
#  include "avr_mod/io90pwm216.h"
#elif defined (__AVR_AT90PWM316__)
#  include "avr_mod/io90pwm316.h"
#elif defined (__AVR_AT90PWM81__)
#  include "avr_mod/io90pwm81.h"
#elif defined (__AVR_ATmega16M1__)
#  include "avr_mod/iom16m1.h"
#elif defined (__AVR_ATmega16U4__)
#  include "avr_mod/iom16u4.h"
#elif defined (__AVR_ATmega32C1__)
#  include "avr_mod/iom32c1.h"
#elif defined (__AVR_ATmega32M1__)
#  include "avr_mod/iom32m1.h"
#elif defined (__AVR_ATmega32U4__)
#  include "avr_mod/iom32u4.h"
#elif defined (__AVR_ATmega32U6__)
#  include "avr_mod/iom32u6.h"
#elif defined (__AVR_ATmega64C1__)
#  include "avr_mod/iom64c1.h"
#elif defined (__AVR_ATmega64M1__)
#  include "avr_mod/iom64m1.h"
#elif defined (__AVR_ATmega128__)
#  include "avr_mod/iom128.h"
#elif defined (__AVR_ATmega1280__)
#  include "avr_mod/iom1280.h"
#elif defined (__AVR_ATmega1281__)
#  include "avr_mod/iom1281.h"
#elif defined (__AVR_ATmega1284P__)
#  include "avr_mod/iom1284p.h"
#elif defined (__AVR_ATmega128RFA1__)
#  include "avr_mod/iom128rfa1.h"
#elif defined (__AVR_ATmega2560__)
#  include "avr_mod/iom2560.h"
#elif defined (__AVR_ATmega2561__)
#  include "avr_mod/iom2561.h"
#elif defined (__AVR_AT90CAN32__)
#  include "avr_mod/iocan32.h"
#elif defined (__AVR_AT90CAN64__)
#  include "avr_mod/iocan64.h"
#elif defined (__AVR_AT90CAN128__)
#  include "avr_mod/iocan128.h"
#elif defined (__AVR_AT90USB82__)
#  include "avr_mod/iousb82.h"
#elif defined (__AVR_AT90USB162__)
#  include "avr_mod/iousb162.h"
#elif defined (__AVR_AT90USB646__)
#  include "avr_mod/iousb646.h"
#elif defined (__AVR_AT90USB647__)
#  include "avr_mod/iousb647.h"
#elif defined (__AVR_AT90USB1286__)
#  include "avr_mod/iousb1286.h"
#elif defined (__AVR_AT90USB1287__)
#  include "avr_mod/iousb1287.h"
#elif defined (__AVR_ATmega64__)
#  include "avr_mod/iom64.h"
#elif defined (__AVR_ATmega640__)
#  include "avr_mod/iom640.h"
#elif defined (__AVR_ATmega644__)
#  include "avr_mod/iom644.h"
#elif defined (__AVR_ATmega644P__)
#  include "avr_mod/iom644.h"
#elif defined (__AVR_ATmega645__)
#  include "avr_mod/iom645.h"
#elif defined (__AVR_ATmega6450__)
#  include "avr_mod/iom6450.h"
#elif defined (__AVR_ATmega649__)
#  include "avr_mod/iom649.h"
#elif defined (__AVR_ATmega6490__)
#  include "avr_mod/iom6490.h"
#elif defined (__AVR_ATmega103__)
#  include "avr_mod/iom103.h"
#elif defined (__AVR_ATmega32__)
#  include "avr_mod/iom32.h"
#elif defined (__AVR_ATmega323__)
#  include "avr_mod/iom323.h"
#elif defined (__AVR_ATmega324P__)
#  include "avr_mod/iom324.h"
#elif defined (__AVR_ATmega325__)
#  include "avr_mod/iom325.h"
#elif defined (__AVR_ATmega325P__)
#  include "avr_mod/iom325.h"
#elif defined (__AVR_ATmega3250__)
#  include "avr_mod/iom3250.h"
#elif defined (__AVR_ATmega3250P__)
#  include "avr_mod/iom3250.h"
#elif defined (__AVR_ATmega328P__)
#  include "avr_mod/iom328p.h"
#elif defined (__AVR_ATmega329__)
#  include "avr_mod/iom329.h"
#elif defined (__AVR_ATmega329P__)
#  include "avr_mod/iom329.h"
#elif defined (__AVR_ATmega3290__)
#  include "avr_mod/iom3290.h"
#elif defined (__AVR_ATmega3290P__)
#  include "avr_mod/iom3290.h"
#elif defined (__AVR_ATmega32HVB__)
#  include "avr_mod/iom32hvb.h"
#elif defined (__AVR_ATmega406__)
#  include "avr_mod/iom406.h"
#elif defined (__AVR_ATmega16__)
#  include "avr_mod/iom16.h"
#elif defined (__AVR_ATmega161__)
#  include "avr_mod/iom161.h"
#elif defined (__AVR_ATmega162__)
#  include "avr_mod/iom162.h"
#elif defined (__AVR_ATmega163__)
#  include "avr_mod/iom163.h"
#elif defined (__AVR_ATmega164P__)
#  include "avr_mod/iom164.h"
#elif defined (__AVR_ATmega165__)
#  include "avr_mod/iom165.h"
#elif defined (__AVR_ATmega165P__)
#  include "avr_mod/iom165p.h"
#elif defined (__AVR_ATmega168__)
#  include "avr_mod/iom168.h"
#elif defined (__AVR_ATmega168P__)
#  include "avr_mod/iom168p.h"
#elif defined (__AVR_ATmega169__)
#  include "avr_mod/iom169.h"
#elif defined (__AVR_ATmega169P__)
#  include "avr_mod/iom169p.h"
#elif defined (__AVR_ATmega8HVA__)
#  include "avr_mod/iom8hva.h"
#elif defined (__AVR_ATmega16HVA__)
#  include "avr_mod/iom16hva.h"
#elif defined (__AVR_ATmega8__)
#  include "avr_mod/iom8.h"
#elif defined (__AVR_ATmega48__)
#  include "avr_mod/iom48.h"
#elif defined (__AVR_ATmega48P__)
#  include "avr_mod/iom48p.h"
#elif defined (__AVR_ATmega88__)
#  include "avr_mod/iom88.h"
#elif defined (__AVR_ATmega88P__)
#  include "avr_mod/iom88p.h"
#elif defined (__AVR_ATmega8515__)
#  include "avr_mod/iom8515.h"
#elif defined (__AVR_ATmega8535__)
#  include "avr_mod/iom8535.h"
#elif defined (__AVR_AT90S8535__)
#  include "avr_mod/io8535.h"
#elif defined (__AVR_AT90C8534__)
#  include "avr_mod/io8534.h"
#elif defined (__AVR_AT90S8515__)
#  include "avr_mod/io8515.h"
#elif defined (__AVR_AT90S4434__)
#  include "avr_mod/io4434.h"
#elif defined (__AVR_AT90S4433__)
#  include "avr_mod/io4433.h"
#elif defined (__AVR_AT90S4414__)
#  include "avr_mod/io4414.h"
#elif defined (__AVR_ATtiny22__)
#  include "avr_mod/iotn22.h"
#elif defined (__AVR_ATtiny26__)
#  include "avr_mod/iotn26.h"
#elif defined (__AVR_AT90S2343__)
#  include "avr_mod/io2343.h"
#elif defined (__AVR_AT90S2333__)
#  include "avr_mod/io2333.h"
#elif defined (__AVR_AT90S2323__)
#  include "avr_mod/io2323.h"
#elif defined (__AVR_AT90S2313__)
#  include "avr_mod/io2313.h"
#elif defined (__AVR_ATtiny2313__)
#  include "avr_mod/iotn2313.h"
#elif defined (__AVR_ATtiny13__)
#  include "avr_mod/iotn13.h"
#elif defined (__AVR_ATtiny13A__)
#  include "avr_mod/iotn13a.h"
#elif defined (__AVR_ATtiny25__)
#  include "avr_mod/iotn25.h"
#elif defined (__AVR_ATtiny45__)
#  include "avr_mod/iotn45.h"
#elif defined (__AVR_ATtiny85__)
#  include "avr_mod/iotn85.h"
#elif defined (__AVR_ATtiny24__)
#  include "avr_mod/iotn24.h"
#elif defined (__AVR_ATtiny44__)
#  include "avr_mod/iotn44.h"
#elif defined (__AVR_ATtiny84__)
#  include "avr_mod/iotn84.h"
#elif defined (__AVR_ATtiny261__)
#  include "avr_mod/iotn261.h"
#elif defined (__AVR_ATtiny461__)
#  include "avr_mod/iotn461.h"
#elif defined (__AVR_ATtiny861__)
#  include "avr_mod/iotn861.h"
#elif defined (__AVR_ATtiny43U__)
#  include "avr_mod/iotn43u.h"
#elif defined (__AVR_ATtiny48__)
#  include "avr_mod/iotn48.h"
#elif defined (__AVR_ATtiny88__)
#  include "avr_mod/iotn88.h"
#elif defined (__AVR_ATtiny87__)
#  include "avr_mod/iotn87.h"
#elif defined (__AVR_ATtiny167__)
#  include "avr_mod/iotn167.h"
#elif defined (__AVR_AT90SCR100__)
#  include "avr_mod/io90scr100.h"
#elif defined (__AVR_ATxmega16A4__)
#  include "avr_mod/iox16a4.h"
#elif defined (__AVR_ATxmega16D4__)
#  include "avr_mod/iox16d4.h"
#elif defined (__AVR_ATxmega32A4__)
#  include "avr_mod/iox32a4.h"
#elif defined (__AVR_ATxmega32D4__)
#  include "avr_mod/iox32d4.h"
#elif defined (__AVR_ATxmega64A1__)
#  include "avr_mod/iox64a1.h"
#elif defined (__AVR_ATxmega64A3__)
#  include "avr_mod/iox64a3.h"
#elif defined (__AVR_ATxmega128A1__)
#  include "avr_mod/iox128a1.h"
#elif defined (__AVR_ATxmega128A3__)
#  include "avr_mod/iox128a3.h"
#elif defined (__AVR_ATxmega192A3__)
#  include "avr_mod/iox192a3.h"
#elif defined (__AVR_ATxmega256A3__)
#  include "avr_mod/iox256a3.h"
#elif defined (__AVR_ATxmega256A3B__)
#  include "avr_mod/iox256a3b.h"
#elif defined (__AVR_ATA6289__)
#  include "avr_mod/ioa6289.h"
/* avr1: the following only supported for assembler programs */
#elif defined (__AVR_ATtiny28__)
#  include "avr_mod/iotn28.h"
#elif defined (__AVR_AT90S1200__)
#  include "avr_mod/io1200.h"
#elif defined (__AVR_ATtiny15__)
#  include "avr_mod/iotn15.h"
#elif defined (__AVR_ATtiny12__)
#  include "avr_mod/iotn12.h"
#elif defined (__AVR_ATtiny11__)
#  include "avr_mod/iotn11.h"
#else
#  if !defined(__COMPILING_AVR_LIBC__)
#    warning "device type not defined"
#  endif
#endif

#include "avr_mod/portpins.h"

#include "avr_mod/common.h"

#include "avr_mod/version.h"

/* Include fuse.h after individual IO header files. */
#include "avr_mod/fuse.h"

/* Include lock.h after individual IO header files. */
#include "avr_mod/lock.h"

#endif /* _AVR_IO_H_ */
