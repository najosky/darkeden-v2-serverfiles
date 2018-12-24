/////////////////////////////////////////////////////////////////////////////
// DynamicZoneOustersMirrorOfAbyss.cpp
/////////////////////////////////////////////////////////////////////////////

#include "DynamicZoneBossRoom2.h"
#include "DynamicZoneInfo.h"
#include "Zone.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
#include "Monster.h"
#include "PCManager.h"
#include "MonsterManager.h"
#include "EffectKillTimer.h"
#include "GQuestManager.h"
#include "Assert.h"
#include "PlayerCreature.h"
#include "Player.h"
#include "Timeval.h"
#include "InstantDungeonMonster.h"
#include "Gpackets/GCSystemMessage.h"
#include "Gpackets/GCNoticeEvent.h"

#include <stdio.h>
#include <stdlib.h>

enum OUSTERS_MIRROR_OF_ABYSS
{
	WAIT_FOR_PC,
	ADD_MONO,
	WAIT_FOR_COMPLETE,
	CLEAR_MONO,
	WAIT_FOR_CLEAR,
	OUSTERS_MIRROR_OF_ABYSS_END,

	OUSTERS_MIRROR_OF_ABYSS_MAX
};

DynamicZoneBossRoom2::DynamicZoneBossRoom2()
{
	m_MonoObjectID = 0;
	m_MonoObjectID2 = 0;
	m_MonoObjectID3 = 0;
}

DynamicZoneBossRoom2::~DynamicZoneBossRoom2()
{
}

void DynamicZoneBossRoom2::init()
{
	Assert( m_pZone != NULL );

	m_OMOAStatus = WAIT_FOR_PC;
	getCurrentTime( m_Deadline );
	m_Deadline.tv_sec += 60;
	getCurrentTime( m_EndTime );
	m_EndTime.tv_sec += 10 * 60;
}

void DynamicZoneBossRoom2::heartbeat()
{
	switch ( m_OMOAStatus )
	{
	case WAIT_FOR_PC:
		if ( checkPC() )
		{
			processEntering();
			m_OMOAStatus = ADD_MONO;
			cout << "-----------------------ADD_MONO" << endl;
		}
		break;

	case ADD_MONO:
		if ( addMono() )
		{
			// 보스형 나오신다.
			timecheck();
			m_OMOAStatus = WAIT_FOR_COMPLETE;
			cout << "-----------------------WAIT_FOR_COMPLETE" << endl;
		}
		break;

	case WAIT_FOR_COMPLETE:
		if ( checkComplete() )
		{
			// 10분이라는 시간이 주어지는데 클리어를 못했을 경우 내보내버린다.
			openGateToOut();
			m_OMOAStatus = CLEAR_MONO;
			cout << "-----------------------CLEAR_MONO" << endl;
		}

		if ( !checkMono() )
		{
			// 보스형을 잡았다. 그래도 내보내버린다.
			openGateToOut();
			m_OMOAStatus = WAIT_FOR_CLEAR;
		}

		break;

	case CLEAR_MONO:
		if ( clearMono() )
		{
			m_OMOAStatus = WAIT_FOR_CLEAR;
			cout << "-----------------------WAIT_FOR_CLEAR" << endl;
		}
		break;

	case WAIT_FOR_CLEAR:
		if ( !checkPC() && !checkMono() )
		{
			m_OMOAStatus = OUSTERS_MIRROR_OF_ABYSS_END;
			m_Status = DYNAMIC_ZONE_STATUS_READY;
			cout << "-----------------------READY" << endl;
		}
		break;
	}

	if ( !checkPC() )
	{
		if ( m_OMOAStatus == WAIT_FOR_PC )
		{
			Timeval current;
			getCurrentTime( current );

			if ( current > m_Deadline )
			{
				m_OMOAStatus = CLEAR_MONO;
				cout << "-----------------------Time out" << endl;
			}
		}
		else if ( m_OMOAStatus == WAIT_FOR_COMPLETE )
		{
			m_OMOAStatus = CLEAR_MONO;
		}
	}
}

