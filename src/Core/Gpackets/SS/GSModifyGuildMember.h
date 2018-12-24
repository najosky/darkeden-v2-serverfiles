//----------------------------------------------------------------------
// 
// Filename    : GSModifyGuildMember.h 
// Written By  : 
// Description : 
// 
//----------------------------------------------------------------------

#ifndef __GS_MODIFY_GUILD_MEMBER_H__
#define __GS_MODIFY_GUILD_MEMBER_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"


//----------------------------------------------------------------------
//
// class GSModifyGuildMember;
//
// ���� �߰��� ����� ������ ��û�Ѵ�.
//
// *CAUTION*
//
//----------------------------------------------------------------------

class GSModifyGuildMember : public Packet {

public:
	
    // Datagram ��ü�������� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream& iStream) throw(ProtocolException, Error);
		    
    // Datagram ��ü�� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream& oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_GS_MODIFY_GUILD_MEMBER; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const throw() 
	{ 
		return szGuildID +				// Guild ID
			   szBYTE +					// name length
			   m_Name.size() +			// name 
			   szGuildMemberRank +		// Guild Member Rank
			   szBYTE +					// sender length
			   m_Sender.size();			// sender
	}

	// get packet name
	string getPacketName() const throw() { return "GSModifyGuildMember"; }
	
	// get packet's debug string
	string toString() const throw();

public:

	// get/set Guild ID
	GuildID_t getGuildID() const throw() { return m_GuildID; }
	void setGuildID( GuildID_t guildID ) throw() { m_GuildID = guildID; }

	// get/set Name
	const string& getName() const throw() { return m_Name; }
	void setName( const string& name ) throw() { m_Name = name; }

	// get/set Guild Member Rank
	GuildMemberRank_t getGuildMemberRank() const throw() { return m_GuildMemberRank; }
	void setGuildMemberRank( GuildMemberRank_t GuildMemberRank ) throw() { m_GuildMemberRank = GuildMemberRank; }

	// get/set sender
	const string& getSender() const throw() { return m_Sender; }
	void setSender( const string& sender ) throw() { m_Sender = sender; }

private :

	// Guild ID
	GuildID_t m_GuildID;

	// name
	string m_Name;

	// Guild Member Rank
	GuildMemberRank_t m_GuildMemberRank;

	// sender
	string m_Sender;

};


//////////////////////////////////////////////////////////////////////
//
// class GSModifyGuildMemberFactory;
//
// Factory for GSModifyGuildMember
//
//////////////////////////////////////////////////////////////////////

class GSModifyGuildMemberFactory : public PacketFactory {

public:
	
	// create packet
	Packet* createPacket() throw() { return new GSModifyGuildMember(); }

	// get packet name
	string getPacketName() const throw() { return "GSModifyGuildMember"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_GS_MODIFY_GUILD_MEMBER; }

	// get packet's max body size
	// *OPTIMIZATION HINT*
	// const static LGIncomingConnectionPacketMaxSize �� ����, �����϶�.
	PacketSize_t getPacketMaxSize() const throw() 
	{ 
		return szGuildID +			// guild ID
			   szBYTE +				// name length
			   20 +					// name max length
			   szGuildMemberRank +	// guild member rank
			   szBYTE +				// sender length
			   20;					// sender max length
	}
};


//////////////////////////////////////////////////////////////////////
//
// class LGIncomingConnectionHandler;
//
//////////////////////////////////////////////////////////////////////

class GSModifyGuildMemberHandler {
	
public:

	// execute packet's handler
	static void execute(GSModifyGuildMember* pPacket, Player* pPlayer) throw(ProtocolException, Error);

};

#endif