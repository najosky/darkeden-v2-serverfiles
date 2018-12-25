//////////////////////////////////////////////////////////////////////////////
// Filename    : GCWarList.h 
// Written By  : 
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __GC_WAR_LIST_H__
#define __GC_WAR_LIST_H__

#include "Packet.h"
#include "PacketFactory.h"
#include "Types.h"
#include "GuildWarInfo.h"
#include "RaceWarInfo.h"
#include <list>

typedef list<WarInfo*> 					WarInfoList;
typedef WarInfoList::const_iterator 	WarInfoListItor;

class GCWarList : public Packet
{
public:
	GCWarList() throw();
	virtual ~GCWarList() throw();

	void	clear() throw();

public:
	void read(SocketInputStream & iStream) throw(ProtocolException, Error);
	void write(SocketOutputStream & oStream) ;
	void execute(Player* pPlayer) throw(ProtocolException, Error);
	PacketID_t getPacketID()  { return PACKET_GC_WAR_LIST; }
	PacketSize_t getPacketSize() ;
	string getPacketName()  { return "GCWarList"; }
	string toString() ;

public:
	int 	getSize()  { return m_WarInfos.size(); }
	bool 	isEmpty()  { return m_WarInfos.empty(); }

	void addWarInfo( WarInfo* pWarInfo ) throw() { m_WarInfos.push_back( pWarInfo ); }
	WarInfo* popWarInfo() throw();

	void	operator = (const GCWarList& WL);

private:
	WarInfoList m_WarInfos;
};

class GCWarListFactory : public PacketFactory {

public :
	
	Packet* createPacket() throw() { return new GCWarList(); }
	string getPacketName()  { return "GCWarList"; }
	PacketID_t getPacketID()  { return Packet::PACKET_GC_WAR_LIST; }
	PacketSize_t getPacketMaxSize()  { return (RaceWarInfo::getMaxSize() + GuildWarInfo::getMaxSize()) * 12; }
};

class GCWarListHandler {
	
public :
	static void execute(GCWarList* pPacket, Player* pPlayer) throw(ProtocolException, Error);

};



#endif // __GC_WAR_LIST_H__

