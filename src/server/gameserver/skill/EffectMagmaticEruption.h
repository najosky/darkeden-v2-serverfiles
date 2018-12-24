//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectShadowOfStorm.h
// Written by  : elca@ewestsoft.com
// Description : �������� ShadowOfStorm�� Effect�� ó�����ֱ� ���� Ŭ�����̴�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_MAGMATIC_ERUPTION__
#define __EFFECT_MAGMATIC_ERUPTION__

#include "Effect.h"
#include <hash_map>

//////////////////////////////////////////////////////////////////////////////
// class EffectShadowOfStorm
//////////////////////////////////////////////////////////////////////////////

class EffectMagmaticEruption : public Effect 
{
public:
	EffectMagmaticEruption(Zone* pZone, ZoneCoord_t zoneX, ZoneCoord_t zoneY) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_MAGMATIC_EUPTION; }

	void affect() throw(Error);
	void unaffect() throw(Error);
	string toString() const throw();

public:
	int getDamage(void) const { return m_Damage; }
	void setDamage(int damage) { m_Damage = damage; }

	ObjectID_t getUserObjectID() const { return m_UserObjectID; }
	void setUserObjectID( ObjectID_t UserObjectID ) { m_UserObjectID = UserObjectID; }

	void checkPosition();

private:
	int     						m_Damage;
	ObjectID_t						m_UserObjectID;
	hash_map<ObjectID_t, TPOINT>	m_TargetPositions;
};

#endif // __EFFECT_SHADOW_OF_STORM__