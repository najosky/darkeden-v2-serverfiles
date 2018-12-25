//////////////////////////////////////////////////////////////////////
// 
// Filename    : WarInfo.cpp 
// Written By  : 
// Description : 
// 
//////////////////////////////////////////////////////////////////////

// include files
#include "LevelWarInfo.h"

//////////////////////////////////////////////////////////////////////
// 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
//////////////////////////////////////////////////////////////////////
void LevelWarInfo::read ( SocketInputStream & iStream ) 
{
	__BEGIN_TRY

	iStream.read( m_Level );
	WarInfo::read( iStream );

	__END_CATCH
}

		    
//////////////////////////////////////////////////////////////////////
// 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
//////////////////////////////////////////////////////////////////////
void LevelWarInfo::write ( SocketOutputStream & oStream ) 
{
	__BEGIN_TRY

	oStream.write( m_Level );
	WarInfo::write( oStream );

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
// get debug string
//////////////////////////////////////////////////////////////////////
string LevelWarInfo::toString () 
{
	StringStream msg;

	msg << "LevelWarInfo("
		<< "Level: " << m_Level
		<< ",RemainTime:" << (int)m_RemainTime
		<< ")";

	return msg.toString();
}

