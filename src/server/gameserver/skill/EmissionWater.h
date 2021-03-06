//////////////////////////////////////////////////////////////////////////////
// Filename    : EmissionWater.h 
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_EMISSION_WATER_HANDLER_H__
#define __SKILL_EMISSION_WATER_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class EmissionWater;
//////////////////////////////////////////////////////////////////////////////

class EmissionWater : public SkillHandler 
{
public:
	EmissionWater()  {}
	~EmissionWater()  {}
	
public:
    string getSkillHandlerName()  { return "EmissionWater"; }
	SkillType_t getSkillType()  { return SKILL_EMISSION_WATER; }

	void execute(Ousters* pOusters, ObjectID_t ObjectID,  OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern EmissionWater g_EmissionWater;

#endif // __SKILL_EMISSION_WATER_HANDLER_H__
