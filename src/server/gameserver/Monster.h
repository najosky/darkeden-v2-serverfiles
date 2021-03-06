//////////////////////////////////////////////////////////////////////////////
// Filename    : Monster.h
// Written By  : excel96
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "Creature.h"
#include "Assert.h"
#include "Timeval.h"
#include "MonsterInfo.h"
#include "PrecedenceTable.h"

//////////////////////////////////////////////////////////////////////////////
// Forward declaration
//////////////////////////////////////////////////////////////////////////////
class Slayer;
class Vampire;
class Ousters;
class MonsterAI;
struct SUMMON_INFO2;

class Monster : public Creature 
{
// 생성자/소멸자
public:
	Monster(MonsterType_t monsterType) ;
	virtual ~Monster();

// 하위 클래스 상속 함수
public:
	virtual CreatureClass getCreatureClass()  { return CREATURE_CLASS_MONSTER; }
	virtual string getCreatureClassString()  { return "CREATURE_CLASS_MONSTER"; }

	virtual Race_t getRace() const;

	virtual void registerObject();

	virtual bool load() throw (InvalidProtocolException, Error) { return true;}
	virtual void save()  {}

	virtual string toString() ;

// AI specific methods
public:

	// AI 코드가 수행되는 메인 메쏘드이다.
	void act(const Timeval& currentTime);
	void actDeadAction(void);

	// enemy specific methods
	void addEnemy(Creature* pCreature);
	void addPotentialEnemy(Creature* pCreature);
	void deleteEnemy(ObjectID_t objectID) throw(NoSuchElementException, Error);
	void deleteAllEnemy();
	Creature* getPrimaryEnemy() ;
	ObjectID_t getEnemy(EnemyPriority enemyPriority = ENEMY_PRIMARY) ;

	// Enemy 리스트에서 로그아웃한 PC 를 삭제한다.
	void verifyEnemies();

	bool isRealEnemy(Creature* pEnemy);

	// 이 몬스터에게 적이 하나이상 지정되어 있는가?
	bool hasEnemy()  { return m_Enemies.size() > 0; }
	uint getMaxEnemies() ;

	list<ObjectID_t>& getEnemies(void)  { return m_Enemies;}

	// 선제 공격 Enemy판별. by sigi. 2002.9.23
	bool isEnemyToAttack(Creature* pCreature) const;
	bool isEnemyToAttack(Slayer* pSlayer) const;
	bool isEnemyToAttack(Vampire* pVampire) const;
	bool isEnemyToAttack(Monster* pMonster) const;

	bool canMove(ZoneCoord_t nx, ZoneCoord_t ny) ;
// get monster-class-level attributes
public:
	MonsterType_t getMonsterType()  { return m_MonsterType; }
	const string&        getName()  { return m_Name; }
	const string&        getMonsterName()  { return m_Name; }
	void                 setName(const string name) { m_Name = name; }

	void                 setLevel(const int level) { m_Level = level; }

	SpriteType_t  getSpriteType() ;
	Level_t       getLevel() ;
	uint          getBodySize() ;
	Color_t       getMainColor() ;
	Color_t       getSubColor() ;
	MAlignment    getAlignment() ;
	//AttackOrder   getAttackOrder() ;


// get/set instance-level attributes
public:
	Attr_t getSTR()  { return m_STR; }
	void setSTR(Attr_t str)  { m_STR = str; }
	
	Attr_t getDEX()  { return m_DEX; }
	void setDEX(Attr_t dex)  { m_DEX = dex; }

	Attr_t getINT()  { return m_INT; }
	void setINT(Attr_t inte)  { m_INT = inte; }

	Exp_t getExp()  { return m_Exp; }
	void setExp(Exp_t str)  { m_Exp = str; }
	
	HP_t getHP(AttrType attrType = ATTR_CURRENT)  { return m_HP[attrType]; }
	void setHP(HP_t hp, AttrType attrType = ATTR_CURRENT)  { m_HP[attrType] = hp; }
	void setHP(HP_t current, HP_t max)  { m_HP[ATTR_CURRENT] = current; m_HP[ATTR_MAX] = max; }

	Defense_t getDefense()  { return m_Defense; }
	void setDefense(Defense_t ac)  { m_Defense = ac; }

	Protection_t getProtection()  { return m_Protection; }
	void setProtection(Protection_t ac)  { m_Protection = ac; }

	ToHit_t getToHit()  { return m_ToHit; }
	void setToHit(ToHit_t tohit)  { m_ToHit = tohit; }

	Damage_t getDamage(AttrType attrType = ATTR_CURRENT)  { return m_Damage[attrType]; }
	void setDamage(Damage_t damage, AttrType attrType = ATTR_CURRENT)  { m_Damage[attrType] = damage; }
	void setDamage(Damage_t current, Damage_t max)  { m_Damage[ATTR_CURRENT] = current; m_Damage[ATTR_MAX] = max; }

