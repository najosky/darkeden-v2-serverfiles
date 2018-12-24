//////////////////////////////////////////////////////////////////////////////
// Filename    : GCAddEffect.h 
// Written By  : elca@ewestsoft.com
// Description : 
// ����� ���������� ������ ��Ŷ�� ���� Ŭ���� ����
//////////////////////////////////////////////////////////////////////////////

#ifndef __GC_LOAD_INVENTORY_H__
#define __GC_LOAD_INVENTORY_H__

#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"
#include "InventoryInfo.h"
#include "GearInfo.h"
#include "ExtraInfo.h"
#include "EffectInfo.h"
#include "BloodBibleSignInfo.h"
//////////////////////////////////////////////////////////////////////////////
// class GCAddEffect;
// ���Ӽ������� Ŭ���̾�Ʈ�� �ڽ��� ����� ������ �˷��ֱ� ���� Ŭ����
//////////////////////////////////////////////////////////////////////////////

class GCLoadInventory : public Packet 
{
public:
	GCLoadInventory() throw();
	~GCLoadInventory() throw();
	
public:
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);
	void execute(Player* pPlayer) throw(ProtocolException, Error);
	PacketID_t getPacketID() const throw() { return PACKET_GC_LOAD_INVENTORY; }

	// ������ �� ������ ��Ģ �迭 ����
	PacketSize_t getPacketSize() const throw() {
	return m_pInventoryInfo->getSize();
	}

	string getPacketName() const throw() { return "GCLoadInventory"; }
	string toString() const throw();

public:
	// get/set Inventory Info
	InventoryInfo* getInventoryInfo() const throw() { return m_pInventoryInfo; }
	void setInventoryInfo(InventoryInfo* pInventoryInfo) throw(Error) { m_pInventoryInfo = pInventoryInfo; }
	
private :
	InventoryInfo* m_pInventoryInfo;
};


//////////////////////////////////////////////////////////////////////////////
// class GCAddEffectFactory;
//////////////////////////////////////////////////////////////////////////////

class GCLoadInventoryFactory : public PacketFactory 
{
public :
	GCLoadInventoryFactory() throw() {}
	virtual ~GCLoadInventoryFactory() throw() {}
	
public:
	Packet* createPacket() throw() { return new GCLoadInventory(); }
	string getPacketName() const throw() { return "GCLoadInventory"; }
	PacketID_t getPacketID() const throw() { return Packet::PACKET_GC_LOAD_INVENTORY; }

	PacketSize_t getPacketMaxSize() const throw() { 
	return InventoryInfo::getMaxSize();
	}
};

//////////////////////////////////////////////////////////////////////////////
// class GCAddEffectHandler;
//////////////////////////////////////////////////////////////////////////////

class GCLoadInventoryHandler 
{
public:
	static void execute(GCLoadInventory* GCLoadInventory, Player* pPlayer) throw(Error);

};

#endif