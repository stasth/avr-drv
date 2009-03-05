/*! \file can.h
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

#ifndef CAN_H_
#define CAN_H_

#include <stdint.h>


typedef enum canIntSrc_e//Interrupt source
{
	intSrc_AERR_00 = 0x00,
	intSrc_FERR_00,
	intSrc_CERR_00,
	intSrc_SERR_00,
	intSrc_BERR_00,
	intSrc_RXOK_00,
	intSrc_TXOK_00,
	intSrc_AERR_01 = 0x10,
	intSrc_FERR_01,
	intSrc_CERR_01,
	intSrc_SERR_01,
	intSrc_BERR_01,
	intSrc_RXOK_01,
	intSrc_TXOK_01,
	intSrc_AERR_02 = 0x20,
	intSrc_FERR_02,
	intSrc_CERR_02,
	intSrc_SERR_02,
	intSrc_BERR_02,
	intSrc_RXOK_02,
	intSrc_TXOK_02,
	intSrc_AERR_03 = 0x30,
	intSrc_FERR_03,
	intSrc_CERR_03,
	intSrc_SERR_03,
	intSrc_BERR_03,
	intSrc_RXOK_03,
	intSrc_TXOK_03,
	intSrc_AERR_04 = 0x40,
	intSrc_FERR_04,
	intSrc_CERR_04,
	intSrc_SERR_04,
	intSrc_BERR_04,
	intSrc_RXOK_04,
	intSrc_TXOK_04,
	intSrc_AERR_05 = 0x50,
	intSrc_FERR_05,
	intSrc_CERR_05,
	intSrc_SERR_05,
	intSrc_BERR_05,
	intSrc_RXOK_05,
	intSrc_TXOK_05,
	intSrc_AERR_06 = 0x60,
	intSrc_FERR_06,
	intSrc_CERR_06,
	intSrc_SERR_06,
	intSrc_BERR_06,
	intSrc_RXOK_06,
	intSrc_TXOK_06,
	intSrc_AERR_07 = 0x70,
	intSrc_FERR_07,
	intSrc_CERR_07,
	intSrc_SERR_07,
	intSrc_BERR_07,
	intSrc_RXOK_07,
	intSrc_TXOK_07,
	intSrc_AERR_08 = 0x80,
	intSrc_FERR_08,
	intSrc_CERR_08,
	intSrc_SERR_08,
	intSrc_BERR_08,
	intSrc_RXOK_08,
	intSrc_TXOK_08,
	intSrc_AERR_09 = 0x90,
	intSrc_FERR_09,
	intSrc_CERR_09,
	intSrc_SERR_09,
	intSrc_BERR_09,
	intSrc_RXOK_09,
	intSrc_TXOK_09,
	intSrc_AERR_10 = 0xA0,
	intSrc_FERR_10,
	intSrc_CERR_10,
	intSrc_SERR_10,
	intSrc_BERR_10,
	intSrc_RXOK_10,
	intSrc_TXOK_10,
	intSrc_AERR_11 = 0xB0,
	intSrc_FERR_11,
	intSrc_CERR_11,
	intSrc_SERR_11,
	intSrc_BERR_11,
	intSrc_RXOK_11,
	intSrc_TXOK_11,
	intSrc_AERR_12 = 0xC0,
	intSrc_FERR_12,
	intSrc_CERR_12,
	intSrc_SERR_12,
	intSrc_BERR_12,
	intSrc_RXOK_12,
	intSrc_TXOK_12,
	intSrc_AERR_13 = 0xD0,
	intSrc_FERR_13,
	intSrc_CERR_13,
	intSrc_SERR_13,
	intSrc_BERR_13,
	intSrc_RXOK_13,
	intSrc_TXOK_13,
	intSrc_AERR_14 = 0xE0,
	intSrc_FERR_14,
	intSrc_CERR_14,
	intSrc_SERR_14,
	intSrc_BERR_14,
	intSrc_RXOK_14,
	intSrc_TXOK_14,
	intSrc_BOFFI = 0xF0,
	intSrc_AERG,
	intSrc_FERG,
	intSrc_CERG,
	intSrc_SERG,
	intSrc_BXOK,
	intSrc_UNKNOWN = 0xFF,
} canIntSrc_t;

/*! \fn void canSetAbortAbort(void)
 *  \brief Force all message boxes to be desactivated.
 *
 * All communication currently ongoing will terminate normally.
 *
 * Flags will not be reset.
 */
void canSetAbortAbort(void);

/*! \fn void canClearAbortAbort(void)
 *  \brief After an #canSetAbortAbort(), this command will reactivate
 *  message boxes.
 */