	int getMeleeRange(void) const { return m_MeleeRange; }
	void setMeleeRange(int range) { m_MeleeRange = range; }

	int getMissileRange(void) const { return m_MissileRange; }
	void setMissileRange(int range) { m_MissileRange = range; }

	Moral_t getMoral(void)  { return m_Moral;}
	void setMoral(Moral_t moral)  { m_Moral = moral;}
				
	Turn_t getDelay()  { return m_Delay; }
	void setDelay(Turn_t delay)  { m_Delay = delay; }

	Turn_t getAttackDelay()  { return m_AttackDelay; }
	void setAttackDelay(Turn_t delay)  { m_AttackDelay = delay; }

	Timeval getAccuDelay()  { return m_AccuDelay; }
	void setAccuDelay(Timeval delay)  { m_AccuDelay = delay; }
	void addAccuDelay(Timeval delay)  { m_AccuDelay = m_AccuDelay + delay; }
	void clearAccuDelay()  { m_AccuDelay.tv_sec = 0; m_AccuDelay.tv_usec = 0; }

	void clearEnemyLimitTime() ;

	Timeval getNextTurn()  { return m_NextTurn; }
	void setNextTurn(Timeval NextTurn)  { m_NextTurn = NextTurn; }

	void setDamaged(bool value=true) ;

	int getEffectClass()  { return m_EffectClass; }
	void setEffectClass(int inte)  { m_EffectClass = inte; }

	void initAllStat(void) ;

	Silver_t getSilverDamage(void)  { return m_SilverDamage; }
	void setSilverDamage(Silver_t damage)  { m_SilverDamage = damage; }

	MonsterAI* getBrain(void) const { return m_pBrain; }
	void	   setBrain(MonsterAI* pBrain);
	void	   removeBrain(void);

	virtual ClanType_t getClanType(void) const { return m_ClanType; }
	virtual void setClanType(ClanType_t clan) { m_ClanType = clan; }

	PrecedenceTable* getPrecedenceTable(void) { return &m_PrecedenceTable; }
//	void addPrecedence(Creature* pCreature, int damage);
	void addPrecedence(const string & Name, int PartyID, int damage);
	int getOustersExp( Ousters* pOusters );

	string getHostName(void) const { return m_HostName; }
	void setHostName(const string& name) { m_HostName = name; }

	int getHostPartyID(void) const { return m_HostPartyID; }
	void setHostPartyID(int ID) { m_HostPartyID = ID; }

	CreatureClass getLastHitCreatureClass(void) const { return m_LastHitCreatureClass; }
	void setLastHitCreatureClass(CreatureClass CClass) { m_LastHitCreatureClass = CClass; }
	
	// 몬스터 이벤트 몬스터인지 세팅하는 부분
    bool getEventMonsterFlag(void) const { return m_isEventMonster; }
	void setEventMonsterFlag(bool flag)  { m_isEventMonster = flag; }

	bool isChief(void) const 		{ return m_bChief; }
	void setChief(bool flag=true) 	{ m_bChief = flag; }


// ..
public:
	bool isAlive()  { return m_HP[ATTR_CURRENT] > 0; }
	bool isDead()  { return m_HP[ATTR_CURRENT] == 0; }

public:
	bool hasRelic()  { return m_RelicIndex; }
	void setRelic(int relicIndex) { m_RelicIndex = relicIndex; }

public:
	bool isScanEnemy() const  { return m_bScanEnemy; }
	void setScanEnemy(bool bScan=true) { m_bScanEnemy = bScan; }

	bool isEnemyLimit() const { return m_bEnemyLimit; }

	bool isMaster() const  { return m_bMaster; }
	void setMaster(bool bMaster=true) { m_bMaster = bMaster; }

	// 몹에서 아이템 나올까? by sigi. 2002.9.2
	bool hasTreasure() const  { return m_bTreasure; }
	void setTreasure(bool bTreasure=true) { m_bTreasure = m_bTreasure && bTreasure; }	// 원래 Treasure가 있는 애들만 Treasure가 있어야 된다.

	// 몬스터가 소환하는 몬스터의 종류. by sigi. 2002.9.2
	bool getMonsterSummonInfo(SUMMON_INFO2& summonInfo);
	bool hasNextMonsterSummonInfo();
	int  getMonsterSummonStep() const { return m_MonsterSummonStep; }
	void setMonsterSummonStep(int ss) { m_MonsterSummonStep = ss; }

	// attackOrder - by sigi. 2002.9.4
	AttackOrder getAttackOrder() const { return m_AttackOrder; }
	void setAttackOrder(AttackOrder attackOrder) { m_AttackOrder = attackOrder; }

