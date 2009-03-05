/*! \file can.c
 \brief API for Atmel CAN module.

 \author Frédéric Nadeau
 \author François-Pierre Pépin
 \author Sy Sech Vong

 \warning Copyright (c) 2008
 Frédéric Nadeau
 François-Pierre Pépin
 Sy Sech Vong
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
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <avr/io.h>

#include "can.h"

#define CAN_MINTQ							8
#define CAN_MAXTQ							25

/************************************************/
/*     CAN General Control Register CANGCON     */
/************************************************/

void canSetAbortAbort(void)
{
	CANGCON |= (1<<ABRQ);
}

void canClearAbortAbort(void)
{
	CANGCON &= ~(1<<ABRQ);
}

void canSetOverloadFrameRequest(void)
{
	CANGCON |= (1<<OVRQ);
}

void canClearOverloadFrameRequest(void)
{
	CANGCON &= ~(1<<OVRQ);
}

void canEnableTimeTriggerCommunication(void)
{
	CANGCON |= (1<<TTC);
}

void canDisableTimeTriggerCommunication(void)
{
	CANGCON &= ~(1<<TTC);
}

void canTTCSyncOnLastBitOfEOF(void)
{
	CANGCON |= (1<<SYNTTC);
}

void canTTCSyncOnSOF(void)
{
	CANGCON &= ~(1<<SYNTTC);
}

void canEnableListeningMode(void)
{
	CANGCON |= (1<<LISTEN);
}

void canDisableListeningMode(void)
{
	CANGCON &= ~(1<<LISTEN);
}

void canSetEnableMode(void)
{
	CANGCON |= (1<<ENASTB);
}

void canSetStandbyMode(void)
{
	CANGCON &= ~(1<<ENASTB);
}

void canRequestReset(void)
{
	CANGCON |= (1<<SWRES);
}

/************************************************/
/*     CAN General Status Register CANGSTA      */
/************************************************/

uint8_t canReadOverloadFrameFlag(void)
{
	uint8_t ubRetVal = CANGSTA; //Read register
	ubRetVal = ubRetVal>>(OVFG); //Shit value so we get 1 or 0
	return ubRetVal;
}

uint8_t canIsTransmitterBusy(void)
{
	uint8_t ubRetVal = CANGSTA; //Read register
	ubRetVal = (ubRetVal & (1<<TXBSY))>>(TXBSY); //Shit value so we get 1 or 0
	return ubRetVal;
}

uint8_t canIsReceiverBusy(void)
{
	uint8_t ubRetVal = CANGSTA; //Read register
	ubRetVal = (ubRetVal & (1<<RXBSY))>>(RXBSY); //Shit value so we get 1 or 0
	return ubRetVal;
}

uint8_t canIsEnable(void)
{
	uint8_t ubRetVal = CANGSTA; //Read register
	ubRetVal = (ubRetVal & (1<<ENFG))>>(ENFG); //Shit value so we get 1 or 0
	return ubRetVal;
}

uint8_t canIsBusOff(void)
{
	uint8_t ubRetVal = CANGSTA; //Read register
	ubRetVal = (ubRetVal & (1<<BOFF))>>(BOFF); //Shit value so we get 1 or 0
	return ubRetVal;
}

uint8_t canIsErrorPassive(void)
{
	uint8_t ubRetVal = CANGSTA; //Read register
	ubRetVal = (ubRetVal & (1<<ERRP))>>(ERRP); //Shit value so we get 1 or 0
	return ubRetVal;
}

/************************************************/
/*    CAN General Interrupt Register CANGIT     */
/************************************************/

uint8_t canIsInterrupt(void)
{
	uint8_t ubRetVal = CANGIT; //Read register
	ubRetVal = (ubRetVal & (1<<CANIT))>>(CANIT); //Shit value so we get 1 or 0
	return ubRetVal;
}

uint8_t canReadBusOffInterruptFlag(void)
{
	uint8_t ubRetVal = CANGIT; //Read register
	ubRetVal = (ubRetVal & (1<<BOFFIT))>>(BOFFIT); //Shit value so we get 1 or 0
	return ubRetVal;
}

void canClearBusOffInterruptFlag(void)
{
	CANGIT |= (1<<BOFFIT);
}

uint8_t canReadOverrunCANTimerInterruptFlag(void)
{
	uint8_t ubRetVal = CANGIT; //Read register
	ubRetVal = (ubRetVal & (1<<OVRTIM))>>(OVRTIM); //Shit value so we get 1 or 0
	return ubRetVal;
}

