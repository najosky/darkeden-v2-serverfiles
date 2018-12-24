//////////////////////////////////////////////////////////////////////////////
// Filename    : Concealment.h 
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_TRUE_COLOR_OF_VAMP_LOAD_HANDLER_H__
#define __SKILL_TRUE_COLOR_OF_VAMP_LOAD_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class Concealment;
//////////////////////////////////////////////////////////////////////////////

class TrueColorofVampLoad : public SkillHandler 
{
public:
	TrueColorofVampLoad() throw() {}
	~TrueColorofVampLoad() throw() {}
	
public:
	string getSkillHandlerName() const throw() { return "TrueColorofVampLoad"; }
	SkillType_t getSkillType() const throw() { return SKILL_TRUE_COLOR_OF_VAMP_LOAD; }

	void execute(Vampire* pSlayer,  VampireSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern TrueColorofVampLoad g_TrueColorofVampLoad;

#endif // __SKILL_CONCEALMENT_HANDLER_H__