	void setOwnerObjectID(ObjectID_t id) 	{ m_OwnerObjectID = id; }
	ObjectID_t  getOwnerObjectID() const 	{ return m_OwnerObjectID; }

	void setEventMonsterIndex(int index)	{ m_EventMonsterIndex = index; }
	int  getEventMonsterIndex()	const		{ return m_EventMonsterIndex; }
	bool isEventMonster() const				{ return m_EventMonsterIndex<0xFFFF; }	// -_-;

	void setQuestItem( Item* pItem )		{ m_pQuestItem = pItem; }
	Item* getQuestItem() const { return m_pQuestItem; }

#ifdef __UNDERWORLD__
	bool isUnderworld() { return m_bUnderWorld; }
	void setUnderworld( bool bUnderworld = true ) { m_bUnderWorld = bUnderworld; }
#endif

	void setLastKiller(ObjectID_t id) { m_LastKiller = id; }
	ObjectID_t getLastKiller() const { return m_LastKiller; }

// data members
private:
	MonsterType_t m_MonsterType;
	string        m_Name;
	Level_t        m_Level;
	Attr_t        m_STR;
	Attr_t        m_DEX;
	Attr_t        m_INT;
	HP_t          m_HP[2];
	Defense_t     m_Defense;
	Protection_t  m_Protection;
	ToHit_t       m_ToHit;
	Damage_t      m_Damage[2];
	int           m_MeleeRange;
	int           m_MissileRange;
	bool          m_isEventMonster;
	bool		  m_bChief;
	bool		  m_bWideAddItem;
	// Exp : 몬스터를 죽였을 때 받는 경험치는?
	Exp_t m_Exp;
	int m_WideAddItemXY;
	// 사기 - 몬스터가 전투에 얼마나 충실히 임하는가?
	Moral_t m_Moral;
	int	m_EffectClass;

	// 처리 딜레이 - 몬스터의 상태에 따라서, 처리 딜레이는 달라져야 한다.
	// 가령 이상한 마법에 걸렸다든지 하면, 처리 딜레이가 길어져서 몬스터가
	// 반응이 느려질 것이다. 이는 개체 레벨이다.
	Turn_t  m_Delay;
	Turn_t  m_AttackDelay;
	Timeval m_AccuDelay;

	// enemy list
	// *CAUTION*
	// 쉽게 생각하면, Creture* 의 리스트로 구현할 수도 있겠지만,
	// 이럴 경우, enemy 로 지정된 PC 가 로그아웃하는 경우, 자신을
	// 적으로 지정한 몬스터를 찾아서 리스트에서 삭제해야 한다는
	// 결론이 나온다. 따라서, OID 를 저장해야 하며, 이 값을 사용해서
	// PC 등을 검색해야 한다.
	list<ObjectID_t> m_Enemies;

	// 다음 액션 실행 시간
	Timeval m_NextTurn;	

	// MonsterAI class
	MonsterAI* m_pBrain;

	// 은 도금 데미지
	Silver_t m_SilverDamage;

	// 클랜 타입
	ClanType_t m_ClanType;

	// "먹자" 방지를 위한 우선권 테이블
	PrecedenceTable m_PrecedenceTable;

	// 이 몬스터에서 나오는 아이템에 대한 우선권을 가진 자의 이름과 파티 ID
	string m_HostName;
	int m_HostPartyID;

	// 이 몬스터를 마지막으로 때린 종족의 크리쳐 클래스
	// 이 몬스터가 죽었을 경우에, 생성하는 아이템을 결정하기 위한 것이다.
	CreatureClass m_LastHitCreatureClass;

	// 이 몬스터가 Relic을 가지고 있는가 아닌가?
	int m_RelicIndex;

//#ifdef __XMAS_EVENT_CODE__
	Timeval m_LastSpeechTime;
//#endif

	bool m_bScanEnemy;
	Timeval m_NextScanTurn;	

	// 몬스터의 적 인식타임
	bool m_bEnemyLimit;
	Timeval m_EnemyLimitTime;
	Creature* m_pOldEnemy;

	// 2002.9.2
	bool m_bMaster;
	bool m_bTreasure;
	int  m_MonsterSummonStep;		// 소환 단계

#ifdef __UNDERWORLD__
	bool m_bUnderWorld;
#endif
	
	// AttackOrder
	AttackOrder  m_AttackOrder;

	// 소환된 몹인 경우.. 혹은 아니더라도.. 주인의 정보
	ObjectID_t	 m_OwnerObjectID;

	// 2002.10.14
	int			m_EventMonsterIndex;

	Item*		m_pQuestItem;

	ObjectID_t	m_LastKiller;

	HP_t		m_RegenAmount;
	Timeval		m_NextRegenTime;
};

#endif // __MONSTER_H__
