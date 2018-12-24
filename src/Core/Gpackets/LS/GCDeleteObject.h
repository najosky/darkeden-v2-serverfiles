//--------------------------------------------------------------------------------
// 
// Filename    : GCDeleteObject.h 
// Written By  : Reiot
// Description : 
// 
//--------------------------------------------------------------------------------

#ifndef __GC_DELETE_OBJECT_H__
#define __GC_DELETE_OBJECT_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"

//--------------------------------------------------------------------------------
//
// class GCDeleteObject;
//
// ���� Ư�� ��ü�� �þ߿��� ����� ��쿡 ���۵Ǹ�, Ŭ���̾�Ʈ�� �� ��Ŷ�� ������
// ��Ŷ ������ OID�� ����ؼ� �ش�Ǵ� ��ü�� ã�Ƽ� Ŭ���̾�Ʈ�� ������ �����ؾ� �Ѵ�.
//
// ������ �� ��Ŷ�� ���۵Ǵ� ��ü���� ��Ȳ�� �����̴�.
//
//(1) PC�� �α׾ƿ��� ���
//(2) �������� ũ��ó�� �ݴ� ���
//(3) Ư�� ����Ʈ�� ����� ���
//(4) ��ü�� ����� ���
//
// *CAUTION*
//
//(3) Ư�� ����Ʈ�� ����� ���.. �� ����Ʈ�� ������ ��, ������� �ð��� ���۵Ǳ�
// ������, �����Ǿ ������ ���̴�. -_-;
//
//--------------------------------------------------------------------------------

class GCDeleteObject : public Packet {

public :

	// constructor
	GCDeleteObject() throw()
	{
	}

	GCDeleteObject(ObjectID_t objectID) throw()
		: m_ObjectID(objectID)
	{
	}


public :
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_GC_DELETE_OBJECT; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const throw() 
	{ 
		return szObjectID; 
	}

	// get packet name
	string getPacketName() const throw() { return "GCDeleteObject"; }
	
	// get packet's debug string
	string toString() const throw();

public :

	// get/set object id
	ObjectID_t getObjectID() const throw() { return m_ObjectID; }
	void setObjectID(ObjectID_t objectID) throw() { m_ObjectID = objectID; }

private :

	// object id
	ObjectID_t m_ObjectID;

};


//////////////////////////////////////////////////////////////////////
//
// class GCDeleteObjectFactory;
//
// Factory for GCDeleteObject
//
//////////////////////////////////////////////////////////////////////

class GCDeleteObjectFactory : public PacketFactory {

public :
	
	// create packet
	Packet* createPacket() throw() { return new GCDeleteObject(); }

	// get packet name
	string getPacketName() const throw() { return "GCDeleteObject"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_GC_DELETE_OBJECT; }

	// get packet's max body size
	PacketSize_t getPacketMaxSize() const throw() 
	{ 
		return szObjectID; 
	}

};


//////////////////////////////////////////////////////////////////////
//
// class GCDeleteObjectHandler;
//
//////////////////////////////////////////////////////////////////////

class GCDeleteObjectHandler {

public :

	// execute packet's handler
	static void execute(GCDeleteObject* pPacket, Player* player) throw(ProtocolException, Error);

};

#endif