void canClearOverrunCANTimerInterruptFlag(void)
{
	CANGIT |= (1<<OVRTIM);
}

uint8_t canReadFrameBufferReveiveInterruptFlag(void)
{
	uint8_t ubRetVal = CANGIT; //Read register
	ubRetVal = (ubRetVal & (1<<BXOK))>>(BXOK); //Shit value so we get 1 or 0
	return ubRetVal;
}

void canClearFrameBufferReveiveInterruptFlag(void)
{
	CANGIT |= (1<<BXOK);
}

uint8_t canReadStuffErrorGeneralInterruptFlag(void)
{
	uint8_t ubRetVal = CANGIT; //Read register
	ubRetVal = (ubRetVal & (1<<SERG))>>(SERG); //Shit value so we get 1 or 0
	return ubRetVal;
}

void canClearStuffErrorGeneralInterruptFlag(void)
{
	CANGIT |= (1<<SERG);
}

uint8_t canReadCRCErrorGeneralInterruptFlag(void)
{
	uint8_t ubRetVal = CANGIT; //Read register
	ubRetVal = (ubRetVal & (1<<CERG))>>(CERG); //Shit value so we get 1 or 0
	return ubRetVal;
}

void canClearCRCErrorGeneralInterruptFlag(void)
{
	CANGIT |= (1<<CERG);
}

uint8_t canReadFormErrorGeneralInterruptFlag(void)
{
	uint8_t ubRetVal = CANGIT; //Read register
	ubRetVal = (ubRetVal & (1<<FERG))>>(FERG); //Shit value so we get 1 or 0
	return ubRetVal;
}

void canClearFormErrorGeneralInterruptFlag(void)
{
	CANGIT |= (1<<FERG);
}

uint8_t canReadAckErrorGeneralInterruptFlag(void)
{
	uint8_t ubRetVal = CANGIT; //Read register
	ubRetVal = (ubRetVal & (1<<AERG))>>(AERG); //Shit value so we get 1 or 0
	return ubRetVal;
}

void canClearAckErrorGeneralInterruptFlag(void)
{
	CANGIT |= (1<<AERG);
}

/************************************************/
/* CAN General Interrupt Enable Register CANGIE */
/************************************************/

void canEnableAllInterrupt(void)
{
	CANGIE |= (1<<ENIT);
}

void canDisableAllInterrupt(void)
{
	CANGIE &= ~(1<<ENIT);
}

void canEnableBusOffInterrupt(void)
{
	CANGIE |= (1<<ENBOFF);
}

void canDisableBusOffInterrupt(void)
{
	CANGIE &= ~(1<<ENBOFF);
}

void canEnableReceiveInterrupt(void)
{
	CANGIE |= (1<<ENRX);
}

void canDisableReceiveInterrupt(void)
{
	CANGIE &= ~(1<<ENRX);
}

uint8_t canIsReceiveInterruptActive(void)
{
	uint8_t ubRetVal = CANGIE & (1 << ENRX);
	ubRetVal = ubRetVal>>ENRX;
	return ubRetVal;
}

void canEnableTransmitInterrupt(void)
{
	CANGIE |= (1<<ENTX);
}

void canDisableTransmitInterrupt(void)
{
	CANGIE &= ~(1<<ENTX);
}

uint8_t canIsTransmitInterruptActive(void)
{
	uint8_t ubRetVal = CANGIE & (1 << ENTX);
	ubRetVal = ubRetVal>>ENTX;
	return ubRetVal;
}

void canEnableMObErrorsInterrupt(void)
{
	CANGIE |= (1<<ENERR);
}

void canDisableMObErrorsInterrupt(void)
{
	CANGIE &= ~(1<<ENERR);
}

void canEnableFrameBufferInterrupt(void)
{
	CANGIE |= (1<<ENBX);
}

void canDisableFrameBufferInterrupt(void)
{
	CANGIE &= ~(1<<ENBX);
}

void canEnableGeneralErrorsInterrupt(void)
{
	CANGIE |= (1<<ENERG);
}

void canDisableGeneralErrorsInterrupt(void)
{
	CANGIE &= ~(1<<ENERG);
}

void canEnableCANTimerOverrunInterrupt(void)
{
	CANGIE |= (1<<ENOVRT);
}

void canDisableCANTimerOverrunInterrupt(void)
{
	CANGIE &= ~(1<<ENOVRT);
}

/************************************************/
/*        CAN Enable Mob Register CANENx        */
/************************************************/

