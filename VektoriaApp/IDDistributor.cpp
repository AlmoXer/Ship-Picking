#include "IDDistributor.h"


IDDistributor::IDDistributor()
{
	m_Counter = 0;
}


IDDistributor::~IDDistributor()
{
}

unsigned long IDDistributor::getID(int p_Element, int p_Selectable, int  p_Type, int p_Player)
{
	m_ID = 0;
	m_Counter++;
	m_ID += p_Element * 10000000;
	m_ID += p_Selectable * 1000000;
	m_ID += p_Type * 10000;
	m_ID += m_Counter *10;
	m_ID += p_Player;
	return m_ID;
}
