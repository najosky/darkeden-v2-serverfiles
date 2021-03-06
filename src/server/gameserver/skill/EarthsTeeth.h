//////////////////////////////////////////////////////////////////////////////
// Filename    : EarthsTeeth.h 
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_EARTHS_TEETH_HANDLER_H__
#define __SKILL_EARTHS_TEETH_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class EarthsTeeth;
//////////////////////////////////////////////////////////////////////////////

class EarthsTeeth : public SkillHandler 
{
public:
	EarthsTeeth()  {}
	~EarthsTeeth()  {}
	
public:
    string getSkillHandlerName()  { return "EarthsTeeth"; }
	SkillType_t getSkillType()  { return SKILL_EARTHS_TEETH; }

	void execute(Ousters* pOusters, ObjectID_t ObjectID,  OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern EarthsTeeth g_EarthsTeeth;

#endif // __SKILL_EARTHS_TEETH_HANDLER_H__
