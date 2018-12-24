//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectParalyze.h
// Written by  : elca@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_FREEZE_RING1__
#define __EFFECT_FREEZE_RING1__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectParalyze
//////////////////////////////////////////////////////////////////////////////

class EffectFreezeRing1 : public Effect 
{
public:
	EffectFreezeRing1(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_FREEZE_RING1; }

	void affect() throw(Error);
	void affect(Creature* pCreature) throw(Error);

	void unaffect() throw(Error);
	void unaffect(Creature* pCreature) throw(Error);

	string toString() const throw();

public:
	Level_t getLevel() const throw() { return m_Level; }
	void setLevel(Level_t level) throw() { m_Level = level; }

//	int getDefensePenalty(void) const throw() { return m_DefensePenalty; }
//	void setDefensePenalty(int penalty) { m_DefensePenalty = penalty; }
	
private:
	Level_t  m_Level;
//	int     m_DefensePenalty;
};

#endif // __EFFECT_PARALYZE__