void canClearAbortAbort(void);

/*! \fn void canSetOverloadFrameRequest(void)
 *  \brief Force la transmission d'un message de surcharge immï¿½diatement
 * aprï¿½s la prochaine reception.
 *
 * Le fanions ne se remet pas ï¿½ zï¿½ro de lui mï¿½me.
 * Pas plus de deux message de surcharge successif ne devrait ï¿½tre transmis successivement.
 */
void canSetOverloadFrameRequest(void);

/*! \fn void canClearOverloadFrameRequest(void)
 *  \brief Si une demande d'envois de message de surcharge fut placï¿½ plustï¿½t,
 * cette fonction permet ne plus transmettre de tel message.
 */
void canClearOverloadFrameRequest(void);

/*! \fn void canEnableTimeTriggerCommunication(void)
 *  \brief Active la communication basï¿½ sur le temps et non pas les ï¿½vï¿½nements.
 */
void canEnableTimeTriggerCommunication(void);

/*! \fn void canDisableTimeTriggerCommunication(void)
 *  \brief Dï¿½sctive la communication basï¿½e sur le temps et
 * active donc la celle basï¿½e sur les ï¿½vï¿½nements.
 */
void canDisableTimeTriggerCommunication(void);

/*! \fn void canTTCSyncOnLastBitOfEOF(void)
 *  \brief Force la synchronisation de TTC lors du dernier bit de EOF.
 * End Of Frame
 *
 * Seulement utilisï¿½ lorsqu'en mode TTC
 */
void canTTCSyncOnLastBitOfEOF(void);

/*! \fn void canTTCSyncOnSOF(void)
 *  \brief Force la synchronisation de TTC lors de SOF.
 * Start Of Frame
 *
 * Seulement utilisï¿½ lorsqu'en mode TTC
 */
void canTTCSyncOnSOF(void);

/*! \fn void canEnableListeningMode(void)
 *  \brief Active le mode d'ï¿½coute. Tx est connectï¿½ vers l'extï¿½rieure ainsi que
 * sur Rx.
 */
void canEnableListeningMode(void);

/*! \fn void canDisableListeningMode(void)
 *  \brief Dï¿½sactive le mode d'ï¿½coute. Rx est connectï¿½ vers l'extï¿½rieure.
 */
void canDisableListeningMode(void);

/*! \fn void canSetEnableMode(void)
 *  \brief Le Module can sera activï¿½ suite ï¿½ la lecture de 11bit.
 *
 * Puisque l'effet de ce fanion n'est pas immï¿½diat, il vaut mieux lire le bit
 * ENFG du registre CANGSTA afin de connaitre le mode prï¿½sent d'opï¿½ration.
 */
void canSetEnableMode(void);

/*! \fn void canSetStandbyMode(void)
 *  \brief La communication en cours se terminera comme prï¿½vue et le cannal CAN
 * sera suspendu(le bit CONMOB de chaque MOb ne changera pas).  Le transmetteur
 * permet donc la reception de donnï¿½s.  Les registres de reception sont disponible
 * pour le CPU.
 *
 * Puisque l'effet de ce fanion n'est pas immï¿½diat, il vaut mieux lire le bit
 * ENFG du registre CANGSTA afin de connaitre le mode prï¿½sent d'opï¿½ration.
 */
void canSetStandbyMode(void);

/*! \fn void canRequestReset(void)
 *  \brief Permet au module CAN de faire une remise ï¿½ zï¿½ro du processeur.
 */
void canRequestReset(void);

/*! \fn uint8_t canReadOverloadFrameFlag(void)
 *  \brief Lit le fanion OVFG
 *  \return 0 Si aucune trame de surcharge est n'envoyï¿½.
 *          1 Si une trame de surcharge est en cour de transmission.
 */
uint8_t canReadOverloadFrameFlag(void);

/*! \fn uint8_t canIsTransmitterBusy(void)
 *  \brief Lit le fanion TXBSY
 *  \return 0 Si le transmetteur est inactif.
 *          1 Si le transmetteur est occupï¿½.
 */
uint8_t canIsTransmitterBusy(void);

/*! \fn uint8_t canIsReceiverBusy(void)
 *  \brief Lit le fanion RXBSY
 *  \return 0 Si le rï¿½cepteur est inactif.
 *          1 Si le rï¿½cepteur est occupï¿½.
 */
uint8_t canIsReceiverBusy(void);

/*! \fn uint8_t canIsEnable(void)
 *  \brief Lit le fanion ENFG.
 *  \return 0 Si le controleur est inactif.
 *          1 Si le controleur est actif.
 */