bool DynamicZoneBossRoom2::checkPC()
{
	Assert( m_pZone != NULL );

	// PC 수 체크
	uint size = m_pZone->getPCManager()->getSize();

	return size != 0;
}

bool DynamicZoneBossRoom2::addMono()
{
	InstantDungeonMonster* pInstantDungeonMonster = g_pInstantDungeonMonsterManager->getInstantDungeonMonster(m_Indun);
	if(pInstantDungeonMonster == NULL) return false;
	Assert( m_pZone != NULL );

	// 이성의 봉인을 생성한다.
	Monster* pMonster = new Monster( pInstantDungeonMonster->getMonsterType() );
	Assert( pMonster != NULL );

	try
	{
		m_pZone->addCreature( pMonster, 12, 27, 2 );
		m_MonoObjectID = pMonster->getObjectID();
	}
	catch ( EmptyTileNotExistException& )
	{
		SAFE_DELETE( pMonster );
	}

	// 이성의 봉인을 생성한다.
	Monster* pMonster2 = new Monster( pInstantDungeonMonster->getMonsterType() );
	Assert( pMonster != NULL );

	try
	{
		m_pZone->addCreature( pMonster2, 16, 27, 2 );
		m_MonoObjectID2 = pMonster2->getObjectID();
	}
	catch ( EmptyTileNotExistException& )
	{
		SAFE_DELETE( pMonster2 );
	}

	// 이성의 봉인을 생성한다.
	Monster* pMonster3 = new Monster( pInstantDungeonMonster->getMonsterType() );
	Assert( pMonster != NULL );

	try
	{
		m_pZone->addCreature( pMonster3, 22, 19, 2 );
		m_MonoObjectID3 = pMonster3->getObjectID();
	}
	catch ( EmptyTileNotExistException& )
	{
		SAFE_DELETE( pMonster3 );
	}

	return true;
}

bool DynamicZoneBossRoom2::clearMono()
{
	Assert( m_pZone != NULL );

	MonsterManager* pMonsterManager = m_pZone->getMonsterManager();
	Assert( pMonsterManager != NULL );

	Creature* pCreature = pMonsterManager->getCreature( m_MonoObjectID );
	if ( pCreature != NULL )
	{
		if ( pCreature->isMonster() )
		{
			EffectKillTimer* pEffect = new EffectKillTimer( pCreature, true );
			pCreature->setFlag( pEffect->getEffectClass() );
			pEffect->setDeadline(50);
			pCreature->addEffect( pEffect );
		}
	}

	Creature* pCreature2 = pMonsterManager->getCreature( m_MonoObjectID2 );
	if ( pCreature2 != NULL )
	{
		if ( pCreature2->isMonster() )
		{
			EffectKillTimer* pEffect = new EffectKillTimer( pCreature2, true );
			pCreature2->setFlag( pEffect->getEffectClass() );
			pEffect->setDeadline(50);
			pCreature2->addEffect( pEffect );
		}
	}

	Creature* pCreature3 = pMonsterManager->getCreature( m_MonoObjectID3 );
	if ( pCreature3 != NULL )
	{
		if ( pCreature3->isMonster() )
		{
			EffectKillTimer* pEffect = new EffectKillTimer( pCreature3, true );
			pCreature3->setFlag( pEffect->getEffectClass() );
			pEffect->setDeadline(50);
			pCreature3->addEffect( pEffect );
		}
	}

	return true;
}

bool DynamicZoneBossRoom2::openGateToOut()
{
	Assert( m_pZone != NULL );

    // 퀘스트를 진행시킨다.
    hash_map<ObjectID_t, Creature*>::const_iterator itr = m_pZone->getPCManager()->getCreatures().begin();
    hash_map<ObjectID_t, Creature*>::const_iterator endItr = m_pZone->getPCManager()->getCreatures().end();

    for ( ; itr != endItr; ++itr )
    {
        Assert( itr->second != NULL );

        if ( itr->second->isPC() )
        {
            PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(itr->second);
            Assert( pPC != NULL );

	m_pZone->getPCManager()->transportAllCreatures( m_ZoneID, m_ZoneX, m_ZoneY );
        }
    }

	return true;
}

