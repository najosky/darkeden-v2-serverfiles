//////////////////////////////////////////////////////////////////////////////
// Filename    : IllusionInversion.h 
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_SPECTOR_INVERSE_HANDLER_H__
#define __SKILL_SPECTOR_INVERSE_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class IllusionInversion;
//////////////////////////////////////////////////////////////////////////////

class SpectorInverse : public SkillHandler 
{
public:
	SpectorInverse()  {}
	~SpectorInverse()  {}
	
public:
    string getSkillHandlerName()  { return "SpectorInverse"; }

	SkillType_t getSkillType()  { return SKILL_SPECTOR_INVERSE; }

	void execute(Slayer* pSlayer, ObjectID_t ObjectID, SkillSlot* pSkillSlot, CEffectID_t CEffectID);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern SpectorInverse g_SpectorInverse;

#endif // __SKILL_ILLUSION_INVERSION_HANDLER_H__
