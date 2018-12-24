//////////////////////////////////////////////////////////////////////////////
// Filename    : AcidStorm.h 
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_BAT_STORM_HANDLER_H__
#define __SKILL_BAT_STORM_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class AcidStorm;
//////////////////////////////////////////////////////////////////////////////

class BatStorm : public SkillHandler 
{
public:
	BatStorm() throw() {}
	~BatStorm() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "BatStorm"; }
	SkillType_t getSkillType() const throw() { return SKILL_BAT_STORM; }

	void execute(Vampire* pVampire, ObjectID_t ObjectID, VampireSkillSlot* pVampireSkillSlot, CEffectID_t CEffectID) throw(Error);
	void execute(Vampire* pVampire, ZoneCoord_t X, ZoneCoord_t Y, VampireSkillSlot* pVampireSkillSlot, CEffectID_t CEffectID) throw(Error);

	void execute(Monster* pMonster, ZoneCoord_t X, ZoneCoord_t Y) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern BatStorm g_BatStorm;

#endif // __SKILL_ACID_STORM_HANDLER_H__