//////////////////////////////////////////////////////////////////////////////
// Filename    : CrossGuard.h 
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_CROSS_GUARD_HANDLER_H__
#define __SKILL_CROSS_GUARD_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class CrossGuard;
//////////////////////////////////////////////////////////////////////////////

class CrossGuard : public SkillHandler 
{
public:
	CrossGuard()  {}
	~CrossGuard()  {}
	
public:
    string getSkillHandlerName()  { return "CrossGuard"; }
	SkillType_t getSkillType()  { return SKILL_CROSS_GUARD; }

	void execute(Ousters* pOusters,  OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern CrossGuard g_CrossGuard;

#endif // __SKILL_CROSS_GUARD_HANDLER_H__
