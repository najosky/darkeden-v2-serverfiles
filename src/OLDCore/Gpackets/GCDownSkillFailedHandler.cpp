//////////////////////////////////////////////////////////////////////
//
// Filename    : GCDownSkillFailed1Handler.cc
// Written By  : elca@ewestsoft.com
// Description :
//
//////////////////////////////////////////////////////////////////////

// include files
#include "GCDownSkillFailed.h"

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void GCDownSkillFailedHandler::execute ( GCDownSkillFailed * pGCDownSkillFailed , Player * pPlayer )
	 throw ( Error )
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
		
#if __TEST_CLIENT__

	//cout << pGCDownSkillFailed1->toString() << endl;
	
#elif __WINDOWS__
#endif

	__END_DEBUG_EX __END_CATCH
}
