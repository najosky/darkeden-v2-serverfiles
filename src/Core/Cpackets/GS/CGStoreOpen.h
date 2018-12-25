//////////////////////////////////////////////////////////////////////
// 
// Filename    : CGStoreOpen.h 
// Written By  :
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __CG_STORE_OPEN_H__
#define __CG_STORE_OPEN_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class CGStoreOpen;
//
//////////////////////////////////////////////////////////////////////

class CGStoreOpen : public Packet
{
public:
	
    // 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
    void write(SocketOutputStream & oStream) ;

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID()  { return PACKET_CG_STORE_OPEN; }
	
	// get packet's body size
	PacketSize_t getPacketSize()  { return 0; }

	// get packet name
	string getPacketName()  { return "CGStoreOpen"; }

	// get packet's debug string
	string toString() ;

};


//////////////////////////////////////////////////////////////////////
//
// class CGStoreOpenFactory;
//
// Factory for CGStoreOpen
//
//////////////////////////////////////////////////////////////////////

class CGStoreOpenFactory : public PacketFactory {

public:
	
	// constructor
	CGStoreOpenFactory() throw() {}
	
	// destructor
	virtual ~CGStoreOpenFactory() throw() {}

	
public:
	
	// create packet
	Packet* createPacket() throw() { return new CGStoreOpen(); }

	// get packet name
	string getPacketName()  { return "CGStoreOpen"; }
	
	// get packet id
	PacketID_t getPacketID()  { return Packet::PACKET_CG_STORE_OPEN; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize()  { return 0; }
};


//////////////////////////////////////////////////////////////////////
//
// class CGStoreOpenHandler;
//
//////////////////////////////////////////////////////////////////////

class CGStoreOpenHandler {

public:

	// execute packet's handler
	static void execute(CGStoreOpen* pCGStoreOpen, Player* pPlayer) throw(Error);

};

#endif
