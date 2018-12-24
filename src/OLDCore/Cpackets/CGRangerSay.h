//////////////////////////////////////////////////////////////////////
// 
// Filename    : CGRangerSay.h 
// Written By  : reiot@ewestsoft.com
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __CG_RANGER_SAY_H__
#define __CG_RANGER_SAY_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class CGRangerSay;
//
// DragonEye �� ���� ����ڰ� Ranger ��ê�� �Ҷ� ����ϴ� ��Ŷ
//
//////////////////////////////////////////////////////////////////////

class CGRangerSay : public Packet
{
public:
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_CG_RANGER_SAY; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const throw() { return szBYTE + m_Message.size(); }

	// get packet name
	string getPacketName() const throw() { return "CGRangerSay"; }
	
	// get packet's debug string
	string toString() const throw();

	// get/set chatting message
	string getMessage() const throw() { return m_Message; }
	void setMessage(const string & msg) throw() { m_Message = msg; }
	

private :
	// chatting message
	string m_Message;
};


//////////////////////////////////////////////////////////////////////
//
// class CGRangerSayFactory;
//
// Factory for CGRangerSay
//
//////////////////////////////////////////////////////////////////////

class CGRangerSayFactory : public PacketFactory
{
public:
	// create packet
	Packet* createPacket() throw() { return new CGRangerSay(); }

	// get packet name
	string getPacketName() const throw() { return "CGRangerSay"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_CG_RANGER_SAY; }

	// get packet's max body size
	// message �� �ִ� ũ�⿡ ���� ������ �ʿ��ϴ�.
	PacketSize_t getPacketMaxSize() const throw() { return szBYTE + 128; }

};


//////////////////////////////////////////////////////////////////////
//
// class CGRangerSayHandler;
//
//////////////////////////////////////////////////////////////////////

class CGRangerSayHandler
{
public:

	// execute packet's handler
	static void execute(CGRangerSay* pPacket, Player* pPlayer) throw(ProtocolException, Error);

};

#endif
