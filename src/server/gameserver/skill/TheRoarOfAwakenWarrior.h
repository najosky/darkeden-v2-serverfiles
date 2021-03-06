//////////////////////////////////////////////////////////////////////////////
// Filename    : Bless.h 
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_THE_ROAR_OF_AWAKEN_WARRIOR_HANDLER_H__
#define __SKILL_THE_ROAR_OF_AWAKEN_WARRIOR_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class Bless;
//////////////////////////////////////////////////////////////////////////////

class TheRoarOfAwakenWarrior : public SkillHandler 
{
public:
	TheRoarOfAwakenWarrior()  {}
	~TheRoarOfAwakenWarrior()  {}
	
public :
    string getSkillHandlerName()  { return "TheRoarOfAwakenWarrior"; }
	SkillType_t getSkillType()  { return SKILL_THE_ROAR_OF_AWAKEN_WARRIOR; }

	void execute(Slayer* pSlayer, SkillSlot* pSkillSlot, CEffectID_t CEffectID);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern TheRoarOfAwakenWarrior g_TheRoarOfAwakenWarrior;

#endif // __SKILL_BLESS_HANDLER_H__
