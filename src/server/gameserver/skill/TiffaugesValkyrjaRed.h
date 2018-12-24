//////////////////////////////////////////////////////////////////////////////
// Filename    : MultiAmputate.h 
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_TIFFAUGES_VALKYRJA_RED_HANDLER_H__
#define __SKILL_TIFFAUGES_VALKYRJA_RED_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class TiffaugesValkyrjaBlue;
//////////////////////////////////////////////////////////////////////////////

class TiffaugesValkyrjaRed : public SkillHandler 
{
public:
	TiffaugesValkyrjaRed() throw() {}
	~TiffaugesValkyrjaRed() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "TiffaugesValkyrjaRed"; }

	SkillType_t getSkillType() const throw() { return SKILL_TIFFAUGES_VALKYRJA_RED; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern TiffaugesValkyrjaRed g_TiffaugesValkyrjaRed;

#endif // __SKILL_MULTI_AMPUTATE_HANDLER_H__
