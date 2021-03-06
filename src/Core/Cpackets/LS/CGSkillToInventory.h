//////////////////////////////////////////////////////////////////////////////
// Filename    : CGSkillToInventory.h 
// Written By  : elca@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __CG_SKILL_TO_INVENTORY_H__
#define __CG_SKILL_TO_INVENTORY_H__

#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class CGSkillToInventory;
//////////////////////////////////////////////////////////////////////////////

class CGSkillToInventory : public Packet 
{
public:
    void read(SocketInputStream & iStream) ;
    void write(SocketOutputStream & oStream) ;
	void execute(Player* pPlayer) ;
	PacketID_t getPacketID()  { return PACKET_CG_SKILL_TO_INVENTORY; }
	PacketSize_t getPacketSize()  { return szSkillType + szObjectID + szObjectID+ szCoordInven*4; }
	string getPacketName()  { return "CGSkillToInventory"; }
	string toString() ;

public:
	SkillType_t getSkillType()   { return m_SkillType; }
	void setSkillType(SkillType_t SkillType)  { m_SkillType = SkillType; }

	ObjectID_t getObjectID()  { return m_ObjectID; }
	void setObjectID(ObjectID_t ObjectID)  { m_ObjectID = ObjectID; }

	ObjectID_t getInventoryItemObjectID()  { return m_InventoryItemObjectID; }
	void setInventoryItemObjectID(ObjectID_t InventoryItemObjectID)  { m_InventoryItemObjectID = InventoryItemObjectID; }

	CoordInven_t getX()  { return m_X; }
	void setX(Coord_t X)  { m_X = X; }

	CoordInven_t getY()  { return m_Y; }
	void setY(Coord_t Y)  { m_Y = Y; }

	CoordInven_t getTargetX()  { return m_TargetX; }
	void setTargetX(Coord_t TargetX)  { m_TargetX = TargetX; }

	CoordInven_t getTargetY()  { return m_TargetY; }
	void setTargetY(Coord_t TargetY)  { m_TargetY = TargetY; }

private :
	SkillType_t  m_SkillType;	// SkillType
	ObjectID_t   m_ObjectID;	// ObjectID
	ObjectID_t	 m_InventoryItemObjectID;
	CoordInven_t m_X;			// Coord X
	CoordInven_t m_Y;			// Coord Y
	CoordInven_t m_TargetX;		// Target X
	CoordInven_t m_TargetY;		// Target Y
};

//////////////////////////////////////////////////////////////////////////////
// class CGSkillToInventoryFactory;
//////////////////////////////////////////////////////////////////////////////

class CGSkillToInventoryFactory : public PacketFactory 
{
public:
	Packet* createPacket()  { return new CGSkillToInventory(); }
	string getPacketName()  { return "CGSkillToInventory"; }
	PacketID_t getPacketID()  { return Packet::PACKET_CG_SKILL_TO_INVENTORY; }
	PacketSize_t getPacketMaxSize()  { return szSkillType + szObjectID + szObjectID + szCoordInven*4; }
};

//////////////////////////////////////////////////////////////////////////////
// class CGSkillToInventoryHandler;
//////////////////////////////////////////////////////////////////////////////

class CGSkillToInventoryHandler 
{
public:
	static void execute(CGSkillToInventory* pCGSkillToInventory, Player* pPlayer);
};

#endif
