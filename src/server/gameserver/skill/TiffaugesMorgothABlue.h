//////////////////////////////////////////////////////////////////////////////
// Filename    : AcidTouch.h 
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_TIFFAUGES_MORGOTH_A_BLUE_HANDLER_H__
#define __SKILL_TIFFAUGES_MORGOTH_A_BLUE_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class AcidTouch;
//////////////////////////////////////////////////////////////////////////////

class TiffaugesMorgothABlue: public SkillHandler 
{
public:
	TiffaugesMorgothABlue()  {}
	~TiffaugesMorgothABlue()  {}
	
public:
    string getSkillHandlerName()  { return "TiffaugesMorgothABlue"; }

	SkillType_t getSkillType()  { return SKILL_TIFFAUGES_MORGOTH_A_BLUE; }

	void execute(Monster* pMonster, Creature* pEnemy);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern TiffaugesMorgothABlue g_TiffaugesMorgothABlue;

#endif // __SKILL_ACID_TOUCH_HANDLER_H__
