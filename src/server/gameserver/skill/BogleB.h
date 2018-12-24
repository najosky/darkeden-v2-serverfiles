//////////////////////////////////////////////////////////////////////////////
// Filename    : TalonOfCrow.h 
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_BOGLE_B_HANDLER_H__
#define __SKILL_BOGLE_B_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class TalonOfCrow;
//////////////////////////////////////////////////////////////////////////////

class BogleB: public SkillHandler 
{
public:
	BogleB() throw() {}
	~BogleB() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "BogleB"; }
	SkillType_t getSkillType() const throw() { return SKILL_BOGLE_B; }

	void execute(Vampire* pVampire, ObjectID_t targetObject, VampireSkillSlot* pVampireSkillSlot, CEffectID_t CEffectID) throw(Error);
	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern BogleB g_BogleB;

#endif // __SKILL_BOGLE_B_HANDLER_H__