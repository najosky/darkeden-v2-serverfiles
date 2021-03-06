//////////////////////////////////////////////////////////////////////////////
// Filename    : AcidTouch.h 
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_TIFFAUGES_KRSNIK_A_RED_HANDLER_H__
#define __SKILL_TIFFAUGES_KRSNIK_A_RED_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class AcidTouch;
//////////////////////////////////////////////////////////////////////////////

class TiffaugesKrsnikARed: public SkillHandler 
{
public:
	TiffaugesKrsnikARed()  {}
	~TiffaugesKrsnikARed()  {}
	
public:
    string getSkillHandlerName()  { return "TiffaugesKrsnikARed"; }

	SkillType_t getSkillType()  { return SKILL_TIFFAUGES_KRSNIK_A_RED; }

	void execute(Monster* pMonster, Creature* pEnemy);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern TiffaugesKrsnikARed g_TiffaugesKrsnikARed;

#endif // __SKILL_ACID_TOUCH_HANDLER_H__