uint8_t canIsMObEnabled(uint8_t ubMOb)
{
	uint8_t uwRetVal = 0;
	assert(ubMOb < 15);

	if (ubMOb < 8)
	{
		uwRetVal = (CANEN2 & (1<<ubMOb))>>(ubMOb);
	}
	else
	{
		ubMOb = ubMOb - 8;
		uwRetVal = (CANEN1 & (1<<ubMOb))>>(ubMOb);
	}
	return uwRetVal;
}

/************************************************/
/*   CAN Enable Interrupt Mob Register CANIEx   */
/************************************************/

void canEnableInterruptMOb(uint8_t ubMOb)
{
	assert(ubMOb < 15);

	if (ubMOb < 8)
	{
		CANIE2 |= (1<<ubMOb);
	}
	else
	{
		//ubMOb &= 0x07;
		ubMOb = ubMOb - 8;
		CANIE1 |= (1<<ubMOb);
	}
}

void canDisableInterruptMOb(uint8_t ubMOb)
{
	assert(ubMOb < 15);

	if (ubMOb < 8)
	{
		CANIE2 &= ~(1<<ubMOb);
	}
	else
	{
		ubMOb = ubMOb - 8;
		CANIE1 &= ~(1<<ubMOb);
	}
}

/************************************************/
/*   CAN Status Interrupt MOb Register CANSITx  */
/************************************************/

/* It returns 1 if has interrupt, 0 else. */
uint8_t canReadStatusInterruptMOb(uint8_t ubMOb)
{
	uint8_t uwRetVal = 0;
	assert(ubMOb < 15);

	if (ubMOb < 8)
	{
		uwRetVal = (CANSIT2 & (1<<ubMOb))>>(ubMOb);
	}
	else
	{
		ubMOb = ubMOb - 8;
		uwRetVal = (CANSIT1 & (1<<ubMOb))>>(ubMOb);
	}
	return uwRetVal;
}

/************************************************/
/*       CAN Bit Timing Register 1 CANBT1       */
/************************************************/

void canWriteBitTimingRegister1(uint8_t ubData)
{
	CANBT1 = ubData & 0x7E;
}

uint8_t canReadBitTimingRegister1(void)
{
	return CANBT1;
}

/************************************************/
/*       CAN Bit Timing Register 2 CANBT2       */
/************************************************/

void canWriteReSyncJumpWidth(uint8_t ubData)
{
	assert(ubData < 4);
	CANBT2 &= ~( (1<<SJW1) | (1<<SJW0) );//Remove current info
	CANBT2 |= (ubData<<SJW0);
}

uint8_t canReadReSyncJumpWidth(void)
{
	uint8_t ubRetVal = 0;
	ubRetVal = CANBT2;
	ubRetVal &= ( (1<<SJW1) | (1<<SJW0) );
	ubRetVal = (ubRetVal>>SJW0);
	return ubRetVal;
}

void canWritePropagationTimeSegment(uint8_t ubData)
{
	assert(ubData < 8);
	CANBT2 &= ~( (1<<PRS2) | (1<<PRS1) | (1<<PRS0) );//Remove current info
	CANBT2 |= (ubData<<PRS0);
}

uint8_t canReadPropagationTimeSegment(void)
{
	uint8_t ubRetVal = 0;
	ubRetVal = CANBT2;
	ubRetVal &= ( (1<<PRS2) | (1<<PRS1) | (1<<PRS0) );
	ubRetVal = (ubRetVal>>SJW0);
	return ubRetVal;
}

/************************************************/
/*       CAN Bit Timing Register 3 CANBT3       */
/************************************************/

void canWritePhaseSegment2(uint8_t ubData)
{
	assert(ubData < 8);
	CANBT3 &= ~( (1<<PHS22) | (1<<PHS21) | (1<<PHS20) );//Remove current info
	CANBT3 |= (ubData<<PHS20);
}

uint8_t canReadPhaseSegment2(void)
{
	uint8_t ubRetVal = 0;
	ubRetVal = CANBT3;
	ubRetVal &= ( (1<<PHS22) | (1<<PHS21) | (1<<PHS20) );
	ubRetVal = (ubRetVal>>SJW0);
	return ubRetVal;
}

void canWritePhaseSegment1(uint8_t ubData)
{
	assert(ubData < 8);
	CANBT3 &= ~( (1<<PHS12) | (1<<PHS11) | (1<<PHS10) );//Remove current info
	CANBT3 |= (ubData<<PHS10);
}

