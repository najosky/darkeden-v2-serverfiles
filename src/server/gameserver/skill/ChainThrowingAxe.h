//////////////////////////////////////////////////////////////////////////////
// Filename    : ChainThrowingAxe.h 
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_CHAIN_THROWING_AXE_HANDLER_H__
#define __SKILL_CHAIN_THROWING_AXE_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class ChainThrowingAxe;
//////////////////////////////////////////////////////////////////////////////

class ChainThrowingAxe : public SkillHandler 
{
public:
	ChainThrowingAxe()  {}
	~ChainThrowingAxe()  {}
	
public:
    string getSkillHandlerName()  { return "ChainThrowingAxe"; }
	SkillType_t getSkillType()  { return SKILL_CHAIN_THROWING_AXE; }

	void execute(Monster*, ZoneCoord_t X, ZoneCoord_t Y);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern ChainThrowingAxe g_ChainThrowingAxe;

#endif // __SKILL_CHAIN_THROWING_AXE_HANDLER_H__
