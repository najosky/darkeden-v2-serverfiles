//////////////////////////////////////////////////////////////////////
// 
// Filename    : Player.h 
// Written by  : reiot@ewestsoft.com
// Description : ���Ӽ���/�α��μ���/�׽�Ʈ Ŭ���̾�Ʈ�� �÷��̾� Ŭ����
// 
//////////////////////////////////////////////////////////////////////

#ifndef __PLAYER_H__
#define __PLAYER_H__

// include files
#include "Types.h"
#include "Exception.h"

// forward declaration
class Socket;
class SocketInputStream;
class SocketOutputStream;
class Packet;

//////////////////////////////////////////////////////////////////////
//
// class Player
//
// �÷��̾�� �ý��� ��ü��, ����� �ϳ��� Ŭ���̾�Ʈ�� �����ȴ�.
// TCP ���ϰ� ��������½�Ʈ���� ���ο� ������, ��Ŷ �����/ó�� �޽�带
// ���� �ִ�. ���Ӽ���/�α��μ���/�׽�ƮŬ���̾�Ʈ������ �� Ŭ������
// ��ӹ޾Ƽ� ����ϰ� �ȴ�.�
//
// *CAUTION*
//
// Ư�� ���Ӽ����� �α��μ����� ���, �� Ŭ������ ��ӹ��� Ŭ��������
// ����ȭ(Mutex Lock/Unlock)�� ����� �Ѵ�.
//
//////////////////////////////////////////////////////////////////////

const bool UNDISCONNECTED = true;
const bool DISCONNECTED   = false;

class Player {

public :

	// constructor
	Player () throw (Error);
	Player (Socket * pSocket) throw ( Error );
	
	// destructor
	virtual ~Player () throw (Error);

	// read socket's receive buffer and fill input buffer
	virtual void processInput () throw (IOException, Error);
	
	// parse packet and execute handler for the packet
	virtual void processCommand (bool Option = true) throw (IOException, Error);
	
	// flush output buffer to socket's send buffer
	virtual void processOutput () throw (IOException, Error, ProtocolException);
	
	// send packet to player's output buffer
	virtual void sendPacket (Packet* pPacket) throw (ProtocolException, Error);

	// send stream to player's output buffer
	virtual void sendStream( SocketOutputStream* pOutputStream ) throw (ProtocolException, Error);

	// disconnect
	// �÷��̾��� ������ ������ ��, ������� �����ϰ� �α׾ƿ����� ���� ��� ������ ������ 
	// �̹� ���� �����Ƿ� disconnect(DISCONNECTED) �� ����ؼ� ������ �����ؾ� �Ѵ�. �ݸ�, 
	// �����ϰ� �α׾ƿ��� �� ��쿡�� disconnect(UNDISCONNECTED) �� ����ؾ� �Ѵ�.
	virtual void disconnect (bool bDisconnected = DISCONNECTED) throw (InvalidProtocolException, Error);
	
	// get/set socket
	Socket* getSocket () throw () { return m_pSocket; }
	void setSocket (Socket* pSocket) throw ();

	// get/set player ID
	string getID () const throw () { return m_ID; }
	void setID (const string & id) throw () { m_ID = id; }

	// get / set ServerGroupID
	ServerGroupID_t getServerGroupID() const throw() { return m_ServerGroupID; }
	void setServerGroupID(const ServerGroupID_t ServerGroupID) throw() { m_ServerGroupID = ServerGroupID; }

	// get / set MAC Address
	const BYTE* getMacAddress() const { return m_MacAddress; }
	void setMacAddress(const BYTE* ma) { copy( ma, ma+6, (BYTE*)m_MacAddress ); }

	// get debug string
	virtual string toString () const throw (Error);

	//add by viva
	void setKey(WORD EncryptKey, WORD HashKey) throw(); 
	
protected :

	// player id
	string m_ID;
	
	// TCP client socket
	Socket* m_pSocket;
	
	// buffered socket input stream
	SocketInputStream* m_pInputStream;

	// buffered socket output stream
	SocketOutputStream* m_pOutputStream;

	// �� �÷��̾ ���� �����ϴ� ������ ��ġ
	ServerGroupID_t m_ServerGroupID;

	// MAC Address
	BYTE m_MacAddress[6];

	//add by viva 2008-12-31
	BYTE* pHashTable;
};

#endif