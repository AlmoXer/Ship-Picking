#pragma once
#include "Ship.h"
class CBattleShip :
	public CShip
{
public:
	CShip *m_AttackTarget;

	virtual void setAttackTarget(CShip *p_Placement);
	virtual void removeAttackTarget();

	CBattleShip();
	~CBattleShip();



};

