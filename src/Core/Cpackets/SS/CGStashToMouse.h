////////////////////////////////////////////////////////////////////////////////
// 
// Filename    : CGStashToMouse.h 
// Written By  : �輺�� 
// Description : 
// 
////////////////////////////////////////////////////////////////////////////////

#ifndef __CG_STASH_TO_MOUSE_H__
#define __CG_STASH_TO_MOUSE_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"

////////////////////////////////////////////////////////////////////////////////
//
// class CGStashToMouse;
//
////////////////////////////////////////////////////////////////////////////////

class CGStashToMouse : public Packet 
{
public:
    void read(SocketInputStream & iStream) ;
    void write(SocketOutputStream & oStream) ;
	void execute(Player* pPlayer) ;
	PacketID_t getPacketID()  { return PACKET_CG_STASH_TO_MOUSE; }
	PacketSize_t getPacketSize()  { return szObjectID + szBYTE*2; }
	string getPacketName()  { return "CGStashToMouse"; }
	string toString() ;
	
public:
	ObjectID_t getObjectID()  { return m_ObjectID; }
	void       setObjectID(ObjectID_t ObjectID)  { m_ObjectID = ObjectID; }
	BYTE       getRack(void)  { return m_Rack;}
	void       setRack(BYTE rack)  { m_Rack = rack;}
	BYTE       getIndex(void)  { return m_Index;}
	void       setIndex(BYTE index)  { m_Index = index;}

private:
	ObjectID_t m_ObjectID;
	BYTE       m_Rack;
	BYTE       m_Index;

};


////////////////////////////////////////////////////////////////////////////////
//
// class CGStashToMouseFactory;
//
////////////////////////////////////////////////////////////////////////////////

class CGStashToMouseFactory : public PacketFactory 
{
public:
	Packet* createPacket()  { return new CGStashToMouse(); }
	string getPacketName()  { return "CGStashToMouse"; }
	PacketID_t getPacketID()  { return Packet::PACKET_CG_STASH_TO_MOUSE; }
	PacketSize_t getPacketMaxSize()  { return szObjectID + szBYTE*2; }

};


////////////////////////////////////////////////////////////////////////////////
//
// class CGStashToMouseHandler;
//
////////////////////////////////////////////////////////////////////////////////

class CGStashToMouseHandler {
	
public:

	// execute packet's handler
	static void execute(CGStashToMouse* pPacket, Player* player) ;
	//static void executeSlayer(CGStashToMouse* pPacket, Player* player) ;
	//static void executeVampire(CGStashToMouse* pPacket, Player* player) ;
};

#endif