uint8_t canIsEnable(void);

/*! \fn uint8_t canIsBusOff(void)
 *  \brief Lit le fanion BOFF.
 *  \return 0 Si le bus n'est pas en mode Off.
 *          1 Si le bus est en mode Off.
 */
uint8_t canIsBusOff(void);

/*! \fn uint8_t canIsErrorPassive(void)
 *  \brief Lit le fanion ERRP.
 *  \return 0 Si le bus n'est pas en mode "Error passive".
 *          1 Si le bus est en mode "Error passive".
 */
uint8_t canIsErrorPassive(void);

/*! \fn uint8_t canIsInterrupt(void)
 *  \brief Indique si un fanion d'intï¿½ruption est actif.
 *  \return 0 Si aucune intï¿½ruption n'est en attente.
 *          1 Si une intï¿½ruption est en attente.
 */
uint8_t canIsInterrupt(void);

uint8_t canReadBusOffInterruptFlag(void);
void canClearBusOffInterruptFlag(void);
uint8_t canReadOverrunCANTimerInterruptFlag(void);
void canClearOverrunCANTimerInterruptFlag(void);

uint8_t canReadFrameBufferReveiveInterruptFlag(void);

/*! \fn void canClearFrameBufferReveiveInterruptFlag(void)
 *  \brief Remet ï¿½ zï¿½ro le fanion de rï¿½ception.
 *
 * Peut seulement ï¿½tre remit ï¿½ zï¿½ro si les deux fnion CONMOB de MOb on ï¿½tï¿½ rï¿½ï¿½crit.
 */
void canClearFrameBufferReveiveInterruptFlag(void);

uint8_t canReadStuffErrorGeneralInterruptFlag(void);
void canClearStuffErrorGeneralInterruptFlag(void);

uint8_t canReadCRCErrorGeneralInterruptFlag(void);

void canClearCRCErrorGeneralInterruptFlag(void);
uint8_t canReadFormErrorGeneralInterruptFlag(void);

void canClearFormErrorGeneralInterruptFlag(void);
uint8_t canReadAckErrorGeneralInterruptFlag(void);
void canClearAckErrorGeneralInterruptFlag(void);

void canEnableAllInterrupt(void);
void canDisableAllInterrupt(void);
void canEnableBusOffInterrupt(void);
void canDisableBusOffInterrupt(void);
void canEnableReceiveInterrupt(void);
void canDisableReceiveInterrupt(void);
uint8_t canIsReceiveInterruptActive(void);
void canEnableTransmitInterrupt(void);
void canDisableTransmitInterrupt(void);
uint8_t canIsTransmitInterruptActive(void);
void canEnableMObErrorsInterrupt(void);
void canDisableMObErrorsInterrupt(void);
void canEnableFrameBufferInterrupt(void);
void canDisableFrameBufferInterrupt(void);
void canEnableGeneralErrorsInterrupt(void);
void canDisableGeneralErrorsInterrupt(void);
void canEnableCANTimerOverrunInterrupt(void);
void canDisableCANTimerOverrunInterrupt(void);

uint8_t canIsMObEnabled(uint8_t uwMOb);

void canEnableInterruptMOb(uint8_t uwMOb);
void canDisableInterruptMOb(uint8_t uwMOb);

uint8_t canReadStatusInterruptMOb(uint8_t uwMOb);

void canWriteBitTimingRegister1(uint8_t uwData);
uint8_t canReadBitTimingRegister1(void);

void canWriteReSyncJumpWidth(uint8_t ubData);
uint8_t canReadReSyncJumpWidth(void);
void canWritePropagationTimeSegment(uint8_t ubData);
uint8_t canReadPropagationTimeSegment(void);

void canWritePhaseSegment2(uint8_t ubData);
uint8_t canReadPhaseSegment2(void);
void canWritePhaseSegment1(uint8_t ubData);
uint8_t canReadPhaseSegment1(void);
void canWriteSamplePoint(uint8_t ubData);
uint8_t canReadSamplePoint(void);

void canWriteTimerControlRegister(uint8_t ubData);
uint8_t canReadTimerControlRegister(void);

uint16_t canReadTimerRegister(void);

uint16_t canReadTTCTimerRegister(void);

uint8_t canReadTransmitErrorCounter(void);
uint8_t canReadReceiveErrorCounter(void);

uint8_t canReadHighestPriorityMObNumber(void);
void canWriteGeneralPurposeBits(uint8_t ubData);
uint8_t canReadGeneralPurposeBits(void);

