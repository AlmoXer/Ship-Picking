#include "BattleShip.h"


CBattleShip::CBattleShip()
{
}


CBattleShip::~CBattleShip()
{
}

void CBattleShip::setAttackTarget(CShip *p_Target)
{
	m_AttackTarget = p_Target;
}

void CBattleShip::removeAttackTarget()
{
	m_AttackTarget = nullptr;
}