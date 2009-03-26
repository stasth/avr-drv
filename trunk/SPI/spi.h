/* Copyright (c) 2009 Frédéric Nadeau
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

/*! \file spi.h
 \brief API for Atmel SPI module.

 \author Frédéric Nadeau
 */
#ifndef SPI_H_
#define SPI_H_

#include "spiDef.h"

#include <stdint.h>

/*! \fn void spiEnable(_Bool isEnable)
 *  \brief Enable or disable SPI block.
 *
 *  \param  isEnable \c true to enable module, \c false to disable it.
 */
void spiEnable(_Bool isEnable);

/*! \fn void spiEnableInt(_Bool isEnable)
 *  \brief Enable or disable interrupt for SPI block.
 *
 *  \param  isEnable \c true to enable interrupt, \c false to disable it.
 */
void spiEnableInt(_Bool isEnable);

/*! \fn int spiInit(_Bool isMsb, SPI_MasterSlave_t masterSlaveMode, SPI_Mode_t mode, SPI_Prescaler_t scaler)
 *  \brief  Configure the SPI port.
 *
 *  \param  isMsb \c true if MSB fist, \c false for LSB first.
 *  \param  masterSlaveMode use #SPI_MasterSlave_t to select operation mode.
 *  \param  mode Use #SPI_Mode_t to select
 *  \param  scaler Use #SPI_Prescaler_t to select clock prescaler.
 *  \return 0 if successful or -1 on error, see errno.\n
 *  #EINVAL Invalid argument.
 */
int spiInit(_Bool isMsb, SPI_MasterSlave_t masterSlaveMode, SPI_Mode_t mode, SPI_Prescaler_t scaler);

/*! \fn int spiSetMasterSlave(SPI_MasterSlave_t mode)
 *  \brief Configure SPI in Slave or Master.
 *
 *  \param  mode use #SPI_MasterSlave_t to select master or slave mode.
 *  \return 0 if successful or -1 on error, see errno.\n
 *  #EINVAL Invalid argument.
 */
int spiSetMasterSlave(SPI_MasterSlave_t mode);

/*! \fn int spiSetMode(SPI_Mode_t mode)
 *  \brief Configure SPI operation mode.
 *
 *  \param  mode use #SPI_Mode_t, see Atmel documentation.
 *  \return 0 if successful or -1 on error, see errno.\n
 *  #EINVAL Invalid argument.
 */
int spiSetMode(SPI_Mode_t mode);

/*! \fn void spiSetMsbLsb(_Bool isMsb)
 *  \brief Configure data order
 *
 * Use to see data transmission in Big Endian or Little Endian
 *  \param  isMsb true is sending MSB fist, false if sending LSB first.
 */
void spiSetMsbLsb(_Bool isMsb);

/*! \fn int spiSetPrescaler(SPI_Prescaler_t scaler)
 *  \brief Configure SPI clock to be use in Master mode.
 *
 *  \param  scaler Division factor, use #SPI_Prescaler_t to select clock source.
 *  \return 0 if successful or -1 on error, see errno.\n
 *  #EINVAL Invalid argument.
 */
int spiSetPrescaler(SPI_Prescaler_t scaler);

/*! \fn int spiTransfer(uint8_t ubDataOut, uint8_t *pubDataIn)
 *  \brief  Send byte over SPI bus.
 *  \param  ubDataOut Data to be send.
 *  \param  pubDataIn Pointer to 8 bit data space.  Red value will be saved at specified address.
 *  \return 0 if successful or -1 on error, see errno.\n
 *  #EINVAL Invalid argument.\n
 *  #ETXDISABLED SPI module is not enabled.
 */
int spiTransfer(uint8_t ubDataOut, uint8_t *pubDataIn);

/*! \fn void spiTransferISR(uint8_t ubDataOut, uint8_t *pubDataIn)
 *  \brief Start a new byte transfer and get last byte in, use only in ISR function.
 *  \param ubDataOut Data to be send.
 *  \param  pubDataIn Pointer to 8 bit data space.
 *          Read value will be saved at specified address.
 *          If address is \c (void*) \c 0, received data will be discarded.
 */
void spiTransferISR(uint8_t ubDataOut, uint8_t *pubDataIn);

#endif /*SPI_H_*/
