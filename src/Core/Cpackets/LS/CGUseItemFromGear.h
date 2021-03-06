//////////////////////////////////////////////////////////////////////////////
// Filename    : CGUseItemFromGear.h 
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __CG_USE_ITEM_FROM_GEAR_H__
#define __CG_USE_ITEM_FROM_GEAR_H__

#include "Packet.h"
#include "PacketFactory.h"

class GamePlayer;

//////////////////////////////////////////////////////////////////////////////
// class CGUseItemFromGear;
//////////////////////////////////////////////////////////////////////////////

class CGUseItemFromGear : public Packet 
{
public:
    void read(SocketInputStream & iStream) ;
    void write(SocketOutputStream & oStream) ;
	void execute(Player* pPlayer) ;
	PacketID_t getPacketID()  { return PACKET_CG_USE_ITEM_FROM_GEAR; }
	PacketSize_t getPacketSize()  { return szObjectID + szBYTE; }
	string getPacketName()  { return "CGUseItemFromGear"; }
	string toString() ;
	
public:
	ObjectID_t getObjectID()  { return m_ObjectID; }
	void setObjectID(ObjectID_t ObjectID)  { m_ObjectID = ObjectID; }

	BYTE getPart()  { return m_Part; }
	void setPart( BYTE part )  { m_Part = part; }

private:
	ObjectID_t   m_ObjectID; // 아이템의 object id 
	BYTE		 m_Part;	 // 아이템이 있는 slot 
};


//////////////////////////////////////////////////////////////////////////////
// class CGUseItemFromGearFactory;
//////////////////////////////////////////////////////////////////////////////

class CGUseItemFromGearFactory : public PacketFactory 
{
public:
	Packet* createPacket()  { return new CGUseItemFromGear(); }
	string getPacketName()  { return "CGUseItemFromGear"; }
	PacketID_t getPacketID()  { return Packet::PACKET_CG_USE_ITEM_FROM_GEAR; }
	PacketSize_t getPacketMaxSize()  { return szObjectID + szBYTE; }
};


//////////////////////////////////////////////////////////////////////////////
// class CGUseItemFromGearHandler;
//////////////////////////////////////////////////////////////////////////////

class Item;

class CGUseItemFromGearHandler 
{
public:
	static void execute(CGUseItemFromGear* pPacket, Player* player) ;

protected:
	static void executeCoupleRing(CGUseItemFromGear* pPacket, GamePlayer* pGamePlayer) ;
};

#endif
