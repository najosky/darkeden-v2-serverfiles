//////////////////////////////////////////////////////////////////////////////
// Filename    : CLChangeServer.cpp 
// Written By  : reiot@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "CLChangeServer.h"

void CLChangeServer::read (SocketInputStream & iStream) 
	 
{
	__BEGIN_TRY

	iStream.read(m_ServerGroupID);

	__END_CATCH
}

void CLChangeServer::write (SocketOutputStream & oStream) const 
     
{
	__BEGIN_TRY
	
	oStream.write(m_ServerGroupID);

	__END_CATCH
}

void CLChangeServer::execute (Player* pPlayer) 
	 
{
	__BEGIN_TRY
		
	CLChangeServerHandler::execute (this , pPlayer);
		
	__END_CATCH
}

