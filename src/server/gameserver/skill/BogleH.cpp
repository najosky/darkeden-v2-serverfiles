//////////////////////////////////////////////////////////////////////////////
// Filename    : GoreGlandFire.cpp
// Written by  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "BogleH.h"
#include "SimpleTileMissileSkill.h"
#include "RankBonus.h"

//////////////////////////////////////////////////////////////////////////////
// 생성자
// 마스크를 초기화한다.
//////////////////////////////////////////////////////////////////////////////
BogleH::BogleH()
	
{
	__BEGIN_TRY

	m_pBogleHMask[0].set(0,  0);
	m_pBogleHMask[1].set(-1, -1);
	m_pBogleHMask[2].set(0, -1);
	m_pBogleHMask[3].set(1, -1);
	m_pBogleHMask[4].set(-1,  0);
	m_pBogleHMask[5].set(1,  0);
	m_pBogleHMask[6].set(-1,  1);
	m_pBogleHMask[7].set(0,  1);
	m_pBogleHMask[8].set(1,  1);

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// 몬스터 타일 핸들러
//////////////////////////////////////////////////////////////////////////////
void BogleH::execute(Monster* pMonster, ZoneCoord_t X, ZoneCoord_t Y)
	
{
	__BEGIN_TRY

	//cout << "TID[" << Thread::self() << "]" << getSkillHandlerName() << "begin " << endl;

	SkillInput input(pMonster);
	SkillOutput output;
	computeOutput(input, output);

	SIMPLE_SKILL_INPUT param;
	param.SkillType     = getSkillType();
	param.SkillDamage   = output.Damage;
	param.Delay         = output.Delay;
	param.ItemClass     = Item::ITEM_CLASS_MAX;
	param.STRMultiplier = 0;
	param.DEXMultiplier = 0;
	param.INTMultiplier = 0;
	param.bMagicHitRoll = true;
	param.bMagicDamage  = true;
	param.bAdd          = false;

	SIMPLE_SKILL_OUTPUT result;

	for (int i=0; i<9; i++)
	{
		param.addMask(m_pBogleHMask[i].x, m_pBogleHMask[i].y, 100);
	}

	g_SimpleTileMissileSkill.execute(pMonster, X, Y, param, result);

	//cout << "TID[" << Thread::self() << "]" << getSkillHandlerName() << " end " << endl;

	__END_CATCH
}

BogleH g_BogleH;
