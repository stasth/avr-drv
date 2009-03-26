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

/*! \file spiDef.h
 \brief Definition of \c typedef and \c enums use by SPI module.

 \author Frédéric Nadeau
 */
#ifndef SPIDEF_H_
#define SPIDEF_H_

typedef enum SPI_MasterSlave_e
{
	SPI_SingleMaster = 0, /*!< SPI act as a single master on bus.
	Chip Select pin will be configured as output to prevent fallback to
	slave mode.*/
	SPI_MultiMaster, /*!< SPI is configured as master but can fall back
	as slave if Chip Select pin is driven low. */
	SPI_Slave, /*! SPI is configured as slave and will become active when
	Chip select is driven low. */
	SPI_MasterSlaveLast = SPI_Slave /*!< Limit detection. */
}SPI_MasterSlave_t;

typedef enum SPI_MODE_e
{
	SPI_Mode_0 = 0, /*!< CPOL = 0, CPHA = 0 */
	SPI_Mode_1, /*!< CPOL = 0, CPHA = 1 */
	SPI_Mode_2, /*!< CPOL = 1, CPHA = 0 */
	SPI_Mode_3, /*!< CPOL = 1, CPHA = 1 */
	SPI_Mode_Last = SPI_Mode_3 /*!< Limit detection. */
}SPI_Mode_t;

typedef enum SPI_PRESCALER_e
{
	SPI_OSCCLK_DIV2 = 0,/*!< OSCCLK/2 */
	SPI_OSCCLK_DIV4,	/*!< OSCCLK/4 */
	SPI_OSCCLK_DIV8,	/*!< OSCCLK/8 */
	SPI_OSCCLK_DIV16,	/*!< OSCCLK/16 */
	SPI_OSCCLK_DIV32,	/*!< OSCCLK/32 */
	SPI_OSCCLK_DIV64,	/*!< OSCCLK/64 */
	SPI_OSCCLK_DIV128,	/*!< OSCCLK/128 */
	SPI_OSCCLK_DIV_Last = SPI_OSCCLK_DIV128 /*!< Limit detection. */
}SPI_Prescaler_t;


#endif /* SPIDEF_H_ */
