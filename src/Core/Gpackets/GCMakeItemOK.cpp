//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCMakeItemOK.cpp 
// Written By  : elca@ewestsoft.com
// Description : 자신에게 쓰는 기술의 성공을 알리기 위한 패킷 클래스의
//               멤버 정의.
// 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// include files
//////////////////////////////////////////////////////////////////////
#include "GCMakeItemOK.h"



//////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////
GCMakeItemOK::GCMakeItemOK () 
     throw ()
{
	__BEGIN_TRY
	__END_CATCH
}

	
//////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////
GCMakeItemOK::~GCMakeItemOK () 
    throw ()
{
	__BEGIN_TRY
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
//////////////////////////////////////////////////////////////////////
void GCMakeItemOK::read ( SocketInputStream & iStream ) 
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY

	GCChangeInventoryItemNum::read( iStream);
	GCAddItemToInventory::read( iStream);
	ModifyInfo::read( iStream);
	__END_CATCH
}

		    
//////////////////////////////////////////////////////////////////////
// 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
//////////////////////////////////////////////////////////////////////
void GCMakeItemOK::write ( SocketOutputStream & oStream ) 
     const throw ( ProtocolException , Error )
{
	__BEGIN_TRY
	GCChangeInventoryItemNum::write( oStream);
	GCAddItemToInventory::write( oStream);
	ModifyInfo::write( oStream);
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
// execute packet's handler
//
//////////////////////////////////////////////////////////////////////
void GCMakeItemOK::execute ( Player * pPlayer ) 
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY
		
	GCMakeItemOKHandler::execute( this , pPlayer );
		
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
// get packet's debug string
//
//////////////////////////////////////////////////////////////////////
string GCMakeItemOK::toString () 
	const throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "GCMakeItemOK("
		<< GCChangeInventoryItemNum::toString()
		<< GCAddItemToInventory::toString()
		<< ModifyInfo::toString();
	msg << ")";
	return msg.toString();

	__END_CATCH
}

