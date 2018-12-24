//////////////////////////////////////////////////////////////////////////////
// Filename    : GCAddEffect.h 
// Written By  : elca@ewestsoft.com
// Description : 
// ����� ���������� ������ ��Ŷ�� ���� Ŭ���� ����
//////////////////////////////////////////////////////////////////////////////

#ifndef __GC_LOAD_GEAR_H__
#define __GC_LOAD_GEAR_H__

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

class GCLoadGear : public Packet 
{
public:
	GCLoadGear() throw();
	~GCLoadGear() throw();
	
public:
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);
	void execute(Player* pPlayer) throw(ProtocolException, Error);
	PacketID_t getPacketID() const throw() { return PACKET_GC_LOAD_GEAR; }

	// ������ �� ������ ��Ģ �迭 ����
	PacketSize_t getPacketSize() const throw() {
	return m_pGearInfo->getSize() + m_pBloodBibleSign->getSize();
	}

	string getPacketName() const throw() { return "GCLoadGear"; }
	string toString() const throw();

public:
	uchar getType() { return m_Type; }
	void setType(uchar Type) { m_Type = Type; }

	// get/set Inventory Info
	InventoryInfo* getInventoryInfo() const throw() { return m_pInventoryInfo; }
	void setInventoryInfo(InventoryInfo* pInventoryInfo) throw(Error) { m_pInventoryInfo = pInventoryInfo; }

	// get/set Gear Info
	GearInfo* getGearInfo() const throw() { return m_pGearInfo; }
	void setGearInfo(GearInfo* pGearInfo) throw(Error) { m_pGearInfo = pGearInfo; }

	// get/set ExtraInfo
	ExtraInfo* getExtraInfo() const throw() { return m_pExtraInfo; }
	void setExtraInfo(ExtraInfo* pExtraInfo) throw(Error) { m_pExtraInfo = pExtraInfo; }

	// get/set EffectInfo
	EffectInfo* getEffectInfo() const throw() { return m_pEffectInfo; }
	void setEffectInfo(EffectInfo* pEffectInfo) throw(Error) { m_pEffectInfo = pEffectInfo; }

	BloodBibleSignInfo*	getBloodBibleSignInfo() { return m_pBloodBibleSign; }
	void	setBloodBibleSignInfo( BloodBibleSignInfo* pInfo ) { m_pBloodBibleSign = pInfo; }
	
private :
	uchar m_Type;
	InventoryInfo* m_pInventoryInfo;
	GearInfo* m_pGearInfo;
	ExtraInfo* m_pExtraInfo;
	EffectInfo* m_pEffectInfo;
	BloodBibleSignInfo* m_pBloodBibleSign;
};


//////////////////////////////////////////////////////////////////////////////
// class GCAddEffectFactory;
//////////////////////////////////////////////////////////////////////////////

class GCLoadGearFactory : public PacketFactory 
{
public :
	GCLoadGearFactory() throw() {}
	virtual ~GCLoadGearFactory() throw() {}
	
public:
	Packet* createPacket() throw() { return new GCLoadGear(); }
	string getPacketName() const throw() { return "GCLoadGear"; }
	PacketID_t getPacketID() const throw() { return Packet::PACKET_GC_LOAD_GEAR; }

	PacketSize_t getPacketMaxSize() const throw() { 
	return GearInfo::getMaxSize() + BloodBibleSignInfo::getMaxSize();
	}
};

//////////////////////////////////////////////////////////////////////////////
// class GCAddEffectHandler;
//////////////////////////////////////////////////////////////////////////////

class GCLoadGearHandler 
{
public:
	static void execute(GCLoadGear* GCLoadGear, Player* pPlayer) throw(Error);

};

#endif