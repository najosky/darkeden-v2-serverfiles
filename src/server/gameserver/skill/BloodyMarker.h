//////////////////////////////////////////////////////////////////////////////
// Filename    : BloodyMarker.h 
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_BLOODY_MARKER_HANDLER_H__
#define __SKILL_BLOODY_MARKER_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class BloodyMarker;
//////////////////////////////////////////////////////////////////////////////

class BloodyMarker: public SkillHandler 
{
public:
	BloodyMarker()  {}
	~BloodyMarker()  {}
	
public:
    string getSkillHandlerName()  { return "BloodyMarker"; }
	SkillType_t getSkillType()  { return SKILL_BLOODY_MARKER; }

	void execute(Vampire* pVampire, ObjectID_t TargetObjectID, CoordInven_t X, CoordInven_t Y, CoordInven_t TargetX, CoordInven_t TargetY, VampireSkillSlot* pVampireSkillSlot);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern BloodyMarker g_BloodyMarker;

#endif // __SKILL_BLOODY_MARKER_HANDLER_H__
