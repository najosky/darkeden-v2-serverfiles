//////////////////////////////////////////////////////////////////////////////
// Filename    : Activation.h 
// Written By  : elca@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_ACTIVATION_HANDLER_H__
#define __SKILL_ACTIVATION_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class Activation;
//////////////////////////////////////////////////////////////////////////////

class Activation: public SkillHandler 
{
public:
	Activation()  {}
	~Activation()  {}
	
public:
    string getSkillHandlerName()  { return "Activation"; }
	SkillType_t getSkillType()  { return SKILL_ACTIVATION; }

	void execute(Slayer* pSlayer, SkillSlot* pSkillSlot, CEffectID_t CEffectID);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern Activation g_Activation;

#endif // __SKILL_ACTIVATION_HANDLER_H__
