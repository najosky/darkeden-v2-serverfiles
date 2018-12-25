//////////////////////////////////////////////////////////////////////////////
// Filename    : GCNPCAskDynamic.h 
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __GC_NPC_ASK_DYNAMIC_H__
#define __GC_NPC_ASK_DYNAMIC_H__

#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class GCNPCAskDynamic;
// NPC 의 대사를 주변의 PC 들에게 전송한다.
//////////////////////////////////////////////////////////////////////////////

class GCNPCAskDynamic : public Packet 
{
public:
	GCNPCAskDynamic() throw();
	virtual ~GCNPCAskDynamic() throw();

public:
	void read(SocketInputStream & iStream) ;
	void write(SocketOutputStream & oStream) ;
	void execute(Player* pPlayer) ;
	PacketID_t getPacketID()  { return PACKET_GC_NPC_ASK_DYNAMIC; }
	PacketSize_t getPacketSize() 
	{ 
		PacketSize_t size = 0;

		size += szObjectID; // npc object id
		size += szScriptID; // script id size
		size += szWORD + m_Subject.size(); // subject length & actual string

		list<string>::const_iterator itr = m_Contents.begin();
		for(; itr != m_Contents.end(); itr++)
			size +=(szWORD +(*itr).size()); // contents length & actual string

		return size;
	}
	string getPacketName()  { return "GCNPCAskDynamic"; }
	string toString() ;

public:
	ObjectID_t getObjectID(void)  { return m_ObjectID; }
	void setObjectID(ObjectID_t creatureID) throw() { m_ObjectID = creatureID; }

	ScriptID_t getScriptID(void)  { return m_ScriptID; }
	void setScriptID(ScriptID_t id) throw() { m_ScriptID = id; }

	string getSubject(void)  { return m_Subject; }
	void setSubject(string subject) throw() { m_Subject = subject; }

	BYTE getContentsCount(void)  { return m_ContentsCount; }

	void addContent(string content) throw();
	string popContent(void) throw();

private:
	ObjectID_t   m_ObjectID;       // NPC's object id
	ScriptID_t   m_ScriptID;       // script id
	string       m_Subject;        // subject
	BYTE         m_ContentsCount;  // content count
	list<string> m_Contents;       // actual content

	
};

//////////////////////////////////////////////////////////////////////////////
// class GCNPCAskDynamicFactory;
//////////////////////////////////////////////////////////////////////////////

class GCNPCAskDynamicFactory : public PacketFactory 
{
public:
	Packet* createPacket() throw() { return new GCNPCAskDynamic(); }
	string getPacketName()  { return "GCNPCAskDynamic"; }
	PacketID_t getPacketID()  { return Packet::PACKET_GC_NPC_ASK_DYNAMIC; }
	PacketSize_t getPacketMaxSize()  
	{ 
		PacketSize_t size = 0;

		size += szObjectID;          // npc object id
		size += szScriptID;          // script id size
		size += szWORD + 1024;       // subject length & actual string
		size += szWORD* 10 + 10240; // contents length & actual strings

		return size;
	}
};

//////////////////////////////////////////////////////////////////////////////
// class GCNPCAskDynamicHandler;
//////////////////////////////////////////////////////////////////////////////

class GCNPCAskDynamicHandler 
{
public:
	static void execute(GCNPCAskDynamic* pPacket, Player* pPlayer) ;
};

#endif