uint8_t canReadPhaseSegment1(void)
{
	uint8_t ubRetVal = 0;
	ubRetVal = CANBT3;
	ubRetVal &= ( (1<<PHS12) | (1<<PHS11) | (1<<PHS10) );
	ubRetVal = (ubRetVal>>SJW0);
	return ubRetVal;
}

void canWriteSamplePoint(uint8_t ubData)
{
	assert(ubData < 2);
	CANBT3 &= ~(1<<SMP);//Remove current info
	CANBT3 |= (ubData<<SMP);
}

uint8_t canReadSamplePoint(void)
{
	uint8_t ubRetVal = 0;
	ubRetVal = CANBT3;
	ubRetVal &= (1<<SMP);
	ubRetVal = (ubRetVal>>SMP);
	return ubRetVal;
}

/************************************************/
/*     CAN Timer Control Register CANTCON       */
/************************************************/

void canWriteTimerControlRegister(uint8_t ubData)
{
	CANTCON = ubData;
}

uint8_t canReadTimerControlRegister(void)
{
	return CANTCON;
}

/************************************************/
/*          CAN Timer Register CANTIMx          */
/************************************************/

uint16_t canReadTimerRegister(void)
{
	uint16_t uwRetVal = CANTIMH;//Read High byte
	uwRetVal = uwRetVal<<8;//Allign high byte
	uwRetVal += CANTIML;//Add low byte
	return uwRetVal;
}

/************************************************/
/*      CAN TTC Timer Register CANTTCx          */
/************************************************/

uint16_t canReadTTCTimerRegister(void)
{
	uint16_t uwRetVal = CANTTCH;//Read High byte
	uwRetVal = uwRetVal<<8;//Allign high byte
	uwRetVal += CANTTCL;//Add low byte
	return uwRetVal;
}

/************************************************/
/*  CAN Transmit Error Counter Register CANTEC  */
/************************************************/

uint8_t canReadTransmitErrorCounter(void)
{
	return CANTEC;
}

/************************************************/
/*  CAN Receive Error Counter Register CANREC   */
/************************************************/

uint8_t canReadReceiveErrorCounter(void)
{
	return CANTEC;
}

/************************************************/
/*  CAN Highest Priority MOb Register CANHPMOB  */
/************************************************/

uint8_t canReadHighestPriorityMObNumber(void)
{
	uint8_t ubRetVal = CANHPMOB;
	ubRetVal &= ( (1<<HPMOB3) | (1<<HPMOB2) | (1<<HPMOB1) | (1<<HPMOB0) );
	ubRetVal = ubRetVal>>HPMOB0;
	return ubRetVal;
}

void canWriteGeneralPurposeBits(uint8_t ubData)
{
	assert(ubData < 16);
	CANHPMOB &= ~( (1<<CGP3) | (1<<CGP2) | (1<<CGP1) | (1<<CGP0) );//Remove current info
	CANHPMOB |= (ubData<<CGP0);
}

uint8_t canReadGeneralPurposeBits(void)
{
	uint8_t ubRetVal = CANHPMOB;
	ubRetVal &= ( (1<<CGP3) | (1<<CGP2) | (1<<CGP1) | (1<<CGP0) );
	ubRetVal = ubRetVal>>HPMOB0;
	return ubRetVal;
}

/************************************************/
/*        CAN Page MOb Register CANPAGE         */
/************************************************/

void canWriteMObNumber(uint8_t ubData)
{
	assert(ubData < 15);
	//CANPAGE &= ~( (1<<MOBNB3) | (1<<MOBNB2) | (1<<MOBNB1) | (1<<MOBNB0) | (0<<AINC) | (1<<INDX2) | (1<<INDX1) | (1<<INDX0));//Remove current info and reset the index
	CANPAGE &= (1<<AINC);//Remove current MOb and reset the index
	CANPAGE |= (ubData<<MOBNB0);
}

uint8_t canReadMObNumber(void)
{
	uint8_t ubRetVal = CANPAGE;
	ubRetVal &= ( (1<<MOBNB3) | (1<<MOBNB2) | (1<<MOBNB1) | (1<<MOBNB0) );
	ubRetVal = ubRetVal>>MOBNB0;
	return ubRetVal;
}

void canWriteAutoIncrement(uint8_t ubData)
{
	assert(ubData < 2);
	CANPAGE &= ~(1<<AINC);//Remove current info
	CANPAGE |= (ubData<<AINC);
}

uint8_t canReadAutoIncrement(void)
{
	uint8_t ubRetVal = CANPAGE;
	ubRetVal &= (1<<AINC);
	ubRetVal = ubRetVal>>AINC;
	return ubRetVal;
}

