//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectGrandMasterSlayer.cpp
// Written by  : 쉭
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectGrandMasterSlayer.h"
#include "Creature.h"
#include "Slayer.h"
#include "Player.h"
#include "Zone.h"
#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCRemoveEffect.h"

#include <cstdio>

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectGrandMasterSlayer::EffectGrandMasterSlayer(Creature* pCreature)
	
{
	__BEGIN_TRY

	setTarget(pCreature);

	__END_CATCH
}

Effect::EffectClass EffectGrandMasterSlayer::getSendEffectClass() 
{
	Slayer* pSlayer = dynamic_cast<Slayer*>(m_pTarget);
	if ( pSlayer == NULL ) return getEffectClass();

	SkillLevel_t level = pSlayer->getHighestSkillDomainLevel();

	if ( level == 150 ) return Effect::EFFECT_CLASS_GRAND_MASTER_SLAYER_150;
	else if ( level >= 130 ) return Effect::EFFECT_CLASS_GRAND_MASTER_SLAYER_130;
	else return getEffectClass();
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGrandMasterSlayer::affect()
	
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature*>(m_pTarget);
	affect( pCreature );

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGrandMasterSlayer::affect(Creature* pCreature)
	
{
	__BEGIN_TRY

	Assert(pCreature->isSlayer());
	setNextTime(60);
	setDeadline(999999);

			Statement* pStmt;
			BEGIN_DB
			{
				pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
				pStmt->executeQuery( "UPDATE `Slayer` SET `PlayTime` = %d where Name = '%s'",pCreature->getName().c_str(),600);
			SAFE_DELETE(pStmt);
			}
			END_DB(pStmt)

	if(!pCreature->isFlag(Effect::EFFECT_CLASS_GRAND_MASTER_SLAYER)){
	pCreature->setFlag(Effect::EFFECT_CLASS_GRAND_MASTER_SLAYER);

	// 주위에 뿌려준다.
	GCAddEffect gcAddEffect;
	gcAddEffect.setObjectID(pCreature->getObjectID());
	gcAddEffect.setEffectID(getSendEffectClass());
	gcAddEffect.setDuration(999999);
	pCreature->getZone()->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcAddEffect);
	}

	__END_CATCH
}

void EffectGrandMasterSlayer::unaffect() 
	
{
	__BEGIN_TRY	

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGrandMasterSlayer::unaffect(Creature* pCreature)
	
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	//cout << "EffectGrandMasterSlayer" << "unaffect BEGIN" << endl;

	Assert(pCreature != NULL);

	// 능력치를 정상적으로 되돌리기 위해서는 플래그를 끄고,
	// initAllStat을 불러야 한다.
	pCreature->removeFlag(Effect::EFFECT_CLASS_GRAND_MASTER_SLAYER);

	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);

	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID(pCreature->getObjectID());
	gcRemoveEffect.addEffectList(Effect::EFFECT_CLASS_GRAND_MASTER_SLAYER);
	pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcRemoveEffect);

	//cout << "EffectGrandMasterSlayer" << "unaffect END" << endl;

	__END_DEBUG
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectGrandMasterSlayer::toString()
	
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectGrandMasterSlayer("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
}
