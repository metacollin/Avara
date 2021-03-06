/*
    Copyright �1995-1996, Juri Munkki
    All rights reserved.

    File: CCommChannel.h
    Created: Monday, February 27, 1995, 23:14
    Modified: Thursday, January 25, 1996, 7:37
*/

#pragma once
#include "CAbstractCommClient.h"
#include "PPCStuff.h"

/*
**	Abstract class that provides queued and
**	asynchronous PPCToolbox communication. It
**	is used by both the clients and CPPCConnection
**	objects.
*/
class	CCommChannel : public CAbstractCommClient
{
public:
			Boolean			isClosing;		//	Accessed publicly
			long			sessionRef;
			long			writeCount;
			long			writtenCount;

			ReadEnvelope	readE;
			PacketInfo		*readPack;
			
			WriteEnvelope	writeE;
			PacketInfo		*writePack;
			QHdr			outQ;
			Boolean			writeActive;

	virtual	void			ICommChannel(short packetSpace);
	virtual	void			FlushOutQueue();
	virtual	void			Dispose();

	virtual	void			AsyncRead();
	virtual	void			ReadComplete();
	virtual	void			ReadErr();
	
	virtual	void			AsyncWrite();
	virtual	void			WriteComplete();
	virtual	void			WritePacket(PacketInfo *thePacket);
	virtual	void			WriteErr();
	
	virtual	short			GetKillReceivers();
};