void canWriteMObNumber(uint8_t ubData);
uint8_t canReadMObNumber(void);
void canWriteAutoIncrement(uint8_t ubData);
uint8_t canReadAutoIncrement(void);
void canWriteFIFOCANDataIndex(uint8_t ubData);
uint8_t canReadFIFOCANDataIndex(void);

void canWriteDataLengthCodeWarning(uint8_t ubData);
uint8_t canReadDataLengthCodeWarning(void);
uint8_t canReadTransmitOKFlag(void);
void canCleanTransmitOKFlag(void);
uint8_t canReadReceiveOKFlag(void);
void canCleanReceiveOKFlag(void);
uint8_t canReadBitErrorFlag(void);
void canCleanBitErrorFlag(void);
uint8_t canReadStuffErrorFlag(void);
void canCleanStuffErrorFlag(void);
uint8_t canReadCRCErrorFlag(void);
void canCleanCRCErrorFlag(void);
uint8_t canReadFormErrorFlag(void);
void canCleanFormErrorFlag(void);
uint8_t canReadAcknowledgementErrorFlag(void);
void canCleanAcknowledgementErrorFlag(void);

void canWriteConfigurationOfMessageObject(uint8_t ubData);
uint8_t canReadWriteConfigurationOfMessageObject(void);
void canSetReplyReadyAndValid(void);
void canSetReplyNotReady(void);
uint8_t canReadReplyValidBit(void);
void canSetIdentifierExtention2A(void);
void canSetIdentifierExtention2B(void);
uint8_t canReadIdentifierExtention(void);
void canWriteDataLengthCode(uint8_t ubData);
uint8_t canReadDataLengthCode(void);

void canWriteIdentifierTagV2A(uint16_t uwData);
uint16_t canReadIdentifierTagV2A(void);
void canWriteIdentifierTagV2B(uint32_t ulData);
uint32_t canReadIdentifierTagV2B(void);
void canWriteRemoteTransmissionRequestTag(uint8_t ubData);
uint8_t canReadRemoteTransmissionRequestTag(void);
void canWriteReservedBit0Tag(uint8_t ubData);
uint8_t canReadReservedBit0Tag(void);
void canWriteReservedBit1Tag(uint8_t ubData);
uint8_t canReadReservedBit1Tag(void);

void canWriteIdentifierMaskV2A(uint16_t uwData);
uint16_t canReadIdentifierMaskV2A(void);
void canWriteIdentifierMaskV2B(uint32_t ulData);
uint32_t canReadIdentifierMaskV2B(void);
void canWriteRemoteTransmissionRequestMask(uint8_t ubData);
uint8_t canReadRemoteTransmissionRequestMask(void);
void canWriteIdentifierExtensionMask(uint8_t ubData);
uint8_t canReadIdentifierExtensionMask(void);

uint16_t canReadTimeStamp(void);

/***************************************************************************************
 * Donnï¿½es de Message Object (Mob)
 ***************************************************************************************/

/*! \fn uint8_t canReadDataMessageObject(void)
 *  \brief Avoir 1 octet dans le FIFO de MOb ACTUELLEMENT pointï¿½ par AT90CANXX (1 des 15
 * MOb disponibles). Index du FIFO incrï¿½mente automatiquement (supposant que
 * AINC = 0 dans le registre CANPAGE).
 *
 */
uint8_t canReadDataMessageObject(void);

/*! \fn uint8_t canWriteDataMessageObject(void)
 *  \brief Mettre 1 octet dans le FIFO de MOb ACTUELLEMENT pointï¿½ par AT90CANXX (1 des 15
 * MOb disponibles). Index du FIFO incrï¿½mente automatiquement (supposant que
 * AINC = 0 dans le registre CANPAGE).
 *
 */
void canWriteDataMessageObject(uint8_t ubData);

/*! \fn void canClearMOb(void)
 *  \brief Effacer les donnï¿½es du MOb ACTUELLEMENT pointï¿½ par AT90CANXX.
 *
 */
void canClearMOb(void);

/*! \fn void canClearAllMOb(void)
 *  \brief Effacer les donnï¿½es de TOUS les MObs.
 *
 */
void canClearAllMOb(void);
uint8_t canGetFreeMObNumber(uint8_t *ubFreeMOb);

/***************************************************************************************
 * Vitesse de CAN Bus
 ***************************************************************************************/
uint8_t canSetBaudRate(uint32_t ulBaudrate, uint8_t ubSamplingRate,
		uint8_t ubTsjw);

canIntSrc_t canGetIntSrc(void);

#endif /*CAN_H_*/
