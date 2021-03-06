//////////////////////////////////////////////////////////////////////////////
// Filename    : RottenApple.h 
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_ROTTEN_APPLE_HANDLER_H__
#define __SKILL_ROTTEN_APPLE_HANDLER_H__

#include "SkillHandler.h"
#include "Creature.h"
//////////////////////////////////////////////////////////////////////////////
// class RottenApple;
//////////////////////////////////////////////////////////////////////////////

class RottenApple : public SkillHandler 
{
public:
	RottenApple()  {}
	~RottenApple()  {}
	
public :
    string getSkillHandlerName()  { return "RottenApple"; }
	SkillType_t getSkillType()  { return SKILL_ROTTEN_APPLE; }

	void execute(Slayer* pSlayer, ObjectID_t ObjectID,  SkillSlot* pSkillSlot, CEffectID_t CEffectID);
	void execute(Slayer* pSlayer, ZoneCoord_t X, ZoneCoord_t Y, SkillSlot* pSkillSlot, CEffectID_t CEffectID);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern RottenApple g_RottenApple;

#endif // __SKILL_ROTTEN_APPLE_HANDLER_H__
