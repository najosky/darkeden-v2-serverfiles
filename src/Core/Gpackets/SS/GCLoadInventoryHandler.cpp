//////////////////////////////////////////////////////////////////////
//
// Filename    : GCAddEffectHandler.cc
// Written By  : elca@ewestsoft.com
// Description :
//
//////////////////////////////////////////////////////////////////////

// include files
#include "GCLoadInventory.h"

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void GCLoadInventoryHandler::execute ( GCLoadInventory * pGCLoadInventory , Player * pPlayer )
	 throw ( Error )
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
		
#ifdef __GAME_CLIENT__

	//cout << pGCAddEffect->toString() << endl;
	
#elif __WINDOWS__

#endif

	__END_DEBUG_EX __END_CATCH
}
