//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectPoisonMesh.h
// Written by  : elca@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_CHAIN_OF_DEMON_BACK__
#define __EFFECT_CHAIN_OF_DEMON_BACK__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectPoisonMesh
//////////////////////////////////////////////////////////////////////////////

class EffectChainOfDemonBack : public Effect 
{
public:
	EffectChainOfDemonBack(Creature* pCreature);

public:
    EffectClass getEffectClass()  { return EFFECT_CLASS_CHAIN_OF_DEMON_BACK; }

	void affect();
	void affect(Creature* pCreature);

	void unaffect();
	void unaffect(Creature* pCreature);

	string toString() ;

public:
	void		setCasterID( ObjectID_t objectID ) { m_CasterID = objectID; }
	ObjectID_t	getCasterID() const { return m_CasterID; }

	void		setDamage( Damage_t damage ) { m_Damage = damage; }
	Damage_t	getDamage() const { return m_Damage; }

private:
	ObjectID_t	m_CasterID;
	Damage_t	m_Damage;
};

#endif // __EFFECT_POISON_MESH__
