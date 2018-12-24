//////////////////////////////////////////////////////////////////////////////
// Filename    : PlayerTypes.h
// Written By  : Reiot
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __PLAYER_TYPES_H__
#define __PLAYER_TYPES_H__

#include "SystemTypes.h"

//////////////////////////////////////////////////////////////////////////////
// �÷��̾� ���� �� ���� ���� ���� ID
//////////////////////////////////////////////////////////////////////////////
enum ErrorID {
	INVALID_ID_PASSWORD,
	ALREADY_CONNECTED,
	ALREADY_REGISTER_ID,
	ALREADY_REGISTER_SSN,
	EMPTY_ID,
	SMALL_ID_LENGTH,
	EMPTY_PASSWORD,
	SMALL_PASSWORD_LENGTH,
	EMPTY_NAME,
	EMPTY_SSN,
	INVALID_SSN,
	NOT_FOUND_PLAYER,
	NOT_FOUND_ID,
	NOT_PAY_ACCOUNT,
	NOT_ALLOW_ACCOUNT,
	ETC_ERROR,
	IP_DENYED,
	CHILDGUARD_DENYED,
	CANNOT_AUTHORIZE_BILLING,	// ���� ������ ã�� �� �����ϴ�.
	CANNOT_CREATE_PC_BILLING,	// ���� ����ڰ� �ƴ϶� ĳ���͸� �� ����ϴ�.
	KEY_EXPIRED,				// Ű ��ȿ�Ⱓ�� ������.
	NOT_FOUND_KEY				// Ű�� ����.
};


//////////////////////////////////////////////////////////////////////////////
// �÷��̾� ���̵�
//////////////////////////////////////////////////////////////////////////////
const uint minIDLength = 4;
const uint maxIDLength = 10;


//////////////////////////////////////////////////////////////////////////////
// �÷��̾� ��ȣ
//////////////////////////////////////////////////////////////////////////////
const uint minPasswordLength = 6;
const uint maxPasswordLength = 10;


//////////////////////////////////////////////////////////////////////////////
// �÷��̾� �̸�
//////////////////////////////////////////////////////////////////////////////
const uint maxNameLength = 20;


//////////////////////////////////////////////////////////////////////////////
// �ֹε�Ϲ�ȣ ( '-' �� �����ؾ� �Ѵ�. )
//////////////////////////////////////////////////////////////////////////////
const uint maxSSNLength = 20;


//////////////////////////////////////////////////////////////////////////////
// ����ȭ
//////////////////////////////////////////////////////////////////////////////
const uint maxTelephoneLength = 15;


//////////////////////////////////////////////////////////////////////////////
// �޴���
//////////////////////////////////////////////////////////////////////////////
const uint maxCellularLength = 15;


//////////////////////////////////////////////////////////////////////////////
// ������ȣ
//////////////////////////////////////////////////////////////////////////////
const uint maxZipCodeLength = 7;


//////////////////////////////////////////////////////////////////////////////
// ���ּ�
//////////////////////////////////////////////////////////////////////////////
const uint maxAddressLength = 100;


//////////////////////////////////////////////////////////////////////////////
// ���ڸ���
//////////////////////////////////////////////////////////////////////////////
const uint maxEmailLength = 50;


//////////////////////////////////////////////////////////////////////////////
// Ȩ������
//////////////////////////////////////////////////////////////////////////////
const uint maxHomepageLength = 50;


//////////////////////////////////////////////////////////////////////////////
// �ڱ�Ұ���
//////////////////////////////////////////////////////////////////////////////
const uint maxProfileLength = 200;


//////////////////////////////////////////////////////////////////////////////
// ����
//////////////////////////////////////////////////////////////////////////////
typedef BYTE Nation_t;
const uint szNation = szBYTE;

enum Nation
{   
	KOREA,
	USA,
	JAPAN
};

const string Nation2String [] =
{   
	"KOREA",
	"USA",
	"JAPAN"
};


//////////////////////////////////////////////////////////////////////////////
// �г�Ƽ Ÿ��
//////////////////////////////////////////////////////////////////////////////
enum PenaltyType 
{
	PENALTY_TYPE_KICKED,				// ������
	PENALTY_TYPE_MUTE,					// ���Ķ�
	PENALTY_TYPE_FREEZING,				// �����
	PENALTY_TYPE_MAX
};


//////////////////////////////////////////////////////////////////////////////
// �α��� ���
//////////////////////////////////////////////////////////////////////////////
enum LoginMode
{
	LOGIN_MODE_NORMAL = 0,				// �׳� �α���
	LOGIN_MODE_WEBLOGIN,				// ������ �α���

	LOGIN_MODE_MAX
};

#endif