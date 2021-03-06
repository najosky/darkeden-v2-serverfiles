//////////////////////////////////////////////////////////////////////////////
// Filename    : EventHeadCount.h
// Written by  : Reiot
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EVENT_HEAD_COUNT_H__
#define __EVENT_HEAD_COUNT_H__

#include "Event.h"
#include "Zone.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////////////
// class EventHeadCount;
//////////////////////////////////////////////////////////////////////////////

class EventHeadCount : public Event 
{
public:
	EventHeadCount(GamePlayer* pGamePlayer) ;
	~EventHeadCount() ;			

public:
	virtual EventClass getEventClass()  { return EVENT_CLASS_HEAD_COUNT; }

	virtual void activate();

	virtual string toString() ;

public:
	void	cutHead()
	{
		m_Count++;
	}

	virtual bool isTemporary()  { return false; }
	virtual bool isPermanent()  { return true; }

private:
	Level_t	m_LastLevel;
	uint	m_Count;
};

#endif
