//////////////////////////////////////////////////////////////////////
// 
// Filename    : CGWithdrawTax.h 
// Written By  :
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __CG_WITHDRAW_TAX_H__
#define __CG_WITHDRAW_TAX_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class CGWithdrawTax;
//
//////////////////////////////////////////////////////////////////////

class CGWithdrawTax : public Packet
{
public:
	
    // 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
    void read(SocketInputStream & iStream) ;
		    
    // 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
    void write(SocketOutputStream & oStream) ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID()  { return PACKET_CG_WITHDRAW_TAX; }
	
	// get packet's body size
	PacketSize_t getPacketSize()  { return szGold; }

	// get packet name
	string getPacketName()  { return "CGWithdrawTax"; }

	// get packet's debug string
	string toString() ;

	// get/set Gold
	Gold_t getGold() const { return m_Gold; }
	void setGold( Gold_t gold ) { m_Gold = gold; }


private :

	Gold_t m_Gold;
};


//////////////////////////////////////////////////////////////////////
//
// class CGWithdrawTaxFactory;
//
// Factory for CGWithdrawTax
//
//////////////////////////////////////////////////////////////////////

class CGWithdrawTaxFactory : public PacketFactory {

public:
	
	// constructor
	CGWithdrawTaxFactory() throw() {}
	
	// destructor
	virtual ~CGWithdrawTaxFactory() throw() {}

	
public:
	
	// create packet
	Packet* createPacket() throw() { return new CGWithdrawTax(); }

	// get packet name
	string getPacketName()  { return "CGWithdrawTax"; }
	
	// get packet id
	PacketID_t getPacketID()  { return Packet::PACKET_CG_WITHDRAW_TAX; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize()  { return szGold; }
};


//////////////////////////////////////////////////////////////////////
//
// class CGWithdrawTaxHandler;
//
//////////////////////////////////////////////////////////////////////

class CGWithdrawTaxHandler {

public:

	// execute packet's handler
	static void execute(CGWithdrawTax* pCGWithdrawTax, Player* pPlayer) throw(Error);

};

#endif
