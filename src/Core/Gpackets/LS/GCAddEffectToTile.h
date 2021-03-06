//////////////////////////////////////////////////////////////////////////////
// Filename    : GCAddEffectToTile.h 
// Written By  : elca@ewestsoft.com
// Description :
// 기술이 성공했을때 보내는 패킷을 위한 클래스 정의
//////////////////////////////////////////////////////////////////////////////

#ifndef __GC_ADD_EFFECT_TO_TILE_H__
#define __GC_ADD_EFFECT_TO_TILE_H__

#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class GCAddEffectToTile;
// 게임서버에서 클라이언트로 자신의 기술이 성공을 알려주기 위한 클래스
//////////////////////////////////////////////////////////////////////////////

class GCAddEffectToTile : public Packet 
{
public:
	GCAddEffectToTile() ;
	~GCAddEffectToTile() ;
	
public:
    void read(SocketInputStream & iStream) ;
    void write(SocketOutputStream & oStream) ;
	void execute(Player* pPlayer) ;
	PacketID_t getPacketID()  { return PACKET_GC_ADD_EFFECT_TO_TILE; }
	PacketSize_t getPacketSize()  { return szObjectID + szCoord*2 + szEffectID + szTurn; }
	string getPacketName()  { return "GCAddEffectToTile"; }
	string toString() ;

public:
	EffectID_t getEffectID()  { return m_EffectID; }
	void setEffectID(EffectID_t e)  { m_EffectID = e; }

	Turn_t getDuration()  { return m_Duration; }
	void setDuration(Turn_t d)  { m_Duration = d; }

	ObjectID_t getObjectID()  { return m_ObjectID; }
	void setObjectID(ObjectID_t d)  { m_ObjectID = d; }

	Coord_t getX()  { return m_X;}
	Coord_t getY()  { return m_Y;}
	void setXY(Coord_t x, Coord_t y)  { m_X = x; m_Y = y;}
	
private:
	Coord_t     m_X;
	Coord_t     m_Y;
	ObjectID_t  m_ObjectID;
	EffectID_t	m_EffectID;
	Turn_t	m_Duration;
};

//////////////////////////////////////////////////////////////////////////////
// class GCAddEffectToTileFactory;
//////////////////////////////////////////////////////////////////////////////

class GCAddEffectToTileFactory : public PacketFactory 
{
public:
	Packet* createPacket()  { return new GCAddEffectToTile(); }
	string getPacketName()  { return "GCAddEffectToTile"; }
	PacketID_t getPacketID()  { return Packet::PACKET_GC_ADD_EFFECT_TO_TILE; }
	PacketSize_t getPacketMaxSize()  { return szObjectID + szCoord*2 + szEffectID + szTurn; }
};

//////////////////////////////////////////////////////////////////////////////
// class GCAddEffectToTileHandler;
//////////////////////////////////////////////////////////////////////////////

class GCAddEffectToTileHandler 
{
public:
	static void execute(GCAddEffectToTile* pGCAddEffectToTile, Player* pPlayer);
};

#endif
