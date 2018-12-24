//////////////////////////////////////////////////////////////////////////////
// Filename    : GCSubInventoryInfo.cpp 
// Written By  :
// Description :
//////////////////////////////////////////////////////////////////////////////
#include "GCSubInventoryInfo.h"

//////////////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////////////
GCSubInventoryInfo::GCSubInventoryInfo() 
	throw ()
{
	__BEGIN_TRY 

	m_pInventoryInfo = NULL;
	m_ObjectID = 0;

	__END_CATCH;
}

//////////////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////////////
GCSubInventoryInfo::~GCSubInventoryInfo() 
	throw ()
{
	__BEGIN_TRY 

	SAFE_DELETE( m_pInventoryInfo );

	__END_CATCH 
}

//////////////////////////////////////////////////////////////////////////////
// �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
//////////////////////////////////////////////////////////////////////////////
void GCSubInventoryInfo::read (SocketInputStream & iStream) 
	 throw (ProtocolException , Error)
{
	__BEGIN_TRY

	m_pInventoryInfo = new InventoryInfo;
	m_pInventoryInfo->read( iStream );
	iStream.read( m_ObjectID );

	__END_CATCH
}

		    
//////////////////////////////////////////////////////////////////////////////
// ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
//////////////////////////////////////////////////////////////////////////////
void GCSubInventoryInfo::write (SocketOutputStream & oStream) const 
     throw (ProtocolException , Error)
{
	__BEGIN_TRY

	m_pInventoryInfo->write( oStream );
	oStream.write( m_ObjectID );

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// execute packet's handler
//////////////////////////////////////////////////////////////////////////////
void GCSubInventoryInfo::execute (Player * pPlayer) 
	 throw (ProtocolException , Error)
{
	__BEGIN_TRY
		
	GCSubInventoryInfoHandler::execute(this , pPlayer);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// get packet's debug string
//////////////////////////////////////////////////////////////////////////////	
string GCSubInventoryInfo::toString () const
       throw ()
{
	__BEGIN_TRY
		
	StringStream msg;
	
	msg << "GCSubInventoryInfo(" ;
	msg << ")";

	return msg.toString();
		
	__END_CATCH
}