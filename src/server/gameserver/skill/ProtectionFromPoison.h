//////////////////////////////////////////////////////////////////////////////
// Filename    : ProtectionFromPoison.h 
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_PROTECTION_FROM_POISON_HANDLER_H__
#define __SKILL_PROTECTION_FROM_POISON_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class ProtectionFromPoison;
//////////////////////////////////////////////////////////////////////////////

class ProtectionFromPoison: public SkillHandler 
{
public:
	ProtectionFromPoison()  {}
	~ProtectionFromPoison()  {}

public:
    string getSkillHandlerName()  { return "ProtectionFromPoison"; }
	SkillType_t getSkillType()  { return SKILL_PROTECTION_FROM_POISON; }

	void execute(Slayer* pSlayer, ObjectID_t TargetObjectID, SkillSlot* pSkillSlot, CEffectID_t CEffectID);
	void execute(Slayer* pSlayer, SkillSlot* pSkillSlot, CEffectID_t CEffectID);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern ProtectionFromPoison g_ProtectionFromPoison;

#endif // __SKILL_PROTECTION_FROM_POISON_HANDLER_H__
