#pragma once
#include "Weapon.h"


class CLaser : public CWeapon
{
public:
	CLaser();
	~CLaser();
	float openClock;
	float openCounterClock;
	float AttackTimer;
	float Range;
	float maxRotationSpeed;
	float cooldown;

	CPlacement *m_Target;

	virtual void Init(CHVector p_Position, CHVector p_Ausrichtung, CShip *p_Ship, float open_clock, float open_counterclock) = 0;
	virtual bool destroy(float p_TimeDelta, CPlacement *p_Placement) = 0;
};

