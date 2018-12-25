//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCUseBonusPointOK.h 
// Written By  : crazydog
// Description : vamp가 bonus사용을 허가 받다.
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GC_USE_BONUS_POINT_OK_H__
#define __GC_USE_BONUS_POINT_OK_H__

// include files
#include "Packet.h"
#include "ModifyInfo.h"
#include "PacketFactory.h"


//////////////////////////////////////////////////////////////////////
//
// class GCUseBonusPointOK;
//
//////////////////////////////////////////////////////////////////////

class GCUseBonusPointOK : public ModifyInfo {

public :

	// Constructor
	GCUseBonusPointOK() throw();

	// Desctructor
	~GCUseBonusPointOK() throw();
	
    // 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
    void write(SocketOutputStream & oStream) ;

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID()  { return PACKET_GC_USE_BONUS_POINT_OK; }
	
	// get packet's body size
	// *OPTIMIZATION HINT*
	// const static GCUseBonusPointOKPacketSize 를 정의해서 리턴하라.
	PacketSize_t getPacketSize()  { return ModifyInfo::getPacketSize(); }

	// get packet name
	string getPacketName()  { return "GCUseBonusPointOK"; }
	
	// get packet's debug string
	string toString() ;

};


//////////////////////////////////////////////////////////////////////
//
// class GCUseBonusPointOKFactory;
//
// Factory for GCUseBonusPointOK
//
//////////////////////////////////////////////////////////////////////

class GCUseBonusPointOKFactory : public PacketFactory {

public :
	
	// create packet
	Packet* createPacket() throw() { return new GCUseBonusPointOK(); }

	// get packet name
	string getPacketName()  { return "GCUseBonusPointOK"; }
	
	// get packet id
	PacketID_t getPacketID()  { return Packet::PACKET_GC_USE_BONUS_POINT_OK; }

	// get packet's max body size
	// *OPTIMIZATION HINT*
	// const static GCUseBonusPointOKPacketSize 를 정의해서 리턴하라.
	PacketSize_t getPacketMaxSize()  { return ModifyInfo::getPacketMaxSize(); }

};


//////////////////////////////////////////////////////////////////////
//
// class GCUseBonusPointOKHandler;
//
//////////////////////////////////////////////////////////////////////

class GCUseBonusPointOKHandler {
	
public :

	// execute packet's handler
	static void execute(GCUseBonusPointOK* pPacket, Player* player) throw(ProtocolException, Error);
};

#endif
