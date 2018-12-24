//////////////////////////////////////////////////////////////////////////////
// Filename    : CGSkillToSelfHandler.cc
// Written By  : elca@ewestsoft.com
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "CGSkillToSelf.h"

#ifdef __GAME_SERVER__
	#include "GamePlayer.h"
	#include "SkillHandlerManager.h"
	#include "ZoneUtil.h"
	#include "RelicUtil.h"
	#include "PlayerCreature.h"
	#include "skill/Sniping.h"
	#include "Effect.h"
	#include "Gpackets/GCSkillFailed1.h"

	// BurstExp
		#include "EffectSevenFoldStone.h"
		#include "Gpackets/GCAddEffect.h"
	//#define __PROFILE_SKILLS__

	#ifdef __PROFILE_SKILLS__
		#include "Profile.h"
	#endif
#endif	// __GAME_SERVER__

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void CGSkillToSelfHandler::execute (CGSkillToSelf* pPacket , Player* pPlayer)
	 throw (Error)
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
		
#ifdef __GAME_SERVER__

	Assert(pPacket != NULL);
	Assert(pPlayer != NULL);

	try 
	{
		bool BurstExp = false;

		GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPlayer);
		Assert(pGamePlayer != NULL);	// by sigi

		if (pGamePlayer->getPlayerStatus() != GPS_NORMAL) return;

		Creature* pCreature = pGamePlayer->getCreature();
		Assert(pCreature != NULL);	// by sigi

		PlayerCreature* pPC          = dynamic_cast<PlayerCreature*>(pCreature);
		Assert(pPC != NULL);	// by sigi

		Zone* pZone = pCreature->getZone();
		Assert(pZone != NULL);

		SkillType_t SkillType = pPacket->getSkillType();

		if(SkillType >= 9997)	BurstExp = true;

		cout << " 여기까진 실행되어짐 " << endl;
		// 완전 안전지대라면 기술 사용 불가. by sigi. 2002.11.14
		ZoneLevel_t ZoneLevel = pZone->getZoneLevel(pCreature->getX(), pCreature->getY());
		if (ZoneLevel & COMPLETE_SAFE_ZONE)
		{
			GCSkillFailed1 _GCSkillFailed1;
			_GCSkillFailed1.setSkillType(SkillType);
			pPlayer->sendPacket(&_GCSkillFailed1);

			return;
		}
	
		disableFlags( pCreature, pZone, SkillType);
	if(!BurstExp){
		if (pCreature->isSlayer()) 
		{
			Slayer*    pSlayer    = dynamic_cast<Slayer*>(pCreature);
			SkillSlot* pSkillSlot = ((Slayer *)pCreature)->hasSkill(SkillType);
			bool       bSuccess   = true;

			if (pSkillSlot == NULL) bSuccess = false;
			if (!isAbleToUseSelfSkill(pSlayer, SkillType)) bSuccess = false;

/*			if (pSlayer->isFlag(Effect::EFFECT_CLASS_SNIPING_MODE))
			{
				g_Sniping.checkRevealRatio(pSlayer, 20, 10);
			} */

			// UN_TRANSFORM 인 경우 -_- 혼자 딴 핸들러 가지고 논다 ~_~
			if (SkillType == SKILL_UN_TRANSFORM)
			{
				if (pSlayer->isFlag(Effect::EFFECT_CLASS_INSTALL_TURRET) )
				{
					SkillHandler* pSkillHandler = g_pSkillHandlerManager->getSkillHandler(SKILL_UN_TRANSFORM);
					Assert(pSkillHandler != NULL);
					pSkillHandler->execute(pSlayer, NULL, (CEffectID_t)0);
					return;
				}
			}

			if (bSuccess) 
			{
				SkillHandler* pSkillHandler = g_pSkillHandlerManager->getSkillHandler(SkillType);
				Assert(pSkillHandler != NULL);

				#ifdef __PROFILE_SKILLS__
					beginProfileEx(SkillTypes2String[SkillType]);
					pSkillHandler->execute(pSlayer, pSkillSlot, pPacket->getCEffectID());
					endProfileEx(SkillTypes2String[SkillType]);
				#else
					pSkillHandler->execute(pSlayer, pSkillSlot, pPacket->getCEffectID());
				#endif
			 }
			 else
			 {
				 GCSkillFailed1 _GCSkillFailed1;
				_GCSkillFailed1.setSkillType(SkillType);
				 pPlayer->sendPacket(&_GCSkillFailed1);
			 }
		} 
		else if (pCreature->isVampire()) 
		{
		cout << " 여기까진 실행되어짐 2" << endl;
			Vampire*          pVampire          = dynamic_cast<Vampire*>(pCreature);
			VampireSkillSlot* pVampireSkillSlot = ((Vampire *)pCreature)->hasSkill(SkillType);
			bool              bSuccess          = true;

			if ((SkillType == SKILL_TRANSFORM_TO_BAT || SkillType == SKILL_TRANSFORM_TO_WOLF)
				 && (pVampire->hasRelicItem() || pVampire->isFlag( Effect::EFFECT_CLASS_HAS_FLAG ) || pVampire->isFlag( Effect::EFFECT_CLASS_HAS_SWEEPER) ))
			{
				cout << "성물을 가진 상태에서는 변신할 수 없습니다" << endl;

				GCSkillFailed1 _GCSkillFailed1;
				_GCSkillFailed1.setSkillType(SkillType);
				pPlayer->sendPacket(&_GCSkillFailed1);
				return;
			}

		cout << " 여기까진 실행되어짐 3" << endl;

			if (SkillType == SKILL_UN_INVISIBILITY && pVampire->isFlag(Effect::EFFECT_CLASS_INVISIBILITY))
			{
				addVisibleCreature(pZone, pVampire, true);
				return;
			}
/*			if (SkillType == SKILL_HOWL && pVampire->isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_WOLF)) 
			{
				SkillHandler* pSkillHandler = g_pSkillHandlerManager->getSkillHandler(SKILL_HOWL);
				Assert(pSkillHandler != NULL);
				pSkillHandler->execute(pVampire, pVampireSkillSlot, pPacket->getCEffectID());
				return;
			} */
			if (SkillType == SKILL_UN_TRANSFORM)
			{
				if (pVampire->isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_WOLF) || pVampire->isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_BAT)
					|| pVampire->isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_WERWOLF) )
				{
		cout << " 여기까진 실행되어짐 4" << endl;
					SkillHandler* pSkillHandler = g_pSkillHandlerManager->getSkillHandler(SKILL_UN_TRANSFORM);
					Assert(pSkillHandler != NULL);
					pSkillHandler->execute(pVampire);
					return;
				}
			}
			if (SkillType == SKILL_OPEN_CASKET && pVampire->isFlag(Effect::EFFECT_CLASS_CASKET)) 
			{
				//cout << "OpenCasket" << endl;
				SkillHandler* pSkillHandler = g_pSkillHandlerManager->getSkillHandler(SKILL_OPEN_CASKET);
				Assert(pSkillHandler != NULL);
				pSkillHandler->execute(pVampire, pVampireSkillSlot, pPacket->getCEffectID());
				return;
			}
		cout << " 여기까진 실행되어짐 6" << endl;

			//cout << "SkillType:" << (int)SkillType << endl;


			if (pVampireSkillSlot == NULL) bSuccess = false;
			if (!isAbleToUseSelfSkill(pVampire, SkillType)) bSuccess = false;
		cout << " 여기까진 실행되어짐 7" << endl;
			if (bSuccess) 
			{
		cout << " 여기까진 실행되어짐 8" << endl;
				SkillHandler* pSkillHandler = g_pSkillHandlerManager->getSkillHandler(SkillType);
				Assert(pSkillHandler != NULL);
		cout << " 여기까진 실행되어짐 9" << endl;

				#ifdef __PROFILE_SKILLS__
					beginProfileEx(SkillTypes2String[SkillType]);
					pSkillHandler->execute(pVampire, pVampireSkillSlot, pPacket->getCEffectID());
					endProfileEx(SkillTypes2String[SkillType]);
				#else
					pSkillHandler->execute(pVampire, pVampireSkillSlot, pPacket->getCEffectID());
				#endif
		cout << " 여기까진 실행되어짐 10" << endl;
			}
			else
			{
				GCSkillFailed1 _GCSkillFailed1;
				_GCSkillFailed1.setSkillType(SkillType);
				pPlayer->sendPacket(&_GCSkillFailed1);
			}
		} 
		else if (pCreature->isOusters()) 
		{
			Ousters*          pOusters          = dynamic_cast<Ousters*>(pCreature);
			OustersSkillSlot* pOustersSkillSlot = ((Ousters *)pCreature)->hasSkill(SkillType);
			bool              bSuccess          = true;

			// UN_TRANSFORM 인 경우 -_- 혼자 딴 핸들러 가지고 논다 ~_~
			if (SkillType == SKILL_UN_TRANSFORM)
			{
				if (pOusters->isFlag(Effect::EFFECT_CLASS_SUMMON_SYLPH) )
				{
					SkillHandler* pSkillHandler = g_pSkillHandlerManager->getSkillHandler(SKILL_UN_TRANSFORM);
					Assert(pSkillHandler != NULL);
					pSkillHandler->execute(pOusters);
					return;
				}
			}

			if (pOustersSkillSlot == NULL) bSuccess = false;
			if (!isAbleToUseSelfSkill(pOusters, SkillType)) bSuccess = false;

			if (bSuccess) 
			{
				SkillHandler* pSkillHandler = g_pSkillHandlerManager->getSkillHandler(SkillType);
				Assert(pSkillHandler != NULL);

				#ifdef __PROFILE_SKILLS__
					beginProfileEx(SkillTypes2String[SkillType]);
					pSkillHandler->execute(pOusters, pOustersSkillSlot, pPacket->getCEffectID());
					endProfileEx(SkillTypes2String[SkillType]);
				#else
					pSkillHandler->execute(pOusters, pOustersSkillSlot, pPacket->getCEffectID());
				#endif
			}
			else
			{
				GCSkillFailed1 _GCSkillFailed1;
				_GCSkillFailed1.setSkillType(SkillType);
				pPlayer->sendPacket(&_GCSkillFailed1);
			}
		}
	}

	if(BurstExp){

	int	EffectID;

	if(SkillType == 9999) EffectID = Effect::EFFECT_CLASS_ATTACK_BLOOD_BURST;
	if(SkillType == 9998) EffectID = Effect::EFFECT_CLASS_DEFENSE_BLOOD_BURST;
	if(SkillType == 9997) EffectID = Effect::EFFECT_CLASS_PARTY_BLOOD_BURST;
	bool bEffected   = pCreature->isFlag((Effect::EffectClass)EffectID);
	if(bEffected){
	GCSkillFailed1 _GCSkillFailed1;
	_GCSkillFailed1.setSkillType(0);
	pPlayer->sendPacket(&_GCSkillFailed1);
		return;
	}
		if (pCreature->isSlayer()) 
		{
			Slayer*    pSlayer    = dynamic_cast<Slayer*>(pCreature);
			Assert(pSlayer != NULL);	// by sigi

			GCModifyInformation gcFameMI;

			if(SkillType == 9999)
			{
			pSlayer->setAttackBloodBurstPoint(0);
			gcFameMI.addLongData( MODIFY_ATTACK_BLOOD_BURST_POINT, pSlayer->getAttackBloodBurstPoint() );
			}
			if(SkillType == 9998){
			pSlayer->setDefenseBloodBurstPoint(0);
			gcFameMI.addLongData( MODIFY_DEFENSE_BLOOD_BURST_POINT, pSlayer->getDefenseBloodBurstPoint() );
			}
			if(SkillType == 9997){
			pSlayer->setPartyBloodBurstPoin(0);
			gcFameMI.addLongData( MODIFY_PARTY_BLOOD_BURST_POINT, pSlayer->getPartyBloodBurstPoint() );
			}
			pSlayer->saveExps();
			pCreature->getPlayer()->sendPacket( &gcFameMI );
		}
		else if (pCreature->isVampire()) 
		{
			Vampire*          pVampire          = dynamic_cast<Vampire*>(pCreature);
			Assert( pVampire != NULL);	// by sigi

			GCModifyInformation gcFameMI;

			if(SkillType == 9999)
			{
			pVampire->setAttackBloodBurstPoint(0);
			gcFameMI.addLongData( MODIFY_ATTACK_BLOOD_BURST_POINT, pVampire->getAttackBloodBurstPoint() );
			}
			if(SkillType == 9998){
			pVampire->setDefenseBloodBurstPoint(0);
			gcFameMI.addLongData( MODIFY_DEFENSE_BLOOD_BURST_POINT, pVampire->getDefenseBloodBurstPoint() );
			}
			if(SkillType == 9997){
			pVampire->setPartyBloodBurstPoin(0);
			gcFameMI.addLongData( MODIFY_PARTY_BLOOD_BURST_POINT, pVampire->getPartyBloodBurstPoint() );
			}
			pVampire->saveExps();
			pCreature->getPlayer()->sendPacket( &gcFameMI );
		}
		else if (pCreature->isOusters()) 
		{
			Ousters*          pOusters          = dynamic_cast<Ousters*>(pCreature);
			Assert(pOusters != NULL);	// by sigi

			GCModifyInformation gcFameMI;

			if(SkillType == 9999)
			{
			pOusters->setAttackBloodBurstPoint(0);
			gcFameMI.addLongData( MODIFY_ATTACK_BLOOD_BURST_POINT, pOusters->getAttackBloodBurstPoint() );
			}
			if(SkillType == 9998){
			pOusters->setDefenseBloodBurstPoint(0);
			gcFameMI.addLongData( MODIFY_DEFENSE_BLOOD_BURST_POINT, pOusters->getDefenseBloodBurstPoint() );
			}
			if(SkillType == 9997){
			pOusters->setPartyBloodBurstPoin(0);
			gcFameMI.addLongData( MODIFY_PARTY_BLOOD_BURST_POINT, pOusters->getPartyBloodBurstPoint() );
			}
			pOusters->saveExps();
			pCreature->getPlayer()->sendPacket( &gcFameMI );
		}

	EffectSevenFoldStone* pEffect = new EffectSevenFoldStone( pPC );

	VSDateTime current = VSDateTime::currentDateTime().addSecs(600);

	VSDateTime MagiccurrentTime = VSDateTime::currentDateTime();
	int diffSecs = MagiccurrentTime.secsTo( current );

	pEffect->setDeadline( (DWORD)diffSecs*10 );
	pEffect->setFeedTime( current );
	pEffect->setLevel( EffectID );
	pEffect->setEffectType( EffectID );
	pEffect->setHeroOption(0);
	pEffect->create(pPC->getName());

	pPC->addEffect( pEffect );
	pPC->setFlag( pEffect->getEffectClass() );

	GCAddEffect gcAddEffect;
	gcAddEffect.setObjectID( pPC->getObjectID() );
	gcAddEffect.setEffectID( pEffect->getSendEffectClass() );
	gcAddEffect.setDuration( (DWORD)diffSecs*10 );
	pZone->broadcastPacket( pPC->getX(), pPC->getY(), &gcAddEffect );

	GCSkillFailed1 _GCSkillFailed1;
	_GCSkillFailed1.setSkillType(0);
	pPlayer->sendPacket(&_GCSkillFailed1);

	} 

	} 
	catch (Throwable & t) 
	{
		//cout << t.toString() << endl;
	}

#endif	// __GAME_SERVER__
		
	__END_DEBUG_EX __END_CATCH
}

