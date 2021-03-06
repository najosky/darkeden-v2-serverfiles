//////////////////////////////////////////////////////////////////////////////
// Filename    : GameServerInfoManager.h
// Written By  : reiot@ewestsoft.com
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __GAME_SERVER_INFO_MANAGER_H__
#define __GAME_SERVER_INFO_MANAGER_H__

#include "Types.h"
#include "Exception.h"
#include "GameServerInfo.h"
#include <hash_map>

typedef hash_map<ServerID_t, GameServerInfo*> HashMapGameServerInfo;
typedef HashMapGameServerInfo::iterator HashMapGameServerInfoItor;

//////////////////////////////////////////////////////////////////////////////
// class GameServerInfoManager;
// 게임 서버의 ID 를 키값으로 하는 GameServerInfo의 hash_map 을 
// 내부에 가지고 있다.
// World 하나의 GameServerInfo를 가진다.
//////////////////////////////////////////////////////////////////////////////

class GameServerInfoManager 
{
public:
	GameServerInfoManager ();
	~GameServerInfoManager ();

public:
	void init ();
	void load ();
	
	void addGameServerInfo ( GameServerInfo * pGameServerInfo, const ServerGroupID_t ServerGroupID ) ;
	void deleteGameServerInfo ( const ServerID_t ServerID, const ServerGroupID_t ServerGroupID ) ;
	GameServerInfo * getGameServerInfo ( const ServerID_t ServerID, const ServerGroupID_t ServerGroupID ) ;
	uint getSize ( const ServerGroupID_t ServerGroupID )  { return m_pGameServerInfos[ServerGroupID].size(); }
	string toString () ;
	
	// get MaxServerGroupID
	int getMaxServerGroupID()  { return m_MaxServerGroupID; }

private:
	// hash map of GameServerInfo
	// key   : GameServerID_t
	// value : GameServerInfo *
	HashMapGameServerInfo* m_pGameServerInfos;
	int m_MaxServerGroupID;

};

// global variable declaration
extern GameServerInfoManager * g_pGameServerInfoManager;

#endif
