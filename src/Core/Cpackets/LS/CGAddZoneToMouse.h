//////////////////////////////////////////////////////////////////////////////
// Filename    : CGAddZoneToMouse.h 
// Written By  : reiot@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __CG_ADD_ZONE_TO_MOUSE_H__
#define __CG_ADD_ZONE_TO_MOUSE_H__

#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class CGAddZoneToMouse;
//////////////////////////////////////////////////////////////////////////////

class CGAddZoneToMouse : public Packet
{
public:
	CGAddZoneToMouse() ;
	~CGAddZoneToMouse() ;

public:
    void read(SocketInputStream & iStream) ;
    void write(SocketOutputStream & oStream) ;
	void execute(Player* pPlayer) ;
	PacketID_t getPacketID()  { return PACKET_CG_ADD_ZONE_TO_MOUSE; }
	PacketSize_t getPacketSize()  { return szObjectID + szCoord + szCoord; }
	string getPacketName()  { return "CGAddZoneToMouse"; }
	string toString() ;
	
public:
	ObjectID_t getObjectID()  { return m_ObjectID; }
	void setObjectID(ObjectID_t ObjectID)  { m_ObjectID = ObjectID; }

	Coord_t getZoneX()  { return m_ZoneX; }
	void setZoneX(Coord_t ZoneX)  { m_ZoneX = ZoneX; }

	Coord_t getZoneY()  { return m_ZoneY; }
	void setZoneY(Coord_t ZoneY)  { m_ZoneY = ZoneY; }

private:
	ObjectID_t m_ObjectID;

	Coord_t m_ZoneX;
	Coord_t m_ZoneY;
};

//////////////////////////////////////////////////////////////////////////////
// class CGAddZoneToMouseFactory;
//////////////////////////////////////////////////////////////////////////////

class CGAddZoneToMouseFactory : public PacketFactory 
{
public:
	Packet* createPacket()  { return new CGAddZoneToMouse(); }
	string getPacketName()  { return "CGAddZoneToMouse"; }
	PacketID_t getPacketID()  { return Packet::PACKET_CG_ADD_ZONE_TO_MOUSE; }
	PacketSize_t getPacketMaxSize()  { return szObjectID + szCoord + szCoord; }
};

//////////////////////////////////////////////////////////////////////////////
// class CGAddZoneToMouseHandler;
//////////////////////////////////////////////////////////////////////////////

class CGAddZoneToMouseHandler 
{
public:
	static void execute(CGAddZoneToMouse* pPacket, Player* player) ;
};

#endif
