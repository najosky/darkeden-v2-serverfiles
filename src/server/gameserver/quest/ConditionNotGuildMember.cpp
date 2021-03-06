////////////////////////////////////////////////////////////////////////////////
// Filename    : ConditionNotGuildMember.cpp
// Written By  : 
// Description :
////////////////////////////////////////////////////////////////////////////////

#include "ConditionNotGuildMember.h"
#include "PlayerCreature.h"

////////////////////////////////////////////////////////////////////////////////
// is satisfied?
////////////////////////////////////////////////////////////////////////////////
bool ConditionNotGuildMember::isSatisfied (Creature * pCreature1 , Creature * pCreature2, void* pParam) const 
	 
{ 
	Assert(pCreature2 != NULL);
	Assert(pCreature2->isPC());

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature2);

	// 길드 이름을 가져와서 없으면 길드원이 아니다
	if ( pPC->getGuildName().size() == 0 )
		return true;

	return false;
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
void ConditionNotGuildMember::read (PropertyBuffer & propertyBuffer) 
	
{
}

////////////////////////////////////////////////////////////////////////////////
	// get debug string
////////////////////////////////////////////////////////////////////////////////
string ConditionNotGuildMember::toString () const 
	 
{ 
	__BEGIN_TRY

	StringStream msg;
	msg << "ConditionNotGuildMember()"; 
	return msg.toString();

	__END_CATCH
}

