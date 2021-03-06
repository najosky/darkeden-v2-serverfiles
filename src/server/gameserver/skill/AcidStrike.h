//////////////////////////////////////////////////////////////////////////////
// Filename    : AcidStrike.h 
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_ACID_STRIKE_HANDLER_H__
#define __SKILL_ACID_STRIKE_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class AcidStrike;
//////////////////////////////////////////////////////////////////////////////

class AcidStrike : public SkillHandler 
{
public:
	AcidStrike()  {}
	~AcidStrike()  {}
	
public:
    string getSkillHandlerName()  { return "AcidStrike"; }
	SkillType_t getSkillType()  { return SKILL_ACID_STRIKE; }

	void execute(Vampire* pVampire, ObjectID_t ObjectID,  VampireSkillSlot* pVampireSkillSlot, CEffectID_t CEffectID);
	void execute(Monster* pMonster, Creature* pEnemy);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern AcidStrike g_AcidStrike;

#endif // __SKILL_ACID_STRIKE_HANDLER_H__
