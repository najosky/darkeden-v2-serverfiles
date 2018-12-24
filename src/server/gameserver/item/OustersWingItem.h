//////////////////////////////////////////////////////////////////////////////
// Filename    : VampireETC.h
// Written By  : Elca
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __OustersWingItem_H__
#define __OustersWingItem_H__

#include "Item.h"
#include "ItemInfo.h"
#include "InfoClassManager.h"
#include "ItemFactory.h"
#include "ItemLoader.h"
#include "Mutex.h"

//////////////////////////////////////////////////////////////////////////////
// class OustersETC;
//////////////////////////////////////////////////////////////////////////////

class OustersWingItem : public Item 
{
public:
	OustersWingItem() throw();
	OustersWingItem(ItemType_t itemType, const list<OptionType_t>& optionType) throw();
	
public:
	virtual void create(const string & ownerID, Storage storage, StorageID_t storageID, BYTE x, BYTE y, ItemID_t itemID=0) throw(Error);
	virtual void save(const string & ownerID, Storage storage, StorageID_t storageID, BYTE x, BYTE y) throw(Error);
	void tinysave(const string & field) const throw (Error)	{ tinysave(field.c_str()); }
	void tinysave(const char* field) const throw (Error);
	virtual string toString() const throw();

	static void initItemIDRegistry(void) throw();

public:
	virtual ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_OUSTERSWING_ITEM; }
	virtual string getObjectTableName() const throw() { return "OustersWingItemObject"; }

	virtual ItemType_t getItemType() const throw() { return m_ItemType; }
	virtual void setItemType(ItemType_t itemType) throw() { m_ItemType = itemType; }

	virtual VolumeWidth_t getVolumeWidth() const throw(Error);
	virtual VolumeHeight_t getVolumeHeight() const throw(Error);
	virtual Weight_t getWeight() const throw(Error);

	virtual Color_t getBodyColor() const throw() { return m_BodyColor; }
	virtual void setBodyColor(Color_t BodyColor) throw() { m_BodyColor = BodyColor; }

	virtual Color_t getEffectColor() const throw() { return m_EffectColor; }
	virtual void setEffectColor(Color_t EffectColor) throw() { m_EffectColor = EffectColor; }

	bool    isStackable() const throw() { return true; }

private:
	ItemType_t m_ItemType; // ...
	Color_t  m_BodyColor;      //  �⺻ �� �ڵ�
	Color_t  m_EffectColor;      //  �⺻ ����Ʈ �ڵ�

	static Mutex    m_Mutex;          // ������ ID ���� ��
	static ItemID_t m_ItemIDRegistry; // Ŭ������ ���� ������ ���̵� �߱ޱ�
};


//////////////////////////////////////////////////////////////////////////////
// class OustersWingItemInfo
//////////////////////////////////////////////////////////////////////////////

class OustersWingItemInfo : public ItemInfo 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_OUSTERSWING_ITEM; }
	virtual string toString() const throw();
};


//////////////////////////////////////////////////////////////////////////////
// class OustersWingItemInfoManager;
//////////////////////////////////////////////////////////////////////////////

class OustersWingItemInfoManager : public InfoClassManager 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_OUSTERSWING_ITEM; }
	virtual void load() throw(Error);
};

// global variable declaration
extern OustersWingItemInfoManager* g_pOustersWingItemInfoManager;


//////////////////////////////////////////////////////////////////////////////
// class OustersWingItemFactory
//////////////////////////////////////////////////////////////////////////////
class OustersWingItemFactory : public ItemFactory 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_OUSTERSWING_ITEM; }
	virtual string getItemClassName() const throw() { return "OustersWingItem"; }
	
public:
	virtual Item* createItem(ItemType_t ItemType, const list<OptionType_t>& OptionType) throw() { return new OustersWingItem(ItemType,OptionType); }
};


//////////////////////////////////////////////////////////////////////////////
// class OustersWingItemLoader;
//////////////////////////////////////////////////////////////////////////////

class OustersWingItemLoader : public ItemLoader 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_OUSTERSWING_ITEM; }
	virtual string getItemClassName() const throw() { return "OustersWingItem"; }

public:
	virtual void load(Creature* pCreature) throw(Error);
	virtual void load(Zone* pZone) throw(Error);
	virtual void load(StorageID_t storageID, Inventory* pInventory) throw(Error);
};

extern OustersWingItemLoader* g_pOustersWingItemLoader;

#endif