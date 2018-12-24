//////////////////////////////////////////////////////////////////////////////
// Filename    : AR.h
// Written By  : Elca
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __AR_H__
#define __AR_H__

//#include "Gun.h"
#include "ConcreteItem.h"
#include "ItemPolicies.h"
#include "ItemInfo.h"
#include "InfoClassManager.h"
#include "ItemFactory.h"
#include "ItemLoader.h"
#include "Mutex.h"

//////////////////////////////////////////////////////////////////////////////
// class AR;
//////////////////////////////////////////////////////////////////////////////

class AR : public ConcreteItem<Item::ITEM_CLASS_AR, NoStack, HasDurability, HasOption, WeaponGrade, SlayerGun, NoEnchantLevel, HasOption2, HasHeroOption, HasHeroOptionAttr>
{
public:
	AR() throw();
	AR(ItemType_t itemType, const list<OptionType_t>& optionType) throw();
	~AR() throw();
	
public:
	virtual void create(const string & ownerID, Storage storage, StorageID_t storageID, BYTE x, BYTE y, ItemID_t itemID=0) throw(Error);
	virtual void save(const string & ownerID, Storage storage, StorageID_t storageID, BYTE x, BYTE y) throw(Error);
	virtual void saveBullet() throw(Error);
	void tinysave(const string & field) const throw (Error)	{ tinysave(field.c_str()); }
	void tinysave(const char* field) const throw (Error);
	virtual string toString() const throw();

	static void initItemIDRegistry(void) throw();

public:
//	virtual ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_AR; }
//	virtual string getObjectTableName() const throw() { return "ARObject"; }

/*	bool isSilverWeapon() const throw() { return true; }

	virtual VolumeWidth_t getVolumeWidth() const throw(Error);
	virtual VolumeHeight_t getVolumeHeight() const throw(Error);
	virtual Weight_t getWeight() const throw(Error);

	virtual Damage_t getMinDamage() const throw(Error);
	virtual Damage_t getMaxDamage() const throw(Error);

	virtual Range_t getRange() const throw(Error);

	virtual ToHit_t getToHitBonus() const throw(Error);

	virtual int getCriticalBonus(void) const throw();*/

	void makePCItemInfo(PCItemInfo& result) const;

private:
	static Mutex    m_Mutex;          // ������ ID ���� ��
	static ItemID_t m_ItemIDRegistry; // Ŭ������ ���� ������ ���̵� �߱ޱ�
};


//////////////////////////////////////////////////////////////////////////////
// class ARInfo
//////////////////////////////////////////////////////////////////////////////

class ARInfo : public ItemInfo 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_AR; }

	virtual Durability_t getDurability() const throw() { return m_Durability; }
	virtual void setDurability(Durability_t durability) throw() { m_Durability = durability; }

	virtual Damage_t getMinDamage() const throw() { return m_MinDamage; }
	virtual void setMinDamage(Damage_t minDamage) throw() { m_MinDamage = minDamage; }

	virtual Damage_t getMaxDamage() const throw() { return m_MaxDamage; }
	virtual void setMaxDamage(Damage_t maxDamage) throw() { m_MaxDamage = maxDamage; }

	Range_t getRange() const throw() { return m_Range; }
	void setRange(Range_t range) throw() { m_Range = range; }

	ToHit_t getToHitBonus() const throw() { return m_ToHitBonus; }
	void setToHitBonus(ToHit_t tohit) throw() { m_ToHitBonus = tohit; }

	virtual Speed_t getSpeed(void) const throw() { return m_Speed; }
	virtual void setSpeed(Speed_t speed) throw() { m_Speed = speed; }

	virtual uint getItemLevel(void) const throw() { return m_ItemLevel; }
	virtual void setItemLevel(uint level) throw() { m_ItemLevel = level; }

	virtual int getCriticalBonus(void) const throw() { return m_CriticalBonus; }
	virtual void setCriticalBonus(int bonus) throw() { m_CriticalBonus = bonus; }

	virtual string toString() const throw();

private:
	Durability_t  m_Durability;    // ������
	Damage_t      m_MinDamage;     // �ּ� ������
	Damage_t      m_MaxDamage;     // �ִ� ������
	Range_t       m_Range;         // �����Ÿ�
	ToHit_t       m_ToHitBonus;    // ���߷� ���ʽ�
	Speed_t       m_Speed;         // ���� �ӵ�
	uint          m_ItemLevel;     // �������� ����
	int           m_CriticalBonus; // �����۸��� �ٸ� ũ��Ƽ�� Ȯ��

};


//////////////////////////////////////////////////////////////////////////////
// class ARInfoManager;
//////////////////////////////////////////////////////////////////////////////

class ARInfoManager : public InfoClassManager 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_AR; }
	virtual void load() throw(Error);
};

extern ARInfoManager* g_pARInfoManager;


//////////////////////////////////////////////////////////////////////////////
// class ARFactory
//////////////////////////////////////////////////////////////////////////////

class ARFactory : public ItemFactory 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_AR; }
	virtual string getItemClassName() const throw() { return "AR"; }
	
public:
	virtual Item* createItem(ItemType_t ItemType, const list<OptionType_t>& OptionType) throw() { return new AR(ItemType,OptionType); }
};


//////////////////////////////////////////////////////////////////////////////
// class ARLoader;
//////////////////////////////////////////////////////////////////////////////

class ARLoader : public ItemLoader 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_AR; }
	virtual string getItemClassName() const throw() { return "AR"; }

public:
	virtual void load(Creature* pCreature) throw(Error);
	virtual void load(Zone* pZone) throw(Error);
	virtual void load(StorageID_t storageID, Inventory* pInventory) throw(Error);
};

extern ARLoader* g_pARLoader;

#endif