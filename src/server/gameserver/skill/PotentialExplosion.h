//////////////////////////////////////////////////////////////////////////////
// Filename    : PotentialExplosion.h 
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_POTENTIAL_EXPLOSION_HANDLER_H__
#define __SKILL_POTENTIAL_EXPLOSION_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class PotentialExplosion;
//////////////////////////////////////////////////////////////////////////////

class PotentialExplosion : public SkillHandler 
{
public:
	PotentialExplosion()  {}
	~PotentialExplosion()  {}

public:
    string getSkillHandlerName()  { return "PotentialExplosion"; }
	SkillType_t getSkillType()  { return SKILL_POTENTIAL_EXPLOSION; }

	void execute(Slayer* pSlayer, SkillSlot* pSkillSlot, CEffectID_t CEffectID);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern PotentialExplosion g_PotentialExplosion;

#endif // __SKILL_POTENTIAL_EXPLOSION_HANDLER_H__
