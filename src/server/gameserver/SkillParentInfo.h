//----------------------------------------------------------------------
//
// Filename    : SkillParentInfo.h
// Written By  : Elca
// Description :
//
//----------------------------------------------------------------------

#ifndef __SKILL_PARENT_INFO_H__
#define __SKILL_PARENT_INFO_H__

#include "Types.h"
#include "Exception.h"

//----------------------------------------------------------------------
//
// Class SkillParentInfo;
//
// 이 스킬의 부모가 누구인지 알 수 있는 메소드들을 가지고 있는 클래스이다
//
//----------------------------------------------------------------------

class SkillParentInfo {

//--------------------------------------------------
// constructor/destructor
//--------------------------------------------------
public:

	// constructor
	SkillParentInfo(SkillType_t SkillType) ;

	// destructor
	~SkillParentInfo() ;
	
	void load() throw(SQLQueryException, Error) {}
	void save()  {}

//--------------------------------------------------
// AI specific methods
//--------------------------------------------------
public:

	// SkillParentInfoType 을 사용해서, SkillParentInfoInfo 로부터 초기화하기
	void init();

	// enemy specific methods
	void addParents(SkillType_t SkillType) throw(DuplicatedException, Error) {
		m_Parents.push_back(SkillType);
	}
	void deleteParents(SkillType_t SkillType) throw(NoSuchElementException, Error);

	SkillType_t getParents(SkillType_t SkillType) ;


	bool hasParent(SkillType_t ParentSkillType) throw(NoSuchElementException, Error);
	bool hasParent()  { return m_Parents.size() > 0; }

//--------------------------------------------------
// get monster-class-level attributes
//--------------------------------------------------
public:

	void setSkillType(SkillType_t SkillType)  { m_SkillType = SkillType; }
	SkillType_t getSkillType()  { return m_SkillType; }

	string toString() ;

//--------------------------------------------------
// data members
//--------------------------------------------------
private:

	SkillType_t m_SkillType;

	list< SkillType_t > m_Parents;

};



//--------------------------------------------------------------------
//
// Class SkillParentInfoManager
//
//--------------------------------------------------------------------
class SkillParentInfoManager {

public:

	// constructor
	SkillParentInfoManager() ;

	// destructor
	~SkillParentInfoManager() ;

	// initialize Manager
	void init();

	// void load() ;
	// Loading from Database to ParentInfoClass
	void load();
	
	// Save to DB
	void save();

	// get SkillParentInfo
	SkillParentInfo* getSkillParentInfo(SkillType_t SkillType) ;

	// add SkillParentInfo
	void addSkillParentInfo(SkillParentInfo* pSkillParentInfo) throw(DuplicatedException, Error);

	// get SkillCount
	uint getSkillCount()  { return m_SkillCount; }

	// toString for Debug
	string toString() ;

private:

	uint m_SkillCount;

	SkillParentInfo ** m_SkillParentInfoList;
		
};

// Global Variable Definition
extern SkillParentInfoManager* g_pSkillParentInfoManager;

#endif	// __SKILL_PARENT_INFO_MANAGER_H__
