////////////////////////////////////////////////////////////////////////////////
// Filename    : ConditionHasInvenSpace.h
// Written By  : 
// Description :
////////////////////////////////////////////////////////////////////////////////

#ifndef __PC_HAS_ORIGINAL_ITEMS_H__
#define __PC_HAS_ORIGINAL_ITEMS_H__

#include "Condition.h"
#include "ConditionFactory.h"
#include "Creature.h"

//////////////////////////////////////////////////////////////////////////////
// class ConditionHasInvenSpace;
//////////////////////////////////////////////////////////////////////////////

class ConditionPcHasOriginalItems : public Condition 
{
public:
	virtual ConditionType_t getConditionType() const throw() { return CONDITION_PC_HAS_ORIGINAL_ITEMS; }
	virtual bool isPassive() const throw() { return true; }
	virtual bool isSatisfied(Creature* pNPC, Creature* pPC = NULL, void* pParam = NULL) const throw();
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual string toString() const throw();
private:
	uint	m_ItemClass, m_ItemType, m_ItemNumber;
};

//////////////////////////////////////////////////////////////////////////////
// class ConditionHasInvenSpaceFactory;
//////////////////////////////////////////////////////////////////////////////

class ConditionPcHasOriginalItemsFactory : public ConditionFactory 
{
public:
    virtual ConditionType_t getConditionType() const throw() { return Condition::CONDITION_PC_HAS_ORIGINAL_ITEMS; }
    virtual Condition* createCondition() const throw() { return new ConditionPcHasOriginalItems(); }
    virtual string getConditionName() const throw() { return "PcHasOriginalItems"; }
};

#endif