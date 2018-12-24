//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCAttackArmsOK3.cpp 
// Written By  : elca@ewestsoft.com
// Description : 자신에게 쓰는 기술의 성공을 알리기 위한 패킷 클래스의
//               멤버 정의.
// 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// include files
//////////////////////////////////////////////////////////////////////
#include "GCAttackArmsOK3.h"
#include "skill/Skill.h"



//////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////
GCAttackArmsOK3::GCAttackArmsOK3 ()
     throw ()
{
	__BEGIN_TRY

	m_SkillType = SKILL_ATTACK_ARMS;

	__END_CATCH
}

	
//////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////
GCAttackArmsOK3::~GCAttackArmsOK3 ()
    throw ()
{
	__BEGIN_TRY
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
//////////////////////////////////////////////////////////////////////
void GCAttackArmsOK3::read ( SocketInputStream & iStream )
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY
		
	// 최적화 작업시 실제 크기를 명시하도록 한다.
	iStream.read( m_SkillType );
	iStream.read( m_ObjectID );
//	iStream.read( m_TargetObjectID );
	iStream.read( m_X);
	iStream.read( m_Y );

	__END_CATCH
}

		    
//////////////////////////////////////////////////////////////////////
// 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
//////////////////////////////////////////////////////////////////////
void GCAttackArmsOK3::write ( SocketOutputStream & oStream )
     const throw ( ProtocolException , Error )
{
	__BEGIN_TRY
		
	// 최적화 작업시 실제 크기를 명시하도록 한다.
	oStream.write( m_SkillType );
	oStream.write( m_ObjectID );
//	oStream.write( m_TargetObjectID );
	oStream.write( m_X);
	oStream.write( m_Y);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
//
// execute packet's handler
//
//////////////////////////////////////////////////////////////////////
void GCAttackArmsOK3::execute ( Player * pPlayer ) 
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY
		
	GCAttackArmsOK3Handler::execute( this , pPlayer );
		
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
// get packet's debug string
//
//////////////////////////////////////////////////////////////////////
string GCAttackArmsOK3::toString () 
	const throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "GCAttackArmsOK3("
		<< "SkillType:" << (int)m_SkillType 
		<< "ObjectID:" << (int)m_ObjectID 
		<< ",TargetXY:" << (int)m_X << "," << (int)m_Y
		<< ")";
	return msg.toString();

	__END_CATCH
}