void canWriteFIFOCANDataIndex(uint8_t ubData)
{
	assert(ubData < 15);
	CANPAGE &= ~( (1<<INDX2) | (1<<INDX1) | (1<<INDX0) );//Remove current info
	CANPAGE |= (ubData<<INDX0);
}

uint8_t canReadFIFOCANDataIndex(void)
{
	uint8_t ubRetVal = CANPAGE;
	ubRetVal &= ( (1<<INDX2) | (1<<INDX1) | (1<<INDX0) );
	ubRetVal = ubRetVal>>INDX0;
	return ubRetVal;
}

/************************************************/
/*       CAN MOb Status Register CANSTMOB       */
/************************************************/

void canWriteDataLengthCodeWarning(uint8_t ubData)
{
	assert(ubData < 2);
	CANSTMOB &= ~(1<<DLCW);//Remove current info
	CANSTMOB |= (ubData<<DLCW);
}

uint8_t canReadDataLengthCodeWarning(void)
{
	uint8_t ubRetVal = CANSTMOB;
	ubRetVal &= (1<<DLCW);
	ubRetVal = ubRetVal>>DLCW;
	return ubRetVal;
}

uint8_t canReadTransmitOKFlag(void)
{
	uint8_t ubRetVal = CANSTMOB;
	ubRetVal &= (1<<TXOK);
	ubRetVal = ubRetVal>>TXOK;
	return ubRetVal;
}

void canCleanTransmitOKFlag(void)
{
	//CANSTMOB |= (1<<TXOK);//must be read-modify-write
	CANSTMOB &= ~(1<<TXOK);
}

uint8_t canReadReceiveOKFlag(void)
{
	uint8_t ubRetVal = CANSTMOB;
	ubRetVal &= (1<<RXOK);
	ubRetVal = ubRetVal>>RXOK;
	return ubRetVal;
}

void canCleanReceiveOKFlag(void)
{
	//CANSTMOB |= (1<<RXOK);//must be read-modify-write
	CANSTMOB &= ~(1<<RXOK);
}

uint8_t canReadBitErrorFlag(void)
{
	uint8_t ubRetVal = CANSTMOB;
	ubRetVal &= (1<<BERR);
	ubRetVal = ubRetVal>>BERR;
	return ubRetVal;
}

void canCleanBitErrorFlag(void)
{
	CANSTMOB |= (1<<BERR);//must be read-modify-write
}

uint8_t canReadStuffErrorFlag(void)
{
	uint8_t ubRetVal = CANSTMOB;
	ubRetVal &= (1<<SERR);
	ubRetVal = ubRetVal>>SERR;
	return ubRetVal;
}

void canCleanStuffErrorFlag(void)
{
	CANSTMOB |= (1<<SERR);//must be read-modify-write
}

uint8_t canReadCRCErrorFlag(void)
{
	uint8_t ubRetVal = CANSTMOB;
	ubRetVal &= (1<<CERR);
	ubRetVal = ubRetVal>>CERR;
	return ubRetVal;
}

void canCleanCRCErrorFlag(void)
{
	CANSTMOB |= (1<<CERR);//must be read-modify-write
}

uint8_t canReadFormErrorFlag(void)
{
	uint8_t ubRetVal = CANSTMOB;
	ubRetVal &= (1<<FERR);
	ubRetVal = ubRetVal>>FERR;
	return ubRetVal;
}

void canCleanFormErrorFlag(void)
{
	CANSTMOB |= (1<<FERR);//must be read-modify-write
}

uint8_t canReadAcknowledgementErrorFlag(void)
{
	uint8_t ubRetVal = CANSTMOB;
	ubRetVal &= (1<<AERR);
	ubRetVal = ubRetVal>>AERR;
	return ubRetVal;
}

void canCleanAcknowledgementErrorFlag(void)
{
	CANSTMOB |= (1<<AERR);//must be read-modify-write
}

/************************************************/
/*   CAN MOb Control and DLC register CANCDMOB  */
/************************************************/

void canWriteConfigurationOfMessageObject(uint8_t ubData)
{
	assert(ubData < 4);
	CANCDMOB &= ~( (1<<CONMOB1) | (1<<CONMOB0) );//Remove current info
	CANCDMOB |= (ubData<<CONMOB0);
}

