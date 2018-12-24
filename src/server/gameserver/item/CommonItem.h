//////////////////////////////////////////////////////////////////////////////
// Filename    : MoonCard.h
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __COMMON_ITEM_H__
#define __COMMON_ITEM_H__

#include "Item.h"
#include "ItemInfo.h"
#include "InfoClassManager.h"
#include "ItemFactory.h"
#include "ItemLoader.h"
#include "Mutex.h"

//////////////////////////////////////////////////////////////////////////////
// class MoonCard;
//////////////////////////////////////////////////////////////////////////////

class CommonItem : public Item 
{
public:
	CommonItem() throw();
	CommonItem(ItemType_t itemType, const list<OptionType_t>& optionType, ItemNum_t Num) throw();
	
public:
	virtual void create(const string & ownerID, Storage storage, StorageID_t storageID, BYTE x, BYTE y, ItemID_t itemID=0) throw(Error);
	virtual void save(const string & ownerID, Storage storage, StorageID_t storageID, BYTE x, BYTE y) throw(Error);
	void tinysave(const string & field) const throw (Error)	{ tinysave(field.c_str()); }
	void tinysave(const char* field) const throw (Error);
	virtual string toString() const throw();

	static void initItemIDRegistry(void) throw();

public:
	virtual ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_COMMON_ITEM; }
	virtual string getObjectTableName() const throw() { return "CommonItemObject"; }

	virtual ItemType_t getItemType() const throw() { return m_ItemType; }
	virtual void setItemType(ItemType_t itemType) throw() { m_ItemType = itemType; }

	virtual VolumeWidth_t getVolumeWidth() const throw(Error);
	virtual VolumeHeight_t getVolumeHeight() const throw(Error);
	virtual Weight_t getWeight() const throw(Error);

public:
	virtual ItemNum_t getNum() const throw() { return m_Num; }
	virtual void setNum(ItemNum_t Num) throw() { m_Num = Num; }

	bool    isStackable() const throw() { return true; }

private:
	ItemType_t m_ItemType;
	ItemNum_t  m_Num;
	
	static Mutex    m_Mutex;          // ������ ID ���� ��
	static ItemID_t m_ItemIDRegistry; // Ŭ������ ���� ������ ���̵� �߱ޱ�
};

//////////////////////////////////////////////////////////////////////////////
// class CommonItemInfo
//////////////////////////////////////////////////////////////////////////////

class CommonItemInfo : public ItemInfo 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_COMMON_ITEM; }
	virtual string toString() const throw();
};

//////////////////////////////////////////////////////////////////////////////
// class CommonItemInfoManager;
//////////////////////////////////////////////////////////////////////////////

class CommonItemInfoManager : public InfoClassManager 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_COMMON_ITEM; }
	virtual void load() throw(Error);
};

extern CommonItemInfoManager* g_pCommonItemInfoManager;

//////////////////////////////////////////////////////////////////////////////
// class CommonItemFactory
//////////////////////////////////////////////////////////////////////////////

class CommonItemFactory : public ItemFactory 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_COMMON_ITEM; }
	virtual string getItemClassName() const throw() { return "CommonItem"; }
	
public:
	virtual Item* createItem(ItemType_t ItemType, const list<OptionType_t>& OptionType) throw() { return new CommonItem(ItemType,OptionType,1); }
};

//////////////////////////////////////////////////////////////////////////////
// class CommonItemLoader;
//////////////////////////////////////////////////////////////////////////////

class CommonItemLoader : public ItemLoader 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_COMMON_ITEM; }
	virtual string getItemClassName() const throw() { return "CommonItem"; }

public:
	virtual void load(Creature* pCreature) throw(Error);
	virtual void load(Zone* pZone) throw(Error);
	virtual void load(StorageID_t storageID, Inventory* pInventory) throw(Error);
};

extern CommonItemLoader* g_pCommonItemLoader;

#endif