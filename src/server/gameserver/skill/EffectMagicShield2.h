//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectConcealment.h
// Written by  : crazydog
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_MAGIC_SHIELD2__
#define __EFFECT_MAGIC_SHIELD2__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectConcealment
//////////////////////////////////////////////////////////////////////////////

class EffectMagicShield2 : public Effect 
{
public:
	EffectMagicShield2(Creature* pCreature);

public:
    EffectClass getEffectClass()  { return EFFECT_CLASS_MAGIC_SHIELD2; }

	void affect() {}

	void unaffect(Creature* pCreature);
	void unaffect();

	string toString() ;

public:
	void setLevel( SkillLevel_t level ) { m_SkillLevel = level; }
	SkillLevel_t getLevel() const { return m_SkillLevel; }

private:
	SkillLevel_t	m_SkillLevel;
};

//////////////////////////////////////////////////////////////////////////////
// class EffectMagicShield2Loader
//////////////////////////////////////////////////////////////////////////////

class EffectMagicShield2Loader : public EffectLoader 
{
public:
	virtual Effect::EffectClass getEffectClass()  { return Effect::EFFECT_CLASS_MAGIC_SHIELD2; }
	virtual string getEffectClassName()  { return "EffectMagicShield2"; }

public:
	virtual void load(Creature* pCreature)  {}
};


#endif // __EFFECT_CONCEALMENT__