uint8_t canReadWriteConfigurationOfMessageObject(void)
{
	uint8_t ubRetVal = CANCDMOB;
	ubRetVal &= (1<<CONMOB1) | (1<<CONMOB0);
	ubRetVal = ubRetVal>>CONMOB0;
	return ubRetVal;
}

void canSetReplyReadyAndValid(void)
{
	CANCDMOB |= (1<<RPLV);
}

void canSetReplyNotReady(void)
{
	CANCDMOB &= ~(1<<RPLV);
}

uint8_t canReadReplyValidBit(void)
{
	uint8_t ubRetVal = CANCDMOB;
	ubRetVal &= (1<<RPLV);
	ubRetVal = ubRetVal>>RPLV;
	return ubRetVal;
}

void canSetIdentifierExtention2A(void)
{
	CANCDMOB &= ~(1<<IDE);
}

void canSetIdentifierExtention2B(void)
{
	CANCDMOB |= (1<<IDE);
}

uint8_t canReadIdentifierExtention(void)
{
	uint8_t ubRetVal = CANCDMOB;
	ubRetVal &= (1<<IDE);
	ubRetVal = ubRetVal>>IDE;
	return ubRetVal;
}

void canWriteDataLengthCode(uint8_t ubData)
{
	assert(ubData < 9);
	CANCDMOB &= ~( (1<<DLC3) | (1<<DLC2) | (1<<DLC1) | (1<<DLC0) );//Remove current info
	//CANCDMOB |= (ubData<<DLC0);
	CANCDMOB |= ubData;
}

uint8_t canReadDataLengthCode(void)
{
	uint8_t ubRetVal = CANCDMOB;
	ubRetVal &= (1<<DLC3) | (1<<DLC2) | (1<<DLC1) | (1<<DLC0);
	ubRetVal = ubRetVal>>DLC0;
	return ubRetVal;
}

/************************************************/
/*      CAN Identifier Tag Register CANIDTx     */
/************************************************/

void canWriteIdentifierTagV2A(uint16_t uwData)
{
	CANIDT1 = (uint8_t)(uwData>>3);
	CANIDT2 = (uint8_t)(uwData<<5);
}

uint16_t canReadIdentifierTagV2A(void)
{
	uint16_t uwRetVal = CANIDT1;//Read High byte
	uwRetVal = uwRetVal<<3;//Allign high byte
	uwRetVal += (CANIDT2>>5);//Add low byte
	return uwRetVal;
}

void canWriteIdentifierTagV2B(uint32_t ulData)
{
	CANIDT1 = (uint8_t)(ulData>>21);
	CANIDT2 = (uint8_t)(ulData>>13);
	CANIDT3 = (uint8_t)(ulData>>5);
	CANIDT4 &= ~( (1<<IDT4) | (1<<IDT3) | (1<<IDT2) | (1<<IDT1) | (1<<IDT0) );
	CANIDT4 |= (uint8_t)(ulData<<3);
}

uint32_t canReadIdentifierTagV2B(void)
{
	uint32_t ulRetVal = ((uint32_t)CANIDT1<<21);
	ulRetVal |= ( ((uint32_t) CANIDT2) << 13 );
	ulRetVal |= ( ((uint32_t) CANIDT3) << 5 );
	ulRetVal |= (uint32_t)(CANIDT4 >> 3);
	//ulRetVal |= (uint32_t)(CANIDT2<<13);
	//ulRetVal |= (uint32_t)(CANIDT3<<5);
	//ulRetVal |= (uint32_t)(CANIDT4>>3);
	return ulRetVal;
}

void canWriteRemoteTransmissionRequestTag(uint8_t ubData)
{
	assert(ubData < 2);
	CANIDT4 &= ~(1<<RTRTAG);//Remove current info
	CANIDT4 |= (ubData<<RTRTAG);
}

uint8_t canReadRemoteTransmissionRequestTag(void)
{
	uint8_t ubRetVal = CANIDT4;
	ubRetVal &= (1<<RTRTAG);
	ubRetVal = ubRetVal>>RTRTAG;
	return ubRetVal;
}

void canWriteReservedBit0Tag(uint8_t ubData)
{
	assert(ubData < 2);
	CANIDT4 &= ~(1<<RB0TAG);//Remove current info
	CANIDT4 |= (ubData<<RB0TAG);
}

uint8_t canReadReservedBit0Tag(void)
{
	uint8_t ubRetVal = CANIDT4;
	ubRetVal &= (1<<RB0TAG);
	ubRetVal = ubRetVal>>RB0TAG;
	return ubRetVal;
}

