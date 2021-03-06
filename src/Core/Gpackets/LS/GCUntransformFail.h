//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCUntransformFail.h 
// Written By  : crazydog
// Description :
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GC_UNTRANSFORM_FAIL_H__
#define __GC_UNTRANSFORM_FAIL_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class GCUntransformFail;
//
//////////////////////////////////////////////////////////////////////

class GCUntransformFail : public Packet {

public :

	// constructor
	GCUntransformFail()  {}
	

public :

    // 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
    void read(SocketInputStream & iStream) ;
		    
    // 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
    void write(SocketOutputStream & oStream) ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID()  { return PACKET_GC_UNTRANSFORM_FAIL; }
	
	// get packet's body size
	PacketSize_t getPacketSize()  { return 0; }
	
	// get packet's name
	string getPacketName()  { return "GCUntransformFail"; }
	
	// get packet's debug string
	string toString() ;
	

public :


private : 


};


//////////////////////////////////////////////////////////////////////
//
// class  GCUntransformFailFactory;
//
// Factory for  GCUntransformFail
//
//////////////////////////////////////////////////////////////////////

class  GCUntransformFailFactory : public PacketFactory {

public :
	
	// create packet
	Packet* createPacket()  { return new GCUntransformFail(); }

	// get packet name
	string getPacketName()  { return "GCUntransformFail"; }
	
	// get packet id
	PacketID_t getPacketID()  { return Packet::PACKET_GC_UNTRANSFORM_FAIL; }

	// get packet's max body size
	PacketSize_t getPacketMaxSize()  { return 0; }
	
};


//////////////////////////////////////////////////////////////////////
//
// class  GCUntransformFailHandler;
//
//////////////////////////////////////////////////////////////////////

class  GCUntransformFailHandler {

public :

	// execute packet's handler
	static void execute(GCUntransformFail* pPacket, Player* pPlayer);

};

#endif