void DynamicZoneBossRoom2::timecheck()
{
	const PCManager* pPCManager = m_pZone->getPCManager();
	const hash_map< ObjectID_t, Creature* > & creatures2 = pPCManager->getCreatures();
	hash_map< ObjectID_t, Creature* >::const_iterator itr2;

	if (creatures2.empty())
		return;

	for (itr2=creatures2.begin(); itr2!=creatures2.end(); itr2++)
	{
		Creature* pCreature = itr2->second;
		if (pCreature->isPC())
		{
		Timeval currentTime;
		getCurrentTime(currentTime);

		int Times = m_EndTime.tv_sec - currentTime.tv_sec;

		GCNoticeEvent gcNoticeEvent;
		gcNoticeEvent.setCode( 3 );
		gcNoticeEvent.setParameter( Times );
		pCreature->getPlayer()->sendPacket( &gcNoticeEvent );
		}
		else
		{
			throw Error("PCManager에 PC아닌게 들어있노 -_-");
		}
	}
}

bool DynamicZoneBossRoom2::checkComplete()
{
	Timeval current;
	getCurrentTime( current );
	if ( current > m_EndTime )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DynamicZoneBossRoom2::processEntering()
{
	Assert( m_pZone != NULL );

    // 퀘스트 존에 들어왔음을 알린다.
    hash_map<ObjectID_t, Creature*>::const_iterator itr = m_pZone->getPCManager()->getCreatures().begin();
    hash_map<ObjectID_t, Creature*>::const_iterator endItr = m_pZone->getPCManager()->getCreatures().end();

    for ( ; itr != endItr; ++itr )
    {
        Assert( itr->second != NULL );

        if ( itr->second->isPC() )
        {
            PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(itr->second);
            Assert( pPC != NULL );
        }
    }
}

bool DynamicZoneBossRoom2::checkMono()
{
	Assert( m_pZone != NULL );

	MonsterManager* pMonsterManager = m_pZone->getMonsterManager();
	Assert( pMonsterManager != NULL );

	Creature* pCreature = pMonsterManager->getCreature( m_MonoObjectID );
	Creature* pCreature2 = pMonsterManager->getCreature( m_MonoObjectID2 );
	Creature* pCreature3 = pMonsterManager->getCreature( m_MonoObjectID3 );
	return pCreature != NULL || pCreature2 != NULL || pCreature3 != NULL;
}

void DynamicZoneBossRoom2::killPC()
{
	Assert( m_pZone != NULL );

    // PC 를 죽인다.
    hash_map<ObjectID_t, Creature*>::const_iterator itr = m_pZone->getPCManager()->getCreatures().begin();
    hash_map<ObjectID_t, Creature*>::const_iterator endItr = m_pZone->getPCManager()->getCreatures().end();

    for ( ; itr != endItr; ++itr )
    {
        Assert( itr->second != NULL );

        if ( itr->second->isPC() )
        {
            PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(itr->second);
            Assert( pPC != NULL );

			if ( pPC->isSlayer() )
			{
				Slayer* pSlayer = dynamic_cast<Slayer*>(pPC);
				Assert( pSlayer != NULL );

				pSlayer->setHP(0);
			}
			else if ( pPC->isVampire() )
			{
				Vampire* pVampire = dynamic_cast<Vampire*>(pPC);
				Assert( pVampire != NULL );

				pVampire->setHP(0);
			}
			else if ( pPC->isOusters() )
			{
				Ousters* pOusters = dynamic_cast<Ousters*>(pPC);
				Assert( pOusters != NULL );

				pOusters->setHP(0);
			}
        }
    }
}

DEFINE_DYNAMIC_ZONE_FACTORY( DynamicZoneBossRoom2, DYNAMIC_ZONE_BOSS_ROOM2 )


