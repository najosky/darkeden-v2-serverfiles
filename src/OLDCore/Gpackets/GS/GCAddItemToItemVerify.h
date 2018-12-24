//////////////////////////////////////////////////////////////////////////////
// Filename    : GCAddItemToItemVerify.h 
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __GC_ADD_ITEM_TO_ITEM_VERIFY_H__
#define __GC_ADD_ITEM_TO_ITEM_VERIFY_H__

#include "Packet.h"
#include "PacketFactory.h"

enum 
{
	ADD_ITEM_TO_ITEM_VERIFY_ERROR,					// error

	ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_IMPOSSIBLE,		// enchant ���� �Ұ�
	ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL_CRASH,		// enchant ����: ������ �μ���
	ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL_DECREASE,	// enchant ����: �ɼ� ������
	ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK,				// enchant ����
	ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_IMPOSSIBLE_NO_PREMIUM,	// enchant �Ұ� : �����̾� �ƴ�

	ADD_ITEM_TO_ITEM_VERIFY_TRANS_OK,
	ADD_ITEM_TO_ITEM_VERIFY_TRANS_IMPOSSIBLE,
	
	ADD_ITEM_TO_ITEM_VERIFY_MIXING_OK,
	ADD_ITEM_TO_ITEM_VERIFY_DETACHING_OK,

	ADD_ITEM_TO_ITEM_VERIFY_MIXING_FAILED_SAME_OPTION_GROUP,	// �������� �ɼ� �׷��� ���Ƽ� ���� �� �����ϴ�.
	ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL,				// enchant ����

	ADD_ITEM_TO_ITEM_VERIFY_REVIVAL_OK,					// �� ��Ȱ ����

	ADD_ITEM_TO_ITEM_VERIFY_CLEAR_OPTION_OK,			// option ���� ����
	ADD_ITEM_TO_ITEM_VERIFY_UP_GRADE_OK,				// grade�ø��� ����

	// add by Coffee 2006.11.3
	ADD_ITEM_TO_ITEM_VERIFY_THREE_ENCHANT_OK,
	//
	ADD_ITEM_TO_ITEM_VERIFY_MAX
};

//////////////////////////////////////////////////////////////////////////////
// class GCAddItemToItemVerify
//////////////////////////////////////////////////////////////////////////////

class GCAddItemToItemVerify : public Packet 
{

public:
	GCAddItemToItemVerify() throw() { m_Code = ADD_ITEM_TO_ITEM_VERIFY_MAX; m_Parameter = 0;}
	virtual ~GCAddItemToItemVerify() throw() {}

public:
	void read(SocketInputStream & iStream) throw(ProtocolException, Error);
	void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	PacketID_t getPacketID() const throw() { return PACKET_GC_ADD_ITEM_TO_ITEM_VERIFY; }
	PacketSize_t getPacketSize() const throw();
	string getPacketName() const throw() { return "GCAddItemToItemVerify"; }
	string toString() const throw();
	
public:
	BYTE getCode(void) const throw() { return m_Code;}
	void setCode(BYTE code) throw() { m_Code = code;}

	uint getParameter(void) const throw() { return m_Parameter; }

	void setParameter(uint parameter) throw() { m_Parameter = parameter; }
	// add by Coffee 2006.11.3
	uint getParameter2(void) const throw() { return m_Parameter2;  }
	void setParameter2(uint parameter2) throw() { m_Parameter2 = parameter2; }

private: 
	BYTE m_Code;
	uint m_Parameter;
	// add by Coffee 2006.11.3  ����ڶ�������
	uint m_Parameter2;
};


//////////////////////////////////////////////////////////////////////////////
// class GCAddItemToItemVerifyFactory;
//////////////////////////////////////////////////////////////////////////////

class GCAddItemToItemVerifyFactory : public PacketFactory 
{
public:
	Packet* createPacket() throw() { return new GCAddItemToItemVerify(); }
	string getPacketName() const throw() { return "GCAddItemToItemVerify"; }
	PacketID_t getPacketID() const throw() { return Packet::PACKET_GC_ADD_ITEM_TO_ITEM_VERIFY; }
	PacketSize_t getPacketMaxSize() const throw() { return szBYTE + szuint +szuint; }
};


//////////////////////////////////////////////////////////////////////////////
// class GCAddItemToItemVerifyHandler
//////////////////////////////////////////////////////////////////////////////

class GCAddItemToItemVerifyHandler 
{
public:
	static void execute( GCAddItemToItemVerify* pPacket, Player* pPlayer) throw(ProtocolException, Error);
};

#endif