void canWriteReservedBit1Tag(uint8_t ubData)
{
	assert(ubData < 2);
	CANIDT4 &= ~(1<<RB1TAG);//Remove current info
	CANIDT4 |= (ubData<<RB1TAG);
}

uint8_t canReadReservedBit1Tag(void)
{
	uint8_t ubRetVal = CANIDT4;
	ubRetVal &= (1<<RB1TAG);
	ubRetVal = ubRetVal>>RB1TAG;
	return ubRetVal;
}

/************************************************/
/*  CAN Identifier Mask Tag Register CANIDMx    */
/************************************************/

void canWriteIdentifierMaskV2A(uint16_t uwData)
{
	CANIDM1 = (uint8_t)(uwData>>3);
	CANIDM2 = (uint8_t)(uwData<<5);
}

uint16_t canReadIdentifierMaskV2A(void)
{
	uint16_t uwRetVal = CANIDM1;//Read High byte
	uwRetVal = uwRetVal<<3;//Allign high byte
	uwRetVal += (CANIDM2>>5);//Add low byte
	return uwRetVal;
}

void canWriteIdentifierMaskV2B(uint32_t ulData)
{
	CANIDM1 = (uint8_t)(ulData>>21);
	CANIDM2 = (uint8_t)(ulData>>13);
	CANIDM3 = (uint8_t)(ulData>>5);
	CANIDM4 &= ~( (1<<IDMSK4) | (1<<IDMSK3) | (1<<IDMSK2) | (1<<IDMSK1) | (1
			<<IDMSK0) );
	CANIDM4 |= (uint8_t)(ulData<<3);
}

uint32_t canReadIdentifierMaskV2B(void)
{
	uint32_t ulRetVal = ((uint32_t)CANIDM1<<21);
	ulRetVal |= (uint32_t)(CANIDM2<<13);
	ulRetVal |= (uint32_t)(CANIDM3<<5);
	ulRetVal |= (uint32_t)(CANIDM4>>3);
	return ulRetVal;
}

void canWriteRemoteTransmissionRequestMask(uint8_t ubData)
{
	assert(ubData < 2);
	CANIDM4 &= ~(1<<RTRMSK);//Remove current info
	CANIDM4 |= (ubData<<RTRMSK);
}

uint8_t canReadRemoteTransmissionRequestMask(void)
{
	uint8_t ubRetVal = CANIDM4;
	ubRetVal &= (1<<RTRMSK);
	ubRetVal = ubRetVal>>RTRMSK;
	return ubRetVal;
}

void canWriteIdentifierExtensionMask(uint8_t ubData)
{
	assert(ubData < 2);
	CANIDM4 &= ~(1<<IDEMSK);//Remove current info
	CANIDM4 |= (ubData<<IDEMSK);
}

uint8_t canReadIdentifierExtensionMask(void)
{
	uint8_t ubRetVal = CANIDM4;
	ubRetVal &= (1<<IDEMSK);
	ubRetVal = ubRetVal>>IDEMSK;
	return ubRetVal;
}

/************************************************/
/*       CAN Time Stamp Registers CANSTMx       */
/************************************************/

uint16_t canReadTimeStamp(void)
{
	uint16_t uwRetVal = CANSTMH;//Read High byte
	uwRetVal = uwRetVal<<8;//Allign high byte
	uwRetVal += CANSTML;//Add low byte
	return uwRetVal;
}

/***************************************************************************************
 * Données de Message Object (Mob)
 ***************************************************************************************/

uint8_t canReadDataMessageObject(void)
{
	return CANMSG;
}

void canWriteDataMessageObject(uint8_t ubData)
{
	CANMSG = ubData;
}

void canClearMOb(void)
{
	void *ptr;
	for (ptr=(void*)&CANSTMOB; ptr < (void*)&CANSTML; ptr++)
	{
		*(uint8_t*)ptr=0x00;
	}
}

void canClearAllMOb(void)
{
	uint8_t i;
	for (i = 0; i < 15; i++)
	{
		canWriteMObNumber(i);
		canClearMOb();
	}
}

uint8_t canGetFreeMObNumber(uint8_t *ubFreeMOb)
{
	uint8_t ubCurrentMOb;
	uint8_t ubRetVal= FALSE;

	ubCurrentMOb = CANPAGE;//Save current value
	for (*ubFreeMOb = 0; *ubFreeMOb < 15; (*ubFreeMOb)++)
	{
		canWriteMObNumber(*ubFreeMOb);
		if ((CANCDMOB & 0xC0) == 0x00) //! Disable configuration
		{
			ubRetVal = TRUE;
			break;
		}
	}
	CANPAGE = ubCurrentMOb;
	return ubRetVal;
}

