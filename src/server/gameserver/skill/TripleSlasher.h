//////////////////////////////////////////////////////////////////////////////
// Filename    : TripleSlasher.h 
// Written By  : elca@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_TRIPLE_SLASHER_HANDLER_H__
#define __SKILL_TRIPLE_SLASHER_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class TripleSlasher;
//////////////////////////////////////////////////////////////////////////////

class TripleSlasher : public SkillHandler 
{
public:
	TripleSlasher()  {}
	~TripleSlasher()  {}
	
public:
    string getSkillHandlerName()  { return "TripleSlasher"; }
	SkillType_t getSkillType()  { return SKILL_TRIPLE_SLASHER; }

	void execute(Slayer* pSlayer, ObjectID_t ObjectID,  SkillSlot* pSkillSlot, CEffectID_t CEffectID);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern TripleSlasher g_TripleSlasher;

#endif // __SKILL_TRIPLE_SLASHER_HANDLER_H__
