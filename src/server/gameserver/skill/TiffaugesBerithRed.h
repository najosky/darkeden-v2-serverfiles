//////////////////////////////////////////////////////////////////////////////
// Filename    : MentalSword.h 
// Written By  : elca@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_TIFFAUGES_BERITH_RED_HANDLER_H__
#define __SKILL_TIFFAUGES_BERITH_RED_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class MentalSword;
//////////////////////////////////////////////////////////////////////////////

class TiffaugesBerithRed : public SkillHandler 
{
public:
	TiffaugesBerithRed()  {}
	~TiffaugesBerithRed()  {}
	
public:
    string getSkillHandlerName()  { return "TiffaugesBerithRed"; }
	SkillType_t getSkillType()  { return SKILL_TIFFAUGES_BERITH_RED; }

	void execute(Monster* pMonster, Creature* pCreature);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern TiffaugesBerithRed g_TiffaugesBerithRed;

#endif // __SKILL_MENTAL_SWORD_HANDLER_H__
