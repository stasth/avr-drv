/*
 *  $Id$
 *  $Date$
 */

/*! \file avr-drv-conf-default.h
 \brief Default configuration file.

 This file is there to prevent compilation error and mistake. All module not
 explicitly disabled by user will be in this file.

 \author Frédéric Nadeau

 \warning Copyright (c) 2008 Frédéric Nadeau
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:\n
 1. Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.\n
 2. Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.\n
 3. The name of the author may not be used to endorse or promote products
 derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef AVRDRVDEFAULT_H_
#define AVRDRVDEFAULT_H_

#include <stdbool.h>

#ifndef CLKPRESCALER_BUILD
#	define CLKPRESCALER_BUILD false
#endif

#ifndef ADC_BUILD
#	define ADC_BUILD false
#endif

#ifndef SPI_BUILD
#	define SPI_BUILD false
#endif

#ifndef USART_BUILD
#	define USART_BUILD false
#endif

#endif /* AVRDRVDEFAULT_H_ */
