//////////////////////////////////////////////////////////////////////////////
// Filename    : SharpChakram.h 
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_SHARP_CHAKRAM_HANDLER_H__
#define __SKILL_SHARP_CHAKRAM_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class SharpChakram;
//////////////////////////////////////////////////////////////////////////////

class SharpChakram : public SkillHandler 
{
public:
	SharpChakram()  {}
	~SharpChakram()  {}
	
public:
    string getSkillHandlerName()  { return "SharpChakram"; }
	SkillType_t getSkillType()  { return SKILL_SHARP_CHAKRAM; }

	void execute(Ousters* pOusters,  OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern SharpChakram g_SharpChakram;

#endif // __SKILL_SHARP_CHAKRAM_HANDLER_H__
