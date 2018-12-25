//----------------------------------------------------------------------
// 
// Filename    : GSGuildMemberLogOn.h 
// Written By  : 
// Description : 
// 
//----------------------------------------------------------------------

#ifndef __GS_GUILDMEMBER_LOGON_H__
#define __GS_GUILDMEMBER_LOGON_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"


//----------------------------------------------------------------------
//
// class GSGuildMemberLogOn;
//
// 팀이 추가를 쉐어드 서버에 요청한다.
//
// *CAUTION*
//
//----------------------------------------------------------------------

class GSGuildMemberLogOn : public Packet {

public:
	
    // Datagram 객체에서부터 데이타를 읽어서 패킷을 초기화한다.
    void read(SocketInputStream& iStream) throw(ProtocolException, Error);
		    
    // Datagram 객체로 패킷의 바이너리 이미지를 보낸다.
    void write(SocketOutputStream& oStream) ;

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID()  { return PACKET_GS_GUILDMEMBER_LOGON; }
	
	// get packet's body size
	PacketSize_t getPacketSize()  
	{ 
		return szGuildID +				// Guild ID
			   szBYTE +					// name length
			   m_Name.size() +			// name 
			   szbool+					// logon
			   szServerID;				// ServerID
	}

	// get packet name
	string getPacketName()  { return "GSGuildMemberLogOn"; }
	
	// get packet's debug string
	string toString() ;

public:

	// get/set Guild ID
	GuildID_t getGuildID()  { return m_GuildID; }
	void setGuildID( GuildID_t guildID ) throw() { m_GuildID = guildID; }

	// get/set Name
	const string& getName()  { return m_Name; }
	void setName( const string& name ) throw() { m_Name = name; }

	// get/set logon
	bool getLogOn()  { return m_bLogOn; }
	void setLogOn( bool logOn ) throw() { m_bLogOn = logOn; }

	// get/set ServerID
	ServerID_t	getServerID()		{ return m_ServerID; }
	void		setServerID( ServerID_t ServerID ) throw() { m_ServerID = ServerID; }
	
	
private :

	// Guild ID
	GuildID_t m_GuildID;

	// name
	string m_Name;

	// log on
	bool m_bLogOn;

	// ServerID
	ServerID_t	m_ServerID;
	
};


//////////////////////////////////////////////////////////////////////
//
// class GSGuildMemberLogOnFactory;
//
// Factory for GSGuildMemberLogOn
//
//////////////////////////////////////////////////////////////////////

class GSGuildMemberLogOnFactory : public PacketFactory {

public:
	
	// create packet
	Packet* createPacket() throw() { return new GSGuildMemberLogOn(); }

	// get packet name
	string getPacketName()  { return "GSGuildMemberLogOn"; }
	
	// get packet id
	PacketID_t getPacketID()  { return Packet::PACKET_GS_GUILDMEMBER_LOGON; }

	// get packet's max body size
	// *OPTIMIZATION HINT*
	// const static LGIncomingConnectionPacketMaxSize 를 정의, 리턴하라.
	PacketSize_t getPacketMaxSize()  
	{ 
		return szGuildID +			// guild ID
			   szBYTE +				// name length
			   20 +					// name max length
			   szbool +				// logon
			   szServerID;			// Server ID
	}
};


//////////////////////////////////////////////////////////////////////
//
// class LGIncomingConnectionHandler;
//
//////////////////////////////////////////////////////////////////////

class GSGuildMemberLogOnHandler {
	
public:

	// execute packet's handler
	static void execute(GSGuildMemberLogOn* pPacket, Player* pPlayer) throw(ProtocolException, Error);

};

#endif
