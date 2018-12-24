//////////////////////////////////////////////////////////////////////////////
// Filename    : InventorySlotInfo.cpp
// Written By  : elca
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "InventorySlotInfo.h"

//////////////////////////////////////////////////////////////////////////////
// read data from socket input stream
//////////////////////////////////////////////////////////////////////////////
void InventorySlotInfo::read ( SocketInputStream & iStream ) 
	throw ( ProtocolException , Error )
{
	__BEGIN_TRY

	// ���� ���� Ŭ�������� �о���δ�.
	PCItemInfo::read(iStream);

	// �� Ŭ������ �ش��ϴ� �����͸� �о���δ�.
	iStream.read( m_InvenX );
	iStream.read( m_InvenY );

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// write data to socket output stream
//////////////////////////////////////////////////////////////////////////////
void InventorySlotInfo::write ( SocketOutputStream & oStream ) const 
	throw ( ProtocolException , Error )
{
	__BEGIN_TRY
	
	// ���� ���� Ŭ�������� ����.
	PCItemInfo::write(oStream);

	// �� Ŭ������ �ش��ϴ� �����͸� ����.
	oStream.write( m_InvenX );
	oStream.write( m_InvenY );

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// get debug string
//////////////////////////////////////////////////////////////////////////////
string InventorySlotInfo::toString () const 
	throw ()
{
	StringStream msg;

	msg << "InventorySlotInfo("
		<< PCItemInfo::toString()
		<< ",InvenX:" << (int)m_InvenX
		<< ",InvenY:" << (int)m_InvenY
		<< ")";
	
	return msg.toString();
}