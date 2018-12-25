//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectRevealer.h
// Written by  : elca@ewestsoft.com
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_REVEALER__
#define __EFFECT_REVEALER__

#include "Effect.h"
#include "EffectLoader.h"

class Creature;
class Slayer;

//////////////////////////////////////////////////////////////////////////////
// class EffectRevealer
//////////////////////////////////////////////////////////////////////////////

class EffectRevealer : public Effect 
{
public:
	EffectRevealer(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass()  { return EFFECT_CLASS_REVEALER; }

	void affect() throw(Error){}
	void affect(Creature* pCreature) throw(Error);
	void affect(Zone* pZone, ZoneCoord_t x, ZoneCoord_t y, Object* pObject) throw(Error);

	void unaffect() throw(Error);
	void unaffect(Creature* pCreature) throw(Error);
	void unaffect(Item* pItem) throw(Error) {}
	void unaffect(Zone* pZone, ZoneCoord_t x, ZoneCoord_t y, Object* pObject) throw(Error);

	string toString() ;

	// 볼 수 있는 레벨 계산
public:
	void setSkillLevel( ExpLevel_t level ) throw() { m_SkillLevel = level; }

	bool canSeeHide( Creature* pTarget ) ;
	bool canSeeSniping( Creature* pTarget ) ;
	bool canSeeInvisibility( Creature* pTarget ) ;


private:
	ExpLevel_t m_SkillLevel;

};

#endif // __EFFECT_REVEALER__
