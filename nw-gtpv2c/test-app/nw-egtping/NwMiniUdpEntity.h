/*----------------------------------------------------------------------------*
 *                                                                            *
 *            M I N I M A L I S T I C     U D P     E N T I T Y               *
 *                                                                            *
 *                    Copyright (C) 2010 Amit Chawre.                         *
 *                                                                            *
 *----------------------------------------------------------------------------*/


/**
 * @file NwMiniUdpEntity.c
 * @brief This file contains example of a minimalistic ULP entity.
*/

#include <stdio.h>
#include <assert.h>
#include "NwEvt.h"
#include "NwLog.h"

#ifndef NW_ASSERT
#define NW_ASSERT assert
#endif

#ifndef __NW_MINI_UDP_ENTITY_H__
#define __NW_MINI_UDP_ENTITY_H__

typedef struct
{
  NwU32T                        ipv4Addr;
  NwU32T                        hSocket;
  NwEventT                      ev;
  NwGtpv2cStackHandleT          hGtpv2cStack;
  NwU32T                        packetsSent;
  NwU32T                        packetsRcvd;
} NwGtpv2cNodeUdpT;

#ifdef __cplusplus
extern "C" {
#endif

NwGtpv2cRcT nwGtpv2cUdpInit(NwGtpv2cNodeUdpT* thiz, NwGtpv2cStackHandleT hGtpv2cStack, NwU8T* ipAddrStr);

NwGtpv2cRcT nwGtpv2cUdpDestroy(NwGtpv2cNodeUdpT* thiz);

NwGtpv2cRcT nwGtpv2cUdpDataReq(NwGtpv2cUdpHandleT udpHandle,
    NwU8T* dataBuf,
    NwU32T dataSize,
    NwU32T peerIp,
    NwU32T peerPort);

NwGtpv2cRcT nwGtpv2cUdpReset(NwGtpv2cNodeUdpT* thiz);

#ifdef __cplusplus
}
#endif

#endif
