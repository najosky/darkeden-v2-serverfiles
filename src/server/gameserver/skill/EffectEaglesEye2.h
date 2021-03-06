//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectConcealment.h
// Written by  : crazydog
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_EAGLES_EYE2__
#define __EFFECT_EAGLES_EYE2__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectConcealment
//////////////////////////////////////////////////////////////////////////////

class EffectEaglesEye2 : public Effect 
{
public:
	EffectEaglesEye2(Creature* pCreature);

public:
    EffectClass getEffectClass()  { return EFFECT_CLASS_EAGLES_EYE2; }

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
// class EffectEaglesEye1Loader
//////////////////////////////////////////////////////////////////////////////

class EffectEaglesEye2Loader : public EffectLoader 
{
public:
	virtual Effect::EffectClass getEffectClass()  { return Effect::EFFECT_CLASS_EAGLES_EYE2; }
	virtual string getEffectClassName()  { return "EffectEaglesEye2"; }

public:
	virtual void load(Creature* pCreature)  {}
};


#endif // __EFFECT_CONCEALMENT__