uint8_t canSetBaudRate(uint32_t ulBaudrate, uint8_t ubSamplingRate,
		uint8_t ubTsjw)
{
	uint8_t ubDivider;
	uint8_t ubTbit;
	uint8_t ubTprs;
	uint8_t ubTphs1;
	uint8_t ubTphs2;
	uint8_t ubBRP = 0;

	//TODO remove F_CPU
	ubDivider = F_CPU / ulBaudrate; /* Trouve le diviseur total de la frï¿½quence du Can */

	ubTbit = ubDivider;
	while ( (ubTbit > CAN_MAXTQ) | (ubTbit < CAN_MINTQ))
	{
		ubTbit = (ubTbit >> 2);
		ubBRP++;
	}

	ubTphs2 = (ubTbit * (100 - ubSamplingRate) / 100);

	if (0 == ubBRP)
	{
		ubTphs1 = ubTphs2 + 1;
	}
	else
	{
		ubTphs1 = ubTphs2;
	}

	ubTprs = ubTbit - ubTphs1 - ubTphs2 - 1;

	CANBT1 = (ubBRP << BRP0);
	CANBT2 = (ubTprs << PRS0) | (ubTsjw << SJW0);
	CANBT3 = (ubTphs2 << PHS20) | (ubTphs1 << PHS10) | (1 << SMP);

	if (ubDivider == (ubBRP + 1) * (ubTprs + ubTphs1 + ubTphs2 + 1))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

canIntSrc_t canGetIntSrc(void)
{
	if (bit_is_set(CANGIE, ENIT) )//Interrupt are enabled
	{
		uint16_t canie;
		//uint16_t cansit;
		uint8_t i;

		canie = ((uint16_t)CANIE1)<<8;
		canie |= (uint16_t)CANIE2;

		//cansit = CANSIT;

		canie &= CANSIT;

		if (canie != 0)
		{
			//Seek interrupt source
			for (i = 0; i < 15; i++)
			{
				if (canie & (1<<i))
					break;
			}

			canWriteMObNumber(i); // Select MOb

			if (bit_is_set(CANGIE, ENRX) && bit_is_set(CANSTMOB, RXOK))
			{
				return 0x10*i + intSrc_RXOK_00;
			}

			if (bit_is_set(CANGIE, ENTX) && bit_is_set(CANSTMOB, TXOK))
			{
				return 0x10*i + intSrc_TXOK_00;
			}

			if (bit_is_set(CANGIE, ENERR) && bit_is_set(CANSTMOB, AERR))
			{
				return 0x10*i + intSrc_AERR_00;
			}

			if (bit_is_set(CANGIE, ENERR) && bit_is_set(CANSTMOB, FERR))
			{
				return 0x10*i + intSrc_FERR_00;
			}

			if (bit_is_set(CANGIE, ENERR) && bit_is_set(CANSTMOB, CERR))
			{
				return 0x10*i + intSrc_CERR_00;
			}

			if (bit_is_set(CANGIE, ENERR) && bit_is_set(CANSTMOB, SERR))
			{
				return 0x10*i + intSrc_SERR_00;
			}

			if (bit_is_set(CANGIE, ENERR) && bit_is_set(CANSTMOB, BERR))
			{
				return 0x10*i + intSrc_BERR_00;
			}
		}

		//Bus off interrupt enabled
		if (bit_is_set(CANGIE, ENBOFF) && bit_is_set(CANGIT, BOFFIT))
		{
			return intSrc_BOFFI;
		}

		//Stuff error General
		if (bit_is_set(CANGIE, ENERG) && bit_is_set(CANGIT, SERG))
		{
			return intSrc_SERG;
		}

		//CAN error General
		if (bit_is_set(CANGIE, ENERG) && bit_is_set(CANGIT, CERG))
		{
			return intSrc_CERG;
		}

		//Frame error General
		if (bit_is_set(CANGIE, ENERG) && bit_is_set(CANGIT, FERG))
		{
			return intSrc_FERG;
		}

		//Ack error General
		if (bit_is_set(CANGIE, ENERG) && bit_is_set(CANGIT, AERG))
		{
			return intSrc_AERG;
		}

		//Frame Buffer Receive Interrupt
		if (bit_is_set(CANGIE, ENBX) && bit_is_set(CANGIT, BXOK))
		{
			return intSrc_BXOK;
		}

	}

	return intSrc_UNKNOWN;
}
