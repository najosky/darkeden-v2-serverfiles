//////////////////////////////////////////////////////////////////////
// 
// Filename    : CGAttack 
// Written By  : elca@ewestsoft.com
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __CG_ATTACK_H__
#define __CG_ATTACK_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

#ifdef __LINUX__
//#include "GCGlobalHandler.h"
#endif // __LINUX__


//////////////////////////////////////////////////////////////////////
//
// class CGAttack;
//
//////////////////////////////////////////////////////////////////////

class CGAttack : public Packet {

public:
	
	// constructor
	CGAttack() throw();
	
	// destructor
	~CGAttack() throw();

	
public:
	
	
    // 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
    void read(SocketInputStream & iStream) ;
		    
    // 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
    void write(SocketOutputStream & oStream) ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID()  { return PACKET_CG_ATTACK; }
	
	// get packet's body size
	PacketSize_t getPacketSize()  { return szObjectID + szCoord + szCoord + szDir; }

	// get packet name
	string getPacketName()  { return "CGAttack"; }
	
	// get packet's debug string
	string toString() ;
	
	// get/set X Coordicate
	Coord_t getX()  { return m_X; }
	void setX(Coord_t x) throw() { m_X = x; }

	// get/set Y Coordicate
	Coord_t getY()  { return m_Y; }
	void setY(Coord_t y) throw() { m_Y = y; }

	// get/set Direction
	Dir_t getDir()  { return m_Dir; }
	void setDir(Dir_t dir) throw() { m_Dir = dir; }
	
	// get/set ObjectID
	ObjectID_t getObjectID()  { return m_ObjectID; }
	void setObjectID(ObjectID_t ObjectID) throw() { m_ObjectID = ObjectID; }
	
private :
	
	ObjectID_t m_ObjectID;  // ObjectID
	Coord_t m_X;			// X 좌표
	Coord_t m_Y;			// Y 좌표
	Dir_t m_Dir;			// 방향

};


//////////////////////////////////////////////////////////////////////
//
// class CGAttackFactory;
//
// Factory for CGAttack
//
//////////////////////////////////////////////////////////////////////

class CGAttackFactory : public PacketFactory {

public:
	
	// constructor
	CGAttackFactory() throw() {}
	
	// destructor
	virtual ~CGAttackFactory() throw() {}

	
public:
	
	// create packet
	Packet* createPacket() throw() { return new CGAttack(); }

	// get packet name
	string getPacketName()  { return "CGAttack"; }
	
	// get packet id
	PacketID_t getPacketID()  { return Packet::PACKET_CG_ATTACK; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize()  { return szObjectID + szCoord + szCoord + szDir; }

};

//////////////////////////////////////////////////////////////////////
//
// class CGAttackHandler;
//
//////////////////////////////////////////////////////////////////////

class CGAttackHandler {
	
public:

	// execute packet's handler
	static void execute(CGAttack* pCGAttack, Player* player) throw(Error);
};

#endif
