//////////////////////////////////////////////////////////////////////////////
// Filename    : Blunting.h 
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_BLUNTING_HANDLER_H__
#define __SKILL_BLUNTING_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class Blunting;
//////////////////////////////////////////////////////////////////////////////

class Blunting : public SkillHandler 
{
public:
	Blunting()  {}
	~Blunting()  {}
	
public:
    string getSkillHandlerName()  { return "Blunting"; }
	SkillType_t getSkillType()  { return SKILL_BLUNTING; }

	void execute(Ousters* pOusters, ObjectID_t ObjectID, OustersSkillSlot* pSkillSlot, CEffectID_t CEffectID);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern Blunting g_Blunting;

#endif // __SKILL_BLUNTING_HANDLER_H__
