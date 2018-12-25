//////////////////////////////////////////////////////////////////////////////
// Filename    : MoonCard.h
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __MOON_CARD_H__
#define __MOON_CARD_H__

#include "Item.h"
#include "ItemInfo.h"
#include "InfoClassManager.h"
#include "ItemFactory.h"
#include "ItemLoader.h"
#include "Mutex.h"

//////////////////////////////////////////////////////////////////////////////
// class MoonCard;
//////////////////////////////////////////////////////////////////////////////

class MoonCard : public Item 
{
public:
	MoonCard() throw();
	MoonCard(ItemType_t itemType, const list<OptionType_t>& optionType, ItemNum_t Num) throw();
	
public:
	virtual void create(const string & ownerID, Storage storage, StorageID_t storageID, BYTE x, BYTE y, ItemID_t itemID=0) throw(Error);
	virtual void save(const string & ownerID, Storage storage, StorageID_t storageID, BYTE x, BYTE y) throw(Error);
	void tinysave(const string & field) const throw (Error)	{ tinysave(field.c_str()); }
	void tinysave(const char* field) ;
	virtual string toString() ;

	static void initItemIDRegistry(void) throw();

public:
	virtual ItemClass getItemClass()  { return Item::ITEM_CLASS_MOON_CARD; }
	virtual string getObjectTableName()  { return "MoonCardObject"; }

	virtual ItemType_t getItemType()  { return m_ItemType; }
	virtual void setItemType(ItemType_t itemType) throw() { m_ItemType = itemType; }

	virtual VolumeWidth_t getVolumeWidth() ;
	virtual VolumeHeight_t getVolumeHeight() ;
	virtual Weight_t getWeight() ;

public:
	virtual ItemNum_t getNum()  { return m_Num; }
	virtual void setNum(ItemNum_t Num) throw() { m_Num = Num; }

	bool    isStackable()  { return true; }

private:
	ItemType_t m_ItemType;
	ItemNum_t  m_Num;
	
	static Mutex    m_Mutex;          // 아이템 ID 관련 락
	static ItemID_t m_ItemIDRegistry; // 클래스별 고유 아이템 아이디 발급기
};

//////////////////////////////////////////////////////////////////////////////
// class MoonCardInfo
//////////////////////////////////////////////////////////////////////////////

class MoonCardInfo : public ItemInfo 
{
public:
	virtual Item::ItemClass getItemClass()  { return Item::ITEM_CLASS_MOON_CARD; }
	virtual string toString() ;
};

//////////////////////////////////////////////////////////////////////////////
// class MoonCardInfoManager;
//////////////////////////////////////////////////////////////////////////////

class MoonCardInfoManager : public InfoClassManager 
{
public:
	virtual Item::ItemClass getItemClass()  { return Item::ITEM_CLASS_MOON_CARD; }
	virtual void load() throw(Error);
};

extern MoonCardInfoManager* g_pMoonCardInfoManager;

//////////////////////////////////////////////////////////////////////////////
// class MoonCardFactory
//////////////////////////////////////////////////////////////////////////////

class MoonCardFactory : public ItemFactory 
{
public:
	virtual Item::ItemClass getItemClass()  { return Item::ITEM_CLASS_MOON_CARD; }
	virtual string getItemClassName()  { return "MoonCard"; }
	
public:
	virtual Item* createItem(ItemType_t ItemType, const list<OptionType_t>& OptionType) throw() { return new MoonCard(ItemType,OptionType,1); }
};

//////////////////////////////////////////////////////////////////////////////
// class MoonCardLoader;
//////////////////////////////////////////////////////////////////////////////

class MoonCardLoader : public ItemLoader 
{
public:
	virtual Item::ItemClass getItemClass()  { return Item::ITEM_CLASS_MOON_CARD; }
	virtual string getItemClassName()  { return "MoonCard"; }

public:
	virtual void load(Creature* pCreature) throw(Error);
	virtual void load(Zone* pZone) throw(Error);
	virtual void load(StorageID_t storageID, Inventory* pInventory) throw(Error);
};

extern MoonCardLoader* g_pMoonCardLoader;

#endif
