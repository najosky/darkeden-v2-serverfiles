//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectEnergyDropToCreature.h
// Written by  : ��ȫâ
// Date        : 2002. 3. 28
//
// Description : EffectEnergyDropToCreature�� ���濡�� 3���� ���� Ÿ����
//               �ִ� ����Ʈ�̴�. 
//               Effect �ø���� Tick�� deadline�� ����ؼ� ������ ������
//               �� �� �ֵ��� �����Ǿ��� ������ �ٸ� ����� Effect
//               �� �״�� �����ͼ� ����� �� �ִ�.
//               ���� EffectEnergyDropToCreature�� EffectPoison�� ���� ���·�
//               �Ǿ� �ִ�.
//
//               EffectEnergyDropToCreature�� ���Ǳ� ���ؼ���
//               Effect.h ���Ͽ� 
//                EFFECT_CLASS_METEO_BLAZE_TO_CREATURE
//               �� ���ǵǾ� �־�� �Ѵ�. 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_METEO_BLAZE_TO_CREATURE__
#define __EFFECT_METEO_BLAZE_TO_CREATURE__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectEnergyDropToCreature
//////////////////////////////////////////////////////////////////////////////

class EffectMeteoBlazeToCreature : public Effect 
{
public:
	EffectMeteoBlazeToCreature(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_METEO_BLAZE_TO_CREATURE; }

	void affect() throw(Error);
	void affect(Creature* pCreature) throw(Error);
	void affect(Zone* pZone, ZoneCoord_t x, ZoneCoord_t y, Object* pObject) throw(Error);

	void unaffect() throw(Error);
	void unaffect(Creature* pCreature) throw(Error);
	void unaffect(Item* pItem) throw(Error) {}
	void unaffect(Zone* pZone, ZoneCoord_t x, ZoneCoord_t y, Object* pObject) throw(Error);

	string toString() const throw();

public:
//	string getCasterName(void) const { return m_CasterName; }
//	void setCasterName(const string & CasterName ) { m_CasterName = CasterName; }

//	int getPartyID(void) const { return m_PartyID; }
//	void setPartyID(int PartyID) { m_PartyID = PartyID; }

	ObjectID_t getUserObjectID() const { return m_UserObjectID; }
	void setUserObjectID( ObjectID_t UserObjectID ) { m_UserObjectID = UserObjectID; }

	Level_t getLevel() const throw() { return m_Level; }
	void setLevel(Level_t Level) throw() { m_Level = Level; }

	HP_t getPoint() const throw() { return m_Point; }
	void setPoint(HP_t Point) throw() { m_Point = Point; }

	void setTick(Turn_t Tick) throw() { m_Tick = Tick; }
	Turn_t getTick() const throw() { return m_Tick; }

private:
//	string  m_CasterName;
//	int     m_PartyID;
	ObjectID_t	m_UserObjectID;
	Level_t		m_Level;
	HP_t		m_Point;
	Turn_t		m_Tick;
};

#endif // __EFFECT_STORM__