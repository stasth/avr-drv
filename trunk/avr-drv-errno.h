/* Copyright (c) 2008,2009 Frédéric Nadeau
   All rights reserved.

   Redistribution and use in source and binary forms,
   with or without modification, are permitted provided
   that the following conditions are met:

   1.Redistributions of source code must retain the above
   copyright notice, this list of conditions and the following
   disclaimer.

   2.Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

   3.Neither the name of the AVR-DRV nor the names of its
   contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

/*! \file avr-drv-errno.h
 \brief This define error number for AVR-DRV.

 This file is there to prevent compilation error and mistake. All module not
 explicitly disabled by user will be in this file.

 \author Frédéric Nadeau
 */

#ifndef AVRDRVERRNO_H_
#define AVRDRVERRNO_H_

#include <errno.h>

#define EINVAL 22 /*!< Invalid argument. */

#define EBAUDRATE 128 /*!< Requested baud rate is not attainable. */
#define ETXDISABLED 129 /*!< Transmission is not enabled. */
#define ERXDISABLED 130 /*!< Reception is not enabled. */
#define ERXPARITY 131 /*!< Parity error on reception. */
#define ERXOVERRUN 132 /*!< Reception buffer overrun. */
#define ERXFRAM 133 /*!< Framing error on reception. */
#define ERXMULTI 134 /*!< Multiple error cause on reception. */

#endif /* AVRDRVERRNO_H_ */
