//--------------------------------------------------------------------------------
// 
// Filename    : CGRequestInfo.h 
// Written By  : 김성민
// 
//--------------------------------------------------------------------------------

#ifndef __CG_REQUEST_INFO_H__
#define __CG_REQUEST_INFO_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"



//--------------------------------------------------------------------------------
//
// class CGRequestInfo;
//
//--------------------------------------------------------------------------------

class CGRequestInfo : public Packet {

public :
	enum REQUEST_INFO_CODE
	{
		REQUEST_CHARACTER_INFO,
		
		REQUEST_INFO_MAX
	};

public:
	
	// 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
	void read(SocketInputStream & iStream) ;
		    
	// 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
	void write(SocketOutputStream & oStream) ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID()  { return PACKET_CG_REQUEST_INFO; }
	
	// get packet's body size
	// *OPTIMIZATION HINT*
	// const static CGRequestInfoPacketSize 를 정의해서 리턴하라.
	PacketSize_t getPacketSize()  { return szBYTE + szuint; }

	// get packet name
	string getPacketName()  { return "CGRequestInfo"; }
	
	// get packet's debug string
	string toString() ;
	
public:

	// get / set Code
	BYTE getCode()  { return m_Code; }
	void setCode(BYTE code) throw() { m_Code = code; }

	// get / set Code
	uint getValue()  { return m_Value; }
	void setValue(uint value) throw() { m_Value = value; }

private :
	
	// Code
	BYTE    m_Code;
	uint    m_Value;

};


//--------------------------------------------------------------------------------
//
// class CGRequestInfoFactory;
//
// Factory for CGRequestInfo
//
//--------------------------------------------------------------------------------

class CGRequestInfoFactory : public PacketFactory {

public:
	
	// create packet
	Packet* createPacket() throw() { return new CGRequestInfo(); }

	// get packet name
	string getPacketName()  { return "CGRequestInfo"; }
	
	// get packet id
	PacketID_t getPacketID()  { return Packet::PACKET_CG_REQUEST_INFO; }

	// get packet's max body size
	// *OPTIMIZATION HINT*
	// const static CGRequestInfoPacketSize 를 정의해서 리턴하라.
	PacketSize_t getPacketMaxSize()  { return szBYTE + szuint; }

};


//--------------------------------------------------------------------------------
//
// class CGRequestInfoHandler;
//
//--------------------------------------------------------------------------------

class CGRequestInfoHandler {
	
public:

	// execute packet's handler
	static void execute(CGRequestInfo* pPacket, Player* player) ;
};

#endif
