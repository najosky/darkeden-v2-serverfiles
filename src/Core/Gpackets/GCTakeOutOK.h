//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCTakeOutOK.h 
// Written By  : reiot@ewestsoft.com
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GC_TAKE_OUT_OK_H__
#define __GC_TAKE_OUT_OK_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"


//////////////////////////////////////////////////////////////////////
//
// class GCTakeOutOK;
//
//////////////////////////////////////////////////////////////////////

class GCTakeOutOK : public Packet {

public :
	
    // 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
    void read(SocketInputStream & iStream) ;
		    
    // 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
    void write(SocketOutputStream & oStream) ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID()  { return PACKET_GC_TAKE_OUT_OK; }
	
	// get packet's body size
	// *OPTIMIZATION HINT*
	// const static GCTakeOutOKPacketSize 를 정의해서 리턴하라.
	PacketSize_t getPacketSize()  { return szObjectID; }

	// get packet name
	string getPacketName()  { return "GCTakeOutOK"; }
	
	// get packet's debug string
	string toString() ;
	
public :

	// get / set ObjectID
	ObjectID_t getObjectID() throw() { return m_ObjectID; }
	void setObjectID(ObjectID_t ObjectID) throw() { m_ObjectID = ObjectID; }

private :
	
	// ObjectID
	ObjectID_t m_ObjectID;

};


//////////////////////////////////////////////////////////////////////
//
// class GCTakeOutOKFactory;
//
// Factory for GCTakeOutOK
//
//////////////////////////////////////////////////////////////////////

class GCTakeOutOKFactory : public PacketFactory {

public :
	
	// create packet
	Packet* createPacket() throw() { return new GCTakeOutOK(); }

	// get packet name
	string getPacketName()  { return "GCTakeOutOK"; }
	
	// get packet id
	PacketID_t getPacketID()  { return Packet::PACKET_GC_TAKE_OUT_OK; }

	// get packet's max body size
	// *OPTIMIZATION HINT*
	// const static GCTakeOutOKPacketSize 를 정의해서 리턴하라.
	PacketSize_t getPacketMaxSize()  { return szObjectID; }

};


//////////////////////////////////////////////////////////////////////
//
// class GCTakeOutOKHandler;
//
//////////////////////////////////////////////////////////////////////

class GCTakeOutOKHandler {
	
public :

	// execute packet's handler
	static void execute(GCTakeOutOK* pPacket, Player* player) ;
};

#endif
