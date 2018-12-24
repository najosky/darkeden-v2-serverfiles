//////////////////////////////////////////////////////////////////////////////
// Filename    : CLLogoutHandler.cpp
// Written By  : Reiot
// Description :
//////////////////////////////////////////////////////////////////////////////

// include files
#include "CGConnectSetKey.h"
#include "Assert.h"
#include "Player.h"
#ifdef __LOGIN_SERVER__
#endif

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void CGConnectSetKeyHandler::execute (CGConnectSetKey* pPacket , Player* pPlayer)
	 throw (ProtocolException , Error)
{
	__BEGIN_TRY __BEGIN_DEBUG_EX

	pPlayer->setKey(pPacket->getEncryptKey(), pPacket->getHashKey());
	//pPlayer->setKey(0 , 0);
	__END_DEBUG_EX __END_CATCH
}
