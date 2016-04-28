#include "Selectable.h"


CSelectable::CSelectable()
{
}


CSelectable::~CSelectable()
{
}

CPlayer* CSelectable::getPlayer()
{
	return m_Player;
}