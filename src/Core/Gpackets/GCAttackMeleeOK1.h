//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCAttackMeleeOK1.h 
// Written By  : elca@ewestsoft.com
// Description : 기술이 성공했을때 보내는 패킷을 위한 클래스 정의
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GC_ATTACK_MELEE_OK_1_H__
#define __GC_ATTACK_MELEE_OK_1_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "ModifyInfo.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class GCAttackMeleeOK1;
//
// 게임서버에서 클라이언트로 자신의 기술이 성공을 알려주기 위한 클래스
//
//////////////////////////////////////////////////////////////////////

class GCAttackMeleeOK1 : public ModifyInfo {

public :
	
	// constructor
	GCAttackMeleeOK1() throw();
	
	// destructor
	~GCAttackMeleeOK1() throw();

	
public :
	
	
    // 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
    void read(SocketInputStream & iStream) ;
		    
    // 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
    void write(SocketOutputStream & oStream) ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID()  { return PACKET_GC_ATTACK_MELEE_OK_1; }
	
	// get packet's body size
	// 최적화시, 미리 계산된 정수를 사용한다.
	PacketSize_t getPacketSize()  { return szObjectID + ModifyInfo::getPacketSize(); }

	// get packet's name
	string getPacketName()  { return "GCAttackMeleeOK1"; }
	
	// get packet's debug string
	string toString() ;

	// get / set CEffectID
	ObjectID_t getObjectID()  { return m_ObjectID; }
	void setObjectID(ObjectID_t ObjectID) throw() { m_ObjectID = ObjectID; }

private :
	
	// ObjectID
	ObjectID_t m_ObjectID;
};


//////////////////////////////////////////////////////////////////////
//
// class GCAttackMeleeOK1Factory;
//
// Factory for GCAttackMeleeOK1
//
//////////////////////////////////////////////////////////////////////

class GCAttackMeleeOK1Factory : public PacketFactory {

public :
	
	// constructor
	GCAttackMeleeOK1Factory() throw() {}
	
	// destructor
	virtual ~GCAttackMeleeOK1Factory() throw() {}

	
public :
	
	// create packet
	Packet* createPacket() throw() { return new GCAttackMeleeOK1(); }

	// get packet name
	string getPacketName()  { return "GCAttackMeleeOK1"; }
	
	// get packet id
	PacketID_t getPacketID()  { return Packet::PACKET_GC_ATTACK_MELEE_OK_1; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize()  { return szObjectID + ModifyInfo::getPacketMaxSize(); }

};


//////////////////////////////////////////////////////////////////////
//
// class GCAttackMeleeOK1Handler;
//
//////////////////////////////////////////////////////////////////////

class GCAttackMeleeOK1Handler {

public :

	// execute packet's handler
	static void execute(GCAttackMeleeOK1* pGCAttackMeleeOK1, Player* pPlayer) throw(Error);

};

#endif
