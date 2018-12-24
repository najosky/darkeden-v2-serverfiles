////////////////////////////////////////////////////////////////////////////////
// Filename    : CGStashList.h 
// Written By  : �輺��
// Description : 
// Ŭ���̾�Ʈ�� ������ �ȿ� ����ִ� �������� ����Ʈ�� �䱸�� �� ���̴�
// ��Ŷ�̴�. 
////////////////////////////////////////////////////////////////////////////////

#ifndef __CG_STASH_LIST_H__
#define __CG_STASH_LIST_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"

////////////////////////////////////////////////////////////////////////////////
//
// class CGStashList;
//
////////////////////////////////////////////////////////////////////////////////

class CGStashList : public Packet 
{
public:
	void read(SocketInputStream & iStream) throw(ProtocolException, Error);
	void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);
	void execute(Player* pPlayer) throw(ProtocolException, Error);
	PacketID_t getPacketID() const throw() { return PACKET_CG_STASH_LIST; }
	PacketSize_t getPacketSize() const throw() { return szObjectID; }
	string getPacketName() const throw() { return "CGStashList"; }
	string toString() const throw();

public:
	ObjectID_t getObjectID() throw() { return m_ObjectID; }
	void setObjectID(ObjectID_t id) throw() { m_ObjectID = id; }

private:
	ObjectID_t m_ObjectID; // �÷��̾� ũ������ object id

};


////////////////////////////////////////////////////////////////////////////////
//
// class CGStashListFactory;
//
// Factory for CGStashList
//
////////////////////////////////////////////////////////////////////////////////

class CGStashListFactory : public PacketFactory 
{
public:
	Packet* createPacket() throw() { return new CGStashList(); }
	string getPacketName() const throw() { return "CGStashList"; }
	PacketID_t getPacketID() const throw() { return Packet::PACKET_CG_STASH_LIST; }
	PacketSize_t getPacketMaxSize() const throw() { return szObjectID; }

};


////////////////////////////////////////////////////////////////////////////////
//
// class CGStashListHandler;
//
////////////////////////////////////////////////////////////////////////////////

class CGStashListHandler 
{
public:
	static void execute(CGStashList* pPacket, Player* player) throw(ProtocolException, Error);

};

#endif