////////////////////////////////////////////////////////////////////////////////
// Filename    : GCTradeVerify.cpp 
// Written By  : 김성민
// Description :
////////////////////////////////////////////////////////////////////////////////

#include "GCTradeVerify.h"

////////////////////////////////////////////////////////////////////////////////
// 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
////////////////////////////////////////////////////////////////////////////////
void GCTradeVerify::read ( SocketInputStream & iStream ) 
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY

	iStream.read( m_Code );
		
	__END_CATCH
}

		    
////////////////////////////////////////////////////////////////////////////////
// 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
////////////////////////////////////////////////////////////////////////////////
void GCTradeVerify::write ( SocketOutputStream & oStream ) const 
     throw ( ProtocolException , Error )
{
	__BEGIN_TRY

	oStream.write( m_Code );
	
	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// execute packet's handler
////////////////////////////////////////////////////////////////////////////////
void GCTradeVerify::execute ( Player * pPlayer ) 
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY
		
	GCTradeVerifyHandler::execute( this , pPlayer );

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// get packet's debug string
////////////////////////////////////////////////////////////////////////////////
string GCTradeVerify::toString () const
       throw ()
{
	__BEGIN_TRY
		
	StringStream msg;
	msg << "GCTradeVerify("
		<< "CODE:" << (int)m_Code
		<< ")";
	return msg.toString();
		
	__END_CATCH
}


