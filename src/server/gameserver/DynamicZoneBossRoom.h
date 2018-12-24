/////////////////////////////////////////////////////////////////////////////
// DynamicZoneOustersMirrorOfAbyss.h
/////////////////////////////////////////////////////////////////////////////

#ifndef __DYNAMIC_ZONE_BOSS_ROOM_H__
#define __DYNAMIC_ZONE_BOSS_ROOM_H__

#include "DynamicZone.h"


///////////////////////////////////////////////////////////
// class DynamicZoneBossRoom
///////////////////////////////////////////////////////////
class DynamicZoneBossRoom : public DynamicZone
{
public:
	DynamicZoneBossRoom();
	virtual ~DynamicZoneBossRoom();

public:
	void init();		// ���̳��� �� �ʱ�ȭ
	void heartbeat();	// ���̳��� �� ��Ʈ��Ʈ

public:
	bool checkPC();
	bool addMono();
	bool clearMono();
	bool openGateToOut();
	bool checkComplete();
	bool checkMono();
	void timecheck();
	void processEntering();
	void killPC();

	int getInstantID() { return m_Indun; }
	void setInstantID( int Indun) { m_Indun = Indun; }

	void setZoneID( int ZoneID) { m_ZoneID = ZoneID; }
	void setZoneX( int ZoneX) { m_ZoneX = ZoneX; }
	void setZoneY( int ZoneY) { m_ZoneY = ZoneY; }

private:
	int m_OMOAStatus;
	ObjectID_t m_MonoObjectID;
	Timeval m_EndTime;
	int m_ZoneID;
	int m_ZoneX;
	int m_ZoneY;

	// �ν���Ʈ ���� ����
	int	m_Indun;
};


DECLARE_DYNAMIC_ZONE_FACTORY( DynamicZoneBossRoom )

#endif
