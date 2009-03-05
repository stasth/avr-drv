/*! \file usart.h
 \brief Function definition for USART module.

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
 3. The name of the author nor the names of its contributors may not
 be used to endorse or promote products derived from this software
 without specific prior written permission.

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
#ifndef USART_H_
#define USART_H_

#include "usartCoreSelection.h"
#include "usartDef.h"

#if USART_NUM_PORT == 1
#	include "usartSingle.h"
#	define  usartSetBaudRate(port, baudRate) usartSingleSetBaudRate(baudRate)
#	define  usartSetNumBit(port, numBit) usartSingleSetNumBit(numBit)
#	define  usartSetParity(port, partity) usartSingleSetParity(partity)
#	define  usartSetStopBit(port, stopBit) usartSingleSetStopBit(stopBit)
#	define  usartSetMode(port, mode) usartSingleSetMode(mode)

#	define  usartEnableRx(port, enable) usartSingleEnableRx(enable)
#	define  usartEnableTx(port, enable) usartSingleEnableTx(enable)

#	define  usartPutc(port, data) usartSinglePutc(data)
#	define  usartPuts(port, data) usartSinglePuts(data)
#	define  usartGetc(port, data) usartSingleGetc(data)

#	define  usartIsTx(port) usartSingleIsTx()

#	define  usartEnableRxInt(port, enable) usartSingleEnableRxInt(enable)
#	define  usartEnableTxBufInt(port, enable) usartSingleEnableTxBufInt(enable)
#	define  usartEnableTxCmpInt(port, enable) usartSingleEnableTxCmpInt(enable)

#	define  usartPutcISR(port, data) usartSinglePutcISR(data)
#	define  usartGetcISR(port, data) usartSingleGetcISR(data)
#else
#	include "usartMulti.h"
#	define  usartSetBaudRate(port, baudRate) usartMultiSetBaudRate(port, baudRate)
#	define  usartSetNumBit(port, numBit) usartMultiSetNumBit(port, numBit)
#	define  usartSetParity(port, partity) usartMultiSetParity(port, partity)
#	define  usartSetStopBit(port, stopBit) usartMultiSetStopBit(port, stopBit)
#	define  usartSetMode(port, mode) usartMultiSetMode(port, mode)

#	define  usartEnableRx(port, enable) usartMultiEnableRx(port, enable)
#	define  usartEnableTx(port, enable) usartMultiEnableTx(port, enable)

#	define  usartPutc(port, data) usartMultiPutc(port, data)
#	define  usartPuts(port, data) usartMultiPuts(port, data)
#	define  usartGetc(port, data) usartMultiGetc(port, data)

#	define  usartIsTx(port) usartMultiIsTx(port)

#	define  usartEnableRxInt(port, enable) usartMultiEnableRxInt(port, enable)
#	define  usartEnableTxBufInt(port, enable) usartMultiEnableTxBufInt(port, enable)
#	define  usartEnableTxCmpInt(port, enable) usartMultiEnableTxCmpInt(port, enable)

#	define  usartPutcISR(port, data) usartMultiPutcISR(port, data)
#	define  usartGetcISR(port, data) usartMultiGetcISR(port, data)
#endif

#endif /* USART_H_ */
