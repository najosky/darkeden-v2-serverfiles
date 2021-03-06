//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectIceOfSoulStone.h
// Written by  : crazydog
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_ICE_OF_SOUL_STONE__
#define __EFFECT_ICE_OF_SOUL_STONE__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectIceOfSoulStone
//////////////////////////////////////////////////////////////////////////////

class EffectIceOfSoulStone : public Effect 
{
public:
	EffectIceOfSoulStone(Creature* pCreature);

public:
    EffectClass getEffectClass()  { return EFFECT_CLASS_ICE_OF_SOUL_STONE; }

	void affect() {}

	void unaffect(Creature* pCreature);
	void unaffect();

	string toString() ;

};

#endif // __EFFECT_ICE_OF_SOUL_STONE__
