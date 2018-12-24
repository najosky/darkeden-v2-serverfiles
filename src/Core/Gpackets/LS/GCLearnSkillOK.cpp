//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCLearnSkillOK.cc 
// Written By  : elca@ewestsoft.com
// Description : Skill이 실패 했을때 날려주는 패킷의 멤버 정의
// 
//////////////////////////////////////////////////////////////////////

// include files
#include "GCLearnSkillOK.h"



//////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////
GCLearnSkillOK::GCLearnSkillOK () 
     throw ()
{
	__BEGIN_TRY
	__END_CATCH
}

	
//////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////
GCLearnSkillOK::~GCLearnSkillOK () 
    throw ()
{
	__BEGIN_TRY
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
//////////////////////////////////////////////////////////////////////
void GCLearnSkillOK::read ( SocketInputStream & iStream ) 
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY
	iStream.read( m_SkillType );
	iStream.read( m_DomainType );
	__END_CATCH
}

		    
//////////////////////////////////////////////////////////////////////
// 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
//////////////////////////////////////////////////////////////////////
void GCLearnSkillOK::write ( SocketOutputStream & oStream ) const 
     throw ( ProtocolException , Error )
{
	__BEGIN_TRY
	oStream.write( m_SkillType );
	oStream.write( m_DomainType );
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// execute packet's handler
//////////////////////////////////////////////////////////////////////
void GCLearnSkillOK::execute ( Player * pPlayer ) 
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY
		
	GCLearnSkillOKHandler::execute( this , pPlayer );
		
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
// get packet's debug string
//
//////////////////////////////////////////////////////////////////////
string GCLearnSkillOK::toString () const
       throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "GCLearnSkillOK("
		<< "SkillType:" << (int)m_SkillType
		<< ",DomainType:" << (int)m_DomainType
		<< ")" ;
	return msg.toString();

	__END_CATCH
}


