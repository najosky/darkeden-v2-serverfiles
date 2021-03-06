//////////////////////////////////////////////////////////////////////////////
// Filename    : DoubleImpact.h 
// Written By  : elca@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_DOUBLE_IMPACT_HANDLER_H__
#define __SKILL_DOUBLE_IMPACT_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class DoubleImpact;
//////////////////////////////////////////////////////////////////////////////

class DoubleImpact : public SkillHandler 
{
public:
	DoubleImpact()  {}
	~DoubleImpact()  {}
	
public:
    string getSkillHandlerName()  { return "DoubleImpact"; }
	SkillType_t getSkillType()  { return SKILL_DOUBLE_IMPACT; }

	void execute(Slayer* pSlayer, ObjectID_t ObjectID,  SkillSlot* pSkillSlot, CEffectID_t CEffectID);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern DoubleImpact g_DoubleImpact;

#endif // __SKILL_DOUBLE_IMPACT_HANDLER_H__
