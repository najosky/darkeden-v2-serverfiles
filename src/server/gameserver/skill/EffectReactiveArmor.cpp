//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectReactiveArmor.cpp
// Written by  : elca
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectReactiveArmor.h"
#include "Ousters.h"

#include "Gpackets/GCRemoveEffect.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectReactiveArmor::EffectReactiveArmor(Creature* pCreature)
	
{
	__BEGIN_TRY

	Assert(pCreature != NULL);
	Assert(pCreature->isOusters());

	setTarget(pCreature);
	m_DamageReduce = 0;

	__END_CATCH
}

void EffectReactiveArmor::affect()
	
{
	__BEGIN_TRY

	Creature* pCastCreature = dynamic_cast<Creature*>(m_pTarget);

	if ( pCastCreature == NULL || !pCastCreature->isOusters() || pCastCreature->isDead() ) return;

	Ousters* pOusters = dynamic_cast<Ousters*>(pCastCreature);
	Assert( pOusters != NULL );

	if (pOusters->getElementalEarth() < 13)
	{
		// 중간에 리스틀릿을 빼버리면 방어 효과가 사라진다.
		setDamageReduce(0);
		return;
	}

	setNextTime( 20 );

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectReactiveArmor::unaffect(Creature* pCreature)
	
{
	__BEGIN_TRY

	//cout << "EffectReactiveArmor" << "unaffect BEGIN" << endl;

	Assert(pCreature != NULL);
	Assert(pCreature->isOusters());

	// 플래그를 끈다.
	pCreature->removeFlag(Effect::EFFECT_CLASS_REACTIVE_ARMOR);

	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);

	Ousters* pTargetOusters = dynamic_cast<Ousters*>(pCreature);
	Assert( pTargetOusters != NULL );

	pTargetOusters->initAllStatAndSend();

	// 이펙트를 삭제하라고 알려준다.
	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID(pCreature->getObjectID());
	gcRemoveEffect.addEffectList(Effect::EFFECT_CLASS_REACTIVE_ARMOR);
	pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcRemoveEffect);

	//cout << "EffectReactiveArmor" << "unaffect END" << endl;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectReactiveArmor::unaffect()
	
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectReactiveArmor::toString()
	
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectReactiveArmor("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH

}

