//////////////////////////////////////////////////////////////////////////////
// Filename    : SummonGoreGland.h 
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_SUMMON_GORE_GLAND_HANDLER_H__
#define __SKILL_SUMMON_GORE_GLAND_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class SummonGoreGland;
//////////////////////////////////////////////////////////////////////////////

class SummonGoreGland : public SkillHandler 
{
public:
	SummonGoreGland()  {}
	~SummonGoreGland()  {}
	
public:
    string getSkillHandlerName()  { return "SummonGoreGland"; }
	SkillType_t getSkillType()  { return SKILL_SUMMON_GORE_GLAND; }

	void execute(Vampire* pVampire, ZoneCoord_t X, ZoneCoord_t Y,  VampireSkillSlot* pVampireSkillSlot, CEffectID_t CEffectID);
	void execute(Vampire* pVampire, ObjectID_t,  VampireSkillSlot* pVampireSkillSlot, CEffectID_t CEffectID);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern SummonGoreGland g_SummonGoreGland;

#endif // __SKILL_SUMMON_GORE_GLAND_HANDLER_H__
