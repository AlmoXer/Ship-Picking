#pragma once
#include "Element.h"
#include "Player.h"

class CSelectable : public CElement
{
public:
	CSelectable();
	~CSelectable();

	CPlayer *m_Player;
	CPlayer* getPlayer();
};

