//////////////////////////////////////////////////////////////////////
// 
// Filename    : CGReady.h 
// Written By  : Reiot
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __CG_LOADING_GEAR_READY_H__
#define __CG_LOADING_GEAR_READY_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class CGReady;
//
//////////////////////////////////////////////////////////////////////

class CGLoadingGearReady : public Packet {

public:

    // 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_CG_LOADING_GEAR_READY; }
	
	// get packet body size
	// *OPTIMIZATION HINT*
	// const static CGLoadingGearReadyPacketSize 를 정의, 리턴하라.
	PacketSize_t getPacketSize() const throw() { return 0; }
	
	// get packet's name
	string getPacketName() const throw() { return "CGLoadingGearReady"; }
	
	// get packet's debug string
	string toString() const throw() { return "CGLoadingGearReady"; }
	
};


//////////////////////////////////////////////////////////////////////
//
// class CGLoadingGearReadyFactory;
//
// Factory for CGLoadingGearReady
//
//////////////////////////////////////////////////////////////////////

class CGLoadingGearReadyFactory : public PacketFactory {

public:
	
	// create packet
	Packet* createPacket() throw() { return new CGLoadingGearReady(); }

	// get packet name
	string getPacketName() const throw() { return "CGLoadingGearReady"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_CG_LOADING_GEAR_READY; }

	// get packet's max body size
	PacketSize_t getPacketMaxSize() const throw() { return 0; }
	
};


//////////////////////////////////////////////////////////////////////
//
// class CGLoadingGearReadyHandler;
//
//////////////////////////////////////////////////////////////////////

class CGLoadingGearReadyHandler {

public:

	// execute packet's handler
	static void execute(CGLoadingGearReady* pPacket, Player* pPlayer) throw(ProtocolException, Error);

};
#endif