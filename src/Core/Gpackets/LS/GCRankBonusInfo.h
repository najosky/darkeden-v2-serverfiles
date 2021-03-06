//--------------------------------------------------------------------------------
// 
// Filename    : GCRankBonusInfo.h 
// Written By  : Reiot
// Description : 
// 
//--------------------------------------------------------------------------------

#ifndef __GC_RANK_BONUS_INFO_H__
#define __GC_RANK_BONUS_INFO_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"
#include "Assert.h"

const DWORD EndOfRankBonus = 9999;


class GCRankBonusInfo : public Packet {

public :

	// constructor
	GCRankBonusInfo() ;

	// destructor
	~GCRankBonusInfo() ;
	
    // 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
    void read(SocketInputStream & iStream) ;
		    
    // 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
    void write(SocketOutputStream & oStream) ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID()  { return PACKET_GC_RANK_BONUS_INFO; }
	
	// get packet's body size
	PacketSize_t getPacketSize()  { return szBYTE + ( szDWORD * m_RankBonusInfoList.size() ); }

	// get packet name
	string getPacketName()  { return "GCRankBonusInfo"; }
	
	// get packet's debug string
	string toString() ;

//--------------------------------------------------
// methods
//--------------------------------------------------
public :

	BYTE getListNum()  { return m_RankBonusInfoList.size(); }

    // add
	void addListElement( DWORD rankBonusType )  { m_RankBonusInfoList.push_back( rankBonusType ); }
	
	// pop front Element in Status List
	DWORD popFrontListElement() 
	{
		if ( !m_RankBonusInfoList.empty() )
		{
			DWORD temp = m_RankBonusInfoList.front();
			m_RankBonusInfoList.pop_front();
			return temp;
		}
		else
			return EndOfRankBonus;
	}

private :

	// Rank Bonus List
	list<DWORD> m_RankBonusInfoList;

};


//--------------------------------------------------------------------------------
//
// class GCRankBonusInfoFactory;
//
// Factory for GCRankBonusInfo
//
//--------------------------------------------------------------------------------

class GCRankBonusInfoFactory : public PacketFactory {

public :
	
	// create packet
	Packet* createPacket()  { return new GCRankBonusInfo(); }

	// get packet name
	string getPacketName()  { return "GCRankBonusInfo"; }
	
	// get packet id
	PacketID_t getPacketID()  { return Packet::PACKET_GC_RANK_BONUS_INFO; }

	// get packet's max body size
	// *OPTIMIZATION HINT*
	// const static GCRankBonusInfoPacketMaxSize 를 정의, 리턴하라.
	PacketSize_t getPacketMaxSize()  
	{ 
		return szBYTE + ( szDWORD * 100 );
	}

};


//--------------------------------------------------------------------------------
//
// class GCRankBonusInfoHandler;
//
//--------------------------------------------------------------------------------

class GCRankBonusInfoHandler {

public :

	// execute packet's handler
	static void execute(GCRankBonusInfo* pPacket, Player* pPlayer) ;

};

#endif
