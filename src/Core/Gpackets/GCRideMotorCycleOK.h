//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCRideMotorCycleOK.h 
// Written By  : elca@ewestsoft.com
// Description : 기술이 성공했을때 보내는 패킷을 위한 클래스 정의
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GC_RIDE_MOTORCYCLE_OK_H__
#define __GC_RIDE_MOTORCYCLE_OK_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class GCRideMotorCycleOK;
//
// 게임서버에서 클라이언트로 자신의 기술이 성공을 알려주기 위한 클래스
//
//////////////////////////////////////////////////////////////////////
class GCRideMotorCycleOK : public Packet {

public :
	
	// constructor
	GCRideMotorCycleOK() throw();
	
	// destructor
	~GCRideMotorCycleOK() throw();

	
public :
	
	
    // 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
    void write(SocketOutputStream & oStream) ;

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID()  { return PACKET_GC_RIDE_MOTORCYCLE_OK; }
	
	// get packet's body size
	// 최적화시, 미리 계산된 정수를 사용한다.
	PacketSize_t getPacketSize()  { return szObjectID; }

	// get packet's name
	string getPacketName()  { return "GCRideMotorCycleOK"; }
	
	// get packet's debug string
	string toString() ;

	// get / set ObjectID
	ObjectID_t getObjectID()  { return m_ObjectID; }
	void setObjectID(ObjectID_t ObjectID) throw() { m_ObjectID = ObjectID; }

private :
	
	// ObjectID
	ObjectID_t m_ObjectID;

};


//////////////////////////////////////////////////////////////////////
//
// class GCRideMotorCycleOKFactory;
//
// Factory for GCRideMotorCycleOK
//
//////////////////////////////////////////////////////////////////////
class GCRideMotorCycleOKFactory : public PacketFactory {

public :
	
	// constructor
	GCRideMotorCycleOKFactory() throw() {}
	
	// destructor
	virtual ~GCRideMotorCycleOKFactory() throw() {}

	
public :
	
	// create packet
	Packet* createPacket() throw() { return new GCRideMotorCycleOK(); }

	// get packet name
	string getPacketName()  { return "GCRideMotorCycleOK"; }
	
	// get packet id
	PacketID_t getPacketID()  { return Packet::PACKET_GC_RIDE_MOTORCYCLE_OK; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize()  { return szObjectID; }

};


//////////////////////////////////////////////////////////////////////
//
// class GCRideMotorCycleOKHandler;
//
//////////////////////////////////////////////////////////////////////
class GCRideMotorCycleOKHandler {

public :

	// execute packet's handler
	static void execute(GCRideMotorCycleOK* pGCRideMotorCycleOK, Player* pPlayer) throw(Error);

};

#endif
