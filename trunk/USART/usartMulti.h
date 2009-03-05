/*! \file usartSingle.h
 \brief Function declaration for device with a multiple USART.

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
#ifndef USARTMULTI_H_
#define USARTMULTI_H_

void usartMultiSetBaudRate(USART_Port_t port, uint32_t baudRate);
void usartMultiSetNumBit(USART_Port_t port, USART_NumBits_t numBit);
void usartMultiSetParity(USART_Port_t port, USART_Parity_t partity);
void usartMultiSetStopBit(USART_Port_t port, USART_StopBit_t stopBit);
void usartMultiSetMode(USART_Port_t port, USART_Mode_t mode);

void usartMultiEnableRx(USART_Port_t port, _Bool enable);
void usartMultiEnableTx(USART_Port_t port, _Bool enable);

int usartMultiPutc(USART_Port_t port, char data);
int usartMultiPuts(USART_Port_t port, char data);
int usartMultiGetc(USART_Port_t port, char *data);

_Bool usartMultiIsTx(USART_Port_t port);

void usartMultiEnableRxInt(USART_Port_t port, _Bool enable);
void usartMultiEnableTxBufInt(USART_Port_t port, _Bool enable);
void usartMultiEnableTxCmpInt(USART_Port_t port, _Bool enable);

void usartMultiputcISR(USART_Port_t port, char data);
void usartMultigetcISR(USART_Port_t port, char *data);


#endif /* USARTMULTI_H_ */
